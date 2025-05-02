#ifndef LOGIC_H
#define LOGIC_H

#include <stdint.h>

// Các ngưỡng khí gas
#define GAS_THRESHOLD_LOW 1000
#define GAS_THRESHOLD_MEDIUM 2000
#define GAS_THRESHOLD_HIGH 3000

// Hàm khởi tạo logic hệ thống
void Logic_Init(void);

// Hàm xử lý logic hệ thống
void Logic_Process(uint16_t gas_value);

#endif // LOGIC_H