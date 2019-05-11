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
	if (argc == 2UL) {
		size_t ciphertext_length = strlen(argv[1]);
		char *ciphertext = (char*)malloc(sizeof(char) * ciphertext_length);
		ciphertext = argv[1];
		fprintf(stdout, "cipher_text:%s\n", ciphertext);
		for (int decipher_key = 0; decipher_key < 26; decipher_key++) {
			char *deciphered_text = caesar_encipher(decipher_key, ciphertext_length, ciphertext);
			fprintf(stdout, "<key:%d, deciphered_text:%s>\n", decipher_key, deciphered_text);
		}
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}