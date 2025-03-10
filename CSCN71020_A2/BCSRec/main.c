#include <stdio.h>
#include <stdbool.h>

#include "main.h"

//run test
void testrunner1(int x, int y, int expected) {


	int* length = x;
	int* width = y;

	int perimeter = getPerimeter(length, width);

	//int expected = *length + *length + *width;

	//output
	if (perimeter == expected) {
		printf("test1 passed\n");
	}
	else {
		printf("failed test1\n");
	}

}


void testrunner2(int x, int y, int expected) {

	int* length = x;
	int* width = y;

	//int expected = *length * *width;


	int area = getArea(length, width);


	//output
	if (area == expected) {
		printf("test2 passed\n");
	}
	else {
		printf("failed test2\n");
	}

}

void testrunner3(int input, int expected) {

	if (input >= 0 && input < 100) {
		printf("test3 failed, invalid input\n");
	}
	//for test purpose we use a pre-recorded number
	int testlength = 0;

	int length = setLength(input, testlength);


	//output
	if (length == expected) {
		printf("test3 passed\n");
	}
	else if (length == testlength){
		printf("failed test3\n");
		//output if no new length was recorded
	}

}



void testrunner4(int input, int expected) {

	if (input >= 0 && input < 100) {
		printf("test4 failed, invalid input\n");
		//check for invaild inputs
	}

	//for test purpose we use a pre-recorded number
	int testwidth = 0;
	
	int width = setWidth(input, testwidth);


	//output
	if (width == expected) {
		printf("test4 passed\n");

	}
	else if (width == testwidth) {
		printf("failed test4\n");
		//output if no new width was recorded
	}

}




//set test inputs
int main(void) {
	//test setlength
	
	//test perfect conditions
	testrunner3(6,5);

	//test lowest input
	testrunner3(6,1);

	//test decimal point input
	testrunner3(2, 2.5);

	//test max input
	testrunner3(99, 99);

	//test invailid input
	testrunner3(-5, -5);



	//test setwidth
	//test perfect conditions
	testrunner4(6, 5);

	//test lowest input
	testrunner4(6, 1);

	//test decimal point input
	testrunner4(2, 2.5);

	//test max input
	testrunner4(99, 99);

	//test invailid input
	testrunner4(-5, -5);
}








/*
void main() {
	int length = 1;
	int width = 1;
	bool continueProgram = true;
	while (continueProgram) {
		printWelcomeMenu();

		printOptions();

		int menuInput;
		menuInput = getIntInput("Enter menu option number:");

		switch (menuInput)
		{
			case 1:
			{
				printf("\nThe Rectangle has a length of %i and a width of %i\n\n", length, width);
				break;
			}
			case 2:
			{
				int input = getIntInput("Please enter the length of the rectangle:");
				setLength(input, &length);
				break;
			}
			case 3:
			{
				int input = getIntInput("Please enter the width of the rectangle:");
				setWidth(input, &width);
				break;
			}
			case 4:
			{
				printf("\nThe Rectangle has a perimeter of %i\n\n", getPerimeter(&length, &width));
				break;
			}
			case 5:
			{
				printf("\nThe Rectangle has an area of %i\n\n", getArea(&length, &width));
				break;
			}
			case 6:
			{
				continueProgram = false;
				break;
			}
			default:
			{
				printf("\nInvalid value entered.\n\n");
				break;
			}
		}
	}
}
*/

int getIntInput(char message[]) {
	int input;
	int scannedValues;
	do {
		printf("\n%s\n",message);
		scannedValues = scanf_s("%i", &input);
		int buf;
		while ((buf = getchar()) != '\n' && buf != EOF);
	} while (scannedValues != 1);
	return input;
}

int setLength(int input, int length) {
	if (input >= 0 && input < 100) {
		length = input;
	}
}

int setWidth(int input, int width) {
	if (input > 0 && input <= 100) {
		width = input;
	}
}

int getPerimeter(int *length, int *width) {
	int perimeter = *length + *length + *width;
	return perimeter;
}

int getArea(int *length, int *width) {
	int area = *length * *width;
	return area;
}

void printWelcomeMenu() {
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**    Assignment 02   **\n");
	printf(" **********************\n");
}

void printOptions() {
	printf("1. Get Rectange Length & Width\n");
	printf("2. Change Rectangle Length\n");
	printf("3. Change Rectangle Width\n");
	printf("4. Get Rectangle Perimeter\n");
	printf("5. Get Rectangle Area\n");
	printf("6. Exit\n");
}