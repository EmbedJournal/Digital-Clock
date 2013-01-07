#include <p18f4520.h>
#include "lcd.h"
#include "clock.h"
#include "rtc.h"

unsigned int units,tens;        // Global var.

void display(void)
{
    time(get_time(2),get_time(1),get_time(0));
    date(get_time(4),get_time(5),get_time(6));
    day(get_time(3));
    return;
}

void time(unsigned int hours,unsigned int minutes,unsigned int seconds)
{
    decode(hours);      // sepatates the variable into highr and lower nibble
    if(tens>3)      // To set AM or PM
    {
        if((tens == 6)|(tens == 7))
        {
            LCD_cmd(0xCF);
            LCD_data('P');
            LCD_data('M');
            tens=tens&1;
        }
        else if((tens == 4)|(tens == 5))
        {
            LCD_cmd(0xCF);
            LCD_data('A');
            LCD_data('M');
            tens=tens&1;
        }
    }
    else
    {
        LCD_cmd(0xCF);
        LCD_data(' ');
        LCD_data(' ');
    }
    LCD_cmd(0xC6);
    LCD_data(tens+48);      // Add 48 to display ASCII value of number
    LCD_data(units+48);

    LCD_cmd(0xC9);
    decode(minutes);        // sepatates the variable into highr and lower nibble
    LCD_data(tens+48);
    LCD_data(units+48);

    LCD_cmd(0xCC);
    decode(seconds);        // sepatates the variable into highr and lower nibble
    LCD_data(tens+48);
    LCD_data(units+48);

}

void date(unsigned int date, unsigned int month,unsigned int year)
{
    LCD_cmd(0x9A);
    decode(date);       // sepatates the variable into highr and lower nibble
    LCD_data(tens+48);
    LCD_data(units+48);

    LCD_cmd(0x9D);
    decode(month);      // sepatates the variable into highr and lower nibble
    LCD_data(tens+48);
    LCD_data(units+48);

    LCD_cmd(0xA2);
    decode(year);       // sepatates the variable into highr and lower nibble
    LCD_data(tens+48);
    LCD_data(units+48);
}

void day(unsigned int disp)
{
    LCD_cmd(0xD9);
    LCD_data('                ');   // to clear past memory
    LCD_cmd(0xDA);
    switch(disp)
    {
	case 1:LCD_string("Sunday");
               break;
	case 2:LCD_string("Monday");
               break;
	case 3:LCD_string("Tuesday");
               break;
	case 4:LCD_string("Wednesday");
               break;
	case 5:LCD_string("Thursday");
               break;
	case 6:LCD_string("Friday");
               break;
	case 7:LCD_string("Saturday");
               break;
    }
}

void decode(unsigned int val)       // Function sepatates the variable into highr and lower nibble
{
    tens=val>>4;
    units=val&0x0F;
    return;
}