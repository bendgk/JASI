/* Vector forward declarations */
typedef struct _Node {
	struct _Node* next;
	int x;
	int y;
} Node;

typedef struct _Queue {
	Node *root;
	size_t size;
} Queue;

void initQueue(Queue *q);

void pushQueue(Queue *q, int x, int y);

Node* popQueue(Queue *q);

void freeQueue(Queue *q);

void printQueue(Queue *q);


