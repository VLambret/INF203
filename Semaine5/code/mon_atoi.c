#include <stdio.h>

int mon_atoi(char *s)
{
	char c = s[0];

	if ((c < '0') || ('9' < c)) {
		return 0;
	}
	return c - '0';
}

int main(int argc, char **argv)
{
	char *nombre = "62";
	printf("nombre = %d\n", mon_atoi(nombre));

	return 0;
}
