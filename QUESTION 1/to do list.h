//Aderibigbe Omoshalewa-prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024


#pragma once

#include <stdio.h>
#include <stdbool.h>

//TO DO LIST INTERFACE
#define MAXSIZE 100
#define MAXNAME 50

typedef enum status {
	Incomplete = 0,
	Complete
}STATUS;


typedef struct task {
	char person[MAXNAME];
	char description[MAXSIZE];
	int id;				//for searching and updating
	STATUS TASKSTATUS[MAXSIZE];

}TASK;

TASK CreateTask(char* person, char* description, int id);

void PrintTask(TASK t);

void SaveTaskToDisk(TASK t, FILE* fp);

TASK  LoadTaskFromDisk(FILE* fp);
