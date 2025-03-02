#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_LENGTH 50

void generate_key(char *key, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;

    for (i = 0; i < len; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
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
            perror("Erreur lors de la création du fichier key.txt");
            return;
        }
        fprintf(key_file, "%s", key);
        fclose(key_file);
        printf("Clé générée et enregistrée dans key.txt.\n");
    } else {
        fclose(key_file);
        printf("Clé déjà présente dans key.txt.\n");
    }
}

void encrypt_decrypt_file(const char *filename, const char *key) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
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
    printf("Fichier '%s' traité.\n", filename);
}


int main() {
    int choice;
    char key[KEY_LENGTH + 1];

    check_and_create_key_file();

    FILE *key_file = fopen("key.txt", "r");
    if (key_file == NULL) {
        perror("Erreur lors de la lecture de key.txt");
        return 1;
    }
    fgets(key, KEY_LENGTH + 1, key_file);
    fclose(key_file);

    printf("Vault Maker - Menu\n");
    printf("1. Crypter le fichier passwords.txt\n");
    printf("2. Decrypter le fichier passwords.txt\n");
    printf("Choisissez une option (1 ou 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt_decrypt_file("passwords.txt", key);
            printf("Fichier crypté avec succès.\n");
            break;
        case 2:
            encrypt_decrypt_file("passwords.txt", key);
            printf("Fichier décrypté avec succès.\n");
            break;
        default:
            printf("Option invalide.\n");
    }

    return 0;
}

