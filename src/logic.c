#include "logic.h"
#include "buzzer.h"
#include "led.h"
#include "relay.h"
#include "button.h"

// Trạng thái hệ thống
static uint8_t system_active = 0; // 0: Dừng, 1: Hoạt động

void Logic_Init(void) {
    // Khởi tạo các thiết bị liên quan
    Buzzer_Init();
    LED_Init();
    Relay_Init();
    Button_Init();
}

void Logic_Process(uint16_t gas_value) {
    // Kiểm tra trạng thái nút nhấn
    if (Button_ReadStart()) {
        system_active = 1; // Bắt đầu hoạt động
    } else if (Button_ReadStop()) {
        system_active = 0; // Dừng hoạt động
    } else if (Button_ReadReset()) {
        system_active = 0; // Reset hệ thống
        gas_value = 0; // Đặt lại giá trị khí gas
    }

    // Xử lý trạng thái hệ thống
    if (!system_active) {
        // Hệ thống dừng hoạt động
        LED_SetBlue(0);
        LED_SetGreen(100); // LED xanh lá
        LED_SetRed(0);
        Relay_Off(); // Tắt relay
        Buzzer_Off(); // Tắt buzzer
        return; // Không xử lý thêm
    }

    // Xử lý logic dựa trên giá trị khí gas
    if (gas_value < GAS_THRESHOLD_LOW) {
        // Không có khí gas
        LED_SetBlue(100); // LED xanh dương
        LED_SetGreen(0);
        LED_SetRed(0);
        Relay_Off(); // Tắt relay
        Buzzer_Off(); // Tắt buzzer
    } else if (gas_value < GAS_THRESHOLD_MEDIUM) {
        // Nồng độ khí gas thấp
        LED_SetBlue(0);
        LED_SetGreen(100); // LED xanh lá
        LED_SetRed(0);
        Relay_Off(); // Tắt relay
        Buzzer_Off(); // Tắt buzzer
    } else if (gas_value < GAS_THRESHOLD_HIGH) {
        // Nồng độ khí gas cao
        LED_SetBlue(0);
        LED_SetGreen(0);
        LED_SetRed(100); // LED đỏ
        Relay_Off(); // Tắt relay
        Buzzer_On(); // Bật buzzer
    } else {
        // Nồng độ khí gas nguy hiểm
        LED_SetBlue(0);
        LED_SetGreen(0);
        LED_SetRed(100); // LED đỏ
        Relay_On(); // Bật relay (ngắt nguồn cung cấp gas)
        Buzzer_On(); // Bật buzzer
    }
}