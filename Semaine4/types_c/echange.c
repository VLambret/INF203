#include <stdio.h>

void echange (int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void echange2 (int *pa, int *pb)
{
	int c;
	c = *pa ;
	*pa = *pb;
	*pb = c;
}

void test_pointeurs_tableaux(void)
{
	char tname[] = "Toto";
	char * pname = tname;

	putchar(tname[2]);
	putchar(pname[2]);
}

void test_diff_pointeurs_tableaux(void)
{
	char tname1[] = "Sarah";
	char tname2[] = "Julien";
	char * pname = tname1;

	pname = tname2;
	tname1 = tname2;
}

int main(int argc, char **argv)
{
	int x= 42 ;
	int y= 13 ;

	echange(x, y) ;
	printf("maintenant x vaut %d et y vaut %d \n", x, y) ;

	echange2(&x, &y) ;
	printf("maintenant x vaut %d et y vaut %d \n", x, y) ;

	test_pointeurs_tableaux();

	return 0;
}
