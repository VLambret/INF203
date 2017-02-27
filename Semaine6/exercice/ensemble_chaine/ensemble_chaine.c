#include <stdio.h>
#include "ensemble.h"
#include "test.h"

int main(int argc, char *argv[])
{
	int rt;
	struct ensemble e1;
	struct ensemble e2;
	int i;

	init_empty(&e1);

	rt = add_element(&e1, 1);
	test_expect(rt == 1, "Insertion OK");

	rt = check_presence(&e1, 1);
	test_expect(rt == 1, "Présence d'un nombre présent");

	rt = check_presence(&e1, 2);
	test_expect(rt == -1, "Présence d'un nombre absent");

	add_element(&e1, 2);
	rt = add_element(&e1, 2);
	test_expect(rt == -1, "Insertion d'un nombre déjà présent");

	add_element(&e1, 3);

	rt = remove_element(&e1, 2);
	test_expect(rt == 1, "Retirer un nombre présent");

	rt = remove_element(&e1, 2);
	test_expect(rt == -1, "Retirer un nombre absent");

	rt = check_presence(&e1, 3);
	test_expect(rt == 1, "Présence quand le précédent a été enlevé");

	init_empty(&e2);
	rt = remove_element(&e1, 2);
	test_expect(rt == -1, "Retirer un entier d'un ensemble vide");
	
	for (i = 0; i < MAX_SIZE; i++) {
		add_element(&e2, i);
	}
	rt = add_element(&e2, MAX_SIZE);
	test_expect(rt == -1, "Insertion dans un ensemble plein");

	rt = remove_element(&e1, 2);
	test_expect(rt == 1, "Retirer un nombre d'un ensemble plein");

	/* Vérification visuelle */
	print_ensemble(&e2);

	test_results();

	return 0;
}
