/*
 * Control_ECU.c
 *
 * Created: 2/2/2021 10:20:56 PM
 * Author : moham
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "dio_reg.h"
#include "dio_interface.h"
#include "compile.h"
#include "usart_reg.h"
#include "usart_interface.h"
#include "spi_reg.h"
#include "spi_interface.h"
int main()
{
	ptr_spi obj = {SPI_MASTER,SPI_MSB,CLK_IDLE_LOW,CLK_SAMPLE_LEADING,SPI_CLK_64};
	MCAL_SPI_voidInit(&obj);
	MCAL_USART_voidInit(9600);
	MCAL_DIO_u8PinDirection(dio_portC,dio_pin_2,dio_pin_output);
	MCAL_DIO_u8PinDirection(dio_portC,dio_pin_7,dio_pin_output);
	uint8_t arr[] = "Please Enter a Button:";
	MCAL_USART_voidTransmitString(arr);
	uint8_t chr;
	while(1)
	{
		chr = MCAL_USART_u8Receive();
		if (chr == '1')
		{
			MCAL_DIO_u8PinVal(dio_portC,dio_pin_2,dio_pin_high);//this one is used to tell us that the program went through this condition
			MCAL_SPI_MasterTransData(chr);
		}
		else if (chr =='2')
		{
			MCAL_DIO_u8PinVal(dio_portC,dio_pin_7,dio_pin_high);//this one is used to tell us that the program went through this condition
			MCAL_SPI_MasterTransData(chr);
		}
		/*else if (chr == '3')
		{
			MCAL_DIO_u8PinVal(dio_portC,dio_pin_2,dio_pin_low);//this one is used to tell us that the program went through this condition
			MCAL_SPI_MasterTransData(chr);
		}
		else if (chr == '4')
		{
			MCAL_DIO_u8PinVal(dio_portC,dio_pin_7,dio_pin_low);//this one is used to tell us that the program went through this condition
			MCAL_SPI_MasterTransData(chr);
		}*/
	}
}