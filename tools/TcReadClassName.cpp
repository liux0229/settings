#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
using namespace std;

char str[1000];

int
main()
{
	while ( scanf("%s", str) != EOF ) {
		if ( strcmp(str, "Class:") == 0 ) {
			scanf("%s", str);
			printf("%s\n", str);
			break;
		}
	}
}
