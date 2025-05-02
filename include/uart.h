#ifndef UART_H
#define UART_H

#include <stm32f103xe.h>
#include <stdint.h>

// Hàm khởi tạo UART
void UART_Init(void);

// Hàm gửi một ký tự qua UART
void UART_SendChar(char c);

// Hàm gửi chuỗi ký tự qua UART
void UART_SendString(const char *str);

#endif // UART_H