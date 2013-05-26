/*
    ** Convert letters in a file all into lowercase or uppercase
    ** The new file will take place of the old file
    ** Usage:
    	case <u|l> <file>
    ** WildCards for <file> is supported
    ** If <file> is not provided, read stdin && output to stdout
*/

#include	<stdlib.h>
#include	<stdio.h>

void
PrtUsage(void)
{
	printf("Usage : case <u|l> <file>\n");
}

void
ChCase(FILE *f_in, FILE *f_out, int option)
{
	int ch;
	while ( (ch = fgetc(f_in)) != EOF ) {
		if ( option == 'u'  )
			ch = toupper(ch);
		else if ( option == 'l' )
			ch = tolower(ch);
		else {
			PrtUsage();
			exit(EXIT_FAILURE);
		}
		fputc(ch, f_out);

	}
}

int
main(int argc, char **argv)
{
	int i = argc - 1;
	char buffer[50];
	FILE *f_in, *f_out;

	if ( argc < 2 ) {
		PrtUsage();
		exit(EXIT_FAILURE);
	}

	if ( argc == 2 ) {
		/* Read stdin && output to stdout */
		ChCase(stdin, stdout, argv[1][0]);
	}

	while ( i >= 2 ) {
		/* Read All File Names */

		/* Check if the old file exists */
		if ( (f_in = fopen(argv[i], "r")) == NULL ) {
			printf("Can't Open File `%s'\n", argv[i]);
			exit(EXIT_FAILURE);
		} else {
			fclose(f_in);
		}
		
		sprintf(buffer, "mv %s %s.tmp", argv[i], argv[i]);
		if ( system(buffer) == -1 ) {
			printf("System Call Error!\n");
			exit(EXIT_FAILURE);
		}

		sprintf(buffer, "%s.tmp", argv[i]);
		if ( (f_in = fopen(buffer, "r")) == NULL ) {
			printf("Can't Open Input File!\n");
			exit(EXIT_FAILURE);
		}
		if ( (f_out = fopen(argv[i], "w")) == NULL ) {
			printf("Can't Open Output File!\n");
			exit(EXIT_FAILURE);
		}

		ChCase(f_in, f_out, argv[1][0]);

		fclose(f_in);
		fclose(f_out);
		sprintf(buffer, "rm -f %s.tmp", argv[i]);
		if ( system(buffer) == -1 ) {
			printf("System Call Error!\n");
			exit(EXIT_FAILURE);
		}
		--i;
	}
	
	return EXIT_SUCCESS;
}










