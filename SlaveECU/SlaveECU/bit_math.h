/*
 * bit_math.h
 *
 * Created: 2/4/2021 4:43:31 AM
 *  Author: moham
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(var,bitNo) (var |=(1<<bitNo))
#define clr_bit(var,bitNo) (var &=~(1<<bitNo))
#define toggle_bit(var,bitNo) (var ^=(1<<bitNo))
#define get_bit(var,bitNo) ((var>>bitNo) & 0x01)
#define assign_bit(var,bitNo,val) (var = (var&~(1<<bitNo)) | (val<<bitNo))



#endif /* BIT_MATH_H_ */