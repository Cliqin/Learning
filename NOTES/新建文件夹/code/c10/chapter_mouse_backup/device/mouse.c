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
static int8_t buffer[3];
static int8_t x, y;
static int8_t old_x;
static int8_t old_y;

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

/*鼠标移动程序*/
// void mouse_move(uint8_t off_x, uint8_t off_y)
// {
//     put_char("##");
// }

/* 鼠标中断处理程序 */
static void intr_mouse_handler(void)
{
    // read to start next interrupt
    // uint32_t code = inb(KBD_BUF_PORT);
    // put_int(offset);

    buffer[offset] = inb(KBD_BUF_PORT);
    offset = (offset + 1) % 3;

    if (offset == 1)

    {
        uint8_t i;
        for (i = 0; i < 3; i++)
        {
            // 有按键按下
            if ((buffer[1] & (0x1 << i)))
            {
                if (i == 0)
                {
                    // put_str("left");
                    // mouse_move(0x02);
                }
                else if (i == 1)
                {
                    // put_str("right");
                    // mouse_move(0x04);
                }
                else if (i == 2)
                {
                    // put_str("middle");
                    // mouse_move(0x06);
                }
                put_str("push ");
            }
        }

        uint8_t new_x = buffer[2] & (0xff) % 16; // X---0-F
        if (new_x - old_x > 0)
        {
            x += 1;
        }
        else if (new_x - old_x < 0)
        {
            x -= 1;
        }
        // 反例
        if (new_x == 0xF && old_x == 0)
        {
            x -= 2;
        }
        if (new_x == 0 && old_x == 0xF)
        {
            x += 2;
        }
        old_x = new_x;
        // x += buffer[2];
        if (x < 0)
            x = 0;
        else if (x >= 80)
            x = 79;

        uint8_t new_y = buffer[0] & (0xff) % 16; // X---0-F
        if (new_y - old_y > 0)
        {
            y -= 1;
        }
        else if (new_y - old_y < 0)
        {
            y += 1;
        }

        // 反例
        if (new_y == 0xF && old_y == 0)
        {
            y += 2;
        }
        if (new_y == 0 && old_y == 0xF)
        {
            y -= 2;
        }
        old_y = new_y;
        // x += buffer[2];
        if (y < 0)
            y = 0;
        else if (y >= 25)
            y = 24;
        uint32_t t = y * 160 + x * 2;
        mouse_move(t);

    }
    return;
}
/* 鼠标初始化 */

void mouse_init()
{
    // put_str("mouse init start\n");
    // register_handler(0x2c, intr_mouse_handler);
    // put_str("mouse init done\n");
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
    offset = 0;
    x = 0x28; // 40
    y = 0xc;  // 12
    uint32_t t = y * 160 + x * 2;
    put_int(t);
    mouse_move(t);
    put_str("#");
    put_int(x);
    old_x = 0x0;
    old_y = 0x0;
    // mouse_move(0x00, 0x77);
    put_str("mouse init done\n");
}
