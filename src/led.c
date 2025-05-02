#include "led.h"

void LED_Init(void) {
    // Bật clock cho GPIOA, GPIOB và Timer2
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Cấu hình PA15 (CH1), PB3 (CH2), PA2 (CH3) làm Alternate Function Push-Pull
    GPIOA->CRH &= ~(GPIO_CRH_MODE15 | GPIO_CRH_CNF15);
    GPIOA->CRH |= GPIO_CRH_MODE15_1 | GPIO_CRH_CNF15_1;

    GPIOB->CRL &= ~(GPIO_CRL_MODE3 | GPIO_CRL_CNF3);
    GPIOB->CRL |= GPIO_CRL_MODE3_1 | GPIO_CRL_CNF3_1;

    GPIOA->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);
    GPIOA->CRL |= GPIO_CRL_MODE2_1 | GPIO_CRL_CNF2_1;

    // Cấu hình Timer2 cho chế độ PWM
    TIM2->PSC = 72 - 1; // Chia tần số (72 MHz / 72 = 1 MHz)
    TIM2->ARR = 100 - 1; // Giá trị đếm tối đa (PWM 100 mức)

    // Cấu hình các kênh PWM
    TIM2->CCMR1 |= (6 << TIM_CCMR1_OC1M_Pos) | (6 << TIM_CCMR1_OC2M_Pos); // CH1, CH2
    TIM2->CCMR2 |= (6 << TIM_CCMR2_OC3M_Pos); // CH3

    TIM2->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E; // Bật các kênh

    // Bật Timer2
    TIM2->CR1 |= TIM_CR1_CEN;
}

void LED_SetRed(uint8_t brightness) {
    TIM2->CCR1 = brightness; // Điều chỉnh độ sáng kênh CH1 (PA15)
}

void LED_SetGreen(uint8_t brightness) {
    TIM2->CCR3 = brightness; // Điều chỉnh độ sáng kênh CH3 (PA2)
}

void LED_SetBlue(uint8_t brightness) {
    TIM2->CCR2 = brightness; // Điều chỉnh độ sáng kênh CH2 (PB3)
}

void LED_Off(void) {
    LED_SetRed(0);
    LED_SetGreen(0);
    LED_SetBlue(0);
}