#pragma once

struct listnode_double {
	double value;
	struct listnode_double *next;
};

struct listnode_char {
	char value;
	struct listnode_char *next;
};

struct listnode_char *list_char_addfront(struct listnode_char *list,char value);
struct listnode_double *list_double_addfront(struct listnode_double *list,double value);
struct listnode_char *list_char_createnode(char value);
struct listnode_double *list_double_createnode(double value);
