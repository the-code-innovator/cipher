#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char get_translated_char(char key, char plaintext) {
	return (char)(((tolower(key) + tolower(plaintext) - 194) % 26) + 97);
}

char* get_translation_key(size_t key_length, char *key, size_t plaintext_length, char *plaintext) {
	char *translation_key = (char*)malloc(sizeof(char) * (key_length + plaintext_length));
	strcpy(translation_key, key);
	strcat(translation_key, plaintext);
	translation_key[plaintext_length] = '\0';
	return translation_key;
}

char* vernam_encipher(size_t key_length, char *key, size_t plaintext_length, char *plaintext) {
	char *translation_key = get_translation_key(key_length, key, plaintext_length, plaintext);
	char *ciphertext = (char*)malloc(sizeof(char) * strlen(translation_key));
	for (size_t iterator = 0UL; translation_key[iterator] != '\0'; iterator += 1UL) {
		ciphertext[iterator] = get_translated_char(translation_key[iterator], plaintext[iterator]);
	}
	return ciphertext;
}

int main(int argc, char *argv[]) {
	if (argc == 3UL) {
		size_t key_length = strlen(argv[1UL]);
		size_t plaintext_length = strlen(argv[2UL]);
		char *key = (char*)malloc(sizeof(char) * key_length);
		key = argv[1UL];
		char *plaintext = (char*)malloc(sizeof(char) * plaintext_length);
		plaintext = argv[2UL];
		char *translation_key = get_translation_key(key_length, key, plaintext_length, plaintext);
		char* ciphertext = vernam_encipher(key_length, key, plaintext_length, plaintext);
		fprintf(stdout, "<key:%s, plain_text:%s, translation_key:%s, cipher_text:%s>\n", key, plaintext, translation_key, ciphertext);
	} else {
		fprintf(stderr, "err: insufficient arguments!\n");
	}
	return 0;
}