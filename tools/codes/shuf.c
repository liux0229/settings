/* Shuffle File Lines */
/* Usage : shuf <file> */
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<mylib.h>

#define		NUL		0

static void
CheckNull(void *ptr, char type)
{
	if ( ptr == NULL ) {
		switch ( type )	 {
			case 'a' : 
				/* Memory Allocation */
				printf("Not Enough Memory!\n");
				break;
			case 'f' :
				/* File Opening */
				printf("Can't Open File\n");
				break;
		}
		exit(EXIT_FAILURE);
	}
}

void
RePerm(char **tbl, int n)
{
	int i;
	Randomize();
	for ( i = 0; i < n - 1; i++ ) {
		int pos = RandomInt(i, n - 1);
		char *tmp = tbl[pos];
		tbl[pos] = tbl[i];
		tbl[i] = tmp;
	}
}

int
main(int argc, char **argv)
{
#define	LINE_SIZE	1000
	int i;
	char line_buf[LINE_SIZE];
	char **str_tbl;
	int n_str_tbl = 100, i_str_tbl = 0;
	str_tbl = (char **) malloc(sizeof(*str_tbl) * n_str_tbl);
	if ( argc != 2 ) {
		printf("Usage : shuf <file>");
		return EXIT_FAILURE;
	}
	freopen(argv[1], "r", stdin);
	while ( fgets(line_buf, sizeof line_buf, stdin) != NULL ) {
		int line_len = strlen(line_buf);
		if ( i_str_tbl == n_str_tbl ) {
			n_str_tbl *= 2;
			str_tbl = (char **)
				    realloc(str_tbl, sizeof(*str_tbl) * n_str_tbl);
		}
		str_tbl[i_str_tbl] = (char *) malloc(sizeof(char) * line_len);
		line_buf[line_len - 1] = NUL;
		strcpy(str_tbl[i_str_tbl], line_buf);
		++i_str_tbl;
	}
	RePerm(str_tbl, i_str_tbl);
	fclose(stdin);
	freopen(argv[1], "w", stdout);
	for ( i = 0; i < i_str_tbl; i++ ) 
		printf("%s\n", str_tbl[i]);
	return EXIT_SUCCESS;
}











