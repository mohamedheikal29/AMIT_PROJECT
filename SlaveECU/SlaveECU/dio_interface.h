/*
 * dio_interface.h
 *
 * Created: 2/4/2021 4:52:42 AM
 *  Author: moham
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/****************************
*********PINS****************
****************************/
#define dio_pin_0 0
#define dio_pin_1 1
#define dio_pin_2 2
#define dio_pin_3 3
#define dio_pin_4 4
#define dio_pin_5 5
#define dio_pin_6 6
#define dio_pin_7 7
/****************************
*********PIN Status**********
****************************/
#define dio_pin_low 0
#define dio_pin_high 1
/****************************
*********PIN Direction*******
****************************/
#define dio_pin_input 0
#define dio_pin_output 1
/****************************
*********Port Status*********
****************************/
#define dio_port_low 0
#define dio_port_high 255
/****************************
*********Port Direction******
****************************/
#define dio_port_input 0
#define dio_port_output 255
/***************************
********Port Number*********
***************************/
#define dio_portA 0
#define dio_portB 1
#define dio_portC 2
#define dio_portD 3
/***************************
**********dio functions*****
***************************/
uint8_t MCAL_DIO_u8PinDirection(uint8_t Copy_u8PortNo, uint8_t Copy_u8PinNo, uint8_t Copy_u8Direction);
uint8_t MCAL_DIO_u8PinVal(uint8_t Copy_u8PortNo, uint8_t Copy_u8PinNo, uint8_t Copy_u8Value);
uint8_t MCAL_DIO_u8PortDirection(uint8_t Copy_u8PortNo, uint8_t Copy_u8Direction);
uint8_t MCAL_DIO_u8PortVal(uint8_t Copy_u8PortNo, uint8_t Copy_u8Value);
uint8_t MCAL_DIO_u8GetPinValue(uint8_t Copy_u8PortNo ,  uint8_t Copy_u8PinNo ,uint8_t *ptr_u8Value);


#endif /* DIO_INTERFACE_H_ */