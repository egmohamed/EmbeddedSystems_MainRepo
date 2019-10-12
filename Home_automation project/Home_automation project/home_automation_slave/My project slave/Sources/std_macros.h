#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg&=(~(1<<bit)))
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define TOGGLE_BIT(reg,bit) (reg^=(1<<bit))
#endif