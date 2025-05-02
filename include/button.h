#ifndef BUTTON_H
#define BUTTON_H

#include <stm32f103xe.h>

// Chân kết nối button
#define START_BUTTON_PIN GPIO_IDR_IDR12
#define STOP_BUTTON_PIN GPIO_IDR_IDR11
#define RESET_BUTTON_PIN GPIO_IDR_IDR10

// Hàm khởi tạo button
void Button_Init(void);

// Hàm đọc trạng thái button
uint8_t Button_ReadStart(void);
uint8_t Button_ReadStop(void);
uint8_t Button_ReadReset(void);

#endif