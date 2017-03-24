#include <stdio.h>

int isCharALineSeparator(char c)
{
//	printf("c=%d\n", c);
	if (c == '\n' || c == '\0' || c == '\r')
		return 1;
	return 0;
}

int getLine(FILE *source, char *buffer, int bufferSize)
{
	char c;
	int i = 0;

	while (!feof(source) && i < bufferSize) {
		fscanf(source, "%c", &c);
		if (isCharALineSeparator(c)) {
			break;
		}
		buffer[i] = c;
		i++;
	}

	if ((i == 0) || (i == bufferSize)) {
		return 0;
	}
	buffer[i] = '\0';
	return 1;
}

int main(int argc, char *argv[])
{
	char buf[1024];
	while(1) {
		if (getLine(stdin, buf, 1024)) {
			printf("Received :");
			printf("%s\n", buf);
		} else {
			printf("No more line\n");
			break;
		}
	}

	return 0;
}
