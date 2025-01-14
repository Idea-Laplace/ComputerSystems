#include <stdio.h>
#include <stdlib.h>

#define BUF 20
#define NEW_LINE 30

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Too few arguments, Usage: $./binary2hex {file_name}\n");
		exit(EXIT_FAILURE);
	}

	FILE *binary, *hex;
	char new_file_name[BUF + 1] = {'\0'};
	int ch, bytes = 1;


	binary = fopen(argv[1], "rb");

	if (binary == NULL) {
		printf("Cannot open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	snprintf(new_file_name, BUF, "hex_%s", argv[1]);
	hex = fopen(new_file_name, "wb");

	if (hex == NULL) {
		printf("Cannot open file: %s\n", new_file_name);
		exit(EXIT_FAILURE);
	}


	while ((ch = fgetc(binary)) != EOF) {
		fprintf(hex, "%.2x ", ch);
		if (bytes++ % NEW_LINE == 0)
			fprintf(hex, "\n");
	}

	fclose(binary);
	fclose(hex);

	return 0;
}

