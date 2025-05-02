#ifndef LED_H
#define LED_H

#include <stm32f103xe.h>

// Hàm khởi tạo LED RGB
void LED_Init(void);

// Hàm điều chỉnh độ sáng của từng màu (0-100%)
void LED_SetRed(uint8_t brightness);
void LED_SetGreen(uint8_t brightness);
void LED_SetBlue(uint8_t brightness);

// Hàm tắt toàn bộ LED
void LED_Off(void);

#endif // LED_H