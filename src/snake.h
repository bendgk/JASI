/* Snake forward declarations */
#include "queue.h"

typedef struct _Snake {
	Queue queue;
	size_t length;

	int x_direction;
	int y_direction;
	char direction;

	unsigned int x;
	unsigned int y;
} Snake;

void initSnake(Snake *s, int x, int y); 

void growSnake(Snake *s);

Node* moveSnake(Snake *s);

void updateSnakeDirection(Snake *s, char direction);