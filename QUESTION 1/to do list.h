//prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024

//Group members: Devaughn Channer, Aderibigbe Omoshalewa,and Fatah Ahmed

//TO DO LIST INTERFACE
#pragma once
#include <stdio.h>
#include <stdbool.h>



#define MAXSIZE 100
#define MAXNAME 50

typedef struct task {
	char person[MAXNAME];
	char description[MAXSIZE];
	int id;				//for searching and updating
}TASK;

TASK CreateTask(char* person, char* description, int id);

void PrintTask(TASK t);

bool CompareTasks(TASK lhs, TASK rhs);

void SaveTaskToDisk(TASK t, FILE* fp);

TASK  LoadTaskFromDisk(FILE* fp);

