#include "lcd.h"
#include "i2c.h"

void LCD_Init(void) {
    // Khởi tạo I2C1 (PB6, PB7)
    I2C1_Init();

    // Gửi các lệnh khởi tạo LCD
    LCD_SendCommand(0x33); // Chế độ 4-bit
    LCD_SendCommand(0x32); // Chế độ 4-bit
    LCD_SendCommand(0x28); // 2 dòng, 5x8 font
    LCD_SendCommand(0x0C); // Bật hiển thị, tắt con trỏ
    LCD_SendCommand(0x06); // Tự động dịch con trỏ
    LCD_SendCommand(0x01); // Xóa màn hình
}

void LCD_SendCommand(uint8_t cmd) {
    // Gửi lệnh đến LCD qua I2C1
    I2C1_SendByte(LCD_I2C_ADDRESS, (cmd & 0xF0));       // Gửi 4 bit cao
    I2C1_SendByte(LCD_I2C_ADDRESS, ((cmd << 4) & 0xF0)); // Gửi 4 bit thấp
}

void LCD_SendData(uint8_t data) {
    // Gửi dữ liệu đến LCD qua I2C1
    I2C1_SendByte(LCD_I2C_ADDRESS, (data & 0xF0) | 0x01);       // Gửi 4 bit cao
    I2C1_SendByte(LCD_I2C_ADDRESS, ((data << 4) & 0xF0) | 0x01); // Gửi 4 bit thấp
}

void LCD_Print(const char *str) {
    // Hiển thị chuỗi ký tự trên LCD
    while (*str) {
        LCD_SendData(*str++);
    }
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    // Đặt vị trí con trỏ trên LCD
    uint8_t address = (row == 0) ? 0x80 : 0xC0; // Dòng 0 bắt đầu tại 0x80, dòng 1 tại 0xC0
    address += col;
    LCD_SendCommand(address);
}

void LCD_Clear(void) {
    // Xóa toàn bộ nội dung trên LCD
    LCD_SendCommand(0x01);
}