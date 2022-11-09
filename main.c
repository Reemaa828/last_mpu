/*
 * main.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Administrator
 */
#ifndef F_CPU
#define F_CPU 8000000UL /* Define CPU clock Frequency 8MHz */
#endif
#include <avr/io.h>     /* Include AVR std. library file */
#include <util/delay.h> /* Include delay header file */
#include "STD_Types.h"  /* Include STD_Types  header file */
#include <stdio.h>      /* Include standard I/O library file */
#include "mpu.h"        /* Include MPU6050 register define file */
#include "DIO.h"        /* Include DIO header file */
#include "I2C.h"
#include "LCD.h"
#include <stdio.h>

int main(void) {
    /* Initialize UART */
    LCD_vInit();

    /* Initialize project configuration */
    tw_init(TW_FREQ_400K, true);  // set I2C Frequency, enable internal pull-up

    mpu_init();
    mpu_data_t accel;
    mpu_data_t gyro;
    while (1) {
        mpu_get_accel(&accel);
        mpu_get_gyro(&gyro);
        lcd_set_cursor(0, 0);
        lcd_printf("AX: %d\n", (u32)accel.x);
        lcd_set_cursor(0, 1);
        lcd_printf("AY: %d\n", (u32)accel.y);
        lcd_set_cursor(8, 1);
        lcd_printf("AZ: %d\n", (u32)accel.z);
        /*
        lcd_set_cursor(0, 0);
        lcd_printf("GX: %d\n", (u32)gyro.x);
        lcd_set_cursor(0, 1);
        lcd_printf("GY: %d\n", (u32)gyro.y);
        lcd_set_cursor(8, 1);
        lcd_printf("GZ: %d\n", (u32)gyro.z);
        //*/
        _delay_ms(200);
    }
}
