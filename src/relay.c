#include "relay.h"

void Relay_Init(void) {
    // Bật clock cho GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Cấu hình PA8 làm Output Push-Pull
    GPIOA->CRH &= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8);
    GPIOA->CRH |= GPIO_CRH_MODE8_1; // Output mode, max speed 2 MHz
}

void Relay_On(void) {
    GPIOA->ODR |= RELAY_PIN; // Set PA8
}

void Relay_Off(void) {
    GPIOA->ODR &= ~RELAY_PIN; // Clear PA8
}