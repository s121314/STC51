/*
 * Copyright        : Shendong MCU studio
 * File Description : Globally Included head file.
 * Created          : oliverzhang@shendongmcu.com
 */

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdio.h>
#include <intrins.h>
#include <string.h>
#include "stc8axx.h"

#define CFG_SYSFREQ 22118400UL

typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned long uint32_t;
typedef signed long int32_t;

#define __disable_irq() do{EA = 0;}while(0)
#define __enable_irq() do{EA = 1;}while(0)

/*led.c*/
extern void led_Initialization(void);
extern void led_TurnOn(unsigned char on);
extern void led_Task(void);
extern void led_SetFlashMode(unsigned char mode);

/*uart1.c*/
extern void uart1_Initialization(void);
extern unsigned char uart1_Read(void *vbuf,unsigned char len);
extern void uart1_Write(const void *vbuf, unsigned char len);

/*console.c*/
extern void console_Task(void);

/*time.c*/
extern void time_Initialization(void);
extern unsigned long time_GetTicks(void);
extern void tick_Task(void);
extern void time_HoggingDelayMs(unsigned int ms);
extern void time_HoggingDelayUs(unsigned int us);

/*key.c*/
enum _key_code_e_{  KEY_ONBD,
	KEY_F1,KEY_F2,KEY_F3,KEY_F4,
	KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_0,
	KEY_ASTERISK,KEY_POUND,
	KEY_LEFT,KEY_RIGHT,KEY_UP,KEY_DOWN,
	
	KEY_SET,KEY_MENU,KEY_MUTE,KEY_TVAV,KEY_DIGIT,KEY_AUTO,KEY_OK,
	KEY_POWER,KEY_PLUS,KEY_MINUS,KEY_RETURN,KEY_CLEAR,KEY_CHANGEPIC,
	KEY_EXIT,KEY_PREVPAGE,KEY_NEXTPAGE,KEY_CHANNELLIST,
	KEY_PROGRAMGUIDE,KEY_PROGRAMINFO,KEY_INFOSERVICE,
	KEY_RED,KEY_GREEN,KEY_YELLOW,KEY_BLUE,
	
	KEY_UNKNOWN,KEY_NONE};
enum  _key_type_e_ {KEY_PRESSED,KEY_REPEATED,KEY_RELEASED};
extern void key_Initialization(void);
extern void key_Task(void);
extern unsigned char key_InsertKeyCode(unsigned char key_code, unsigned char state);
extern unsigned char key_GetKeyCode(unsigned char *pcode,unsigned char *pstate);

/*ir.c*/
extern void ir_Task(void);
extern void ir_Initialization(void);

/*eeprom.c*/
extern void i2c_StartCondition(void);
extern uint8_t i2c_SendByteCheckAck(uint8_t uc);
extern uint8_t i2c_ReceiveByteWithAck(void);
extern uint8_t i2c_ReceiveByteWithoutAck(void);
extern void i2c_StopCondition(void);
extern int eeprom_Read(void *vbuf, uint16_t len, uint16_t addr);
extern int eeprom_Write(const void *vbuf, uint16_t len, uint16_t addr);

/*pcf8563.c*/
struct human_time {
	uint16_t year;/*1970-*/
	uint8_t month;/*1--12*/
	uint8_t day;/*1--31*/
	uint8_t hour;/*0--23*/
	uint8_t minute;/*0--59*/
	uint8_t second;/*0--59*/
};
extern int rtc_Initialization(void);
extern int rtc_GetCalendar(struct human_time *pcal);
extern int rtc_SetCalendar(const struct human_time *pcal);
extern uint8_t rtc_GetMonthDays(uint16_t year, uint8_t month);
extern uint8_t rtc_GetWeekdayOfDay(uint16_t year, uint8_t month, uint8_t day);



#endif
