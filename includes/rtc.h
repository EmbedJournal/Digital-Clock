#ifndef RTC_H
#define RTC_H

#define RTC_ADR 0b11010000
#define I2C_READ 1
#define I2C_WRITE 0

void reset_time();
void disp_frame();
unsigned int get_time(unsigned int address);
void set_time(unsigned int address, unsigned int x);

#endif