/*
    ** Cut jargon1 into 26 pieces
*/

#include	<stdlib.h>
#include	<stdio.h>

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

int
main()
{
	FILE *fp, *fp_out;
	char buffer[MAX_LEN_LINE];
	char file_name_out[] = "a.j";
	fp = OpenFile("jargon1", "r");

	fp_out = OpenFile(file_name_out, "w");
	while ( fgets(buffer, MAX_LEN_LINE, fp) != NULL ) {
		if ( buffer[0] == '=' )	{
			fclose(fp_out);
			file_name_out[0] = tolower(buffer[2]);
			fp_out = OpenFile(file_name_out, "w");
			fgets(buffer, MAX_LEN_LINE, fp);
			fgets(buffer, MAX_LEN_LINE, fp);
			fgets(buffer, MAX_LEN_LINE, fp);
		}
		fprintf(fp_out, "%s", buffer);
	}
	fclose(fp_out);	

	fclose(fp);
	return EXIT_SUCCESS;
}










