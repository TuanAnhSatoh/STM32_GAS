#include "i2c.h"

void I2C1_Init(void) {
    // Bật clock cho I2C1 và GPIOB
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    // Cấu hình PB6 (SCL) và PB7 (SDA) ở chế độ Alternate Function Open-Drain
    GPIOB->CRL &= ~(GPIO_CRL_MODE6 | GPIO_CRL_CNF6 | GPIO_CRL_MODE7 | GPIO_CRL_CNF7);
    GPIOB->CRL |= (GPIO_CRL_MODE6_1 | GPIO_CRL_CNF6_1 | GPIO_CRL_MODE7_1 | GPIO_CRL_CNF7_1);

    // Cấu hình I2C1
    I2C1->CR2 = 36; // Tần số clock APB1 = 36 MHz
    I2C1->CCR = 180; // Tốc độ I2C = 100 kHz
    I2C1->TRISE = 37; // Thời gian tăng
    I2C1->CR1 |= I2C_CR1_PE; // Bật I2C
}

void I2C2_Init(void) {
    // Bật clock cho I2C2 và GPIOB
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;

    // Cấu hình PB10 (SCL) và PB11 (SDA) ở chế độ Alternate Function Open-Drain
    GPIOB->CRH &= ~(GPIO_CRH_MODE10 | GPIO_CRH_CNF10 | GPIO_CRH_MODE11 | GPIO_CRH_CNF11);
    GPIOB->CRH |= (GPIO_CRH_MODE10_1 | GPIO_CRH_CNF10_1 | GPIO_CRH_MODE11_1 | GPIO_CRH_CNF11_1);

    // Cấu hình I2C2
    I2C2->CR2 = 36; // Tần số clock APB1 = 36 MHz
    I2C2->CCR = 180; // Tốc độ I2C = 100 kHz
    I2C2->TRISE = 37; // Thời gian tăng
    I2C2->CR1 |= I2C_CR1_PE; // Bật I2C
}

void I2C1_SendByte(uint8_t address, uint8_t data) {
    // Gửi một byte qua I2C1
    I2C1->CR1 |= I2C_CR1_START; // Bắt đầu truyền
    while (!(I2C1->SR1 & I2C_SR1_SB)); // Đợi cờ Start Bit

    I2C1->DR = address << 1; // Gửi địa chỉ (Write)
    while (!(I2C1->SR1 & I2C_SR1_ADDR)); // Đợi cờ Address
    (void)I2C1->SR2; // Đọc SR2 để xóa cờ

    I2C1->DR = data; // Gửi dữ liệu
    while (!(I2C1->SR1 & I2C_SR1_TXE)); // Đợi cờ truyền xong

    I2C1->CR1 |= I2C_CR1_STOP; // Kết thúc truyền
}

void I2C2_SendByte(uint8_t address, uint8_t data) {
    // Gửi một byte qua I2C2
    I2C2->CR1 |= I2C_CR1_START; // Bắt đầu truyền
    while (!(I2C2->SR1 & I2C_SR1_SB)); // Đợi cờ Start Bit

    I2C2->DR = address << 1; // Gửi địa chỉ (Write)
    while (!(I2C2->SR1 & I2C_SR1_ADDR)); // Đợi cờ Address
    (void)I2C2->SR2; // Đọc SR2 để xóa cờ

    I2C2->DR = data; // Gửi dữ liệu
    while (!(I2C2->SR1 & I2C_SR1_TXE)); // Đợi cờ truyền xong

    I2C2->CR1 |= I2C_CR1_STOP; // Kết thúc truyền
}

void I2C1_SendBytes(uint8_t address, const uint8_t *data, uint8_t length) {
    // Gửi nhiều byte qua I2C1
    I2C1->CR1 |= I2C_CR1_START; // Bắt đầu truyền
    while (!(I2C1->SR1 & I2C_SR1_SB)); // Đợi cờ Start Bit

    I2C1->DR = address << 1; // Gửi địa chỉ (Write)
    while (!(I2C1->SR1 & I2C_SR1_ADDR)); // Đợi cờ Address
    (void)I2C1->SR2; // Đọc SR2 để xóa cờ

    for (uint8_t i = 0; i < length; i++) {
        I2C1->DR = data[i]; // Gửi từng byte
        while (!(I2C1->SR1 & I2C_SR1_TXE)); // Đợi cờ truyền xong
    }

    I2C1->CR1 |= I2C_CR1_STOP; // Kết thúc truyền
}

void I2C2_SendBytes(uint8_t address, const uint8_t *data, uint8_t length) {
    // Gửi nhiều byte qua I2C2
    I2C2->CR1 |= I2C_CR1_START; // Bắt đầu truyền
    while (!(I2C2->SR1 & I2C_SR1_SB)); // Đợi cờ Start Bit

    I2C2->DR = address << 1; // Gửi địa chỉ (Write)
    while (!(I2C2->SR1 & I2C_SR1_ADDR)); // Đợi cờ Address
    (void)I2C2->SR2; // Đọc SR2 để xóa cờ

    for (uint8_t i = 0; i < length; i++) {
        I2C2->DR = data[i]; // Gửi từng byte
        while (!(I2C2->SR1 & I2C_SR1_TXE)); // Đợi cờ truyền xong
    }

    I2C2->CR1 |= I2C_CR1_STOP; // Kết thúc truyền
}