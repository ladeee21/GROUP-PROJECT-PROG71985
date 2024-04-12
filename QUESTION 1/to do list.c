//prog71985-winter24
//GROUP PROJECT-TODO LIST
//WEEK 14- 02/04/2024

//Group members: Devaughn Channer, Aderibigbe Omoshalewa, and Fatah Ahmed

// TO-DO LIST IMPLEMENATATION


#define _CRT_SECURE_NO_WARNINGS

#include "to do list.h"
#include <stdlib.h>
#include <string.h>


TASK CreateTask(char* person, char* description, int id) {
	TASK t;


	strncpy_s(t.person, MAXNAME, person, MAXNAME);

	strncpy_s(t.description, MAXSIZE, description, MAXSIZE);

	t.id = id;

	return t;
}

void PrintTask(TASK t) {
	printf("TASK %d:", t.id);
	printf("% s,", t.person);
	printf("%s\n", t.description);


}

bool CompareTasks(TASK lhs, TASK rhs) {
	return (lhs.id == rhs.id);
}


void SaveTaskToDisk(TASK t, FILE* fp) {

	fprintf(fp, "TASK:");
	fprintf(fp, "%s\n", t.person);
	fprintf(fp, "%s\n", t.description);
	fprintf(fp, "%d\n", t.id);
}

TASK  LoadTaskFromDisk(FILE* fp) {
	TASK loadedTask;
	char descriptionbuffer[MAXSIZE] = { 0 };
	fgets(descriptionbuffer, MAXSIZE, fp);

	char personbuffer[MAXNAME] = { 0 };
	fgets(personbuffer, MAXNAME, fp);

	int task_id;
	fscanf_s(fp, "%d\n", &task_id);

	loadedTask = CreateTask(personbuffer, descriptionbuffer, task_id);

	return loadedTask;
}
