/* Return a big rand using rand() */
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>

#define		NUL		'\0'

int
main(int argc, char **argv)
{
	char *usage = "rand [n_num]";
	int i, n_num, is_first = 1;
	if ( argc == 2 ) 
		n_num = atoi(argv[1]);
	else
		n_num = 1;
	srand((unsigned)time(NULL));
	for ( i = 0; i < n_num; i++ ) {
		if ( ! is_first ) 
			printf(" ");
		printf("%d", rand());
		is_first = 0;
	}
	printf("\n");
	return EXIT_SUCCESS;
}











