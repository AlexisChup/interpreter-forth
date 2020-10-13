#ifndef TESTS_METHODS_H
#define TESTS_METHODS_H

#include "unit_test_first_and_second_parts.c"

/*
    *used to make more beautiful print in terminal
*/
void printResultOfTest(int *isOk);
void printReturnedValue(int retVal);

/*
    *used to insert X random number in the stack for tests
*/
int insertNRandomNumberInStack(int stack[MAX_PILE_D], unsigned int numberOfRandomNumber, int *indexOfTheStack, int *isOk);

void testPushMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testPopMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testGetMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);

void testTopMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testMaxMethod(int *isOk);

void testPushNMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testPopNMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);
void testGetNMethod(int stack[MAX_PILE_D], int *indexOfTheStack, int *isOk);

#endif