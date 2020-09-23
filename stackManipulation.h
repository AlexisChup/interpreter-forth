#include "constants.h"
#include "stackManipulation.c"

void initStack(int stack[]);

void removeAllValueFromTheStack(int *indexOfTheStack);

int push(int *value, int stack[MAX_PILE_D], int *indexOfTheStack);
int pop(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal);
int get(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal);

unsigned int top(int *indexOfTheStack, int *retVal);

int pushN(int *value, int stack[MAX_PILE_D], int *indexOfTheStack, unsigned int index);
int popN(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal, unsigned int index);
int getN(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal, unsigned int index);
