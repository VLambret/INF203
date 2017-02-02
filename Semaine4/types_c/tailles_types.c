#include <stdio.h>

int main(int argc, char **argv)
{
	// Taille des types

	printf("char      : %d octets\n", sizeof(char));
	printf("short     : %d octets\n", sizeof(short));
	printf("int       : %d octets\n", sizeof(int));
	printf("long      : %d octets\n", sizeof(long));
	printf("long long : %d octets\n", sizeof(long long));

	// Notation binaire
	int n1 = 10;
	int n2 = 010;
	int n3 = 0b10;
	int n4 = 0x10;


	// char - int
	char    c1 = 65;
	short   c2 = 65;
	int     c3 = 65;

	printf("c1=%c, c2=%c, c3=%c\n", c1, c2, c3);
	printf("c1=%d, c2=%d, c3=%d\n", c1, c2, c3);
}

