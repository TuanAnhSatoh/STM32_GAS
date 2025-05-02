#include "button.h"

void Button_Init(void) {
    // Bật clock cho GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Cấu hình PA12, PA11, PA10 làm Input với Pull-up
    GPIOA->CRH &= ~(GPIO_CRH_MODE12 | GPIO_CRH_CNF12 |
                    GPIO_CRH_MODE11 | GPIO_CRH_CNF11 |
                    GPIO_CRH_MODE10 | GPIO_CRH_CNF10);
    GPIOA->CRH |= (GPIO_CRH_CNF12_1 | GPIO_CRH_CNF11_1 | GPIO_CRH_CNF10_1);
    GPIOA->ODR |= (START_BUTTON_PIN | STOP_BUTTON_PIN | RESET_BUTTON_PIN); // Kích hoạt Pull-up
}

uint8_t Button_ReadStart(void) {
    return !(GPIOA->IDR & START_BUTTON_PIN); // Trả về 1 nếu nút được nhấn
}

uint8_t Button_ReadStop(void) {
    return !(GPIOA->IDR & STOP_BUTTON_PIN);
}

uint8_t Button_ReadReset(void) {
    return !(GPIOA->IDR & RESET_BUTTON_PIN);
}