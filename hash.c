#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// On defini les tailles des hashs
#define MD5_LENGTH 32
#define SHA1_LENGTH 40
#define SHA224_LENGTH 56 // Nouvelle constante pour SHA-224
#define SHA256_LENGTH 64
#define SHA384_LENGTH 96 // Nouvelle constante pour SHA-384
#define SHA512_LENGTH 128

// Fonction pour calculer la longueur d'une chaîne de caractères
int calculerLongueurChaine(char *chaine) {
    int longueur = 0;
    while (chaine[longueur] != '\0') {
        longueur++;
    }
    return longueur;
}

// Fonction pour determiner le type de hachage et le renvoyer
void determinerType(int hash_length) {
    switch (hash_length) {
        case MD5_LENGTH:
            printf("Le hash est de type MD5.\n");
            break;
        case SHA1_LENGTH:
            printf("Le hash est de type SHA-1.\n");
            break;
        case SHA224_LENGTH: 
            printf("Le hash est de type SHA-224.\n");
            break;
        case SHA256_LENGTH:
            printf("Le hash est de type SHA-256.\n");
            break;
        case SHA384_LENGTH: 
            printf("Le hash est de type SHA-384.\n");
            break;
        case SHA512_LENGTH:
            printf("Le hash est de type SHA-512.\n");
            break;
        default:
            printf("Type de hash indetermine.\n");
            break;
    }
}

// Fonction pour determiner le type de hachage et mesurer le temps d'execution
void determinerTypeEtMesurerTemps(char *hash) {
    struct timespec debut, fin;
    double tempsExecution = 0.0;
    int hash_length = calculerLongueurChaine(hash);

    // Debut de la mesure du temps
    clock_gettime(CLOCK_MONOTONIC, &debut);

    // Determination du type de hachage
    determinerType(hash_length);

    // Fin de la mesure du temps
    clock_gettime(CLOCK_MONOTONIC, &fin);
    tempsExecution = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;

    printf("Temps d'execution pour determiner le type de hachage : %.10lf secondes\n", tempsExecution);
}

// Fonction principale + gestion des arguments
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage : %s [-f | -h] <hash>\n", argv[0]);
        return 1;
    }

    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        // Appel de la fonction pour determiner le type de hachage et mesurer le temps d'execution
        determinerTypeEtMesurerTemps(argv[2]);
    } else if (argv[1][0] == '-' && argv[1][1] == 'f') {
        // Lire le fichier et traiter chaque hachage
        FILE *fichier = fopen(argv[2], "r");
        // Gestion des erreurs
        if (fichier == NULL) {
            printf("Erreur : Impossible d'ouvrir le fichier %s\n", argv[2]);
            return 1;
        }

        char hash[129]; // Pour stocker le hachage (128 caractères + 1 pour le caractère de fin de chaîne)
        while (fscanf(fichier, "%128[^;];", hash) == 1) {
            printf("Hachage lu depuis le fichier : %s\n", hash);
            // Appel de la fonction pour determiner le type de hachage et mesurer le temps d'execution
            determinerTypeEtMesurerTemps(hash);
        }

        fclose(fichier);
    } else {
        // Gestion des erreurs
        printf("Option non reconnue : %s\n", argv[1]);
        return 1;
    }
    return 0;
}
