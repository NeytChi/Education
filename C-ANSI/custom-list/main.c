#include <stdio.h>


#define LIST_FOREACH(curr, list) \
	ListNode *curr = list->first;\
    for (ListNode *_node = list->first; \
         _node != NULL; \
         curr = _node = _node->next)

struct ListNode;

typedef struct ListNode 
{
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct List 
{
	int count;
	ListNode *first;
	ListNode *last;
} List;


int testForeach()
{
	List *list;

	/* Fill the linked list */

	LIST_FOREACH(curr, list)
	{
		printf("%d\n", (int)curr->value);
	}
}