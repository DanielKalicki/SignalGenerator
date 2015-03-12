#include <avr/io.h>
#include <avr/interrupt.h>
#include "i2cmaster.h"

#define DAC_ADDRESS  0xC0

int channel[4]={-1,-1,-1,-1};	//initialy all channels power down

unsigned char read_i2c(unsigned char address){
	unsigned char data=0;
	if (i2c_start(DAC_ADDRESS+I2C_WRITE))  {i2c_stop();	return 0;} 				// set device address and write mode
	i2c_write(address);						// write address = i_address
	i2c_rep_start(DAC_ADDRESS+I2C_READ);				// set device address and read mode
	data = i2c_readNak();								// read one byte form address 0
	i2c_stop();
	return data;
}
unsigned char initDAC(){
	/*
	Vref=Vdd
	*/
	
	/*if(i2c_start(DAC_ADDRESS+I2C_WRITE)) {i2c_stop();	return 0;}
	//C2=1 C1=0 C0=0	This command writes Reference (VREF) selection bits of each channel.
	// 1 0 0 x | VrefA VrefB VrefC VrefD
	i2c_write(0x80);	//in this case all Vref=0 => it means that reference for every channel will be Vdd
	i2c_stop();
	*/
	i2c_start(DAC_ADDRESS+I2C_WRITE);
	//C2=1 C1=0 C0=0	This command writes Reference (VREF) selection bits of each channel.
	// 1 0 0 x | VrefA VrefB VrefC VrefD
	//i2c_write(0x80);
	i2c_write(0xDF);	//in this case all Vref=0 => it means that reference for every channel will be Vdd
	i2c_stop();
	
	return 1;
}
unsigned char writeToDAC(){
	
	if(i2c_start(DAC_ADDRESS+I2C_WRITE)) {i2c_stop();	return 0;}     // set device address and write mode
	
	/*
		Command types. First 2 bytes is for channel A, second 2 bytes for channel B, etc.
		First byte for channel:  (The Fast Write command is used to update the input DAC registers from channels A to D sequentially. The EEPROM data is not affected by this command. This command is called “Fast Write” because it updates the input registers with only limited data bits. Only the	Power-Down mode selection bits (PD1 and PD0) and 12 bits of DAC input data are writable)
				Fast Mode Write: 0 0 
				Next PD1 and PD0		Power down bytes  (0_0 -> normal mode, 0_1 -> 1k to ground, 1_0 -> 100k to ground, 1_1 -> 500k to ground)
				Next D11 D10 D9 D8
			next byte:
				D7 D6 D5 D4 D3 D2 D1 D0
				
	*/
	//channel A
	if(channel[0]>=0){
		i2c_write(0x07&((uint8_t)(channel[0]/256)));		//Normal mode and data from channel[0]
		i2c_write(channel[0]%256);
	}
	else {
		i2c_write(0x30);	//power down mode
		i2c_write(0x00);
	}

	//channel B
	if(channel[1]>=0){
		i2c_write(0x07&((uint8_t)(channel[1]/256)));		//Normal mode
		i2c_write(channel[1]%256);
	}
	else {
		i2c_write(0x30);	//power down mode
		i2c_write(0x00);
	}
	
	//channel C
	if(channel[2]>=0){
		i2c_write(0x07&((uint8_t)(channel[2]/256)));		//Normal mode
		i2c_write(channel[2]%256);
	}
	else {
		i2c_write(0x30);	//power down mode
		i2c_write(0x00);
	}
	
	//channel D
	if(channel[3]>=0){
		i2c_write(0x07&((uint8_t)(channel[3]/256)));		//Normal mode
		i2c_write(channel[3]%256);
	}
	else {
		i2c_write(0x30);	//power down mode
		i2c_write(0x00);
	}
	i2c_stop();

	return 1;				//success
}

int main(void)
{
	
	//initGPIO
	
	channel[0]=800;
	
	sei();
	i2c_init();
	if(i2c_start(DAC_ADDRESS+I2C_WRITE)) {i2c_stop();}
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}