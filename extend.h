#ifndef EXTEND_H_INCLUDED
#define EXTEND_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct article {
        char nom_editeur [30];
        char adresse_editeur [30];
        char nom_journal [30];
        char redacteur [30];
        int numero_journal;
        char nom_auteur_de_larticle [30];
        char adresse_auteur[35];
        char article_titre [50];
    }arti;

    FILE *f;

    int number_of_article;

    struct article* article_remplisage();


    void read_article();

    void edit();

    void Delete();


    void main_menu();

#endif // EXTEND_H_INCLUDED
