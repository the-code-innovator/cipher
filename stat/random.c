#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(0));
	int val = rand();
	printf("%d\n", val);
	return 0;
}