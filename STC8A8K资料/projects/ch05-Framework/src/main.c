/*
 * Copyright        : Shendong mcu studio
 * File Description : Main Cotntrol Loop.
 * Created          : by oliverzhang@shendongmcu.com
 */

#include "global.h"

static void InitSTC8A(void)
{
	P0M1 = 0x00;
	P0M0 = 0x00;
	P1M1 = 0x00;
	P1M0 = 0x00;
	P2M1 = 0x00;
	P2M0 = 0x00;
	P3M1 = 0x00;
	P3M0 = 0x00;
	P4M1 = 0x00;
	P4M0 = 0x00;
	P5M1 = 0x00;
	P5M0 = 0x00;
	P6M1 = 0x00;
	P6M0 = 0x00;
	P7M1 = 0x00;
	P7M0 = 0x00;
}

void ProcessKey(void)
{
	static unsigned char idata flash_mode = 0;
	unsigned char ret,keycode,keystate;
	
	ret = key_GetKeyCode(&keycode, &keystate);
	if(ret == 0) return;
	//printf("Running.\r\n");
	if(keycode == KEY_SET && keystate == KEY_PRESSED)
	{
		flash_mode++;
		if(flash_mode > 2) flash_mode = 0;
		led_SetFlashMode(flash_mode);
	}
	printf("keycode=%bu keystate=%bu\r\n",keycode,keystate);
}

void main(void)
{
	InitSTC8A();
	time_HoggingDelayMs(1000);
	time_HoggingDelayUs(1);
	time_Initialization();
	led_Initialization();
	key_Initialization();
	uart1_Initialization();
	printf("Hello world.\r\n");
	EA = 1;
	for(;;)
	{
		led_Task();
		key_Task();
		ProcessKey();
	}
}
