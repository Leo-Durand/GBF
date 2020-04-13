/*
 * TEST ATTINY84.c
 *
 * Created: 17/02/2020 22:06:36
 * Author : léo
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0xFF;																				//assignation I/O et declaration variables
	PORTA = 0x00;
	DDRB = 0x2;
	char i = 0;
	char f = 0;
    while (1) 
    {
		if((PORTB & (1<<PORTB0)) == 0){															//selection forme du signal
			while((PORTB & (1<<PORTB0)) != 0);
			if(i == 5){
				i = 0;
			}
			else{
				i++;
				}	
			}
		if((PORTB & (1<<PORTB1)) == 0){															//selection fréquence
			while((PORTB & (1<<PORTB1)) != 0);
			if(f == 4){
				f = 0;
			}
			else{
				f++;
			}
		switch(f){																				//choix fréquence
			case 0:																				//110 Hz
				PORTA &= ((~(1<< PORTA0))|(~(1<< PORTA1))); 
			break;
			case 1:																				//1100 Hz
				PORTA |= (1<<PORTA0);
				PORTA &= (~(1<<PORTA1));
			break;
			case 2:																				//11 kHz
				PORTA |= (1<<PORTA1);
				PORTA &= (~(1<<PORTA0));
			break;
			case 3:																				//110 KHz
				PORTA |= ((1<<PORTA0) | (1<<PORTA1));
			break;
		}
		}			
		switch(i){																				//choix forme du signal
			case 0:																				//signal carré
				PORTA &=((~(1<<PORTA2))|(~(1<<PORTA3))|(~(1<<PORTA4))|(~(1<<PORTA5))); 			//xx0000xx (etat des ports)
			break;
			case 1:																				//signal sinusoidal
				PORTA |= (1<<PORTA3);
				PORTA &= ((~(1<<PORTA2))|(~(1<<PORTA4))|(~(1<<PORTA5)));						//xx0010xx
			break;
			case 2:																				//signal triangulaire
				PORTA |= ((1<<PORTA3)|(1<<PORTA4));
				PORTA &= ((~(1<<PORTA2))|(~(1<<PORTA5))); 										//xx0110xx
			break;
			case 3:																				//signal rampe
				PORTA |= ((1<<PORTA3)|(1<<PORTA5));
				PORTA &= ((~(1<<PORTA2))|(~(1<<PORTA4)));										//xx1010xx
			break;
			case 4:																				//signal pulse
				PORTA |= (1<<PORTA5);
				PORTA &=((~(1<<PORTA2))|(~(1<<PORTA3))|(~(1<<PORTA4)));							//xx1000xx
			break;
		
		}
	}
	}

