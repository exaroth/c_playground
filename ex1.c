#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>



/* create new structure defining types used inside */
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};


/*
 Function for creating new Person (struct) 
 returns new structure
 
 1. allocate memory for the structure
 2. assert memory has been allocated
 3. define properties of the new structure
 4. return the structure
 */

struct Person *Person_create(char *name, int age, int height, int weight){
	struct Person *who = malloc(sizeof(struct Person));

	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;

};

/* Remove structure from memory if exists */

void Person_destroy(struct Person *who){
	assert(who != NULL);

	free(who->name);
	free(who);
};


/* Print out the info about the person */

void Person_print(struct Person *who){
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
};

int main(int argc, char *argv[]){


	struct Person *konrad = Person_create(
			"Konrad Wasowicz", 29, 123,12
			);

	struct Person *malgosia = Person_create(
			"Malgosia Zurek", 26, 12, 211
			);

	printf("Malgosia is at memory loc: %p:\n", malgosia);

	Person_print(konrad);
	Person_print(malgosia);
	konrad->age -= 20;
	konrad->weight = 10;

	Person_print(konrad);

	Person_destroy(malgosia);

	Person_print(malgosia);

	return 0;

}



