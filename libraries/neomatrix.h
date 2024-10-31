// neomatrix.c
// Declarations for neomatrix functions

#ifndef NEOMATRIX_H_
#define NEOMATRIX_H_

/************************************Includes***************************************/

#include <stdio.h>
#include "generated/neopixel.pio.h"
#include "pico/stdlib.h"

/************************************Includes***************************************/

/*************************************Defines***************************************/

#define WS2812_PIN              7
#define NEOMATRIX_ENABLE        10

#define NEOMATRIX_WIDTH         8
#define NEOMATRIX_HEIGHT        8
#define NEOMATRIX_SIZE          NEOMATRIX_WIDTH * NEOMATRIX_HEIGHT

#define NEOPIXEL_GREEN          0xFF0000
#define NEOPIXEL_RED            0x00FF00
#define NEOPIXEL_BLUE           0x0000FF

#define NEOPIXEL_CHILL_GREEN    0x220000
#define NEOPIXEL_CHILL_RED      0x002200
#define NEOPIXEL_CHILL_BLUE     0x000022

/*************************************Defines***************************************/

/******************************Data Type Definitions********************************/
/******************************Data Type Definitions********************************/

/****************************Data Structure Definitions*****************************/
/****************************Data Structure Definitions*****************************/

/***********************************Externs*****************************************/
/***********************************Externs*****************************************/

/********************************Public Functions***********************************/

bool neomatrix_init(void);
void neomatrix_set_pixel(uint8_t row, uint8_t col, uint32_t color);
void neomatrix_clear_pixels(void);
void neomatrix_write(void);

/********************************Public Functions***********************************/

/*******************************Private Variables***********************************/
/*******************************Private Variables***********************************/

/*******************************Private Functions***********************************/
/*******************************Private Functions***********************************/

#endif /* NEOMATRIX_H_ */