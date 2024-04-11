#include <stdio.h>
#include "tasknode.h"

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