//prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024

//Group members: Devaughn Channer, Aderibigbe Omoshalewa, and Fatah Ahmed


//Tasknode implementation

#define _CRT_SECURE_NO_WARNINGS

#include "tasknode.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Initializetasks(PLISTNODE* tasklist) {


 	LoadTask(tasklist,"task.dat.txt");

}

void AddTask(PLISTNODE* task, TASK t) {
	PLISTNODE newnode = (PLISTNODE)malloc(sizeof(TASKNODE));

	if (newnode == NULL) {
		fprintf(stderr, "error allocating memory\n");
		return;
	}
	//copy task into the node
	newnode->tasks = t;

	newnode->next = NULL;

	//if the list is empty, sets the newnode as head
	if (*task == NULL) {
		*task = newnode;
	}
	else {
		//finds the last node and append the newnode
		PLISTNODE current = *task;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newnode;

	 	printf("Task with id %d added successfuly\n", t.id);
	}
	
}

void AddTaskToList(PLISTNODE* tasklist) {


	TASK newtask;

	//prompt user to enter name of task/their names
	printf("Enter your name/name of task:");
	scanf_s("%[^\n]%*c", newtask.person, sizeof(newtask.person));

	//prompt user to enter description of task
	printf("Enter description of task:");
	scanf_s("%[^\n]%*c", newtask.description, sizeof(newtask.description));

	//prompt user to enter Id of task
	printf("Enter task id:");
	scanf_s("%d", &newtask.id, sizeof(newtask.id));

	//call the add function to add the task to the list

	AddTask(tasklist, newtask);

}

void DeleteTask(PLISTNODE* task, int id) {
	PLISTNODE current = *task;
	PLISTNODE prev = NULL;
	//traverse through the list to find task to delete
	while (current != NULL && current->tasks.id != id) {
		prev = current;
		current = current->next;
	}
	//if task not found
	if (current == NULL) {
		printf("Task with ID %d not found.", id);
		return;
	}

	//if task to delete is the first node
	if (prev == NULL) {
		*task = current->next;
	}
	else {
		prev->next = current->next;
	}

	//free the memory allocation for the deleted node
	free(current);
	printf("Task with ID %d deleted successfully.", id);
}

void DeleteTaskFromList(PLISTNODE* tasklist) {
	int taskIdToDelete;
	char input[MAXSIZE];

	//prompt user to enter the Id of the task to delete

	printf("Enter Id of the task you want to delete:");
	fgets(input, sizeof(input), stdin);
	sscanf_s(input, "%d", &taskIdToDelete);

	//call the delete function to remove the task from the list
	DeleteTask(tasklist, taskIdToDelete);
}

void UpdateTask(PLISTNODE task) {
	int taskIdToUpdate = 0;
	char input[MAXSIZE];

	//prompt user to enter the id of the task to update
	printf("Enter id of the task to update:");
	fgets(input, sizeof(input), stdin);
	sscanf_s(input, "%d", &taskIdToUpdate);

	PLISTNODE current = task;

	//traverse through the list to find the task with the specified id
	while (current != NULL && current->tasks.id != taskIdToUpdate) {
		current = current->next;
	}

	//if task is not found
	if (current == NULL) {
		printf("Task with Id %d  not found.\n", taskIdToUpdate);
		return;

	}

	//prompt user to enter the new name 

	printf("Enter the new name for the task:");
	scanf_s("%[^\n]%*c", current->tasks.person, sizeof(current->tasks.person));

	//prompt user to enter new description
	printf("Enter the new description for the task:");
	scanf_s("%[^\n]%*c", current->tasks.description, sizeof(current->tasks.description));

	printf("Task with Id %d updated successfully\n", taskIdToUpdate);
}

void DisplaySingleTask(PLISTNODE task) {
	int TaskIdToDisplay = 0;
	char input[MAXSIZE];

	//prompt user to enter the id of the task to update
	printf("Enter id of the task to display:");
	fgets(input, sizeof(input), stdin);
	sscanf_s(input, "%d", &TaskIdToDisplay);

	PLISTNODE current = task;

	//Traverse the list to find the task with the specified Id 
	while (current != NULL && current->tasks.id != TaskIdToDisplay) {
		current = current->next;
	}
	//if task is not found
	if (current == NULL) {
		printf("Task with Id %d not found\n", TaskIdToDisplay);
		return;
	}

	//display the task
	PrintTask(current->tasks);
}

void DisplayRangeOfTask(PLISTNODE task) {
	int startId = 0, endId = 0;
	char input[MAXSIZE];
	bool found = false;

	//Prompt the user for the starting id
	printf("Enter the starting id of the range of tasks:");
	fgets(input, sizeof(input), stdin);
	sscanf_s(input, "%d", &startId);

	//prompt the user for the ending id
	printf("Enter the ending id of the range of tasks:");
	fgets(input, sizeof(input), stdin);
	sscanf_s(input, "%d", &endId);

	PLISTNODE current = task;

	//traverse through the list to find the tasks within the specified range of IDs
	while (current != NULL) {
		if (current->tasks.id >= startId && current->tasks.id <= endId) {
			//display the tasks
			printf("\nTask details\n");
			PrintTask(current->tasks);
			found = true;
		}
		current = current->next;
	}
	//if not tasks were found within the specified range
	if (!found) {
		printf("No tasks were found within the specified range.");
	}

}

void DisplayAllTask(PLISTNODE task) {
	if (task == NULL) {
		printf("No tasks found in the list.\n");
		return;
	}
	PLISTNODE current = task;

	//traverse through the list to display all tasks

	while (current != NULL) {
		PrintTask(current->tasks);
		current = current->next;

	}
}


bool SearchForTask(PLISTNODE task) {
	int taskIdToSearch;
	char input[MAXSIZE];

	//prompt the user to enter the id of the task to search for
	printf("Enter the id of the task to search for:");
	fgets(input, sizeof(input), stdin);
	sscanf_s(input, "%d", &taskIdToSearch);

	TASK taskToSearch;
	taskToSearch.id = taskIdToSearch;

	PLISTNODE current = task;

	//traverse through the list to find the task with the specified id

	while (current != NULL) {
		if (CompareTasks(current->tasks, taskToSearch)) {

			//task found, print the task
			PrintTask(current->tasks);
			return true;
		}
		current = current->next;
	}
	//task not found
	printf("Task with Id %d not found.\n", taskIdToSearch);
	return false;
}


bool SaveTask(PLISTNODE task, const char* filename) {
	//open the file for writing
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "unable to open file for writing\n");
		return false;

	}
	PLISTNODE current = task;

	//traverse through the list and saves tasks to disk
	while (current != NULL) {

		SaveTaskToDisk(current->tasks, fp);
		current = current->next;
	}
	fclose(fp);
	return true;
}

void LoadTask(PLISTNODE* tasklist, const char* filename) {
	//open the file for reading
  	FILE* fp = fopen(filename, "r");
	if (fp != NULL) {

		char line[MAXSIZE];
		int task_id=0;   //the task id, which is the id used to save in disk, is used in deleting tasks
		while (fgets(line, sizeof(line),fp)!=NULL) {
			if (strncmp(line, "TASK:", strlen("TASK:")) == 0) {
				TASK loadedTask = { .id = task_id };

			 	sscanf_s(line, "TASK:%s %[^\n] %d", loadedTask.person, MAXNAME, loadedTask.description, MAXSIZE, &loadedTask.id);

				AddTask(tasklist, loadedTask);
				
			}
			task_id++;
		}
		printf("File loaded successfully\n");

		fclose(fp);
	}
	else {
		printf("there are no saved tasks\n");
	}

}