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

int main(int argc, int **argv)
{
	int x= 42 ;
	int y= 13 ;

	echange(x, y) ;
	printf("maintenant x vaut %d et y vaut %d \n", x, y) ;

	echange2(&x, &y) ;
	printf("maintenant x vaut %d et y vaut %d \n", x, y) ;

}
