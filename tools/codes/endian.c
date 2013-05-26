/* Prt Endian of the machine */
#include	<stdlib.h>
#include	<stdio.h>

#define		NUL		0

int
main()
{
	unsigned int i;
	unsigned char *p;
	p = (unsigned char *) &i;
	*(p + 0) = 0x11;
	*(p + 1) = 0x22;
	*(p + 2) = 0x33;
	*(p + 3) = 0x44;
	if ( i == 0x11223344 )
		printf("Big Endian\n");
	else if ( i == 0x44332211 )
		printf("Little Endian\n");
	else
		printf("Unknown Endian\n");
	return EXIT_SUCCESS;
}











