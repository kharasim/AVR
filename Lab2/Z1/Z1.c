//Poni¿ej podaj swoje dane
//<Dominik Boczkowski>
//<094207>
//<Grupa studencka: 1>
//<Grupa laboratoryjna: 1>
//Cw2Z1
///////////////////////

#define F_CPU 4000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main (void) 
{
    cli(); //wylaczenie przerwan
    DDRA = DDRA | 0b11110000;
	PORTA = PORTA^0b00001111;       //Ustawienie poczatkowe
    //DDRB | = 0b0000000;             //
    DDRC = DDRC | 0b11111111;       //

//--------- Konfiguracja wejscia INT0 ---------//
    DDRD = DDRD & ~ (1<<PD2);       //Wyzerowanie bitu na PIND2 -> wejscie
    PORTD |= (1<<PD2);              //rezystor pull-up na PIND2

    MCUCR |= (1<<ISC01)|(1<<ISC00); //INT0 - zbocze narastajace
    GICR |= (1<<INT0);              //wylaczenie przerwania z INT0
    sei();                          //globalne zezwolenie na przerwania
    while (1)
    {
        _delay_ms(20);
        PORTC = PORTC ^ 0b11111111;
    }
}

ISR(INT0_vect)
{
    PORTA = PORTA^0b11111111; //
    // PORTD ^= 0b10000000
}
