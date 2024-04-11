//Aderibigbe Omoshalewa-prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024


#pragma once
#include "to do list.h"
#include <stdbool.h>


typedef struct tasknode {
	TASK tasks;
	struct tasknode* next;
}TASKNODE, * PLISTNODE;

void Display(PLISTNODE task);

void Update(PLISTNODE* task, TASK t);

bool Save(PLISTNODE task, const char* filename);

bool Load(PLISTNODE* task,const char* filename);
