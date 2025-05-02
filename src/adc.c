#include "adc.h"

void ADC_Init(void) {
    // Bật clock cho ADC1 và GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;  // Bật clock cho ADC1
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Bật clock cho GPIOA

    // Cấu hình PA6 thành chế độ Analog
    GPIOA->CRL &= ~(GPIO_CRL_MODE6 | GPIO_CRL_CNF6); // MODE6 = 00, CNF6 = 00

    // Cấu hình ADC
    ADC1->CR2 |= ADC_CR2_ADON; // Bật ADC
    for (volatile int i = 0; i < 1000; i++); // Đợi ADC ổn định

    ADC1->SMPR2 |= ADC_SMPR2_SMP6; // Chọn thời gian lấy mẫu cho Channel 6 (239.5 cycles)
    ADC1->SQR3 = 6; // Chọn Channel 6 làm kênh đầu tiên trong chuỗi

    ADC1->CR2 |= ADC_CR2_CAL; // Hiệu chuẩn ADC
    while (ADC1->CR2 & ADC_CR2_CAL); // Đợi hiệu chuẩn hoàn tất
}

uint16_t ADC_Read(void) {
    ADC1->CR2 |= ADC_CR2_ADON; // Bắt đầu chuyển đổi
    while (!(ADC1->SR & ADC_SR_EOC)); // Đợi chuyển đổi hoàn tất
    return ADC1->DR; // Trả về giá trị ADC
}