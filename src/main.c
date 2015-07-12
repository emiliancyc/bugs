#include <stdio.h>
#include "person.h"

int main(int argc, const char *argv[])
{
	const char* name = "Emilian";

	struct person* p = create("Roman");
	printf("Name: %s \n", p->get_name(p));
	p->set_name(p, name);
	//printf("%s",*(p->pd->name));
	printf("Person name: %s\n", p->get_name(p));
	destroy(p);

	return 0;
}
