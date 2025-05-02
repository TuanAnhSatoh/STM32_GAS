#ifndef RELAY_H
#define RELAY_H

#include <stm32f103xe.h>

// Chân GPIO điều khiển relay (PA8)
#define RELAY_PIN GPIO_ODR_ODR8

// Hàm khởi tạo relay
void Relay_Init(void);

// Hàm bật relay
void Relay_On(void);

// Hàm tắt relay
void Relay_Off(void);

#endif // RELAY_H