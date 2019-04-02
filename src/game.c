#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "game.h"

int checkBounds(unsigned int x, unsigned int y) {
	return (y >= 0 && y < HEIGHT - 1) && (x >= 0 && x < WIDTH);
}

void render(Game *game) {
	clear();

	printw("+");
	for (int i = 0; i < WIDTH; i++) { printw("-"); }
	printw("+\n|");

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			printw("%c", game->map[y][x]);
		}
		printw("|\n|");
	}
	move(HEIGHT, 0);
	printw("+");
	for (int i = 0; i < WIDTH; i++) { printw("-"); }
	printw("+\n");
}

void initGame(Game *game) {
	/* setup terminal */
	initscr();
	noecho();
	nodelay(stdscr, TRUE);;

	for (int i = 0; i < (HEIGHT * WIDTH); i++) {
		game -> map[i/WIDTH][i%WIDTH] = GAME_CHAR;
	}
}

void put(Game *game, unsigned int x, unsigned int y, char c) {
	if (checkBounds(x, y)) {
		game -> map[y][x] = c;
	}
}

char get(Game *game, unsigned int x, unsigned int y) {
	if(checkBounds(x, y)) {
		return game -> map[y][x];
	}

	else {
		return 0;
	}
}