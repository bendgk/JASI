game: main.c
	cc -lncurses -Wall -Wextra -g main.c game.c queue.c snake.c -o game

queue: queue.c
	cc -Wall -Wextra -g queue.c -o queue -v

clean:
	rm queue
	rm game
	rm -rf game.dSYM
	rm -rf queue.dSYM
