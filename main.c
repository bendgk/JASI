#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <curses.h>
#include <time.h>
#include "game.h"
#include "snake.h"

int main (int argc, char *argv[]) {
	/* setup game */
	Game game;
	initGame(&game);

	Snake snake;
	initSnake(&snake, 10, 5);
	int frames = 0;
	int dt = 500 * 1000;

	struct timespec last, current;
	clock_gettime(CLOCK_MONOTONIC_RAW, &last);

	/* game loop */
	char c = '\0';
	while(c != 'q') {
		c = getch();

		/* handle game input */
		if (c != ERR) {
			updateSnakeDirection(&snake, c);
		}

		clock_gettime(CLOCK_MONOTONIC_RAW, &current);
		if (((current.tv_sec - last.tv_sec) * 1000000 + (current.tv_nsec - last.tv_nsec) / 1000) >= dt) {
			//update game state
			put(&game, snake.x, snake.y, 's');
			
			Node *popped = moveSnake(&snake);
			if (popped != NULL)
				put(&game, popped->x, popped->y, GAME_CHAR);

			//update last clock
			clock_gettime(CLOCK_MONOTONIC_RAW, &last);
			frames++;
		}

		render(&game);

		//Debugging information
		if (c == ERR)
			printw("Input: ''\n");
		else
			printw("Input: %c\n", c);
		printw("frame: %d\n", frames);

		nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);
	}
	endwin();
	system("clear");
	printf("Thank you for playing!\n");
	return 0;
}
