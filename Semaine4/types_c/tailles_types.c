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
	char    c = 65;
	int     i = 65;

	printf("c1=%c, c2=%d\n", c, c);
	printf("i1=%c, i2=%d\n", i, i);
}

