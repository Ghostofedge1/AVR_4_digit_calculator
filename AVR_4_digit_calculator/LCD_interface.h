#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include "STD_TYPES.h"

#define LCD_ROW_1 1
#define LCD_ROW_2 2

typedef enum {
	LCD_COL_0,
	LCD_COL_1,
	LCD_COL_2,
	LCD_COL_3,
	LCD_COL_4,
	LCD_COL_5,
	LCD_COL_6,
	LCD_COL_7,
	LCD_COL_8,
	LCD_COL_9,
	LCD_COL_10,
	LCD_COL_11,
	LCD_COL_12,
	LCD_COL_13,
	LCD_COL_14,
	LCD_COL_15
}COL_NUM_t;


void LCD_VoidSendCommand(u8 Copy_u8Command);
void LCD_VoidSendData(u8 Copy_u8Data);
void LCD_VoidInit(void);
void LCD_VoidSendString(s8 * Copy_u8ptrString);
void LCD_VoidSendInteger(s32 Copy_s32Int);
void LCD_VoidSetPosition(u8 Copy_u8Row,u8 Copy_u8Col);
void LCD_VoidSendString4BitMode(s8 * Copy_u8ptrString);
void LCD_VoidSendData4BitMode(u8 Copy_u8Data);
void LCD_VoidSendCommand4BitMode(u8 Copy_u8Command);
void LCD_VoidInit4BitMode();
void LCD_VoidSendInteger4BitMode(u32 Copy_s32Int);
void LCD_VoidSetPosition4BitMode(u8 Copy_u8Row,u8 Copy_u8Col);
void LCD_VoidSendFloat4BitMode(f32 Copy_f32float,u8 Copy_u8NumberofDigits)
;
#endif
