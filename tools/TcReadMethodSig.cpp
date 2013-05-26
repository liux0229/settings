#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
#include	<cctype>
using namespace std;

char str[1000];

int
main()
{
	while ( scanf("%s", str) != EOF ) {
		if ( strcmp(str, "signature:") == 0 ) {
			int ch;
			while ( isspace(ch = getchar()) ) ;
			str[0] = ch;
			int n = 1;
			while ( (ch = getchar()) != '(' ) str[n++] = ch;
			str[n++] = '(';
			while ( (ch = getchar()) != ')' ) str[n++] = ch;
			str[n++] = ')';
			printf("%s\n", str);
			break;
		}
	}
}
