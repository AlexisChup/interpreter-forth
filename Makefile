main: constants.h displaying.c main.c stack_manipulation.c utils.c displaying.h stack_manipulation.h utils.h
	gcc -o main displaying.c main.c stack_manipulation.c utils.c

units_tests: constants.h displaying.c stack_manipulation.c utils.c displaying.h stack_manipulation.h utils.h units_tests_methods.c units_tests_methods.h unit_tests_main.c
	gcc -o units_tests displaying.c stack_manipulation.c utils.c units_tests_methods.c unit_tests_main.c
