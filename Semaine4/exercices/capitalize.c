#include <stdio.h>

char capitalize(char c)
{
	if (( 'a' <= c ) && ( c <= 'z'))
		return (c - ('a' - 'A'));
	else
		return c;
}

void capitalizeWord(char word[])
{
	int i = 0;
	char c;

	while (word[i] != '\0') {
		c = word[i];
		c = capitalize(c);
		i++;
		putchar(c);
	}

}

int main(int argc, char **argv)
{
	char c;
	char name[20] = "Bonjour !\n";

	capitalizeWord(name);

	while (1) {
		printf("Entrez un caractère\n");
		do {
			c = getchar();
		} while ( c == '\n' || c == '\r' );
		printf("capitalize(c) = %c\n", capitalize(c));
	}
	
	return 0;
}
