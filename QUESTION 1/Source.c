#include <stdio.h>
#include "tasknode.h"

//Menu Function
void DisplayMenu() {
	printf("\n--- To-Do List Menu ---\n");
	printf("1. Add a new task\n");
	printf("2. Delete a task\n");
	printf("3. Display all tasks\n");
	printf("4. Save tasks to file\n");
	printf("5. Load tasks from file\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
}

int main() {
	PLISTNODE tasknode = NULL;

	bool loadSuccess = Load(&tasknode,"task.dat.txt");
	if (!loadSuccess) {
		printf("failure in loading tasks from file\n");
		return 1;
	}

	printf("Tasks loaded from file: \n");


	 Display(tasknode);

	

	Save(tasknode,"task.dat.txt");

	

	return 0;
}