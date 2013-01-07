#include <p18f4520.h>
#include "i2c.h"
#include "lcd.h"

void disp_frame()   // To display the basic frame that does not change.
{
    LCD_cmd(LCD_LINE1);
    LCD_string("    Digital Clock   ");

    LCD_cmd(LCD_LINE2);
    LCD_string("Time: ");
    LCD_cmd(0xC8);
    LCD_data(':');
    LCD_cmd(0xCB);
    LCD_data(':');

    LCD_cmd(LCD_LINE3);
    LCD_string("Date: ");
    LCD_cmd(0x9C);
    LCD_data('/');
    LCD_cmd(0x9F);
    LCD_data('/');
    LCD_data('2');
    LCD_data('0');

    LCD_cmd(LCD_LINE4);
    LCD_string("Day : ");
}

void reset_time()       // resets the time-keeping register
{

    i2c_start();
    i2c_write(0b11010000);
    i2c_write(0x00);    // sec
    i2c_write(0x00);    // min
    i2c_write(0x00);    // hrs
    i2c_write(0x01);    // day
    i2c_write(0x01);    // date
    i2c_write(0x01);    // month
    i2c_write(0x01);    // year
    i2c_write(0x00);    // wave
//    i2c_write(0);
    i2c_stop();
    return;
}

unsigned int get_time(unsigned int address)     // Gets time
{
    unsigned int data;
    i2c_start();
    i2c_write(0b11010000);
    i2c_write(address);
    i2c_restart();
    i2c_write(0b11010001);
    SSPCON2bits.ACKDT=1;
    data=i2c_read();
    i2c_stop();
    return (data);
}

void set_time(unsigned int address, unsigned int x)     // sets time
{
    i2c_start();
    i2c_write(0b11010000);
    i2c_write(address);
    i2c_write(x);
    i2c_stop();
    return;
}

