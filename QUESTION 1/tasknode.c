#define _CRT_SECURE_NO_WARNINGS
#include "tasknode.h"
#include <stdio.h>
#include <string.h>

void Display(PLISTNODE task) {
	PLISTNODE current = task;

	while (current != NULL) {
		PrintTask(current->tasks);
		current = current->next;

	}
}

void Update(PLISTNODE* task, TASK t) {
	PLISTNODE current = *task;
	while (current != NULL) {
		if (current->tasks.id == t.id) {
			strncpy_s(current->tasks.person, MAXNAME, t.person, MAXNAME);
			strncpy_s(current->tasks.description, MAXSIZE, t.description, MAXSIZE);
			return;
		}
		current = current->next;
	}
	printf("Task with ID %d not found\n", t.id);
}

bool Save(PLISTNODE task, const char* filename) {
	//open the file for writing
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "unable to open file for writing\n");
		return false;

	}
	PLISTNODE current = task;
	while (current != NULL) {

		SaveTaskToDisk(current->tasks, fp);
		current = current->next;
	}
	fclose(fp);
	return true;
}

bool Load(PLISTNODE* task,const char* filename) {
	//open the file for reading
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "unable to open file for reading: %s\n",filename);
		return false;

	}


	while (!feof(fp)) {
		TASK loadedTask= LoadTaskFromDisk(fp);
		if (&loadedTask == NULL) {
			fprintf(stderr, "Error loading taskk from disk\n");
			fclose(fp);
			return false;
		}
	}
	
	
	fclose(fp);
	return true;

}