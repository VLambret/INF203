#include <stdio.h>

int main()
{
	int i;
	i = getchar();
	char tab[i];

	printf("i = %d\n", i);
	printf("sizeof(tab) = %d\n", sizeof(tab));

	return 0;

}
