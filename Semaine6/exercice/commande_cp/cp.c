#include <stdio.h>

#define BUFFER_SIZE 16

int my_cp(FILE *src, FILE *dest)
{
	unsigned char buffer[BUFFER_SIZE];
	size_t rd;
	size_t wr;
	int done = 0;

	while (done == 0)
	{
		rd = fread(buffer, 1, BUFFER_SIZE, src);
		printf("rd = %d\n", rd);
		if (rd == 0)
		{
			done = 1;
		}

		wr = fwrite(buffer, 1, rd, dest);
		printf("wr = %d\n", wr);
	}

	return 0;
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

	return my_cp(source, dest);
}
