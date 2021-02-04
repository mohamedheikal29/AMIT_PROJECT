/*
 * spi_prog.c
 *
 * Created: 2/4/2021 4:54:12 AM
 *  Author: moham
 */ 
#include "std_types.h"
#include "bit_math.h"
#include "compile.h"
#include "dio_reg.h"
#include "dio_interface.h"
#include "spi_reg.h"
#include "spi_interface.h"
//#define F_CPU 16000000UL
//#include <util/delay.h>
/*
typedef struct
{
	uint8_t spi_type;
	uint8_t spi_data_direction;
	uint8_t clk_polarity;
	uint8_t clk_phase;
	uint8_t spi_clk;
}ptr_spi;
*/
void MCAL_SPI_voidInit(ptr_spi *ptr_info)
{
	if ((ptr_info->spi_type)==SPI_MASTER)
	{
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_4,dio_pin_output);
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_5,dio_pin_output);
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_6,dio_pin_input);
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_7,dio_pin_output);
		assign_bit(SPCR,SPCR_MSTR,ptr_info->spi_type);
		if (((ptr_info->spi_data_direction)==SPI_MSB)||((ptr_info->spi_data_direction)==SPI_LSB))
		{
			assign_bit(SPCR,SPCR_DORD,ptr_info->spi_data_direction);
		}
		if (((ptr_info->clk_polarity)==CLK_IDLE_LOW) || ((ptr_info->clk_polarity)==CLK_IDLE_HIGH))
		{
			assign_bit(SPCR,SPCR_CPOL,ptr_info->clk_polarity);
		}
		if (((ptr_info->clk_phase)==CLK_SAMPLE_LEADING) || ((ptr_info->clk_phase)==CLK_SAMPLE_TRAILING))
		{
			assign_bit(SPCR,SPCR_CPHA,ptr_info->clk_phase);
		}
		if (((ptr_info->spi_clk)>=SPI_CLK_4)&&((ptr_info->spi_clk)<=SPI_CLK_Double_64))
		{
			SPCR |= (SPCR & 0xFC) | ((ptr_info->spi_clk) & 0x03);
		}
		if ((ptr_info->spi_clk)>=SPI_CLK_Double_2)
		{
			set_bit(SPSR,SPSR_SPI2X);
		}
		set_bit(SPCR,SPCR_SPE);
	}
	else if ((ptr_info->spi_type)==SPI_SLAVE)
	{
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_4,dio_pin_input);
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_5,dio_pin_input);
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_6,dio_pin_output);
		MCAL_DIO_u8PinDirection(dio_portB,dio_pin_7,dio_pin_input);
		
		if (((ptr_info->spi_data_direction)==SPI_MSB)||((ptr_info->spi_data_direction)==SPI_LSB))
		{
			assign_bit(SPCR,SPCR_DORD,ptr_info->spi_data_direction);
		}
		if (((ptr_info->clk_phase)==CLK_SAMPLE_LEADING) || ((ptr_info->clk_phase)==CLK_SAMPLE_TRAILING))
		{
			assign_bit(SPCR,SPCR_CPHA,ptr_info->clk_phase);
		}
		set_bit(SPCR,SPCR_SPE);
	}
	
	
}

void MCAL_SPI_MasterTransData(uint8_t u8Data)
{
	SPDR = u8Data;
	MCAL_DIO_u8PinVal(dio_portB,dio_pin_4,dio_pin_low);	
	set_bit(SPCR,SPCR_SPE);
	while(get_bit(SPSR,SPSR_SPIF)!=1);
	clr_bit(SPCR,SPCR_SPE);
	MCAL_DIO_u8PinVal(dio_portB,dio_pin_4,dio_pin_high);
}

uint8_t MCAL_SPI_u8SlaveReceive()
{
	uint8_t x;
	//SPDR=0;
	set_bit(SPCR,SPCR_SPE);
	while(get_bit(SPSR,SPSR_SPIF)!=1);
	x = SPDR;
	clr_bit(SPCR,SPCR_SPE);
	return x;
}