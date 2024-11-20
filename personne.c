#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_P 10

  struct personne
{
    int id;
   char nom[30];
   int age;
   struct Adresse
{
    char ville[20];
    char rue[20];
    char code_postal[20];
    
}adresse[3];

};
void creer(struct personne *p){
      printf("entrer le nom : ");
      scanf("%s",p->nom);
      //fgets(p->nom,sizeof(p->nom), stdin);

      printf("entrer l'age : ");
      scanf("%d",&p->age);

     printf("entrer la ville : ");
    scanf("%s", p->adresse[0].ville);

    printf("entrer la rue : ");
    scanf("%s", p->adresse[0].rue);

    printf("entrer le code postal : ");
    scanf("%s", p->adresse[0].code_postal);
}

void afficher(struct personne p)
{
    printf("\n-------------------------------------------------------------------------\n");
    printf("le nom : %s\n age : %d \nAdresse :\n ville : %s\n rue : %s\n code postal %s\n",
           p.nom, p.age, p.adresse[0].ville, p.adresse[0].rue, p.adresse[0].code_postal);
    printf("\n-------------------------------------------------------------------------\n");
}

void delete(){

}
void mise_a_jour(struct personne *p,int field ,char nv[]){
  switch (field)
  {
  case 1:
   strcpy(p->nom,nv);
    break;
  case 2:
  p->age=atoi(nv);
  break;
  case 3:
  strcpy(p->adresse->ville,nv);
  break;
  case 4:
  strcpy(p->adresse->rue,nv);
  break;
  case 5:
  strcpy(p->adresse->code_postal,nv);
  break;
  
  default:
  printf("Invalid field");
    break;
  }
    
}



int main(){
  struct personne p[MAX_P];
  int choix , n = 0;

  do
  {
    printf("pour creer entrer 1 pour afficher entrer 2 pour mise_a_jour entrer 3 pour  delete enter 4 pour exist entrer 0: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 0:
    break;

    case 1:
    if (n<MAX_P)
    {
            creer(&p[n]);
            n++;

    }else      printf("Maximum number of persons reached.\n");

    


      break;


    case 2:
    for (int i = 0; i < n; i++)
    {
              afficher(p[i]);

    }
    
      break;

      case 3:
     {
      int field;
      char nv[100];
      printf("poure mise a jour le : 1 nom , 2 age , 3 ville , 4 rue , 5 code postal :");
      scanf("%d",&field);

      printf("Entrer la nouvelle valeur : ");
      scanf("%s",nv);
       mise_a_jour(&p,field,nv);

    printf("pour creer entrer 1 pour afficher entrer 2 pour mise_a_jour entrer 3 pour  delete enter 4 pour exist entrer 0: ");
    scanf("%d", &choix);
    break;
     }
     case 4:
     {
      char nv[100];
      delete(&p,nv);
      break;
     }
    
    default:
    printf("\n Invalid \n");
      break;
    }
    
  } while (choix!=0);
  
 
}

