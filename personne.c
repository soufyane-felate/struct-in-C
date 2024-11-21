#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PERSONNES 100
// Create struct Adresse (for address details)
struct Adresse
{
    char ville[20];       
    char rue[20];        
    char code_postal[20]; 
};

// Create struct Personne (for person details)
struct personne
{
    int id;              
    char nom[30];        
    int age;             
    struct Adresse adresse[3];
};

// Function to create and input person information
void create(struct personne *p, int id)
{
    p->id = id;
    printf("Entrer le nom : ");
    scanf("%s", p->nom);

    printf("Entrer l'age : ");
    scanf("%d", &p->age);

    printf("Entrer la ville : ");
    scanf("%s", p->adresse[0].ville);

    printf("Entrer la rue : ");
    scanf("%s", p->adresse[0].rue);

    printf("Entrer le code postal : ");
    scanf("%s", p->adresse[0].code_postal);
}

// Function to display person information
void show(struct personne p)
{
    if (p.id != 0)
    {
        printf("\n___________________________________________________________________________\n");
        printf("ID: %d\nNom: %s\nAge: %d\nAdresse:\n  Ville: %s\n  Rue: %s\n  Code Postal: %s\n",
               p.id, p.nom, p.age, p.adresse[0].ville, p.adresse[0].rue, p.adresse[0].code_postal);
        printf("\n___________________________________________________________________________\n");
    }
}

// Function to delete a person (reset all fields)
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

// Function to update a person's information
void update(struct personne *p, int field, char nv[])
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

// Main function to test the above functions
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
       printf("Program finished.");
            break;
        case 1:
            if (id < MAX_PERSONNES)
            {
                // Create a new person
                create(&personnes[id], id + 1); 
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
             // Show information of all persons

                show(personnes[i]); 
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
            // Update specific field for the person
            update(&personnes[update_id - 1], field, nv); 

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
             // Delete the person
            delete_personne(&personnes[delete_id - 1]);

            break;
        }
        default:
        // Invalid choice
            printf("Choix invalide\n"); 
            break;
        }
    } while (choix != 0);

    return 0;
}
