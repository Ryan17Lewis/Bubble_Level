// neomatrix.c
// Defines for neopixel functions

/************************************Includes***************************************/

#include "neomatrix.h"

/************************************Includes***************************************/

/********************************Public Variables***********************************/

uint32_t pixels[NEOMATRIX_SIZE];

/********************************Public Variables***********************************/

/********************************Public Functions***********************************/

bool neomatrix_init(void) {
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &neomatrix_program);

    // enable power to the connected NeoPixels
    gpio_init(NEOMATRIX_ENABLE);
    gpio_set_dir(NEOMATRIX_ENABLE, GPIO_OUT);
    gpio_put(NEOMATRIX_ENABLE, true);

    neomatrix_program_init(pio, sm, offset, WS2812_PIN, 800000, false);

    return true;

}

void neomatrix_set_pixel(uint8_t row, uint8_t col, uint32_t color) {
    uint8_t index = row + col * NEOMATRIX_WIDTH;
    pixels[index] = color;
}

void neomatrix_clear_pixels(void) {
    for (int i = 0; i < NEOMATRIX_SIZE; i++) {
        pixels[i] = 0;
    }
}

void neomatrix_write(void) {
    for (int i = 0; i < NEOMATRIX_SIZE; i++) {
        pio_sm_put_blocking(pio0, 0, pixels[i] << 8u);
    }
}

/********************************Public Functions***********************************/