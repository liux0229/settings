/*
    ** Wrap [a-z].j into [a-z] && [a-z]-disc, each line: 
    ** [a-z] contains a word-name
    ** [a-z]-disc contains word-disc seperated by `\r' to mean `\n'  	
*/

#include	<stdlib.h>
#include	<stdio.h>

#define		NUL		0

#define		MAX_LEN_N	100
#define		MAX_LEN_LINE	100

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


char *
ToLowerS(char *str)
{
	/* ToLower a string */
	char *p;
	for ( p = str; *p != NUL; p++ )
		*p = tolower(*p);
	return str;
}

void
wrap(char L)
{
	char file_name_i[] = "a.j";
	char file_name_n[] = "a";
	char file_name_d[] = "a-disc";
	FILE *f_i, *f_n, *f_d;
	char name_buffer[MAX_LEN_N];
	char line_buffer[MAX_LEN_LINE];
	int i, first = 1;

	file_name_i[0] = L; file_name_n[0] = L; file_name_d[0] = L;
	f_i = OpenFile(file_name_i, "r");
	f_n = OpenFile(file_name_n, "w");
	f_d = OpenFile(file_name_d, "w");

	while ( fgets(line_buffer, MAX_LEN_LINE, f_i) != NULL )	 {
		if ( line_buffer[0] == ':' ) {
			/* Have found a new word */
			if ( ! first ) 
				fprintf(f_d, "\n"); /* Close last word's disc */
			first = 0;

			i = 0;
			while ( (name_buffer[i] = line_buffer[i+1]) != ':' )
				++i;
			name_buffer[i] = NUL;
			fprintf(f_n, "%s\n", ToLowerS(name_buffer));
		}
		line_buffer[strlen(line_buffer)-1] = '\r';
		fprintf(f_d, "%s", line_buffer);
	}
	fprintf(f_d, "\n");

	fclose(f_i); fclose(f_n); fclose(f_n);
}

int
main()
{
	int ch;
	for ( ch = 'a'; ch <= 'z'; ch++ )
		wrap(ch);
	return EXIT_SUCCESS;
}










