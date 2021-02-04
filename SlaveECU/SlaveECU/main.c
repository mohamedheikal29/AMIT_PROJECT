/*
 * SlaveECU.c
 *
 * Created: 2/4/2021 4:38:12 AM
 * Author : moham
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "dio_reg.h"
#include "dio_interface.h"
#include "compile.h"
#include "spi_reg.h"
#include "spi_interface.h"



int main(void)
{
	uint8_t x;
	MCAL_DIO_u8PinDirection(dio_portD,dio_pin_1,dio_pin_output);
	MCAL_DIO_u8PinDirection(dio_portD,dio_pin_2,dio_pin_output);
    ptr_spi obj = {SPI_SLAVE,SPI_MSB,CLK_IDLE_LOW,CLK_SAMPLE_LEADING};
	MCAL_SPI_voidInit(&obj);
	MCAL_DIO_u8PinVal(dio_portD,dio_pin_1,dio_pin_low);
    MCAL_DIO_u8PinVal(dio_portD,dio_pin_2,dio_pin_low);
    while (1) 
    {
		x = MCAL_SPI_u8SlaveReceive();
		if (x == '1')
		{
			if (get_bit(PIND,dio_pin_1)==1)
			{
				MCAL_DIO_u8PinVal(dio_portD,dio_pin_1,dio_pin_low);
			} 
			else if(get_bit(PIND,dio_pin_1)==0)
			{
				MCAL_DIO_u8PinVal(dio_portD,dio_pin_1,dio_pin_high);
			}
		} 
		else if (x == '2')
		{
			if (get_bit(PIND,dio_pin_2)==1)
			{
				MCAL_DIO_u8PinVal(dio_portD,dio_pin_2,dio_pin_low);
			}
			else if(get_bit(PIND,dio_pin_2)==0)
			{
				MCAL_DIO_u8PinVal(dio_portD,dio_pin_2,dio_pin_high);
			}
		}
    }
}

