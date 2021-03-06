<<<<<<< HEAD
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{

DDRA |= 1 << PINA0; 
PORTA ^= 1 << PINA0;
DDRA |= 1 << PINA1; 
PORTA ^= 1 << PINA1;
DDRA |= 1 << PINA2; 
PORTA ^= 1 << PINA2;
DDRA |= 1 << PINA3; 
PORTA ^= 1 << PINA3;
DDRA |= 0 << PINA4; 
PORTA ^= 0 << PINA4;
DDRA |= 0 << PINA5; 
PORTA ^= 0 << PINA5;
DDRA |= 0 << PINA6; 
PORTA ^= 0 << PINA6;
DDRA |= 0 << PINA7; 
PORTA ^= 0 << PINA7;

DDRC |= 1 << PINA0; 
PORTC ^= 1 << PINA0;
DDRC |= 1 << PINA1; 
PORTC ^= 1 << PINA1;
DDRC |= 1 << PINA2; 
PORTC ^= 1 << PINA2;
DDRC |= 1 << PINA3; 
PORTC ^= 1 << PINA3;
DDRC |= 1 << PINA4; 
PORTC ^= 1 << PINA4;
DDRC |= 1 << PINA5; 
PORTC ^= 1 << PINA5;
DDRC |= 1 << PINA6; 
PORTC ^= 1 << PINA6;
DDRC |= 1 << PINA7; 
PORTC ^= 1 << PINA7;
					
DDRD &= ~(1 << PIND1); //Data Direction Register input PINB1
PORTD |= 1 << PIND1; //Set PINB1 to a high reading

	while (1)
		{
			PORTC |=(0b11111111);
			_delay_ms(20);
		}
}

ISR(INT0_vect)
{
PORTD |= 1 << PIND1;
}