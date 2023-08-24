#include "STD_TYPES.h"
#include "BIT_MATh.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Key_Pad_interface.h"
#include <util/delay.h>

u32 arrttointeger(u32 arr[],u32 numberofdigits);


int main(){
	KPD_VoidInit();
	LCD_VoidInit4BitMode();
	LCD_VoidSendString4BitMode("Welcome to AVR  4-digit Calc");
	_delay_ms(2000);
	LCD_VoidSendCommand4BitMode(0x01);
	LCD_VoidSetPosition4BitMode(1,0);

    u32 in1,op=0;

    u32 arr1[4],arr2[4];
    u32 num1=0,num2=0;
    u32 iterator1=0,iterator2=0;
	while(1){
		in1=KPD_u8GetPressedKey();

		if(in1!=0xff && in1=='='&& op>0 && iterator1>0 && iterator2>0){
				LCD_VoidSendData4BitMode(in1);
				num1=arrttointeger(arr1,iterator1);
				num2=arrttointeger(arr2,iterator2);
				LCD_VoidSendCommand4BitMode(0x01);
				LCD_VoidSetPosition4BitMode(1,0);
				LCD_VoidSendString4BitMode("Result=");
				LCD_VoidSetPosition4BitMode(2,0);
				u32 res;
				f32 f;

				switch(op){
				case '+' :
					res=num1+num2;
					if(res==0){
						LCD_VoidSendData4BitMode('0');
					}
					else{
					LCD_VoidSendInteger4BitMode(num1+num2);
					}
					break;
				case '-' :
				res=num1-num2;
				if(res==0){
					LCD_VoidSendData4BitMode('0');
				}
				else{
				LCD_VoidSendInteger4BitMode(num1-num2);
				}
				break;
				case '*' :
					res=num1*num2;
				if(res==0){
					LCD_VoidSendData4BitMode('0');
				}
				else{
				LCD_VoidSendInteger4BitMode(num1*num2);
				}
				break;
				case '/' :
					 f=(float)num1/num2;

					if(f==0){
						LCD_VoidSendData4BitMode('0');
					}

					else if(f<1 && f>0){
						LCD_VoidSendData4BitMode('0');
						LCD_VoidSendFloat4BitMode((float)num1/num2,4);
					}
					else{

					LCD_VoidSendFloat4BitMode((float)num1/num2,4);

					}
					break;
				case '%' :
					res=num1%num2;
				if(res==0){
					LCD_VoidSendData4BitMode('0');
				}
				else{
				LCD_VoidSendInteger4BitMode(num1%num2);
				}
				break;
				}

				_delay_ms(2000);
				iterator1=0;
				iterator2=0;
				op=0;
				LCD_VoidSendCommand4BitMode(0x01);
				LCD_VoidSetPosition4BitMode(1,0);

			}

		else if((in1!=0xff) && ( iterator1>0) && (op==0)
    	&&(in1=='+' ||in1=='-' ||in1=='*' ||in1=='/' ||in1=='%' )){

		 op=in1;
		 LCD_VoidSendData4BitMode(op);

    }
		else if(in1!=0xff && op==0 &&iterator1<4){

			arr1[iterator1++]=in1;
			if(arr1[iterator1-1]==0){
				LCD_VoidSendData4BitMode('0');
			}
			else if(arr1[iterator1-1]>0){
				LCD_VoidSendInteger4BitMode(arr1[iterator1-1]);
			}

		}
		else	if(in1!=0xff && op>0 &&iterator2<4){
					arr2[iterator2++]=in1;
					if(arr2[iterator2-1]==0){
						LCD_VoidSendData4BitMode('0');
					}
					else if(arr2[iterator2-1]>0){
						LCD_VoidSendInteger4BitMode(arr2[iterator2-1]);
					}

				}


    }

	}




u32 arrttointeger(u32 arr[],u32 numberofdigits){
int snum=0;
 for(int i=0;i<numberofdigits-1;i++){
   for(int j=0;j<numberofdigits-i-1;j++){
    arr[i]*=10;
   }
 }
 for(int i=0;i<numberofdigits;i++){
    snum+=arr[i];
 }
 return snum;
}
