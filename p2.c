#include<stdio.h>
#include<string.h>
struct Adresse{
    char rue[30];
    char ville[30];
    char codePostal[30];
};

struct personne
{
char* nom;
int age;
struct Adresse adresse;

   
};

void afficher(struct personne p) {
    printf("Nom: %s, Age: %d, Adresse: %s, %s, %s\n", 
            p.nom, p.age, p.adresse.rue, p.adresse.ville, p.adresse.codePostal);
}



int main(){
    struct personne p;
    

 

     char nom[] = "Soufyane";
    p.nom = nom;
    p.age = 21;

    strcpy(p.adresse.rue, "Nahda");
    strcpy(p.adresse.ville, "Boujaad");
    strcpy(p.adresse.codePostal, "25060");

    afficher(p);
    return 0;
}
