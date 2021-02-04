/*
 * dio_prog.c
 *
 * Created: 2/2/2021 10:24:36 PM
 *  Author: moham
 */ 
#include "std_types.h"
#include "bit_math.h"
#include "dio_reg.h"
#include "dio_interface.h"
#include "compile.h"

uint8_t MCAL_DIO_u8PinDirection(uint8_t Copy_u8PortNo, uint8_t Copy_u8PinNo, uint8_t Copy_u8Direction)
{
	uint8_t Local_ErrorStatus = NoError;
	if ((Copy_u8PinNo>=dio_pin_0)&&(Copy_u8PinNo<=dio_pin_7))
	{
		switch(Copy_u8PortNo)
		{
			case dio_portA:
			assign_bit(DDRA,Copy_u8PinNo,Copy_u8Direction);
			break;
			case dio_portB:
			assign_bit(DDRB,Copy_u8PinNo,Copy_u8Direction);
			break;
			case dio_portC:
			assign_bit(DDRC,Copy_u8PinNo,Copy_u8Direction);
			break;
			case dio_portD:
			assign_bit(DDRD,Copy_u8PinNo,Copy_u8Direction);
			break;
			default:
			Local_ErrorStatus =Error;
		}
	}
	else
	{
		Local_ErrorStatus = Error;
	}
	return Local_ErrorStatus;
}
uint8_t MCAL_DIO_u8PinVal(uint8_t Copy_u8PortNo, uint8_t Copy_u8PinNo, uint8_t Copy_u8Value)
{
	uint8_t Local_ErrorStatus = NoError;
	if ((Copy_u8PinNo>=dio_pin_0)&&(Copy_u8PinNo<=dio_pin_7))
	{
		switch(Copy_u8PortNo)
		{
			case dio_portA:
			assign_bit(PORTA,Copy_u8PinNo,Copy_u8Value);
			break;
			case dio_portB:
			assign_bit(PORTB,Copy_u8PinNo,Copy_u8Value);
			break;
			case dio_portC:
			assign_bit(PORTC,Copy_u8PinNo,Copy_u8Value);
			break;
			case dio_portD:
			assign_bit(PORTD,Copy_u8PinNo,Copy_u8Value);
			break;
			default:
			Local_ErrorStatus =Error;
		}
	}
	else
	{
		Local_ErrorStatus = Error;
	}
	return Local_ErrorStatus;
}
uint8_t MCAL_DIO_u8PortDirection(uint8_t Copy_u8PortNo, uint8_t Copy_u8Direction)
{
	uint8_t Local_ErrorStatus = NoError;
	switch(Copy_u8PortNo)
	{
		case dio_portA:
		DDRA = Copy_u8Direction;
		break;
		case dio_portB:
		DDRB = Copy_u8Direction;
		break;
		case dio_portC:
		DDRC = Copy_u8Direction;
		break;
		case dio_portD:
		DDRD = Copy_u8Direction;
		break;
		default:
		Local_ErrorStatus = Error;
		break;
	}
	return Local_ErrorStatus;
}
uint8_t MCAL_DIO_u8PortVal(uint8_t Copy_u8PortNo, uint8_t Copy_u8Value)
{
	uint8_t Local_ErrorStatus = NoError;
	switch(Copy_u8PortNo)
	{
		case dio_portA:
		PORTA = Copy_u8Value;
		break;
		case dio_portB:
		PORTB = Copy_u8Value;
		break;
		case dio_portC:
		PORTC = Copy_u8Value;
		break;
		case dio_portD:
		PORTD = Copy_u8Value;
		break;
		default:
		Local_ErrorStatus = Error;
		break;
	}
	return Local_ErrorStatus;
}
uint8_t MCAL_DIO_u8GetPinValue(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t *ptr_u8Value )
{
	uint8_t Local_u8ErrorStatus = NoError;							

	if(Copy_u8PinNo >= dio_pin_0 && Copy_u8PinNo <= dio_pin_7)      
	{
		switch(Copy_u8PortNo)                                   	
		{
			case dio_portA :                                    	
			*ptr_u8Value = get_bit(PINA , Copy_u8PinNo);    	
			break ;
			case dio_portB :                                    	
			*ptr_u8Value = get_bit(PINB , Copy_u8PinNo);    	
			break ;
			case dio_portC :                                    	
			*ptr_u8Value = get_bit(PINC , Copy_u8PinNo);    	
			break ;
			case dio_portD :                                    	
			*ptr_u8Value = get_bit(PIND , Copy_u8PinNo);    	
			break ;
			default :                                           	
			Local_u8ErrorStatus = Error;                    	
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus = Error ;                           
	}

	return Local_u8ErrorStatus ;                                
}