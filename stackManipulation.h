#include "constants.h"
#include "stackManipulation.c"

void initStack(int stack[]);

int push(int *value, int stack[MAX_PILE_D], int *indexOfTheStack);
int pop(int stack[MAX_PILE_D], int *indexOfTheStack, int *retVal);
