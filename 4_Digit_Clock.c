#include <avr/io.h>
#include <util/delay.h>
uint8_t zero = 0xff; // No middle dash
uint8_t one = 0x14; // No Middle Dash
uint8_t two = 0x39;
uint8_t three = 0x3C;
uint8_t four =0x16;
uint8_t five =0x2E;
uint8_t six =0x2F;
uint8_t seven = 0x34;   // No Middle Dashes
uint8_t eight =0x3F;  
uint8_t nine = 0x36;
uint8_t  d1 =0x31;
uint8_t  d2  =0x32;
uint8_t  d3  =0x34;
uint8_t  d4 =0x38;
uint8_t  d1_moff =0x11;
uint8_t  d2_moff  =0x12;
uint8_t  d3_moff  =0x14;
uint8_t  d4_moff =0x18;
int ones_min = 0;
int tens_min = 3;
int ones_hr = 8;
int tens_hr = 1;

void digit1(int num){	// tens_hr
	switch(num){
		case 0:
			bitTran(d1_moff,zero);
			break;
		case 1:
			bitTran(d1_moff,one);
			break;
		case 2:
			bitTran(d1,two);
			break;
		case 3:
			bitTran(d1,three);
			break;
		case 4:
			bitTran(d1,four);
			break;
		case 5:
			bitTran(d1,five);
			break;
		case 6:
			bitTran(d1,six);
			break;
		case 7:
			bitTran(d1_moff,seven);
			break;
		case 8:
			bitTran(d1,eight);
			break;
		case 9:
			bitTran(d1,nine);
			break;
	}
}
void digit2(int num){	// one_hours
	switch(num){
		case 0:
			bitTran(d2_moff,zero);
			break;
		case 1:
			bitTran(d2_moff,one);
			break;
		case 2:
			bitTran(d2,two);
			break;
		case 3:
			bitTran(d2,three);
			break;
		case 4:
			bitTran(d2,four);
			break;
		case 5:
			bitTran(d2,five);
			break;
		case 6:
			bitTran(d2,six);
			break;
		case 7:
			bitTran(d2_moff,seven);
			break;
		case 8:
			bitTran(d2,eight);
			break;
		case 9:
			bitTran(d2,nine);
			break;
	}
}
void digit3(int num){	// one_hours
	switch(num){
		case 0:
			bitTran(d3_moff,zero);
			break;
		case 1:
			bitTran(d3_moff,one);
			break;
		case 2:
			bitTran(d3,two);
			break;
		case 3:
			bitTran(d3,three);
			break;
		case 4:
			bitTran(d3,four);
			break;
		case 5:
			bitTran(d3,five);
			break;
		case 6:
			bitTran(d3,six);
			break;
		case 7:
			bitTran(d3_moff,seven);
			break;
		case 8:
			bitTran(d3,eight);
			break;
		case 9:
			bitTran(d3,nine);
			break;
	}
}
void digit4(int num){	// ones of minutes
	switch(num){
		case 0:
			bitTran(d4_moff,zero);
			break;
		case 1:
			bitTran(d4_moff,one);
			break;
		case 2:
			bitTran(d4,two);
			break;
		case 3:
			bitTran(d4,three);
			break;
		case 4:
			bitTran(d4,four);
			break;
		case 5:
			bitTran(d4,five);
			break;
		case 6:
			bitTran(d4,six);
			break;
		case 7:
			bitTran(d4_moff,seven);
			break;
		case 8:
			bitTran(d4,eight);
			break;
		case 9:
			bitTran(d4,nine);
			break;
	}
}
void display(){//int tens_hr, int ones_hr, int tens_min, int ones_min){
	digit1(tens_hr);
	_delay_ms(23);
	digit2(ones_hr);
	_delay_ms(23);
	digit3(tens_min);
	_delay_ms(23);
	digit4(ones_min);
	_delay_ms(23);
}
void timerecorder(){
	RTC.CNT = 0x0000;
	while(RTC.CNT < 0x003B){
		display();
	}
	ones_min = ones_min + 1;
	if(ones_min == 10){
		ones_min = 0;
		tens_min = tens_min + 1;
	}
	if(tens_min == 6){
		tens_min = 0;
		ones_hr = ones_hr + 1;
	}
	if (ones_hr == 10){
		ones_hr = 0;
		tens_hr = tens_hr + 1;
	}
	if(tens_hr == 2 && ones_hr == 4){
		tens_hr = 0;
		ones_hr = 0;
		tens_min = 0;
		ones_min = 0;
	}
}
int main(void)
{
	RTC.CTRLA = RTC_PRESCALER_DIV32768_gc | RTC_RTCEN_bm;
	PORTA.DIR = 0xFF;
	PORTA.OUT = 0xFF;
	SPI0.CTRLA = SPI_DORD_bm|SPI_MASTER_bm|SPI_PRESC_DIV128_gc|SPI_ENABLE_bm;
	SPI0.CTRLB = SPI_BUFEN_bm|SPI_BUFWR_bm|SPI_SSD_bm|SPI_MODE_1_gc;
	SPI0.INTCTRL = 0x40;	//	
	while(1){
		// bitTran(0x31, 0xFE);
		// _delay_ms(22);
		// SPI0.INTFLAGS = SPI_TXCIF_bm | SPI_DREIE_bm;
		timerecorder();
	}
}
void bitTran(uint8_t transelect, uint8_t digitselect){
	SPI0_INTFLAGS = 0x40;
	SPI0.DATA = transelect;
	while((SPI0.INTFLAGS & 0x40) == 0x40) { }
	SPI0_INTFLAGS = 0x40;
	SPI0.DATA = digitselect;
	while((SPI0.INTFLAGS & 0x40) == 0x40) { }
	SPI0_INTFLAGS = 0x40;
}