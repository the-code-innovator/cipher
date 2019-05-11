#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_unique_key(size_t key_length, char *key) {
	char *unique_key = (char*)malloc(sizeof(char) * key_length);
	return unique_key;
}

int main(int argc, char *argv[]) {
	if (argc == 3UL) {
		size_t key_length = strlen(argv[1]);
		char *key = (char*)malloc(sizeof(char) * key_length);
		key = argv[1];
		size_t plaintext_length = strlen(argv[2]);
		char *plaintext = (char*)malloc(sizeof(char) * plaintext_length);
		plaintext = argv[2];
		key = get_unique_key(key_length, key);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}