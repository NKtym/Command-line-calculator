#include <stdio.h>
#include <stdlib.h>

#include "listnode.h"

struct listnode_double *list_double_createnode(double value)
{
	struct listnode_double *p;
	p = malloc(sizeof(*p));
	if (p != NULL) {
		p->value = value;
		p->next = NULL;
	}
	return p;
}

struct listnode_char *list_char_createnode(char value)
{
	struct listnode_char *p;
	p = malloc(sizeof(*p));
	if (p != NULL) {
		p->value = value;
		p->next = NULL;
	}
	return p;
}

struct listnode_double *list_double_addfront(struct listnode_double *list,double value)
{
	struct listnode_double *newnode;
	newnode = list_double_createnode(value);
	if (newnode != NULL) {
		newnode->next = list;
		return newnode;
	}
	return list;
}

struct listnode_char *list_char_addfront(struct listnode_char *list,char value)
{
	struct listnode_char *newnode;
	newnode = list_char_createnode(value);
	if (newnode != NULL) {
		newnode->next = list;
		return newnode;
	}
	return list;
}
