//prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024

//Group members: Devaughn Channer, Aderibigbe Omoshalewa, and Fatah Ahmed

#pragma once
#include "to do list.h"
#include <stdbool.h>


typedef struct tasknode {
	TASK tasks;
	struct tasknode* next;
}TASKNODE, * PLISTNODE;

//Devaughn C 
//Group Project To-do list
void AddTask(PLISTNODE* task, TASK t);

void DeleteTask(PLISTNODE* task, int id);


//OMOSHALEWA
//Group Project To-do list
void UpdateTask(PLISTNODE task);

void DisplayAllTask(PLISTNODE task);

void DisplaySingleTask(PLISTNODE task);

void DisplayRangeOfTask(PLISTNODE task);

bool SearchForTask(PLISTNODE task);

bool SaveTask(PLISTNODE task, const char* filename);

bool LoadTask(PLISTNODE* task, const char* filename);

void AddTaskToList(PLISTNODE* tasklist);

void DeleteTaskFromList(PLISTNODE* tasklist);

