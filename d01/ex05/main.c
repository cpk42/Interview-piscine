#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	printf("_____________________________________________\n");
	tankPush(tank, 990);
	printf("_____________________________________________\n");
	tankPush(tank, 10);
	printf("_____________________________________________\n");
	tankPush(tank, 1000);
	printf("_____________________________________________\n");
	tankPop(tank);
	printf("_____________________________________________\n");
	tankPop(tank);
	printf("_____________________________________________\n");
	tankPop(tank);
	printf("_____________________________________________\n");
	tankPop(tank);
	printf("_____________________________________________\n");
	tankPush(tank, 1000);
	return (0);
}



// Function used for the test
// Don't go further :)
