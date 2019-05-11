#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ALPHABET 26UL

char* to_lower(size_t plaintext_length, char *plaintext) {
	char *lower_string = (char*)malloc(sizeof(char) * plaintext_length);
	for (size_t iterator = 0UL; iterator < plaintext_length; iterator += 1UL) {
		lower_string[iterator] = (char)tolower(plaintext[iterator]);
	}
	lower_string[plaintext_length] = '\0';
	return lower_string;
}

size_t* get_translation_map(unsigned int key) {
	srand(key * time(0));
	size_t *translation_map = calloc((size_t)ALPHABET, sizeof(size_t));
	for (size_t iterator = 0UL; iterator < (size_t)ALPHABET; iterator += 1UL) {
		translation_map[iterator] = iterator;
	}
	while (key != 0) {
		for (size_t iterator = 0UL; iterator < (size_t)ALPHABET; iterator += 1UL) {
			size_t index_1 = (size_t)rand() % (size_t)ALPHABET;
			size_t index_2 = (size_t)rand() % (size_t)ALPHABET;
			size_t temp = translation_map[index_1];
			translation_map[index_1] = translation_map[index_2];
			translation_map[index_2] = temp;
		}
		key -= 1;
	}
	return translation_map;
}

char* monoalphabetic_encrypt(unsigned int key, size_t plaintext_length, char *plaintext) {
	plaintext = to_lower(plaintext_length, plaintext);
	size_t *translation_map = get_translation_map(key);
	char *ciphertext = (char*)malloc(sizeof(char) * plaintext_length);
	for (size_t iterator = 0UL; plaintext[iterator] != '\0'; iterator += 1UL) {
		ciphertext[iterator] = (char)(translation_map[(size_t)(plaintext[iterator] - (int)'a')] + (int)'a');
	}
	ciphertext[plaintext_length] = '\0';
	return ciphertext;
}

void put_translation_map(FILE *print_stream, unsigned int key) {
	srand(key * time(0));
	size_t *translation_map = calloc((size_t)ALPHABET, sizeof(size_t));
	for (size_t iterator = 0UL; iterator < (size_t)ALPHABET; iterator += 1UL) {
		translation_map[iterator] = iterator;
	}
	while (key != 0) {
		for (size_t iterator = 0UL; iterator < (size_t)ALPHABET; iterator += 1UL) {
			size_t index_1 = (size_t)rand() % (size_t)ALPHABET;
			size_t index_2 = (size_t)rand() % (size_t)ALPHABET;
			size_t temp = translation_map[index_1];
			translation_map[index_1] = translation_map[index_2];
			translation_map[index_2] = temp;
		}
		key -= 1;
	}
	fprintf(print_stream, "KEY -> {");
	for (size_t iterator = 0UL; iterator < (size_t)ALPHABET; iterator += 1UL) {
		fprintf(print_stream, "%zu, ", translation_map[iterator]);
	}
	fprintf(print_stream, "\b\b  \b\b}\n");
}

int main(int argc, char *argv[]) {
	if (argc == 3UL) {
		unsigned int seed = (unsigned int)atoi(argv[1]);
		size_t plaintext_length = strlen(argv[2]);
		char *plaintext = (char*)malloc(sizeof(char) * plaintext_length);
		plaintext = argv[2];
		char *ciphertext = monoalphabetic_encrypt(seed, plaintext_length, plaintext);
		put_translation_map(stdout, seed);
		fprintf(stdout, "<seed:%d, plain_text:%s, cipher_text:%s>\n", seed, plaintext, ciphertext);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}
