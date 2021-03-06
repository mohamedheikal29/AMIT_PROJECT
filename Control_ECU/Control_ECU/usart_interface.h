/*
 * usart_interface.h
 *
 * Created: 2/2/2021 10:25:55 PM
 *  Author: moham
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define F_CLK 16000000UL
void MCAL_USART_voidInit(uint32_t BaudRate);
void MCAL_USART_voidTransmit(uint8_t Data);
uint8_t MCAL_USART_u8Receive();
void MCAL_USART_voidTransmitString(uint8_t *ptr_data);



#endif /* USART_INTERFACE_H_ */