// LIS3DH.c
// Defines for LIS3DH functions

/************************************Includes***************************************/

#include "LIS3DH.h"

/************************************Includes***************************************/

/********************************Public Variables***********************************/

accel_data_t accel;;

/********************************Public Variables***********************************/

/********************************Public Functions***********************************/

bool LIS3DH_init(void) {
    // Turn normal mode and 1.344kHz data rate on
    LIS3DH_set_reg(CTRL_REG_1, 0x97);

    if (LIS3DH_read_reg(CTRL_REG_1) == 0x97) {
        return true;
    }
    return false;
}

void LIS3DH_set_reg(uint8_t reg, uint8_t val) {
    uint8_t buf[2];
    buf[0] = reg;
    buf[1] = val;
    i2c_write_blocking(i2c_default, LIS3DH_ADDR, buf, 2, false);
}

uint8_t LIS3DH_read_reg(uint8_t reg) {
    uint8_t data = 0;
    i2c_write_blocking(i2c_default, LIS3DH_ADDR, &reg, 1, true);
    i2c_read_blocking(i2c_default, LIS3DH_ADDR, &data, 1, false);

    return data;
}

void LIS3DH_update(accel_data_t* accel) {
    uint16_t raw_x, raw_y, raw_z;

    // read acccel x, y, z
    raw_x = (LIS3DH_read_reg(ACCEL_XH) << 8) | LIS3DH_read_reg(ACCEL_XL);
    raw_y = (LIS3DH_read_reg(ACCEL_YH) << 8) | LIS3DH_read_reg(ACCEL_YL);
    raw_z = (LIS3DH_read_reg(ACCEL_ZH) << 8) | LIS3DH_read_reg(ACCEL_ZL);

    // convert acceleration values and update struct
    accel->x = (float) ((int16_t) raw_x * SCALING);
    accel->y = (float) ((int16_t) raw_y * SCALING);
    accel->z = (float) ((int16_t) raw_z * SCALING);

}

/********************************Public Functions***********************************/