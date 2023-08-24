#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Key_Pad_interface.h"
#include "Key_Pad_config.h"

void KPD_VoidInit(void){
	    DIO_VidSetPinDirection(PORT_D,Pin0,Output);
		DIO_VidSetPinDirection(PORT_D,Pin1,Output);
		DIO_VidSetPinDirection(PORT_D,Pin2,Output);
		DIO_VidSetPinDirection(PORT_D,Pin3,Output);
		DIO_VidSetPinDirection(PORT_D,Pin4,Input);
		DIO_VidSetPinDirection(PORT_D,Pin5,Input);
		DIO_VidSetPinDirection(PORT_D,Pin6,Input);
		DIO_VidSetPinDirection(PORT_D,Pin7,Input);

		DIO_VidSetPortValue(PORT_D,0xFF);



}
u8 KPD_u8GetPressedKey(void){

	u8 local_u8_Pressed_Key=KPD_NO_PRESSED_KEY;

	//counters for (for loop)
	u8 local_u8_colunmn_counter,local_u8_row_counter;

	u8 local_u8_Pin_State;

	static u8 local_u8_kpd_Arr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;

	static u8 local_u8_Column_Arr[COLUMN_NUM]={KPD_COLUMN_0,KPD_COLUMN_1,KPD_COLUMN_2,KPD_COLUMN_3};

	static u8 local_u8_Row_Arr[ROW_NUM]={KPD_ROW_0,KPD_ROW_1,KPD_ROW_2,KPD_ROW_3};

	for(local_u8_colunmn_counter=0;local_u8_colunmn_counter<COLUMN_NUM;local_u8_colunmn_counter++){


		DIO_VidSetPinValue(KPD_PORT,local_u8_Column_Arr[local_u8_colunmn_counter],PinLow);


		for(local_u8_row_counter=0;local_u8_row_counter<ROW_NUM;local_u8_row_counter++){

			DIO_VidGetPinValue(KPD_PORT,local_u8_Row_Arr[local_u8_row_counter],&local_u8_Pin_State);

			if(local_u8_Pin_State==PinLow){

				local_u8_Pressed_Key=local_u8_kpd_Arr[local_u8_row_counter][local_u8_colunmn_counter];

				while(local_u8_Pin_State==PinLow){

					DIO_VidGetPinValue(KPD_PORT,local_u8_Row_Arr[local_u8_row_counter],&local_u8_Pin_State);
				}
				return local_u8_Pressed_Key;
			}
		}

		DIO_VidSetPinValue(KPD_PORT,local_u8_Column_Arr[local_u8_colunmn_counter],PinHigh);

	}
	return local_u8_Pressed_Key;
}
