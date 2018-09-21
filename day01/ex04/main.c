#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *queue;

	queue = queueInit();
	enqueue(queue, "first");
	enqueue(queue, "second");
	enqueue(queue, "third");
	enqueue(queue, "fourth");
	enqueue(queue, "fifth");
	printf("peek: %s\n", peek(queue));
	printf("dequeue: %s\n\n", dequeue(queue));
	printf("peek: %s\n", peek(queue));
	printf("dequeue: %s\n\n", dequeue(queue));
	printf("peek: %s\n", peek(queue));
	printf("dequeue: %s\n\n", dequeue(queue));
	printf("peek: %s\n", peek(queue));
	printf("dequeue: %s\n\n", dequeue(queue));
	printf("peek: %s\n", peek(queue));
	printf("dequeue: %s\n\n", dequeue(queue));
	printf("isEmpty ? %d\n", isEmpty(queue));
	
	return (0);
}



// Function used for the test
// Don't go further :)

