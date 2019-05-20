// the AVR input/output header file
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#define F_CPU 16000000
// 16MHz, the frequency of our main clock
//RTC.CNT = 0x0000;
void delay(int ms){ // input as ms
	PORTB.OUT = 0x10; // initialize the led as off
	RTC.CNT = 0x0000; // reset count = 0
	if(ms == 3250){	// this means that the input is a space character
		while(RTC.CNT != 0xBB80){	// delay for 3sec which is 48000ticks (the other .5 sec is at the end of the method)
			PORTB.OUT = 0x10; // initialize the led as off
		}
	}
	if(ms == 500){
		while(RTC.CNT != 0x1F40){	// delays for 500ms (8000 ticks)
			PORTB.OUT = 0x00;	//LED on
		}
	}
	if(ms == 1500){
		while(RTC.CNT != 0x5DC0){	// delays for 1500ms (24000 ticks)
			PORTB.OUT = 0x00;	//LED on
		}
	}
	RTC.CNT = 0x0000; // reset count = 0
	while(RTC.CNT != 0x1F40){	// delays for 500ms (8000 ticks) <---- this is for spaces in between characters
		PORTB.OUT = 0x10; // initialize the led as off
	}
}
void matching(char x){
	switch(x)
	{
		case 'W':
		{
			int arr[] = {500, 1500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//.--
			break;
		}
		case 'A':
		{
			int arr[] = {500, 1500};
			//.-
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			break;
		}
		case 'S':
		{
			int arr[] = {500, 500, 500};
			//...
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			break;
		}
		case 'H':
		{
			int arr[] = {500, 500, 500, 500};
			//....
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			break;
		}

		case 'I':
		{
			int arr[] = {500, 500};
			int len = sizeof(arr) / sizeof(arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//..
			break;
		}
		case 'N':
		{
			int arr[] = {1500, 500};
			int len = sizeof(arr) / sizeof(arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//-.
			break;
		}
		case 'G':
		{
			int arr[] = { 1500, 1500, 500 };
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//--.
			break;
		}
		case 'T':
		{
			int arr[] = { 1500 };
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//-
			break;
		}
		case 'O':
		{
			int arr[] = { 1500, 1500, 1500 };
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//---
			break;
		}
		case '-':
		{
			int arr[] = {1500, 500, 500, 500, 500, 1500};
			//-....-
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			break;
		}
		case 'J':
		{
			int arr[] = {500, 1500, 1500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//.---
			break;
		}
		case 'L':
		{
			int arr[] = { 500, 1500, 500, 500 };
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//.-..
			break;
		}
		case 'U':
		{
			int arr[] = {500, 500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//..-
			break;
		}
		case 'Y':
		{
			int arr[] = {1500, 500, 1500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			// -.--
			break;
		}
		case (','):
		{
			int arr[] = { 1500, 1500, 500, 500, 1500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//--..--
			break;
		}
		case '2':
		{
			int arr[] = {500, 500, 1500, 1500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//..---
			break;
		}
		case '1':
		{
			int arr[] = {500, 1500, 1500, 1500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//.----
			break;
		}
		case '8':
		{
			int arr[] = {1500, 1500, 1500, 500, 500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			//---..
			break;
		}
		case '6':
		{
			int arr[] = {1500, 500, 500, 500, 500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			// -....
			break;
		}
		case '.':
		{
			int arr[] = {500, 1500, 500, 1500, 500, 1500};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			break;
		}
		case ' ':
		{
			int arr[] = {3250};
			int len = sizeof (arr) / sizeof (arr[0]);
			for (int j = 0; j < len; j = j + 1){
				delay(arr[j]);
			}
			break;
		}
		default:
		printf ("Translated");
	}
}
int main(void){
	RTC.CTRLA = 0x09;	// set (/2) enable RTC
	PORTB.DIR = 0x10;
	while (1)
	{
		PORTB.OUT = 0x00;
		//0x10 turns off
		//0x00 turns on
		char *p2= "2.";
		for(int i = 0; i<strlen(p2); i++){
			matching(p2[i]);
		}
	}
	return 0;
}