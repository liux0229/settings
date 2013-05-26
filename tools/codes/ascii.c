/* Supress all non-ascii chars in the given file(s) */
#include	<stdlib.h>
#include	<stdio.h>
#include	<ctype.h>

#define		NUL		'\0'

FILE *
OpenFile(char *file_name, char *mode)
{
	FILE *fp;
	fp = fopen(file_name, mode);
	if ( fp == NULL ) {
		printf("Can't Open `%s'\n", file_name);
		exit(EXIT_FAILURE);
	}
	return fp;
}

void
Process_back(FILE *f_in, FILE *f_out)
{
	int ch;
	while ( (ch = fgetc(f_in)) != EOF )	{
		if ( isascii(ch) ) 
			fputc(ch, f_out);
	}
}

void
Process(char *file_name)
{
	char cmd[50] = "mv -f .ascii.tmp ";
	FILE *f_in, *f_out;
	f_in  = OpenFile(file_name, "r");
	f_out = OpenFile(".ascii.tmp", "w");
	Process_back(f_in, f_out);
	fclose(f_out); fclose(f_in);
	strcat(cmd, file_name);
	system(cmd);
}

int
main(int argc, char **argv)
{
	int i;
	if ( argc == 1 ) 
		Process_back(stdin, stdout);
	else {
		for ( i = 1; i < argc; i++ ) 
			Process(argv[i]);
	}
	return EXIT_SUCCESS;
}











