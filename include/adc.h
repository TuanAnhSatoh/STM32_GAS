#ifndef ADC_H
#define ADC_H

#include <stm32f103xe.h>

// Hàm khởi tạo ADC
void ADC_Init(void);

// Hàm đọc giá trị ADC từ kênh được chọn
uint16_t ADC_Read(void);

#endif // ADC_H