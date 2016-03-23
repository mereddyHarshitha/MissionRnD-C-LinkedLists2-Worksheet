/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	
	struct node* ptr1 = head1;
	struct node* ptr2 = head2;
	struct node* temp = NULL;

	struct node* ptr = temp;

	if (head1 == NULL)
		return head2;

	else if (head2 == NULL)
		return head1;

	else if (head1 == NULL && head2 == NULL)
		return NULL;

	else{
		while (ptr1 != NULL && ptr2 != NULL){
			if (ptr1->num > ptr2->num){
				if (temp == NULL)
					temp = ptr = ptr2;
				else{
					ptr->next = ptr2;
					ptr = ptr->next;
				}
				ptr2 = ptr2->next;
			}
			else if (ptr1->num < ptr2->num){
				if (temp == NULL)
					temp = ptr = ptr1;
				else{
					ptr->next = ptr1;
					ptr = ptr->next;
				}
				ptr1 = ptr1->next;
			}
			else{
				if (temp == NULL){
					ptr = temp = ptr1;
					ptr1 = ptr1->next;
					ptr->next = ptr2;
					ptr = ptr->next;
					ptr2 = ptr2->next;
				}
				else{
					ptr->next = ptr1;
					ptr = ptr->next;
					ptr1 = ptr1->next;
					ptr->next = ptr2;
					ptr = ptr->next;
					ptr2 = ptr2->next;
				}
			}
		}
		while (ptr1 != NULL){
			if (temp == NULL)
				temp = ptr = ptr1;
			else{
				ptr->next = ptr1;
				ptr = ptr->next;
			}
			ptr1 = ptr1->next;
		}
		while (ptr2 != NULL){
			if (temp == NULL)
				temp = ptr = ptr2;
			else{
				ptr->next = ptr2;
				ptr = ptr->next;
			}
			ptr2 = ptr2->next;
		}
		ptr->next = NULL;
		return temp;
	}
}
