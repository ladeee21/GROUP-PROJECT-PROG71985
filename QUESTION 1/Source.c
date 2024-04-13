//prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024

//Group members: Devaughn Channer, Aderibigbe Omoshalewa, and Fatah Ahmed

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "tasknode.h"
#include "menu.h"

int main(void) {
	//initializes the node
	PLISTNODE tasknode = NULL;
	int option;
	
	

	Initializetasks(&tasknode);


	do {
		//displays menu
		DisplayMenu();

		//reads user choice
		option = GetUserChoice();

		switch (option) {
		case 1:
			AddTaskToList(&tasknode);

			//clears input buffer
			while (getchar() != '\n');

			break;
		case 2:
			DeleteTaskFromList(&tasknode);
			break;
		case 3:
			UpdateTask(tasknode);
			break;
		case 4:
			DisplaySingleTask(tasknode);
			break;
		case 5:
			DisplayRangeOfTask(tasknode);
			break;
		case 6:
			DisplayAllTask(tasknode);
			break;
		case 7:
			SearchForTask(tasknode);
			break;
		case 8:
			SaveTask(tasknode, "task.dat.txt");
			printf("exiting to-do list....Goodbye\n");
			break;
		default:
			printf("Invalid option. Try again\n");
			break;

		}

	} while (option != 8);

	return 0;
}
