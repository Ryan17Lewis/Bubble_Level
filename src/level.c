#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"

#include "../libraries/LIS3DH.h"
#include "../libraries/neomatrix.h"

// I2C defines
// This example will use I2C0 on GPIO8 (SDA) and GPIO9 (SCL) running at 400KHz.
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define I2C_PORT i2c0
#define I2C_SDA 2
#define I2C_SCL 3

#define LED_PIN 13

#define THRESH 0.1
#define MAX_VALUE 0.5

uint8_t get_neopixel_index(float value, uint8_t max_dim) {

    value = -value;

    if (value < -MAX_VALUE) {
        return 0;
    }
    else if (value > MAX_VALUE) {
        return max_dim-1;
    }
    else {
        return (uint8_t)((value + MAX_VALUE) * (max_dim-1) / (2*MAX_VALUE));
    }

}

int main()
{
    stdio_init_all();

    // I2C Initialization. Using it at 400Khz.
    i2c_init(I2C_PORT, 400*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    // For more examples of I2C use see https://github.com/raspberrypi/pico-examples/tree/master/i2c

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    bool toggle = true;

    accel_data_t accel;
    LIS3DH_init();
    neomatrix_init();
    while (true) {

        LIS3DH_update(&accel);

        // printf("Accel.x = %f\n", accel.x);
        // printf("Accel.y = %f\n", accel.y);
        // printf("Accel.z = %f\n", accel.z);

        neomatrix_clear_pixels();
        if (accel.x < THRESH && accel.x > -THRESH && accel.y < THRESH && accel.y >-THRESH) {
            neomatrix_set_pixel(3,3,NEOPIXEL_CHILL_GREEN);
            neomatrix_set_pixel(3,4,NEOPIXEL_CHILL_GREEN);
            neomatrix_set_pixel(4,3,NEOPIXEL_CHILL_GREEN);
            neomatrix_set_pixel(4,4,NEOPIXEL_CHILL_GREEN);
        }
        else {
            uint8_t x = get_neopixel_index(accel.x, NEOMATRIX_WIDTH);
            uint8_t y = get_neopixel_index(accel.y, NEOMATRIX_HEIGHT);
            neomatrix_set_pixel(x,y,NEOPIXEL_CHILL_RED);
        }

        neomatrix_write();

        sleep_ms(100);
        gpio_put(LED_PIN, toggle);
        toggle = !toggle;
    }
}
