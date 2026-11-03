#ifndef _BUTTON_H_
#define _BUTTON_H_  

#define TASK2_BUTTON_C 2
#define TASK3_BUTTON_D 3

void button_initD(int button);
int button_readD(int button);
void button_pullup_enableD(int button);

void button_initC(int button);
int button_readC(int button);
void button_pullup_enableC(int button);

void button_interrupt1_on_falling_edge_enableD();

#endif
