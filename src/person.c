#include "person.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct person_data {
	char* name;
};

static void set_name(struct person* self, const char* p_name)
{
	if (self->pd) {
		if (self->pd->name != NULL)
			free(self->pd->name);
		if (p_name) {

			self->pd->name = (char*) malloc((strlen(p_name)+1) * sizeof(char)); //+1 znak alokowany na \n
		//	printf("%d", strlen(p_name));
			//memset(self->pd->name, 0, sizeof(*self->pd->name));
			strcpy(self->pd->name, p_name);
			//self->pd->name[5]='\0';
		} else {

			self->pd->name = 0;
		}
	}
}

static const char* get_name(struct person* self)
{
	if (self->pd)
		return self->pd->name;
	return 0;
}

struct person* create(const char* p_name)
{
	struct person* result = (struct person*) malloc(sizeof(struct person));
	result->pd = (struct person_data*) malloc(sizeof(struct person_data)); //inicjalizacja pd
	//memset(result, 0 ,sizeof(*result)); //pamiec zaalokowana ale nie zainicjalizowana
	result->set_name = &set_name;
	result->get_name = &get_name;

	if (p_name) {
		result->pd->name = (char*) malloc((strlen(p_name))+1 * sizeof(char)); //1
		strcpy(result->pd->name, p_name);
	}
	//printf("OK");
	return result;
}

void destroy(struct person* p_person)
{
	if (p_person) {
		if (p_person->pd->name)
			free(p_person->pd->name);

		if(p_person->pd)
			free(p_person->pd);
	free(p_person);
	}
}

