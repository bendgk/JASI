/* Game forward declarations */
#define WIDTH 20
#define HEIGHT 10
#define GAME_CHAR ' '
#define FRUIT_CHAR '*'

typedef struct _Game {
	char map[HEIGHT][WIDTH];
} Game;

int checkBounds(unsigned int x, unsigned int y);

void render(Game *game);

void initGame(Game *game);

void put(Game *game, unsigned int x, unsigned int y, char c);

char get(Game *game, unsigned int x, unsigned int y);