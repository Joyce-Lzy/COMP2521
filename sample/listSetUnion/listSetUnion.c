
#include "list.h"

static void inserts3(List s3, int v);

List listSetUnion(List s1, List s2) {
	List s3 = newList();
	
	Node n = s1->head;
	while (n != NULL) {
		inserts3(s3, n->value);
		n = n->next;
	}

	n = s2->head;
	while (n != NULL) {
		inserts3(s3, n->value);
		n = n->next;
	}

	return s3;
}

static void inserts3(List s3, int v) {
	Node curr = s3->head;
	Node new = newNode(v);
	
	if (s3->head == NULL) {
		s3->head = new;
		return;
	}
	Node pre = NULL;
	while (curr != NULL) {
	 	if (curr->value == v) {
			// duplicate
			free(new);
			return;
		}
		pre = curr;
		curr = curr->next;
	}
	pre->next = new;	
	return;
}