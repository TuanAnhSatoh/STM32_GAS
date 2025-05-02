#include "buzzer.h"

void Buzzer_Init(void) {
    // Bật clock cho GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Cấu hình PA9 làm Output Push-Pull
    GPIOA->CRH &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9);
    GPIOA->CRH |= GPIO_CRH_MODE9_1; // Output mode, max speed 2 MHz
}

void Buzzer_On(void) {
    GPIOA->ODR |= BUZZER_PIN; // Set PA9
}

void Buzzer_Off(void) {
    GPIOA->ODR &= ~BUZZER_PIN; // Clear PA9
}