#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char get_translated_char(int key, char plaintext) {
	return (char)(((tolower(plaintext) - 97 + key) % 26) + 97);
}

char* caesar_encipher(int key, size_t plaintext_length, char *plaintext) {
	char *ciphertext = (char*)malloc(sizeof(char) * plaintext_length);
	for (size_t iterator = 0UL; plaintext[iterator] != '\0'; iterator += 1UL) {
		ciphertext[iterator] = get_translated_char(key, plaintext[iterator]);
	}
	ciphertext[plaintext_length] = '\0';
	return ciphertext;
}

int main(int argc, char *argv[]) {
	if (argc == 3UL) {
		int caesar_shift_key = atoi(argv[1UL]);
		size_t plaintext_length = strlen(argv[2UL]);
		char *plaintext = (char*)malloc(sizeof(char) * plaintext_length);
		plaintext = argv[2UL];
		char *ciphertext = caesar_encipher(caesar_shift_key, plaintext_length, plaintext);
		fprintf(stdout, "<key:%d, plain_text:%s, cipher_text:%s>\n", caesar_shift_key, plaintext, ciphertext);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}