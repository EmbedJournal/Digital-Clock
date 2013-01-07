#ifndef I2C_H
#define I2C_H

void i2c_start(void);
void i2c_restart(void);
void i2c_device(void);
unsigned int i2c_read(void);
void i2c_write(unsigned int data);
void i2c_stop(void);

#endif