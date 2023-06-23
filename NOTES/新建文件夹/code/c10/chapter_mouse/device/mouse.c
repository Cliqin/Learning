#include "mouse.h"
#include "print.h"
#include "interrupt.h"
#include "io.h"
#include "global.h"

#define KBD_BUF_PORT 0x60 // 键盘buffer寄存器端口号为0x60
#define MOS_BUF_PORT 0x64 // 鼠标buffer寄存器端口号为0x64
#define KEYSTA_SEND_NOTREADY 0x02
#define KEYCMD_SENDTO_MOUSE 0xd4
#define MOUSECMD_ENABLE 0xf4

static int8_t offset;
static int16_t buffer[3];
static int8_t button;
static int16_t x, y;

static int16_t old_quadrant;
static int16_t old_x;
static int16_t old_y;
static int16_t new_x;
static int16_t new_y;
static int8_t mouse_status;
static int8_t message;

// asm volatile("movw %ebx,%gs","movb (%%ecx),%0":"=a"(retval):"c"(kk),"b"(SELECTOR VIDEO):"memory");
// static inline void extract(int8_t kk)
// {
//     uint8_t retval;
//     asm volatile("movw %ebx,%1","movb (%%ecx),%0":"=a"(message):"c"(kk),"b"(0x0003 << 3):"memory");
// }

void waitKBCReady()
{
    for (;;)
    {
        if ((inb(MOS_BUF_PORT) & 0x02) == 0)
        {
            break;
        }
    }
}

/* 鼠标中断处理程序 */
static void intr_mouse_handler(void)
{
    uint16_t a = inb(KBD_BUF_PORT);
    // 接收第一次收到的0xfa,并标志鼠标已启动
    if (mouse_status == 0 && a == 0xfa)
    {
        put_str("READY ");
        mouse_status = 1;
        return;
    }

    buffer[offset] = a;

    offset = (offset + 1) % 3;
    // 已连续录入三个字节的信息,现在开始解析
    if (offset == 0)
    {
        // 记录按键
        if (buffer[0] == 0x9)
        {
            put_str("(");
            put_int(old_x);
            put_str(",");
            put_int(old_y);
            put_str(") ");
            return;
        }
        else if (buffer[0] == 0xa)
        {
            // extract(old_x * 2 + old_y * 160);
            mouse_extract(old_x * 2 + old_y * 160);
            put_char(*(uint8_t *)0x0ff0);
            return;
        }
        else if (buffer[0] == 0xc)
        {
            // 中键按下
            return;
        }
        else if (buffer[0] == 0x8)
        {
            // 在移动
            if (buffer[1] || buffer[2])
            {
            }
            else
            {
                // 抬起,不管它
                return;
            }
        }
        if(old_y==1){
            mouse_recover(old_x * 2 + (old_y-1) * 160);
        }
        if(old_y>1){
            mouse_recover(old_x * 2 + (old_y-1) * 160);
            mouse_recover(old_x * 2 + (old_y-2) * 160);
        }
        mouse_recover(old_x * 2 + old_y * 160);
        // 判断x是否为负
        if (buffer[0] & 0x10)
        {
            new_x = x - (0xff - buffer[1]);
        }
        else
        {
            new_x = x + buffer[1];
        }
        // 判断y是否为负
        if (buffer[0] & 0x20)
        {
            new_y = y + (0xff - buffer[2]);
        }
        else
        {
            new_y = y - buffer[2];
        }

        int16_t draw_x = new_x / 4;
        int16_t draw_y = new_y / 8;

        if (draw_x >= 80)
            draw_x = 79;
        if (draw_x < 0)
            draw_x = 9;
        if (draw_y >= 25)
            draw_y = 24;
        if (draw_y < 0)
            draw_y = 0;

        mouse_move(draw_x * 2 + draw_y * 160);
        old_x = draw_x;
        old_y = draw_y;
        old_quadrant = buffer[0];
    }
    return;
}
/* 鼠标初始化 */

void mouse_init()
{
    put_str("mouse init start\n");
    waitKBCReady();
    // 0x60让键盘电路进入数据接受状态
    outb(0x64, 0x60);
    waitKBCReady();
    // 数据0x47要求键盘电路启动鼠标模式，这样鼠标硬件所产生的数据信息，通过键盘电路端口0x60就可读到
    outb(0x60, 0x47);
    waitKBCReady();
    outb(0x64, 0xd4);
    waitKBCReady();
    // 0xf4数据激活鼠标电路，激活后将会给CPU发送中断信号
    outb(0x60, 0xf4);
    register_handler(0x2c, intr_mouse_handler);
    outb(0x64, 0x66);
    mouse_status = 0;
    old_quadrant = 8;
    offset = 0;
    old_x = 0;
    old_y = 0;
    x = 179; // 179
    y = 100; // 100
    put_str("mouse init done\n");
}
