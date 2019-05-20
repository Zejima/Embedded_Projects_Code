/*
 * MIDI_Assignment.c
 *
 * Created: 4/27/2019 5:31:54 PM
 * Author : Alan Chen, Chidinma Ejiofor
 */ 
#define FOSC 16000000UL // Clock Speed
#include <avr/io.h>
// #define FOSC 16000000 // Clock Speed
#define BAUD 31250
#define MYUBRR FOSC/16/BAUD-1
void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	DDRB = (1<<DDB0)|(1<<DDB2)|(1<<DDB3)|(1<<DDB5);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);
}
void SPI_MasterTransmit(uint8_t cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
}
void USART_Init(unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}
int main(void)
{
	//PRR &= ~(1<<PRSPI);
	//PORTB &= ~(1<<DDB0);
	USART_Init(MYUBRR);
	SPI_MasterInit();
	while(1){
		unsigned char decoy = USART_Receive();
		// if((decoy == 0x80) || (decoy == 0x90)){
		unsigned char Real = USART_Receive();
		SPI_MasterTransmit(Real);
		unsigned char decoy1 = USART_Receive();
		}
}