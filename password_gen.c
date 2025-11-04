#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SYMBOLS "!@#$%^&*()-_=+[]{};:,.<>?/"

int main() {
    int length, i;
    char password[256];  // maximum password length
    char charset[256] = ""; // all allowed characters

    // Combine all character sets
    sprintf(charset, "%s%s%s%s", LOWERCASE, UPPERCASE, DIGITS, SYMBOLS);

    printf("Enter password length (max 255): ");
    scanf("%d", &length);

    if (length <= 0 || length > 255) {
        printf("Invalid length.\n");
        return 1;
    }

    srand(time(NULL)); // seed random number generator

    for (i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        password[i] = charset[key];
    }
    password[length] = '\0'; // null-terminate

    printf("Generated password: %s\n", password);

    return 0;
}
