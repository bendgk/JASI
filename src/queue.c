/* Queue forward declaration */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/*
	Initialize Queue
		- init null root
		- set size to 0
*/
void initQueue(Queue *q) {
	q->root = NULL;
	q->size = 0;
}

/*
	Push item to the HEAD of queue
		- sets root if null
		- pushes items down the queue (FIFO)
		- increments queue size

*/
void pushQueue(Queue *q, int x, int y) {
	//if root node is not set create it and set its data
	if (q->root == NULL) {
		q->root = (Node*) malloc(sizeof(Node));
		q->root->x = x;
		q->root->y = y;
		q->root->next = NULL;
	}

	else {
		Node* tmp = q->root;

		q->root = (Node*) malloc(sizeof(Node));
		q->root->x = x;
		q->root->y = y;
		q->root->next = tmp;
	}

	q->size++;
}

/*
	Pop and return Node from END of queue
		- Crashes with error message "No items left to remove from queue" when queue is empty
		- Sets root to null if last item is removed
		- performs linear search for last item in queue
		- decrements queue size
*/
Node* popQueue(Queue *q) {
	Node* return_node = (Node*) malloc(sizeof(Node));
	return_node->next = NULL;

	if (q->size == 0) {
		printf("No items left to remove from queue!\n");
		exit(-1);
	}

	else if (q->size == 1) {
		return_node->x = q->root->x;
		return_node->y = q->root->y;
		free(q->root);
		q->root = NULL;
	}

	else {
		Node *prev_node = q->root;
		Node *current_node = q->root;
		while (current_node->next != NULL) {
			prev_node = current_node;
			current_node = current_node->next;
		}

		return_node->x = current_node->x;
		return_node->y = current_node->y;

		free(current_node);
		prev_node->next = NULL;
	}

	q->size--;
	return return_node;


}

/*
	Free Queue
		- O(N) algorithm for freeing every element in queue
*/
void freeQueue(Queue *q) {
	Node *current_node = q->root;
	while (current_node != NULL) {
		Node *next = current_node->next;
		free(current_node);
		current_node = next;
	}
}

/*
	Print Queue
		- O(N) algorithm for printing every item in queue 
*/
void printQueue(Queue *q) {
	Node *current_node = q->root;
	printf("Queue: ");
	while (current_node != NULL) {
		printf("(x: %d, y: %d),", current_node->x, current_node->y);
		current_node = current_node->next;
	}

	printf("\n");
}