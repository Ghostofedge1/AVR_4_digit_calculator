#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_PRIVATE.h"

//***************/* setting pin direction*/******************
void DIO_VidSetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin ,u8 Copy_u8Direction){
	if(Copy_u8Direction==Input){
		switch(Copy_u8Port){
		case PORT_A:CLR_BIT(DDRA,Copy_u8Pin);
		break;
		case PORT_B:CLR_BIT(DDRB,Copy_u8Pin);
		break;
		case PORT_C:CLR_BIT(DDRC,Copy_u8Pin);
		break;
		case PORT_D:CLR_BIT(DDRD,Copy_u8Pin);
		break;

		}
	}
	else if(Copy_u8Direction==Output){
		switch(Copy_u8Port){
				case PORT_A:SET_BIT(DDRA,Copy_u8Pin);
				break;
				case PORT_B:SET_BIT(DDRB,Copy_u8Pin);
				break;
				case PORT_C:SET_BIT(DDRC,Copy_u8Pin);
				break;
				case PORT_D:SET_BIT(DDRD,Copy_u8Pin);
				break;

				}
	}
}



//****************/* setting pin value*/****************
void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){
	if(Copy_u8Value==PinLow){
			switch(Copy_u8Port){
			case PORT_A:CLR_BIT(PORTA,Copy_u8Pin);
			break;
			case PORT_B:CLR_BIT(PORTB,Copy_u8Pin);
			break;
			case PORT_C:CLR_BIT(PORTC,Copy_u8Pin);
			break;
			case PORT_D:CLR_BIT(PORTD,Copy_u8Pin);
			break;

			}
		}
		else if(Copy_u8Value==PinHigh){
			switch(Copy_u8Port){
					case PORT_A:SET_BIT(PORTA,Copy_u8Pin);
					break;
					case PORT_B:SET_BIT(PORTB,Copy_u8Pin);
					break;
					case PORT_C:SET_BIT(PORTC,Copy_u8Pin);
					break;
					case PORT_D:SET_BIT(PORTD,Copy_u8Pin);
					break;

					}
		}


}

//************************/* getting pin value*/****************************
void DIO_VidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *pu8Data){

	switch(Copy_u8Port){
						case PORT_A:*pu8Data=GET_BIT(PINA,Copy_u8Pin);
						break;
						case PORT_B:*pu8Data=GET_BIT(PINB,Copy_u8Pin);
						break;
						case PORT_C:*pu8Data=GET_BIT(PINC,Copy_u8Pin);
						break;
						case PORT_D:*pu8Data=GET_BIT(PIND,Copy_u8Pin);
						break;

						}

}


//*************************/* setting port direction*/*******************
void DIO_VidSetPortDirection(u8 Copy_u8Port ,u8 Copy_u8Direction){
	if(Copy_u8Direction==Input){
		switch(Copy_u8Port){
							case PORT_A:DDRA=0x00;
							break;
							case PORT_B:DDRB=0x00;
							break;
							case PORT_C:DDRC=0x00;
							break;
							case PORT_D:DDRD=0x00;
							break;

							}
	}
	else if(Copy_u8Direction==Output){
		switch(Copy_u8Port){
								case PORT_A:DDRA=0xFF;
								break;
								case PORT_B:DDRB=0xFF;
								break;
								case PORT_C:DDRC=0xFF;
								break;
								case PORT_D:DDRD=0xFF;
								break;

								}
	}

}


//*********************/* setting port value*/*******************
void DIO_VidSetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value){

		switch(Copy_u8Port){
							case PORT_A:PORTA=Copy_u8Value;
							break;
							case PORT_B:PORTB=Copy_u8Value;
							break;
							case PORT_C:PORTC=Copy_u8Value;
							break;
							case PORT_D:PORTD=Copy_u8Value;
							break;

							}
	}


//************************/* getting port Value*/**********************
void DIO_VidGetPortValue(u8 Copy_u8Port ,u8 *pu8Data){

	switch(Copy_u8Port){
							case PORT_A:*pu8Data=PORTA;
							break;
							case PORT_B:*pu8Data=PORTA;
							break;
							case PORT_C:*pu8Data=PORTA;
							break;
							case PORT_D:*pu8Data=PORTA;
							break;

							}
}
