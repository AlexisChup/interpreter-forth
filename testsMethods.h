#include "testsMethods.c"

void printResultOfTest(int *isOk);

void testPushMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testPopMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testGetMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);

void testPushNMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);


int insertNRandomNumberInStack(int stack[MAX_PILE_D], unsigned int numberOfRandomNumber, int *indexOfTheStack, int *isOk);