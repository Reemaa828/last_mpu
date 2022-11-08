/*
 * MACROS.h
 *
 *  Created on: Sep 9, 2022
 *      Author: hp
 */

#ifndef MACROS_H_
#define MACROS_H_

#include "STD_Types.h"

#define SET_BIT(Var,PIN_NUM)    Var |=  (1 << (PIN_NUM)) //or , shift
#define CLR_BIT(Var,PIN_NUM)    Var &= ~(1 << (PIN_NUM)) // and , shift
#define TOG_BIT(Var,PIN_NUM)    Var^=(1<<(PIN_NUM)) //xor  , shift
#define GET_BIT(Var,PIN_NUM)    ((Var&(1<<(PIN_NUM)))>>PIN_NUM)

#endif /* MACROS_H_ */
