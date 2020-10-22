#ifndef STACK_MANIPULATION_H
#define STACK_MANIPULATION_H


void initStack();

void removeAllValueFromTheStack();

int Push(long int val);
int Pop(long int *val);
int Get(long int *val);

unsigned int Max();
unsigned int Top();

int PushN(long int val, unsigned int index);
int PopN(long int *val, unsigned int index);
int GetN(long int *val, unsigned int index);

void DisplayStack();

#endif
