#ifndef __LIB_KERNEL_PRINT_H
#define __LIB_KERNEL_PRINT_H
#include "stdint.h"
void put_char(uint8_t char_asci);
void put_str(char* message);
void put_int(uint32_t num);	 // 以16进制打印
void set_cursor(uint32_t cursor_pos);
void mouse_move(uint32_t x);
void mouse_recover(uint32_t x);
uint8_t mouse_extract(uint32_t x);
#endif

