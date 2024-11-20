#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PERSONNES 100

struct Adresse
{
    char ville[20];
    char rue[20];
    char code_postal[20];
};

struct personne
{
    int id;
    char nom[30];
    int age;
    struct Adresse adresse[3];
};

void creer(struct personne *p, int id)
{
    p->id = id;
    printf("entrer le nom : ");
    scanf("%s", p->nom);

    printf("entrer l'age : ");
    scanf("%d", &p->age);

    printf("entrer la ville : ");
    scanf("%s", p->adresse[0].ville);

    printf("entrer la rue : ");
    scanf("%s", p->adresse[0].rue);

    printf("entrer le code postal : ");
    scanf("%s", p->adresse[0].code_postal);
}

void afficher(struct personne p)
{
    if (p.id != 0)
    {
      printf("\n___________________________________________________________________________\n");
        printf("ID: %d\nNom: %s\nAge: %d\nAdresse:\n  Ville: %s\n  Rue: %s\n  Code Postal: %s\n",
               p.id, p.nom, p.age, p.adresse[0].ville, p.adresse[0].rue, p.adresse[0].code_postal);
      printf("\n___________________________________________________________________________\n");
    }
}

void delete_personne(struct personne *p)
{
    p->id = 0;
    strcpy(p->nom, "");
    p->age = 0;

    for (int i = 0; i < 3; i++)
    {
        strcpy(p->adresse[i].ville, "");
        strcpy(p->adresse[i].rue, "");
        strcpy(p->adresse[i].code_postal, "");
    }

    printf("Personne deleted successfully.\n");
}

void mise_a_jour(struct personne *p, int field, char nv[])
{
    switch (field)
    {
    case 1:
        strcpy(p->nom, nv);
        break;
    case 2:
        p->age = atoi(nv);
        break;
    case 3:
        strcpy(p->adresse[0].ville, nv);
        break;
    case 4:
        strcpy(p->adresse[0].rue, nv);
        break;
    case 5:
        strcpy(p->adresse[0].code_postal, nv);
        break;
    default:
        printf("Invalid field\n");
        break;
    }
}

int main()
{
    struct personne personnes[MAX_PERSONNES] = {0};
    int choix, id = 0;

    do
    {
        printf("\n___________________________________________________________________________\n");

        printf("1. Creer\n2. Afficher\n3. Mise a jour\n4. Delete\n0. Exist\nVotre choix: ");
        scanf("%d", &choix);
        printf("\n___________________________________________________________________________\n");


        switch (choix)
        {
        case 0:
            break;
        case 1:
            if (id < MAX_PERSONNES)
            {
                creer(&personnes[id], id + 1);
                id++;
            }
            else
            {
                printf("Maximum number of persons reached.\n");
            }
            break;
        case 2:
            for (int i = 0; i < id; i++)
            {
                afficher(personnes[i]);
            }
            break;
        case 3:
        {
            int update_id, field;
            char nv[100];
            printf("Entrer l'ID de la personne pour mise a jour : ");
            scanf("%d", &update_id);
            if (update_id < 1 || update_id > id)
            {
                printf("Invalid ID\n");
                break;
            }
            printf("Mise a jour le : 1. Nom, 2. Age, 3. Ville, 4. Rue, 5. Code Postal: ");
            scanf("%d", &field);

            printf("Entrer la nouvelle valeur : ");
            scanf("%s", nv);
            mise_a_jour(&personnes[update_id - 1], field, nv);

            break;
        }
        case 4:
        {
            int delete_id;
            printf("Entrer l'ID de la personne à supprimer : ");
            scanf("%d", &delete_id);
            if (delete_id < 1 || delete_id > id)
            {
                printf("Invalid ID\n");
                break;
            }
            delete_personne(&personnes[delete_id - 1]);

            break;
        }
        default:
            printf("Choix invalide\n");
            break;
        }
    } while (choix != 0);

    return 0;
}
