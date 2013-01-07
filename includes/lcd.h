#ifndef LCD_H
#define LCD_H

#define LCD_LINE1 0x80
#define LCD_LINE2 0xC0
#define LCD_LINE3 0x94
#define LCD_LINE4 0xD4

void LCD_init(void);
void LCD_data(unsigned char data);
void LCD_cmd(unsigned char cmd);
void LCD_string(const rom char *ptr);
void LCD_isbusy(void);
#endif