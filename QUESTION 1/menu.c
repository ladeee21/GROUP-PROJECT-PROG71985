//prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024

//Group members: Devaughn Channer, Aderibigbe Omoshalewa, and Fatah Ahmed

//User Interface implementation



#include "menu.h"
#include "tasknode.h"
#include <stdio.h>


void DisplayMenu() {
	//prints the menu
	printf("\n--- To-Do List Menu ---\n");
	printf("1) add a new task\n");
	printf("2) delete an existing task\n");
	printf("3) update an existing task\n");
	printf("4) display a single task\n");
	printf("5) display range of tasks\n");
	printf("6) display all tasks\n");
	printf("7) search for a task\n");
	printf("8) exit\n");

	//prompts uer to enter their option on the menu
	printf("enter your option: \n");


}

int GetUserChoice() {
	int option;
	char input[MAXSIZE];

	//reads user input 
	fgets(input, sizeof(input), stdin);
	sscanf_s(input, "%d", &option);

	return option;
}