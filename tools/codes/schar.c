/*
    ** Special Char Writer
*/

#include	<stdlib.h>
#include	<stdio.h>

int
main()
{
	FILE *fp;
	int i;
	char *name[] = {
		"\\r", "NUL"
	};
	char schar[] = {
		'\r', '\000'
	};

	if ( (fp = fopen("schar.out", "w")) == NULL ) {
		printf("Can't Open `schar'\n");
		exit(EXIT_FAILURE);
	}
	for ( i = 0; i < sizeof(name) / sizeof(name[0]); i++ ) {
		fprintf(fp, "%5s = %c\n", name[i], schar[i]);
	}

	fclose(fp);	
	return EXIT_SUCCESS;
}










