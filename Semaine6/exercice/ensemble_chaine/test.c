#include <stdio.h>
#include "test.h"

static int total = 0;
static int passing = 0;

void test_expect(int condition, const char *test_name)
{
	total++;
	if (!condition) {
		printf("\033[31m[KO]\033[0m : %s\n", test_name);

	} else {
		passing++;
		printf("\033[32m[OK]\033[0m : %s\n", test_name);
	}
}

void test_results()
{
	if (total == passing) {
		printf("All %d test passings, bravo !\n", total);
	} else {
		if (passing != 0) {
			printf("%d / %d test passings\n", passing, total);
		} else {
			printf("None of the %d tests passed, SHAME ON YOU !!!!!\n", total);
		}
	}
}

