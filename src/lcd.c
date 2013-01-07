#include<p18f4520.h>
#include<delays.h>
#include"lcd.h"

#define HIGH 1
#define LOW 0
#define RS PORTCbits.RC0
#define RW PORTCbits.RC1
#define EN PORTCbits.RC2
#define BF PORTDbits.RD7

void LCD_init(void){
	TRISD=0x00;
	TRISC=0x00;
	LCD_cmd(0x38);	// 2 Line 5x7 display
	LCD_cmd(0x01);  // clear display
	LCD_cmd(0x06);	// Entry mode
	LCD_cmd(0x0F);	// Display on Cursor blinking
	return;
}	

void LCD_data(unsigned char data)
{
	LCD_isbusy();
	RS = HIGH;
	RW = LOW;
	EN = HIGH;
	LATD = data;
	Delay1KTCYx(50);
	EN = LOW;	
	return;
}
	
void LCD_cmd(unsigned char cmd)
{
	LCD_isbusy();
	RS = LOW;
	RW = LOW;
	EN = HIGH;
	LATD = cmd;
	Delay1KTCYx(50);
	EN = LOW;
	return;	
}

void LCD_string(const rom char *buffer)
{
        while(*buffer)                  // Write data to LCD up to null
        {
                LCD_isbusy();      // Wait while LCD is busy
                LCD_data(*buffer); // Write character to LCD
                buffer++;               // Increment buffer
        }
        return;
}

void LCD_isbusy(void){
	TRISDbits.TRISD7=1;
	RS = LOW;
	RW = HIGH;
	EN = HIGH;
	Delay1KTCYx(50);
	while(BF);
	TRISDbits.TRISD7=0;
	EN = LOW;
	return;
}