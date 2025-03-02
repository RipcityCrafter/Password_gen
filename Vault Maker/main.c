#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_LENGTH 200

void generate_key(char *key, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:,.<>?";
    int i = 0;

    while (i < len) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
        i++;
    }
    key[len] = '\0';
}

void check_and_create_key_file() {
    FILE *key_file = fopen("key.txt", "r");
    if (key_file == NULL) {
        char key[KEY_LENGTH + 1];
        srand(time(NULL));
        generate_key(key, KEY_LENGTH);

        key_file = fopen("key.txt", "w");
        if (key_file == NULL) {
            perror("");
            return;
        }
        fprintf(key_file, "%s", key);
        fclose(key_file);
        printf("Key generated and saved in key.txt.\n");
    } else {
        fclose(key_file);
        printf("Key already present in key.txt.\n");
    }
}

void encrypt_decrypt_file(const char *filename, const char *key) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("");
        return;
    }

    char ch;
    size_t i = 0;
    while ((ch = fgetc(file)) != EOF) {
        ch ^= key[i % KEY_LENGTH];
        fseek(file, -1, SEEK_CUR);
        fputc(ch, file);
        i++;
    }
    fclose(file);
    printf("File '%s' processed.\n", filename);
}

int main() {
    int choice;
    char key[KEY_LENGTH + 1];

    check_and_create_key_file();

    FILE *key_file = fopen("key.txt", "r");
    if (key_file == NULL) {
        perror("");
        return 1;
    }
    fgets(key, KEY_LENGTH + 1, key_file);
    fclose(key_file);

    printf("Vault Maker - Menu\n");
    printf("1. Encrypt the file passwords.txt\n");
    printf("2. Decrypt the file passwords.txt\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt_decrypt_file("passwords.txt", key);
            printf("File encrypted successfully.\n");
            break;
        case 2:
            encrypt_decrypt_file("passwords.txt", key);
            printf("File decrypted successfully.\n");
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}
