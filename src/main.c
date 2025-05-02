#include "adc.h"
#include "lcd.h"
#include "buzzer.h"
#include "led.h"
#include "relay.h"
#include "esp32.h"
#include "button.h"
#include "logic.h"
#include <stdio.h> // Thêm dòng này để sử dụng sprintf

int main(void) {
    uint16_t gas_value;

    // Khởi tạo các module
    ADC_Init();
    LCD_Init(); // Sử dụng I2C1
    ESP32_Init(); // Sử dụng I2C2
    Buzzer_Init();
    LED_Init();
    Relay_Init();
    Button_Init();
    Logic_Init();

    while (1) {
        // Đọc giá trị khí gas
        gas_value = ADC_Read();

        // Hiển thị giá trị khí gas trên LCD
        LCD_SetCursor(0, 0);
        LCD_Print("Gas Value:");
        LCD_SetCursor(1, 0);
        char buffer[16];
        sprintf(buffer, "%u", gas_value);
        LCD_Print(buffer);

        // Gửi giá trị khí gas đến ESP32
        uint8_t esp32_data[2];
        esp32_data[0] = (gas_value >> 8) & 0xFF; // Byte cao
        esp32_data[1] = gas_value & 0xFF;        // Byte thấp
        ESP32_SendData(esp32_data, 2);

        // Xử lý logic hệ thống
        Logic_Process(gas_value);
    }
}