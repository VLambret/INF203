#include <stdio.h>

#define BUFFER_SIZE 16

void my_cp(FILE *src, FILE *dest)
{
	unsigned char buffer[BUFFER_SIZE];
	size_t rd;

	while (!feof(src))
	{
		rd = fread(buffer, 1, BUFFER_SIZE, src);
		fwrite(buffer, 1, rd, dest);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage : %s fichier1 fichier2\n", argv[0]);
		return -1;
	}

	FILE *source = fopen(argv[1], "r");
	if (source == NULL)
	{
		fprintf(stderr, "Can't open file %s with reading rights\n", argv[1]);
		return -1;
	}

	FILE *dest = fopen(argv[2], "w");
	if (source == NULL)
	{
		fprintf(stderr, "Can't open file %s with writing rights\n", argv[2]);
		fclose(source);
		return -1;
	}

	my_cp(source, dest);
	return 0;
}
