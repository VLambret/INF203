#include <stdio.h>

int ctoi(char c) 
{
	if (('0' <= c) && ( c <= '9'))
		return c - '0';
	if (('A' <= c) && ( c <= 'F'))
		return 10 + c - 'A';
	if (('a' <= c) && ( c <= 'f'))
		return 10 + c - 'a';
	return 0;
}

// Renvoi 1 si c est un caractère hexa valide
// 0 sinon
int isValidHexa(char c)
{
	if (('0' <= c) && ( c <= '9'))
		return 1;
	if (('A' <= c) && ( c <= 'F'))
		return 1;
	if (('a' <= c) && ( c <= 'f'))
		return 1;
	return 0;
}

int mon_atoi(char *s)
{
	int i = 0;
	int acc = 0;

	while (s[i] != '\0') {
		printf("acc[%d] = %d\n", i, acc);
		if (isValidHexa(s[i]) == 0) {
			return 0;
		}

		acc = (acc * 16) + ctoi(s[i]);
		i++;
	}
	printf("acc[final] = %d\n", acc);
	return acc;
}

int main(int argc, char **argv)
{
	char *nombre = "1A";
	printf("nombre = %d\n", mon_atoi(nombre));

	return 0;
}
