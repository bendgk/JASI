#include <stdlib.h>
#include <stdio.h>
#include "snake.h"

void initSnake(Snake *s, int x, int y) {
	//init queue
	Queue queue;
	initQueue(&queue);
	pushQueue(&queue, x, y);

	//init rest of snake attributes
	s->queue = queue;
	s->x = x;
	s->y = y;
	s->length = 4;
	s->x_direction = -1;		//start in the left direction
	s->y_direction = 0;
	s->direction = 'a';
}

void growSnake(Snake *s) {
	s->length += 4;
}

Node* moveSnake(Snake *s) {
	//update position of head
	s->x += s->x_direction;
	s->y += s->y_direction;

	Node *popped = NULL;
	if (s->queue.size >= s->length + 1) {
		popped = popQueue(&s->queue); 
	}

	pushQueue(&s->queue, s->x, s->y);

	return popped;

}

void updateSnakeDirection(Snake *s, char direction) {
	switch(direction) {
		case 'w':
			if (s->direction != 's') {
				s->x_direction = 0;
				s->y_direction = -1;
				s->direction = direction;
			}
			break;
		case 's':
			if (s->direction != 'w') {
				s->x_direction = 0;
				s->y_direction = 1;
				s->direction = direction;
			}
			break;
		case 'a':
			if (s->direction != 'd') {
				s->x_direction = -1;
				s->y_direction = 0;
				s->direction = direction;
			}
			break;
		case 'd':
			if (s->direction != 'a') {
				s->x_direction = 1;
				s->y_direction = 0;
				s->direction = direction;
			}
			break;
		default:
			break;
	}
}