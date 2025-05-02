#ifndef BUZZER_H
#define BUZZER_H

#include <stm32f103xe.h>

// Chân GPIO điều khiển buzzer (PA9)
#define BUZZER_PIN GPIO_ODR_ODR9

// Hàm khởi tạo buzzer
void Buzzer_Init(void);

// Hàm bật buzzer
void Buzzer_On(void);

// Hàm tắt buzzer
void Buzzer_Off(void);

#endif // BUZZER_H