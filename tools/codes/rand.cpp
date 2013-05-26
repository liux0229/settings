#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<mylib.h>

#define		NUL		'\0'

int
main(int argc, char **argv)
{
	char *usage = "rand <lower> <upper> [n_num] [-n] (inclusive; -n : every number in a line)";
	int lower, upper, n_num;
	int i;
	if ( argc < 3 ) {
		printf("%s\n", usage);
		exit(EXIT_FAILURE);
	}
	lower = atoi(argv[1]);
	upper = atoi(argv[2]);
	if ( argc >= 4 ) 
		n_num = atoi(argv[3]);
	else
		n_num = 1;
	bool nl = 0;
	if ( argc >= 5 ) nl = 1;
	Randomize();
	for ( i = 0; i < n_num; i++ ) {
		if ( ! nl && i ) printf(" ");
		printf("%d", RandomInt(lower, upper));
		if ( nl ) printf("\n");
	}
	if ( ! nl ) printf("\n");
	return EXIT_SUCCESS;
}











