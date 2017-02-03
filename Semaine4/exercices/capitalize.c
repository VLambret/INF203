#include <stdio.h>

char capitalize(char c)
{
	// compléter ici
	return c;
}

int main(int argc, char **argv)
{
	char c;
	char name[20] = "Bonjour !\n";

	while (1) {
		printf("Entrez un caractère\n");
		do {
			c = getchar();
		} while ( c == '\n' || c == '\r' );
		printf("capitalize(c) = %c\n", capitalize(c));
	}
	
	return 0;
}
