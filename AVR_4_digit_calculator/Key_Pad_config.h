#ifndef KEY_PAD_CONFIG_H
#define KEY_PAD_CONFIG_H

#define KPD_PORT PORT_D

#define KPD_NO_PRESSED_KEY 0xff



#define KPD_COLUMN_0 Pin0
#define KPD_COLUMN_1 Pin1
#define KPD_COLUMN_2 Pin2
#define KPD_COLUMN_3 Pin3


#define KPD_ROW_0    Pin4
#define KPD_ROW_1    Pin5
#define KPD_ROW_2    Pin6
#define KPD_ROW_3    Pin7


#define ROW_NUM    4
#define COLUMN_NUM 4

#define KPD_ARR_VAL { {1,2,3,'/'} ,\
                      {4,5,6,'*'} ,\
					  {7,8,9,'+'} ,\
					  {0,'-','%','='} }

#endif
