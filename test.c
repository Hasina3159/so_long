/*#include <stdio.h>
#include <stdlib.h>

void printBinary(int num) {
    int size = sizeof(num) * 8; // Nombre de bits dans un int
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1); // Utilisation des opérateurs de décalage et de masque
        if ((i) % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

// Fonction pour afficher la représentation binaire d'un unsigned int
void printUnsignedBinary(unsigned int num) {
    int size = sizeof(num) * 8; // Nombre de bits dans un unsigned int
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1); // Utilisation des opérateurs de décalage et de masque
        if ((i) % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int signedInt;
    unsigned int unsignedInt;

    if (argc != 2)
        return (0);

    unsignedInt = atoi(argv[1]);
    signedInt = (int) atoi(argv[1]);
    printf("Représentation binaire de signedInt: \t");
    printBinary(signedInt);
    printf("\t%d\n", signedInt);

    printf("Représentation binaire de unsignedInt: \t");
    printUnsignedBinary(unsignedInt);
    printf("\t%d\n", unsignedInt);

    return 0;
}*/