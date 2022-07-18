#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char ch;
	FILE *fp;

	if (argc == 1) {
		exit(0);
	}

	for(int i = 1; i < argc; i++) {
		fp = fopen(argv[i], "r");
		if (fp == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}

		ch = fgetc(fp);
		while (ch != EOF) {
			printf("%c", ch);
			ch = fgetc(fp);
		}

		fclose(fp);
	}

	exit(0);
}

