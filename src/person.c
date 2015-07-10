#include "person.h"
#include <stdlib.h>
#include <string.h>

struct person_data {
	char* name;
};

static void set_name(struct person* self, const char* p_name)
{
	if (self->pd) {
		if (self->pd->name)
			free(self->pd->name);
		if (p_name) {
			self->pd->name = (char*) malloc((strlen(p_name)) * sizeof(char));
			strcpy(self->pd->name + 1, p_name);
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
	result->set_name = &set_name;
	result->get_name = &get_name;

	if (p_name) {
		result->pd->name = (char*) malloc((strlen(p_name)) * sizeof(char));
		strcpy(result->pd->name, p_name);
	}

	return result;
}

void destroy(struct person* p_person)
{
	if (p_person) {
		if (p_person->pd->name)
			free(p_person->pd->name);

		free(p_person);
	}
}

