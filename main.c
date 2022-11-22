#include <stdint.h>
#include <stm32f10x.h>
#include <utils.h>
#include <spi.h>
#include <display.h>
#include <stdbool.h>
#include <ball.h>


int __attribute((noreturn)) main(void) {
	
	SPI_Config();
	display_config();
	
	display_clear();

	// uint8_t LCD_Buff[128];				// 1024 or 1056 causes overflow (?)
	// display_buff_init(LCD_Buff, 128);
	// LCD_Buff[5] = 0xFE;
	// repaint(LCD_Buff);
	
	extern uint8_t ball[10];

	base_point bp = {10, 10, 1, 1};

	while (1)
	{
		// set_column(56);
		// for (uint8_t i = 0; i < 12; i++)
		// {
		// 	data(0x00);
		// }
			
		// for (uint8_t i = 0; i < 56; i++)
		// {
		// 	draw_ball(ball, i, i);
		// 	delay_us(50000);
		// }

		// for (uint8_t i = 0; i < 56; i++)
		// {
		// 	draw_ball(ball, 55-i, 55-i);
		// 	delay_us(50000);
		// }
		//__NOP();
		move_ball(&bp, ball);
		
	}


}
