#include "LCD_interface.h"
#include "STD_TYPES.h"
#include "LCD_config.h"
#include "util/delay.h"
#include "DIO_interface.h"
#include <math.h>

#define send_upper(PORT,Data) (PORT=(PORT & 0xF0)|((Data >> 4) & 0x0F))
#define send_lower(PORT,Data) (PORT=(PORT & 0xF0)|(Data  & 0x0F))

void LCD_VoidSendCommand(u8 Copy_u8Command){

	// switching RS to the Command mode
	DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,PinLow);

	// switching RW to the Write mode
	DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,PinLow);

	// assigning  the command to the port
	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_u8Command);

	// initiating the enable pin so the LCD can receive the Command
	DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinHigh);
    _delay_ms(1);
    DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinLow);
    _delay_ms(1);
}


void LCD_VoidSendData(u8 Copy_u8Data){
        // switching RS to the Data mode
	    DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,PinHigh);

	    // switching RW to the Write mode
		DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,PinLow);

		// assigning  the Data to the port
		DIO_VidSetPortValue(LCD_DATA_PORT,Copy_u8Data);

		// initiating the enable pin so the LCD can receive the data
		DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinHigh);
	    _delay_ms(1);
	    DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinLow);
	    _delay_ms(1);

}

void LCD_VoidInit(void){

	DIO_VidSetPortDirection(LCD_DATA_PORT,Output);
	DIO_VidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,PinHigh);
	DIO_VidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,PinHigh);
	DIO_VidSetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,PinHigh);

	_delay_ms(40);

// Function set command : 2 lines , 5*8 font size
	LCD_VoidSendCommand(0b00111000);

	_delay_ms(1);

	// display on off control : display enable ,disable cursor ,no blink cursor
	LCD_VoidSendCommand(0b00001110);

	_delay_ms(1);

	//clear display
	LCD_VoidSendCommand(1);



}

/*  function to send string */
void LCD_VoidSendString(s8 * Copy_u8ptrString){

	u8 LCD_u8Iterator =0;

	while(Copy_u8ptrString[LCD_u8Iterator]!='\0'){
		LCD_VoidSendData(Copy_u8ptrString[LCD_u8Iterator]);
		LCD_u8Iterator++;
	}
}
/*  function to send Integers */
void LCD_VoidSendInteger(s32 Copy_s32Int){
	  s8 ASCi[16];
	  sprintf(ASCi, "%d", Copy_s32Int);
	  LCD_VoidSendString(ASCi);

}

/*  function to set the position */
void LCD_VoidSetPosition(u8 Copy_u8Row,u8 Copy_u8Col){

	if(Copy_u8Row==LCD_ROW_1){
		LCD_VoidSendCommand((0x80)+Copy_u8Col);
	}
	else if(Copy_u8Row==LCD_ROW_2){
		LCD_VoidSendCommand((0x80)+64+Copy_u8Col);
	}
}

void LCD_VoidInit4BitMode(){

	DIO_VidSetPinDirection(LCD_DATA_PORT,Pin0,Output);
	DIO_VidSetPinDirection(LCD_DATA_PORT,Pin1,Output);
	DIO_VidSetPinDirection(LCD_DATA_PORT,Pin2,Output);
	DIO_VidSetPinDirection(LCD_DATA_PORT,Pin3,Output);
		DIO_VidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,Output);
		DIO_VidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,Output);
		DIO_VidSetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,Output);


	_delay_ms(20);
	LCD_VoidSendCommand4BitMode(0x33);
	_delay_ms(1);
	LCD_VoidSendCommand4BitMode(0x32);// start the 4 bit mode
	_delay_ms(1);
	LCD_VoidSendCommand4BitMode(0x28);	// 4 BIT Mode 2 lines
	_delay_ms(1);
	LCD_VoidSendCommand4BitMode(0x0E);
	_delay_ms(1);
	LCD_VoidSendCommand4BitMode(0x06);
	LCD_VoidSendCommand4BitMode(0x01);	// clear display
	_delay_ms(40);

}



void LCD_VoidSendCommand4BitMode(u8 Copy_u8Command)
{
	DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,PinLow);
	DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,PinLow);
	u8 port_data;
	DIO_VidGetPortValue(LCD_DATA_PORT,&port_data);
	 send_upper(port_data,Copy_u8Command);
	 DIO_VidSetPortValue(LCD_DATA_PORT,port_data);

	 DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinHigh);
	     _delay_ms(1);
	     DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinLow);
	     _delay_ms(1);

	 _delay_ms(20);
	 DIO_VidGetPortValue(LCD_DATA_PORT,&port_data);
	 send_lower(port_data,Copy_u8Command);
	 DIO_VidSetPortValue(LCD_DATA_PORT,port_data);

	 DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinHigh);
	     _delay_ms(1);
	     DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinLow);
	     _delay_ms(1);

	_delay_ms(5);
}


 u8 ROW_Check=1,Cloumn_Check=0;


void LCD_VoidSendData4BitMode(u8 Copy_u8Data){
    	DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,PinHigh);
		DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,PinLow);

		u8 port_data;
		DIO_VidGetPortValue(LCD_DATA_PORT,&port_data);
		 send_upper(port_data,Copy_u8Data);
		 DIO_VidSetPortValue(LCD_DATA_PORT,port_data);

		 DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinHigh);
		     _delay_ms(1);
		     DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinLow);
		     _delay_ms(1);

		 _delay_ms(20);

		 DIO_VidGetPortValue(LCD_DATA_PORT,&port_data);
		 send_lower(port_data,Copy_u8Data);
		 DIO_VidSetPortValue(LCD_DATA_PORT,port_data);

		 DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinHigh);
		     _delay_ms(1);
		     DIO_VidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,PinLow);
		     _delay_ms(1);

		_delay_ms(5);
	Cloumn_Check++;
	if(Cloumn_Check==16 && ROW_Check==1){
		ROW_Check++;
		Cloumn_Check=Cloumn_Check%16;
			LCD_VoidSetPosition4BitMode(ROW_Check,Cloumn_Check);
		}

}

void LCD_VoidSendString4BitMode(s8 * Copy_u8ptrString){

	u8 LCD_u8Iterator =0;

	while(Copy_u8ptrString[LCD_u8Iterator]!='\0'){
		LCD_VoidSendData4BitMode(Copy_u8ptrString[LCD_u8Iterator]);
		LCD_u8Iterator++;


	}
}

int Inttostring(char str[], int num)
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return i;
}
void LCD_VoidSendInteger4BitMode(u32 Copy_s32Int){
	      s8 ASCi[16];
		 // sprintf(ASCi, "%d", Copy_s32Int);
	      Inttostring(ASCi,Copy_s32Int);
		  LCD_VoidSendString4BitMode(ASCi);
}

void Floattostring(char str[], float num,int afterpoint)
{
    char str_fpart[6];
  // Extract integer part
   int ipart = (int)num;

   // Extract floating part
   float fpart = num - (float)ipart;

   for(int j=0; j < afterpoint;j++){
      fpart*=10;
   }
   // convert integer part to string
    int i = Inttostring(str,ipart);

   // check for display option after point
   if (afterpoint != 0) {
       str[i] = '.'; // add dot
   }
   int f = Inttostring(str_fpart,fpart);

int z;
for( z=0 ; z<afterpoint ; z++){
    str[i+1+z]=str_fpart[z];
}
str[i+afterpoint+1]='\0';

}
void LCD_VoidSendFloat4BitMode(f32 Copy_f32float,u8 Copy_u8NumberofDigits){
	      s8 ASCi[16];
	      Floattostring(ASCi,Copy_f32float,Copy_u8NumberofDigits);
		  LCD_VoidSendString4BitMode(ASCi);
}

void LCD_VoidSetPosition4BitMode(u8 Copy_u8Row,u8 Copy_u8Col){

	if(Copy_u8Row==LCD_ROW_1){
		LCD_VoidSendCommand4BitMode((0x80)+Copy_u8Col);
	}
	else if(Copy_u8Row==LCD_ROW_2){
		LCD_VoidSendCommand4BitMode((0x80)+64+Copy_u8Col);

 }

}

