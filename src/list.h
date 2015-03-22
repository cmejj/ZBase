#pragma once

#include "container.h"

#ifdef __cplusplus
extern "C" {
#endif

//#define LIST_POISON1 ((void *)0x00100100)
//#define LIST_POISON2 ((void *)0x00200200)
#define LIST_POISON1 NULL
#define LIST_POISON2 NULL

struct list_node {
	struct list_node *prev;
	struct list_node *next;
};

void list_add(struct list_node *, struct list_node *);
void list_del(struct list_node *);

#ifdef __cplusplus
}
#endif