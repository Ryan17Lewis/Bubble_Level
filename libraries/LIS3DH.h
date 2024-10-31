// LIS3DH.c
// Declarations for LIS3DH functions

#ifndef LIS3DH_H_
#define LIS3DH_H_

/************************************Includes***************************************/

#include <stdio.h>
#include "hardware/i2c.h"

/************************************Includes***************************************/

/*************************************Defines***************************************/

#define LIS3DH_ADDR       0x18

#define WHO_AM_I          0x0F
#define CTRL_REG_1        0x20
#define ACCEL_XL          0x28
#define ACCEL_XH          0x29
#define ACCEL_YL          0x2A
#define ACCEL_YH          0x2B
#define ACCEL_ZL          0x2C
#define ACCEL_ZH          0x2D

#define SENSITIVITY       0.001f 
#define SCALING           SENSITIVITY / 16

/*************************************Defines***************************************/

/******************************Data Type Definitions********************************/
/******************************Data Type Definitions********************************/

/****************************Data Structure Definitions*****************************/

typedef struct accel_data_t {
    float x, y, z;
} accel_data_t;

/****************************Data Structure Definitions*****************************/

/***********************************Externs*****************************************/
/***********************************Externs*****************************************/

/********************************Public Variables***********************************/
/********************************Public Variables***********************************/

/********************************Public Functions***********************************/

bool LIS3DH_init(void);
void LIS3DH_set_reg(uint8_t reg, uint8_t val);
uint8_t LIS3DH_read_reg(uint8_t reg);
void LIS3DH_update(accel_data_t* accel);

/********************************Public Functions***********************************/

/*******************************Private Variables***********************************/
/*******************************Private Variables***********************************/

/*******************************Private Functions***********************************/
/*******************************Private Functions***********************************/

#endif /* LIS3DH_H_ */