/*
    ** Convert Dos Plain Text To Unix Format
    ** Remove '\r' at end of each line.
    ** Input file name wild card supported
*/
#include	<stdlib.h>
#include	<stdio.h>	

void
convert(char *file_name)
{
	char buffer[50];
	FILE *f_in, *f_out;
	int ch;

	sprintf(buffer, "mv %s %s.tmp", file_name, file_name);
	system(buffer);
	sprintf(buffer, "%s.tmp", file_name);
	if ( (f_in = fopen(buffer, "r")) == NULL ) {
		printf("Can't Open Temp File!\n");
		exit(EXIT_FAILURE);
	}
	if ( (f_out = fopen(file_name, "w")) == NULL ) {
		printf("Can't Open Output File!\n");
		exit(EXIT_FAILURE);
	}

	while ( (ch = fgetc(f_in)) != EOF ) {
		if ( ch != '\r' )
			fputc(ch, f_out);
	}
	
	fclose(f_in);
	fclose(f_out);
	sprintf(buffer, "rm -f %s.tmp", file_name);
	system(buffer);
}

int
main(int argc, char **argv)
{
	while ( --argc > 0 ) {
		convert(argv[argc]);
	}
	return EXIT_SUCCESS;
}










