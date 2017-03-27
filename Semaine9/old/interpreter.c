#include <stdio.h>

#define MAX_ARGS        16

int isCharALineSeparator(char c)
{
//	printf("c=%d\n", c);
	if (c < 0 || 127 < c)
		return 2;
	if (c == '\n' || c == '\0' || c == '\r')
		return 1;
	return 0;
}

int splitArguments(char *commandLine, char *argv[MAX_ARGS])
{
	int i = 0;
	int argc = 1;

	argv[0] = commandLine;
	while(commandLine[i] != '\0') {
		if (commandLine[i] == ' ') {
			argv[argc] = &commandLine[i+1];
			argc++;
			commandLine[i] = '\0';
		}
		i++;
	}

	return argc;
}

void showArguments(int argc, char *argv[])
{
	int i = 0;
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
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
	int rt;
	char buf[1024];
	int my_argc;
	char *my_argv[MAX_ARGS];

	while(1) {
		rt = getLine(stdin, buf, 1024);
		if (rt == 0) {
			printf("No more line\n");
			break;
		}

		printf("Received :");
		printf("%s\n", buf);

		my_argc = splitArguments(buf, my_argv);
		showArguments(my_argc, my_argv);
	}

	return 0;
}
