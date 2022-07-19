#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_file(FILE *fp, char * search_term) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, fp)) != EOF) {
		if (strstr(line, search_term)) {
			printf("%s", line);
		}
	}
	fclose(fp);
}


int main(int argc, char *argv[])
{
	// no inputs, exit
	if (argc < 2) {
		printf("wgrep: searchterm [file ...]\n");
		exit(EXIT_FAILURE);
	}

	char *search_term = argv[1];
	// printf("[*] searchterm: %s\n", search_term);

	// only search term provided
	// read from stdin
	if (argc == 2) {
		// printf("[*] reading from stdin\n");
		search_file(stdin, search_term);
		exit(EXIT_SUCCESS);
	}

	// start at 2
	// argv[0] is the binary name
	// argv[1] is the search term
	for(int i = 2; i < argc; i++) {
		// printf("[*] reading %s\n", argv[i]);

		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			printf("wgrep: cannot open file\n");
			exit(EXIT_FAILURE);
		}
		search_file(fp, search_term);
	}
	exit(EXIT_SUCCESS);
}

