/*
    ** A simple wrapper program to wrap dictionary into world-list.
*/

#include	<stdlib.h>
#include	<stdio.h>

#define		NUL		0

void
wrap(char *file_name)
{
	/* 
	    ** Wrap file [file_name] into word-list 
	    ** file_name is like `letter.txt' &&
	   	the name of word-list will be this single `letter'
	*/	
	FILE *f_in, *f_out;
	char out_file_name[2] = {NUL, NUL};
	int i, ch; 
	char buffer[100];
	char last_word[100] = {NUL};

	if ( (f_in = fopen(file_name, "r")) == NULL ) {
		printf("Can't Open File `%s'\n", file_name);
		exit(EXIT_FAILURE); 
	} 
	out_file_name[0] = file_name[0];
	if ( (f_out = fopen(out_file_name, "w")) == NULL ) {
		printf("Cant' Open File `%s'\n", file_name);
		exit(EXIT_FAILURE);
	}

	/* Drop the discription of the First Letter */
	while ( (ch = fgetc(f_in)) != '\r' )
		;
	fgetc(f_in); fgetc(f_in); fgetc(f_in);

	while ( (ch = fgetc(f_in)) != EOF ) {
		/* Procceed one word */
		i = 0;
		while ( ch != '(' ) {
			buffer[i++] = ch;
			ch = fgetc(f_in);
		}
		buffer[i - 1] = NUL;
		if ( strcmp(buffer, last_word) != 0 ) {
			fprintf(f_out, "%s\n", buffer);
			strcpy(last_word, buffer);
		}

		while ( (ch = fgetc(f_in)) != '\r' )
			;
		fgetc(f_in); fgetc(f_in); fgetc(f_in);
	}

	fclose(f_in);
	fclose(f_out);
}

int
main()
{
	int i;
	char file_name[6] = "a.txt";
	
	for ( i = 'a'; i <= 'z'; i++ ) {
		file_name[0] = i;
		wrap(file_name);
	}
	return EXIT_SUCCESS;
}










