#include "uart.h"

void UART_Init(void) {
    // Bật clock cho GPIOA và USART1
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN;

    // Cấu hình PA9 (TX) ở chế độ Alternate Function Push-Pull
    GPIOA->CRH &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9);
    GPIOA->CRH |= GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_CNF9_1;

    // Cấu hình PA10 (RX) ở chế độ Input Floating
    GPIOA->CRH &= ~(GPIO_CRH_MODE10 | GPIO_CRH_CNF10);
    GPIOA->CRH |= GPIO_CRH_CNF10_0;

    // Cấu hình USART1
    USART1->BRR = 72000000 / 9600; // Baud rate = 9600 (APB2 clock = 72 MHz)
    USART1->CR1 |= USART_CR1_TE | USART_CR1_RE; // Bật truyền và nhận
    USART1->CR1 |= USART_CR1_UE; // Bật USART
}

void UART_SendChar(char c) {
    while (!(USART1->SR & USART_SR_TXE)); // Đợi TXE (Transmit Data Register Empty)
    USART1->DR = c; // Gửi ký tự
}

void UART_SendString(const char *str) {
    while (*str) {
        UART_SendChar(*str++);
    }
}