#include "Trajet.h"
#include "Case.h"
#include "ListeChainee.h"
#include "TrajetComposee.h"
#include "Catalogue.h"
#include<unistd.h>
#include <cstring>
#include <iostream>
using namespace std;

void RestitutionDeTrajets(Catalogue * catalogue){
  cout<<"\t1:Lire que les trajets allant d'une meme ville de départ voulue"<<endl;
  cout<<"\t2:Lire que les trajets ayant une meme ville d'arrivée voulue"<<endl;
  cout<<"\t3:Lire que les trajets ayant une meme ville de départ et d'arrivée voulues"<<endl;
  cout<<"\t4:Lire tous les trajets"<<endl;
  cout<<"\t5:Lire que les trajets simples"<<endl;
  cout<<"\t6:Lire que les trajets composés"<<endl;
  cout << "Veuillez rentrer votre choix svp:";
  int choix;  // c'est la variable ou sera stocké le choix de l'utilisateur
  char sorte = 'T'; // c'est une variable qu'on utilise pour voir si on restitue tout les trajets :T, simples : C et composés : C
  char * depart =new char [sizeof(char)*25]; // on alloue de l'espace pour la ville de départ;
  char * arrivee =new char [sizeof(char)*25]; // on alloue de l'espace pour la ville d'arrivée;
  cin >> choix; // le choix de l'utilisateur est stocké ici
  while ( ((choix != 1) && (choix != 2) && (choix != 3)&& (choix != 4) && (choix != 5) && (choix != 6) ) || ( cin.fail() ) ) {  // après cette boucle on est sur que l'utilisateur a rentré un des 6 choix proposés
      cout << "il n'y a Aucune action relative à votre choix, veuillez choisir entre le choix '1 ou 2 ou 3 ou 4 ou 5 ou 6' :";
      cin.clear(); // elle remet les flags à zéro
      cin.ignore(100,'\n');
      cin >> choix; // on lui redemande de saisir un des choix disponibles
  }
  char * fileName =new char [sizeof(char)*25];
  cout<< "Entrez le nom du fichier  :"; // on alloue de l'espace pour le nom du fichier;
  cin >> fileName; // l'utilisateur rentre le nom du fichier
  if (choix==1){  // l'utilisateur choisit la restitution avec une ville de départ voulue
     cout << " Veuillez rentrer la ville de départ à rechercher dans le fichier  :" ;
     cin >> depart; // l'utilisateur rentre la ville de départ voulue
     catalogue->LectureTrajet(fileName,choix,depart);
  }
  else if (choix==2){  //l'utilisateur choisit la restitution avec une ville d'arrivée voulue
     cout << " Veuillez rentrer la ville d'arrivée à rechercher dans le fichier" <<endl;
     cin >> arrivee; // l'utilisateur rentre la ville d'arrivée voulue
     catalogue->LectureTrajet(fileName,choix,arrivee);
  }
  else if (choix == 3){ //l'utilisateur choisit la restitution avec une ville d'arrivée et de départ voulues
    cout << " Veuillez rentrer la ville de départ à rechercher dans le fichier" <<endl;
    cin >> depart;// l'utilisateur rentre la ville dde départ voulue
    cout << " Veuillez rentrer la ville d'arrivée à rechercher dans le fichier" <<endl;
    cin >> arrivee;// l'utilisateur rentre la ville d'arrivée voulue
    catalogue->LectureTrajet(fileName,choix,depart,arrivee);
  }
  else if (choix ==4){ //l'utilisateur choisit la restitution de tout les trajets disponibles
    sorte = 'T'; // ici on dit que 'T' pour 'Tout'
    catalogue->LectureTrajet(fileName,sorte);
  }
  else if (choix==5){ //l'utilisateur choisit la restitution que des trajets simples disponibles
     sorte = 'S'; // ici on dit 'S' pour 'Simple'
     catalogue->LectureTrajet(fileName,sorte);
  }
  else if (choix ==6){ //l'utilisateur choisit la restitution que des trajets composées disponibles
     sorte  = 'C';  // ici on dit 'C' pour 'Composée'
     catalogue->LectureTrajet(fileName,sorte);
  }
  delete[] depart; // On libère l'espace MÉMOIRE POUR LE DÉPART
  delete[] arrivee; // On libère l'espace MÉMOIRE POUR L'arrivée
  delete[] fileName; // On libère l'espace MÉMOIRE POUR le nom du fichier
}


void SauvegardeDeTrajets(Catalogue * catalogue)
{
    cout<<"\t1:sauvegarder tous les trajets"<<endl;
    cout<<"\t2:sauvegarder les trajets simples"<<endl;
    cout<<"\t3:sauvegarder les trajets composés"<<endl;
    cout<<"\t4:sauvegarder tous les trajets allant d'une meme ville de départ"<<endl;
    cout<<"\t5:sauvegarder tous les trajets avec la meme ville d'arrivee"<<endl;
    cout<<"\t6:sauvegarder les trajets selon une ville de depart et celle d'arrivee "<<endl;
    cout << "Veuillez rentrer votre choix svp:";
    int choix;
    cin >> choix;
    while ( ( (choix != 1) && (choix != 2) && (choix != 3) && (choix != 4) && (choix != 5) && (choix != 6) ) || ( cin.fail() ) ) {  // après cette boucle on est sur que l'utilisateur a rentré un des 6 choix proposés
        cout << "il n'y a Aucune action relative à votre choix, veuillez choisir entre le choix '1 ou 2 ou 3 ou 4 ou 5 ou 6' :";
        cin.clear(); // elle remet les flags à zéro
        cin.ignore(100,'\n');
        cin >> choix; // on lui redemande de rerentrer un des choix disponibles
    }
    char * fileName=new char [sizeof(char)*25]; // on alloue dynamiquement de l'espace mémoire pour le nom du fichier
    cout<< "Entrez le nom du fichier dans lequel vous voulez sauvegarder vos trajets :";
    cin >> fileName; // l'utilisateur saisit le nom du fichier
    if(choix ==1){ // ici l'utilisateur choisit de sauvegarder tout les trajets du catalogue
      catalogue->SauvegarderCatalogueSimplement(fileName);
    }else if(choix ==2){ // ici l'utilisateur choisit de sauvegarder tout les trajets simples du catalogue
      catalogue->SauvegarderLesTrajetsSimples(fileName);
    }else if(choix ==3){ // ici l'utilisateur choisit de sauvegarder tout les trajets composés du catalogue
      catalogue->SauvegarderLesTrajetsComposes(fileName);
    }else if(choix ==4){ // ici l'utilisateur choisit de sauvegarder tout les trajets allant d'une ville de départ souhaitée du catalogue
      catalogue->SauvegarderLesTrajetsAvecDepart(fileName);
    }else if(choix ==5){ // ici l'utilisateur choisit de sauvegarder tout les trajets allant d'une ville d'arrivée souhaitée du catalogue
      catalogue->SauvegarderLesTrajetsAvecArrivee(fileName);
    }else{ // // ici l'utilisateur choisit de sauvegarder tout les trajets allant d'une ville de départ  et d'arrivée souhaitées du catalogue
      catalogue->SauvegarderLesTrajetsAvecDepartEtArrivee(fileName);
    }
    delete[] fileName; // On libère l'espace MÉMOIRE POUR le nom du fichier
}

void RechercherParcours(Catalogue * catalogue)
// Algorithme : on demande à l'utilisateur la ville de départ et d'arrivée recherchées et puis on affiche l'ensemble des trajets qu'on pourra lui fournir
// que ce soit des trajets non combinées ou des trajets combinées entre eux
{
  cout << "Entrez votre ville de départ svp :";
  char * Depart = new char[sizeof(char)*25];
  cin >> Depart;      // ici on stocke la ville de départ que l'utilisateur veut rechercher ;
  cout << "Entrez votre ville d'arrivée svp :";
  char * Arrivee = new char[sizeof(char)*25];
  cin >> Arrivee;    // ici on stocke la ville de départ que l'utilisateur veut rechercher ;
  catalogue->ChercherTrajetSimplement(Depart,Arrivee); // on affiche les trajets non combinées ici pour le voyage voulu
  cout << "Voici les trajets selon la Recherche Avancée" <<endl;
  catalogue->ChercherTrajetAvancee(Depart,Arrivee);  // on affiche les trajets combinées du catalogue entre eux pour le voyage voulu
  delete[] Arrivee; // on libère l'espace mémoire pour l'arrivée
  delete[] Depart; // on libère l'espace mémoire pour le départ
}

void AjoutTrajet(Catalogue * catalogue){
  // Algorithme : après quelques demandes à l'utilisateur on ajoute un trajet qu'il soit composée ou simple c'est le choix de l'utilisateur
  int choix;
  cout << "Voulez-vous ajouter :"<<endl;  // on demande à l'utilisateur quel sorte de trajet il veut ajouter
  cout << "\t1: Un trajet simple "<< endl;
  cout << "\t2: Un trajet composé "<< endl;
  cout <<"Veuillez rentrer votre choix svp :";
  cin >> choix; // l'utilisateur rentre son choix
  while ( ( (choix != 1) && (choix != 2) ) || ( cin.fail() ) ) {  // après cette boucle on est sur que l'utilisateur a rentré un des 2 choix proposés
      cout << "il n'y a Aucune action relative à votre choix, veuillez choisir entre le choix '1 ou 2' :";
      cin.clear(); // elle remet les flags à zéro
      cin.ignore(100,'\n');
      cin >> choix;
  }
  if ( choix == 1){ // si l'utilisateur choisit un trajet simple
     cout << "vous avez choisi d'ajouter un Trajet S."<< endl;
     char * Depart = new char[sizeof(char)*25]; // ON ALLOUE UN ESPACE MÉMOIRE POUR LE DÉPART
     cout << "Entrez votre ville de départ svp :"; // on lui demande de rentrer sa ville de départ
     cin >> Depart;
     char * Arrivee = new char[sizeof(char)*25]; // ON ALLOUE UN ESPACE MÉMOIRE POUR L'ARRIVÉE
     cout << "Entrez votre ville d'arrivée svp :"; // on lui demande de rentrer sa ville d'arrivée
     cin >> Arrivee;
     char * MoyenT = new char[sizeof(char)*25]; // ON ALLOUE UN ESPACE MÉMOIRE POUR LE MOYEN DE TRANSPORT
     cout << "Entrez le moyen de transport Souhaité svp :"; // on lui demande de rentrer son moyen de transport
     cin >> MoyenT;
     TrajetSimple * ts = new TrajetSimple(Depart,Arrivee,MoyenT);
     catalogue->AjouterTrajet(ts);
     cout << "Merci ! Le Trajet Simple a bien été ajouté au catalogue"<< endl;
     delete[] Depart; // On libère l'espace MÉMOIRE POUR LE DÉPART
     delete[] Arrivee; // On libère l'espace MÉMOIRE POUR L'ARRIVÉE
     delete[] MoyenT; // On libère l'espace MÉMOIRE POUR LE MOYEN DE TRANSPORT
  }
  else{ // ici on est sur que l'utilisateur a choisi un trajet composé
    cout << "vous avez choisi d'ajouter un Trajet C."<< endl;
    int nbTrajet;
    cout << " votre trajet Composé est composé de combien de trajets simples ? "; // on lui demande combien de trajets simples compose son trajet composé
    cin >> nbTrajet;
    while (nbTrajet < 2){ // ici on s'assure que le nombre de trajets qu'il veux rentrer est forcément plus que 2
       cout << "il est impossible de faire un trajet composés contenant "<< nbTrajet <<endl;
       cout << "Veuillez donner un entier supérieur à 1 SVP: ";
       cin >> nbTrajet;
    }
    char * Depart = new char[sizeof(char)*25];
    cout << "Entrez votre ville de départ initial svp :"; // on lui demande de rentrer sa ville de départ initiale
    cin >> Depart;
    char * Arrivee = new char[sizeof(char)*25];
    cout << "Entrez votre ville d'arrivée finale svp :"; // on lui demande de rentrer sa ville d'arrivée finale
    cin >> Arrivee;
    char * tmp = Depart;
    ListeChainee * liste = new ListeChainee();
    char * depart2 = new char[sizeof(char)*25]; // ON ALLOUE UN ESPACE MÉMOIRE POUR LES DÉPARTS INTÉRMÉDIAIRES
    char * arrivee2 = new char[sizeof(char)*25]; // ON ALLOUE UN ESPACE MÉMOIRE POUR LES ARRIVÉES INTÉRMÉDIAIRES
    char * moyenT = new char[sizeof(char)*25]; // ON ALLOUE UN ESPACE MÉMOIRE POUR LES MOYENS DE TRANSPORTS INTÉRMÉDIAIRES
    for (int i =0; i<nbTrajet ; i++){  // ici on prend tout les trajets simples composant le trajet composé
       cout << "Veuillez rentrer svp le départ du "<< i+1 << "er/ème sous trajet : "; // on lui demande le départ du i+1 eme sous trajet
       cin >> depart2;
       while (strcmp(depart2,tmp) != 0){ // ici on regarde si le départ est bien cohérent
           if (i==0){// ici on regarde si le départ du premier sous trajet est le meme que celui du départ initial
              cout << "Impossible, le départ du premier sous trajet doit etre le meme que le départ Initial svp"<< endl;
              cout << " veuillez rerentrer le départ du premier sous trajet svp : ";
            }else{ // ici on regarde si le départ du i+1 sous trajet est le meme que l'arrivée du i ème sous trajet
              cout << "Impossible le départ du "<< i+1 << "er/ème sous trajet doit etre égale à l'arrivée du  "<< i <<" er/eme sous trajet"<<endl;
              cout << " veuillez rerentrer le départ du "<<i+1<<"er/ème sous trajet svp : ";
            }
            cin >> depart2;
       }
       cout << "Veuillez rentrer svp l'arrivée du "<< i+1 << "er/ème sous trajet : "; // on lui demande l'arrivée du i+1 eme sous trajet
       cin >> arrivee2;
       if (i == nbTrajet-1){
          while( (strcmp(arrivee2,Arrivee)!=0) ){ // ici on regarde si l'arrivée du dernier trajet est la meme que celle de l'arrivée finale
              cout << "Impossible, l'arrivée du dernier sous trajet doit etre égale à l'arrivée Initiale svp"<< endl;
              cout << " veuillez rerentrer l'arrivée du dernier sous trajet svp : ";
              cin >> arrivee2;
          }
       }
       cout << "Veuillez rentrer le moyen de transport du "<< i+1<<"er/ème sous trajet svp :";// ici on demande le moyen de transport pour le i+1 eme sous trajet
       cin >> moyenT;
       TrajetSimple *ts = new TrajetSimple(depart2,arrivee2,moyenT); // ici on insère le sous trajet donné qui est valide forcément
       liste->Inserer(ts);
       tmp = arrivee2;
  }
    TrajetComposee * trajet = new TrajetComposee(Depart,Arrivee,liste); // ici on ajoute le trajet composé au catalogue
    catalogue->AjouterTrajet(trajet);
    cout << "Merci ! Le Trajet Composé a bien été ajouté au catalogue"<< endl;
    delete[] Depart; // On libère l'espace MÉMOIRE POUR LE DÉPART INITIALE
    delete[] Arrivee; // On libère l'espace MEMOIRE POUR L'ARRIVÉE FINALE
    delete[] depart2;  // On libère l'espace MEMOIRE POUR LES DÉPARTS INTERMÉDIAIRES
    delete[] arrivee2; // On libère l'espace MEMOIRE POUR LES ARRIVÉES INTERMÉDIAIRES
    delete[] moyenT;  // On libère l'espace MEMOIRE POUR LES MOYENS DE TRANSPORTS INTERMÉDIAIRES
  }

}

int main()
// Algorithme : on fait défiler un menu à l'utilisateur pour lequel il doit choisir un des choix proposés et on fait appel aux fonctions qui éxécutent ces choix
{
  unsigned int microsecond = 30000;
  Catalogue * catalogue1 =  new Catalogue();
  cout << "\t\tBienvenue sur votre assistant de Voyage !" << endl;
  usleep(3 * microsecond);//sleeps for 1 second approximatively
  while(1) {
    cout << "Menu:" <<endl;
    usleep(1.0 * microsecond);//sleeps for 1 second
    cout << "\t1: Ajouter un Trajet"<< endl;
    usleep(1.0 * microsecond);//sleeps for 1 second
    cout <<"\t2: Afficher les Trajets du Catalogue"<< endl;
    usleep(1.0 * microsecond);//sleeps for 1 second
    cout <<"\t3: Rechercher un Parcours"<< endl;
    usleep(1.0 * microsecond);//sleeps for 1 second
    cout <<"\t4: Sauvegarder les Trajets"<< endl;
    usleep(1.0 * microsecond);//sleeps for 1 second
    cout <<"\t5: Restituer les Trajets"<< endl;
    usleep(1.0 * microsecond);//sleeps for 1 second
    cout <<"\t0: Quitter" << endl;
    usleep(1.0 * microsecond);//sleeps for 1 second
    cout <<"Veuillez rentrer votre choix svp :";
    int choix;
    cin >> choix;
    while (  ( cin.fail() ) ) {  // après cette boucle on est sur que l'utilisateur a rentré un entier
        cout << "il n'y a Aucune action relative à votre choix, veuillez choisir entre le choix '0 ou 1 ou 2 ou 3 ou 4 ou 5' :";
        cin.clear(); // elle remet les flags à zéro
        cin.ignore(100,'\n');
        cin >> choix;
    }
    switch(choix)
    {
        case 0:
              goto fin;
        case 1: // ici on veut ajouter un trajet
              AjoutTrajet(catalogue1);
              break;
        case 2: // ici on veut afficher le catalogue
              catalogue1->AfficherCatalogue();
              break;
        case 3: // ici on veut rechercher le catalogue
              RechercherParcours(catalogue1);
              break;
        case 4 : // ici on veut sauvegarder les trajetSuivants
              SauvegardeDeTrajets(catalogue1);
              break;
        case 5 : // ici on veut restituer les trajets
              RestitutionDeTrajets(catalogue1);
              break;
        default: // l'utilisateur a rentré une saisie non valide
          cout << "choix incorrect, veuillez choisir parmi les choix disponibles svp" << endl;
          continue ; // revenir au menu
    }
  }
  fin:
    cout << "Merci ! Au revoir" << endl;
  delete catalogue1; // on libère l'espace mémoire prix par le catalogue
  return 0;
}
