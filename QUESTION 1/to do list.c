#include "to do list.h"
#include <stdlib.h>
#include <string.h>


#define _CRT_SECURE_NO_WARNINGS

TASK CreateTask(char* person, char* description, int id) {
	TASK t;


	strncpy_s(t.person, MAXNAME, person, MAXNAME);

	strncpy_s(t.description, MAXSIZE, description, MAXSIZE);

	t.id = id;

	return t;
}

void PrintTask(TASK t) {
	printf("TASK:%s,%s,%d", t.person, t.description, t.id);
}


void SaveTaskToDisk(TASK t, FILE* fp) {

	fprintf(fp, "TASK:");
	fprintf(fp, "%s\n", t.person);
	fprintf(fp, "%s\n", t.description);
	fprintf(fp, "%d\n", t.id);

}

TASK LoadTaskFromDisk(FILE* fp) {

	TASK loadedTask;
	char descriptionbuffer[MAXSIZE] = { 0 };
	fgets(descriptionbuffer, MAXSIZE, fp);

	char personbuffer[MAXNAME] = { 0 };
	fgets(personbuffer, MAXNAME, fp);

	int task_id;
	fscanf_s(fp, "%d\n", &task_id);

	 loadedTask= CreateTask(personbuffer, descriptionbuffer, task_id);

	return loadedTask;


}