/*
 * main.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Administrator
 */
#define F_CPU 8000000UL		/* Define CPU clock Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */
#include "STD_Types.h"		/* Include STD_Types  header file */
#include <stdio.h>		/* Include standard I/O library file */
#include "mpu.h" /* Include MPU6050 register define file */
#include "DIO.h"	/* Include DIO header file */
#include "I2C.h"
#include "LCD.h"
#include <stdio.h>

int main(void) {
/* Initialize UART */
   LCD_vInit();

    /* Initialize project configuration */
    tw_init(TW_FREQ_400K, true); // set I2C Frequency, enable internal pull-up
    // lcd_print("hmmm");
    
    mpu_init();
    // lcd_print("el i2c 3ady");
    mpu_data_t accel;

    while (1) {
        mpu_get_accel(&accel);
        lcd_set_cursor(0,0);
        lcd_printf("X: %d\n", (u32)accel.x);
        lcd_set_cursor(0,1);
         lcd_printf("Y: %d\n", (u32)accel.y);
         lcd_set_cursor(8,1);
         lcd_printf("Z: %d\n", (u32)accel.z);

        _delay_ms(200);
    }
}


