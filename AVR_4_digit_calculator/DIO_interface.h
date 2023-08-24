
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}et_PORTS;

typedef enum{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
}et_PINS;

typedef enum{
	Input,
	Output
}et_Direction;

typedef enum{
	PinLow,
	PinHigh
}et_Status;

/* setting pin direction*/
void DIO_VidSetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin ,u8 Copy_u8Direction);

/* setting pin value*/
void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);

/* getting pin value*/
void DIO_VidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *pu8Data);

/* setting port direction*/
void DIO_VidSetPortDirection(u8 Copy_u8Port ,u8 Copy_u8Direction);

/* setting port value*/
void DIO_VidSetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value);

///* setting port getting*/
void DIO_VidGetPortValue(u8 Copy_u8Port ,u8 *pu8Data);

#endif
