#include <p18f4520.h>
#include "lcd.h"
#include "rtc.h"
#include "clock.h"
#pragma config OSC=HS, FCMEN=ON, WDT=OFF, IESO=OFF, XINST=OFF, LVP=OFF 

void main()
{
    SSPADD=49;  //set i2c clock
    SSPCON1=0b00101000; //set i2c master
    SSPSTATbits.SMP=1;  //select mode...standard selected
    ADCON1 = 0x0F;
    LCD_init();
    LCD_cmd(0x0C);
    disp_frame();

//    ROUTINE TO SET TIME.
//    Uncomment The following lines to set time to the RTC
//    reset_time();     // reset the time-keeping register to avoid collusion
//    set_time(0x00,0x30);      // seconds
//    set_time(0x01,0x11);      // Miniutes
//    set_time(0x02,0x48);      // Hours along with 12hour and AM/PM selection bit.
//    set_time(0x03,0x07);      // Day
//    set_time(0x04,0x28);      // Date
//    set_time(0x05,0x07);      // Month
//    set_time(0x06,0x12);      // Year
// ********************************

    while(1)
    {
        display();      // Repeatedly call the display function
    }
}

