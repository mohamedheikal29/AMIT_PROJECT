/*
 * usart_prog.c
 *
 * Created: 2/2/2021 10:27:00 PM
 *  Author: moham
 */ 
#include "std_types.h"
#include "bit_math.h"
#include "dio_reg.h"
#include "dio_interface.h"
#include "compile.h"
#include "usart_reg.h"
#include "usart_interface.h"

void MCAL_USART_voidInit(uint32_t BaudRate)
{
	
	uint32_t BaudPrescale;
	BaudPrescale = ((F_CLK/(BaudRate*16UL))-1);
	/*enable transmitter and receiver*/
	usart_UCSRB |= (1<<usart_UCSRB_RXEN)|(1<<usart_UCSRB_TXEN);
	usart_UCSRC_UBRRH |= (1<<usart_UCSRC_URSEL)|(1<<usart_UCSRC_UCSZ1)|(1<<usart_UCSRC_UCSZ0);
	/*MCAL_DIO_u8PinDirection(dio_portD,dio_pin_3,dio_pin_output);*/
	/*MCAL_DIO_u8PinVal(dio_portD,dio_pin_3,dio_pin_high);*/
	/*set baud rate*/
	usart_UBRRL = (uint8_t) BaudPrescale;
	usart_UCSRC_UBRRH = (uint8_t)(BaudPrescale>>8);
	//usart_UBRRL = BaudRate;
	//usart_UCSRC_UBRRH = (BaudRate>>8);
	/*MCAL_DIO_u8PinDirection(dio_portC,dio_pin_2,dio_pin_output);*/
	/*MCAL_DIO_u8PinVal(dio_portC,dio_pin_2,dio_pin_high);*/
}

void MCAL_USART_voidTransmit(uint8_t Data)
{
	while((usart_UCSRA&(1<<usart_UCSRA_UDRE))==0);
	usart_UDR = Data;
}
uint8_t MCAL_USART_u8Receive()
{
	while((usart_UCSRA&(1<<usart_UCSRA_RXC))==0);
	return usart_UDR;
}
void MCAL_USART_voidTransmitString(uint8_t *ptr_data)
{
	uint8_t counter = 0;
	while(ptr_data[counter] != '\0')
	{
		MCAL_USART_voidTransmit(ptr_data[counter]);
		counter++;
	}
}