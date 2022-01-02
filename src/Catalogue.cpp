/*************************************************************************
                            Catalogue  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <ostream>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue :: LectureTrajet(char * nomDuFichier,char sorte)
// Algorithme : on ouvre le canal du nom de fichier et on lit les trajets dedans et on selectionne les trajets souhaités soit: tout les trajets, que les trajets simples ou que les trajets composés
//
{
   ifstream canal;
   canal.open(nomDuFichier); // ouverture du canal du nombre de fichiers
   int i =0;   // ici c'est pour voir si on a ajouter des trajets ou pas
   if (canal){
     string type;
     string depart;
     string  arrivee;
     string moyenTransport;
     while (canal.peek() != EOF){ // tant que on est pas arrivé à la fin du fichier on rentre dans la boucle
       getline(canal,type,':'); // on prend le type et on le stocke dans la chaine de caractères type
       if (type=="TS1"){
         getline(canal,depart,'$'); // on prend le depart et on le stocke dans la chaine de caractères depart
         getline(canal,arrivee,'$'); // on prend l'arrivee et on le stocke dans la chaine de caractères arrivee
         getline(canal,moyenTransport); // on prend le moyen de transport et on le stocke dans la chaine de caractères moyenTransport
         if ( (sorte == 'T') ||(sorte == 'S') ){ // ici on ajoute le trajet simple si le sorte est tout ou simple
            i=1;
            cout << "Un trajet simple est en ajout dans le catalogue depuis le fichier" << endl;
            Trajet * trajet = new TrajetSimple( depart.c_str(),arrivee.c_str(),moyenTransport.c_str() ); // on initialise le trajet
            AjouterTrajet(trajet); // on ajoute le trajet
         }
       }
       else {
         getline(canal,depart,'$'); // on prend le depart et on le stocke dans la chaine de caractères depart
         getline(canal,arrivee,'|'); // on prend l'arrivee et on le stocke dans la chaine de caractères arrivee
         ListeChainee * liste = new ListeChainee();
         while(canal.peek() != '\n'){  // ici on termine la ligne des rajets composées
           string depTMP;
           string arrTMP;
           string mTransTMP;
           getline(canal,depTMP,'$');// on prend le depart temporaire et on le stocke dans la chaine de caractères depTMP
           getline(canal,arrTMP,'$'); // on prend l'arrivée temporaire et on le stocke dans la chaine de caractères arrTMP
           getline(canal,mTransTMP,'|'); // on prend le moyen de transport temporaire et on le stocke dans la chaine de caractères mTransTMP
           Trajet * trajetTMP = new TrajetSimple(depTMP.c_str(),arrTMP.c_str(),mTransTMP.c_str());
           liste->Inserer(trajetTMP); // on insère le trajet temporaire
         }
           canal.get();
           if ( (sorte == 'T') ||(sorte == 'C') ){ // on ajoute le trajet si le sorte est soit composée soit tout
             i=1;
             cout << "Un trajet Composée est en ajout dans le catalogue depuis le fichier" << endl;
             Trajet * trajet = new TrajetComposee(depart.c_str(),arrivee.c_str(),liste);
             AjouterTrajet(trajet);
           }
       }
     }
     if (i==0){ // ici on est sur que le fichier est vide est donc on a rien ajouté
       cout << "Aucun trajet n'a été lu et ajouté au catalogue avec le filtre voulu" << endl;
     }
   }
   else{ // ici c'est il y'a une lecture de fichier fausse
     cerr << "Erreur de lecture dans le fichier" << endl;
   }
}

void Catalogue :: LectureTrajet(char * nomDuFichier,int choix ,char * ville, char * villeSupplementaire)
// Algorithme : on ouvre le canal du nom de fichier et on lit les trajets dedans et on selectionne les trajets souhaités soit en fonction de la ville de départ, d'arrivée ou les 2.
//
{
   ifstream canal;
   int i=0; // ici c'est pour voir si on a ajouter des trajets ou pas
   canal.open(nomDuFichier); // ouverture du canal du nombre de fichiers
   if (canal){
     string type;
     string depart;
     string  arrivee;
     string moyenTransport;
     while (canal.peek() != EOF){ // tant que on est pas arrivé à la fin du fichier on rentre dans la boucle
       getline(canal,type,':'); // on prend le type et on le stocke dans la chaine de caractères type
       if (type=="TS1"){
         getline(canal,depart,'$'); // on prend le depart et on le stocke dans la chaine de caractères depart
         getline(canal,arrivee,'$'); // on prend l'arrivée et on le stocke dans la chaine de caractères arrivée
         getline(canal,moyenTransport); // on prend le moyen de transport et on le stocke dans la chaine de caractères moyenTransport
         if ( ( (choix == 1) && (strcmp(ville,depart.c_str())==0) ) || ( (choix == 2) && (strcmp(ville,arrivee.c_str())==0) )|| ( (choix == 3) && (strcmp(ville,depart.c_str())==0) && (strcmp(villeSupplementaire,arrivee.c_str())==0))) { // ici on dit quand on veut ajouter le trajet simple
            i=1;
            cout << "Un trajet simple est en ajout dans le catalogue depuis le fichier" << endl;
            Trajet * trajet = new TrajetSimple( depart.c_str(),arrivee.c_str(),moyenTransport.c_str() ); // un trajet simple pour l'ajouter
            AjouterTrajet(trajet);
         }
       }
       else {
         getline(canal,depart,'$'); // on prend le depart et on le stocke dans la chaine de caractères depart
         getline(canal,arrivee,'|'); // on prend l'arrivée et on le stocke dans la chaine de caractères arrivée
         ListeChainee * liste = new ListeChainee();
         while(canal.peek() != '\n'){ // ici tant que on ne croise pas la fin de la ligne
           string depTMP;
           string arrTMP;
           string mTransTMP;
           getline(canal,depTMP,'$'); // on prend le depart temporaire et on le stocke dans la chaine de caractères depTMP
           getline(canal,arrTMP,'$'); // on prend l'arrivée temporaire et on le stocke dans la chaine de caractères arrTMP
           getline(canal,mTransTMP,'|'); // on prend le moyen de transport temporaire et on le stocke dans la chaine de caractères mTransTMP
           Trajet * trajetTMP = new TrajetSimple(depTMP.c_str(),arrTMP.c_str(),mTransTMP.c_str());
           liste->Inserer(trajetTMP);
         }
           canal.get();
           if ( ( (choix == 1) && (strcmp(ville,depart.c_str())==0) ) || ( (choix == 2) && (strcmp(ville,arrivee.c_str())==0) )|| ( (choix == 3) && (strcmp(ville,depart.c_str())==0) && (strcmp(villeSupplementaire,arrivee.c_str())==0))) { // ici on dit quand on veut ajouter le trajet composée
              i=1;
              cout << "Un trajet Composée est en ajout dans le catalogue depuis le fichier" << endl;
              Trajet * trajet = new TrajetComposee(depart.c_str(),arrivee.c_str(),liste);
              AjouterTrajet(trajet); // on ajoute le trajet
           }
       }
     }
     if (i==0){ // ici on est sur que le fichier est vide est donc on a rien ajouté
       cout << "Aucun trajet n'a été lu et ajouté au catalogue avec le filtre voulu" << endl;
     }
   }
   else{ // ici c'est il y'a une lecture de fichier fausse
     cerr << "Erreur de lecture dans le fichier" << endl;
   }
}

void Catalogue :: SauvegarderLesTrajetsAvecDepartEtArrivee(char * nomDuFichier)
// Algorithme : ici on sauvegarde tout les trajets présent dans le catalogue, qui ont une ville d'arrivée et de départ qui seront renseignés par l'utilisateur, dans le fichier passé en paramètre
//
{
  if (listeTrajet->EstVide()){ // on regarde si il n'y a aucun trajets dans le catalogue
    cout << "Il n'y a aucun trajet dans le catalogue pour le sauvegarder dans le fichier, veuillez rajouter des trajets et réessayer svp " <<endl;
  }
  else{  // dans le catalogue on est sur qu'il y'a au moins un trajet
     cout << "Entrez votre ville de départ svp :";
     char * Depart = new char[sizeof(char)*25]; // on alloue dynamiquement l'espace mémoire pour le départ
     cin >> Depart;        // l'utilisateur rentre la ville de départ
     cout << "Entrez votre ville d'arrivée svp :";
     char * Arrivee = new char[sizeof(char)*25]; // on alloue dynamiquement l'espace mémoire pour l'arrivée
     cin >> Arrivee; //l'utilisateur rentre la ville d'arrivée
     int i=0; // ici pour voir si on affiche le message de aucun trajet n'a été sauvegardé ou pas
     Case * tmp=listeTrajet->GetFirstCase();
     ofstream os(nomDuFichier); // on ouvre le canal
     while(tmp!=nullptr){ // tant qu'on a des trajets dans le catalogue
        if ( (strcmp(tmp->GetTrajetActuel()->GetArrivee(),Arrivee)==0) && (strcmp(tmp->GetTrajetActuel()->GetDepart(),Depart)==0) ){ // si le trajet a la meme ville de départ et arrivée que celles voulues
           i=1;
            if(tmp->GetTrajetActuel()->EstUnTrajetSimple()){
                os<<"TS1:";
                tmp->GetTrajetActuel()->Sauvegarder(os); // on le sauvegarde
            }else{
                tmp->GetTrajetActuel()->Sauvegarder(os);  // on  sauvegarde le trajet
            }
            os<<'\n';
        }
        tmp=tmp->GetNextCase(); // on passe au trajet suivant
    }
    delete[] Depart; // on libère l'espace mémoire donné au départ
    delete[] Arrivee; // on libère l'espace mémoire donné a l'arrivée
    os.close(); // on ferme le canal ouvert
    if (i==0){  // ici on est sur qu'on a sauvegardé aucun trajet avec la meme ville d'arrivée et de départ voulues.
      cout<< "Votre catalogue ne contient aucun trajet avec ce nom de ville d'arrivée et ce nom de ville de départ" << endl;
    }
  }
}


void Catalogue :: SauvegarderLesTrajetsAvecArrivee(char * nomDuFichier)
// Algorithme : ici on sauvegarde tout les trajets présent dans le catalogue, qui ont une ville d'arrivée  qui sera renseigné par l'utilisateur, dans le fichier passé en paramètre
//
{
  if (listeTrajet->EstVide()){ // on regarde si il n'y a aucun trajets dans le catalogue
    cout << "Il n'y a aucun trajet dans le catalogue pour le sauvegarder dans le fichier, veuillez rajouter des trajets et réessayer svp " <<endl;
  }
  else{   // dans le catalogue on est sur qu'il y'a au moins un trajet
     cout << "Entrez votre ville d'arrivée svp :";
     char * Arrivee = new char[sizeof(char)*25];  // on alloue dynamiquement l'espace mémoire pour l'arrivée
     cin >> Arrivee;  // l'utilisateur renseigne l'arrivée
     Case * tmp=listeTrajet->GetFirstCase();
     int i=0; // ici pour voir si on affiche le message de aucun trajet n'a été sauvegardé ou pas
     ofstream os(nomDuFichier);  // on ouvre le canal pour écrire les trajets
     while(tmp!=nullptr){ // tant que il y'a des trajets
        if(strcmp(tmp->GetTrajetActuel()->GetArrivee(),Arrivee)==0){ // on regarde si le trajet a la meme arrivée que celle voulue
            i=1;
            if(tmp->GetTrajetActuel()->EstUnTrajetSimple()){
                os<<"TS1:";
                tmp->GetTrajetActuel()->Sauvegarder(os); // on sauvegarde alors
            }else{
                tmp->GetTrajetActuel()->Sauvegarder(os); // on sauvegarde alors
            }
            os<<'\n';
        }
        tmp=tmp->GetNextCase(); // on passe au trajet suivant
    }
    delete[] Arrivee;  // on libère l'espace mémoire donné a l'arrivée
    os.close(); // on ferme le canal ouvert
    if (i==0){ // ici on est sur qu'on a sauvegardé aucun trajet avec la meme ville d'arrivée
      cout<< "Votre catalogue ne contient aucun trajet avec ce nom de ville d'arrivée" << endl;
    }
  }
}
void Catalogue :: SauvegarderLesTrajetsAvecDepart(char * nomDuFichier)
// Algorithme : ici on sauvegarde tout les trajets présent dans le catalogue, qui ont une ville de départ qui sera renseigné par l'utilisateur, dans le fichier passé en paramètre
//
{
  if (listeTrajet->EstVide()){ // on regarde si il n'y a aucun trajets dans le catalogue
    cout << "Il n'y a aucun trajet dans le catalogue pour le sauvegarder dans le fichier, veuillez rajouter des trajets et réessayer svp " <<endl;
  }
  else{ // dans le catalogue on est sur qu'il y'a au moins un trajet
      cout << "Entrez votre ville de départ svp :";
      char * Depart = new char[sizeof(char)*25]; // on alloue dynamiquement l'espace mémoire pour le départ
      cin >> Depart; // l'utilisateur renseigne le départ
      Case * tmp=listeTrajet->GetFirstCase(); //
      ofstream os(nomDuFichier); // on ouvre le canal pour écrire les trajets
      int i =0; // c'est pour savoir si on a sauvegardé des trajets ou pas
      while(tmp!=nullptr){ // tant que il y'a des trajets
         if(strcmp(tmp->GetTrajetActuel()->GetDepart(),Depart)==0){ // on regarde si le trajet a le meme départ que celui voulu
             i=1;
             if(tmp->GetTrajetActuel()->EstUnTrajetSimple()){
                os<<"TS1:";
                tmp->GetTrajetActuel()->Sauvegarder(os); // on sauvegarde le trajet
             }else{
                tmp->GetTrajetActuel()->Sauvegarder(os); // on sauvegarde le trajet
             }
             os<<'\n';
         }
         tmp=tmp->GetNextCase(); // on passe au trajet suivant
     }
     delete[] Depart; // on libère l'espace mémoire donné au départ
     os.close();
     if (i==0){ // ici on est sur qu'on a sauvegardé aucun trajet
       cout<< "Votre catalogue ne contient aucun trajet avec ce nom de ville de départ" << endl;
     }
  }
}

void Catalogue :: SauvegarderCatalogueSimplement(char * nomFichier)
// Algorithme : ici on sauvegarde tout les trajets présent dans le catalogue dans le fichier passé en paramètre
//
{
  if (listeTrajet->EstVide()){ // on regarde si il n'y a aucun trajets dans le catalogue
    cout << "Il n'y a aucun trajet dans le catalogue pour le sauvegarder dans le fichier, veuillez rajouter des trajets et réessayer svp " <<endl;
  }
  else { // dans le catalogue on est sur qu'il y'a au moins un trajet
    ofstream os(nomFichier);
    Case * tmp = listeTrajet->GetFirstCase(); //on prend le premier trajet
    while (tmp != nullptr){ // tant qu'il y'a des trajets dans le catalogue
      if (tmp->GetTrajetActuel()->EstUnTrajetSimple()){
          os << "TS1:";
      }
      tmp->GetTrajetActuel()->Sauvegarder(os); // on sauvegarde le trajet dans le fichier passé en paramètre
      os << "\n";
      tmp = tmp->GetNextCase(); // on passe au trajet suivant
    }
    os.close(); // on ferme le canal
  }
}

void Catalogue :: SauvegarderLesTrajetsSimples(char * nomDuFichier)
// Algorithme : ici on sauvegarde tout les trajets simples présents dans le catalogue dans le fichier passé en paramètre
//
{
  if (listeTrajet->EstVide() ){ // on regarde si il n'y a aucun trajets dans le catalogue
    cout << "Il n'y a aucun trajet dans le catalogue pour le sauvegarder dans le fichier, veuillez rajouter des trajets et réessayer svp " <<endl;
  }
  else { // dans le catalogue on est sur qu'il y'a au moins un trajet
    ofstream os(nomDuFichier);
    int i = 0;
    Case * tmp = listeTrajet->GetFirstCase(); // on prend le premier trajet
    while (tmp != nullptr){ // tant qu'on a un trajet on rentre dans la boucle
      if (tmp->GetTrajetActuel()->EstUnTrajetSimple()){
          i=1; // on change car on a trouvé un trajet
          os << "TS1:";
          tmp->GetTrajetActuel()->Sauvegarder(os);
          os << "\n";
      }
      tmp = tmp->GetNextCase(); // on passe au trajet suivant
    }
    os.close();
    if (i==0){ // ici on est sur que le catalogue ne contient aucun trajet simple
      cout << "Votre catalogue ne contient aucun trajet simple" << endl;
    }
  }
}

void Catalogue :: SauvegarderLesTrajetsComposes(char * nomDuFichier)
// Algorithme : ici on sauvegarde tout les trajets composées présents dans le catalogue dans le fichier passé en paramètre
//
{
  if (listeTrajet->EstVide() ){ // on regarde si il n'y a aucun trajets dans le catalogue
    cout << "Il n'y a aucun trajet dans le catalogue pour le sauvegarder dans le fichier, veuillez rajouter des trajets et réessayer svp " <<endl;
  }
  else { // dans le catalogue on est sur qu'il y'a au moins un trajet
    int i=0; // c'est pour voir si il n'y a aucun trajet composée
    ofstream os(nomDuFichier);
    Case * tmp = listeTrajet->GetFirstCase(); // on prend le premier trajet
    while (tmp != nullptr){ // tant que il y'a des trajets on rentre dans la boucle
      if (tmp->GetTrajetActuel()->EstUnTrajetSimple()==false){ // si c'est un trajet composé on le sauvegarde
          i=1;
          tmp->GetTrajetActuel()->Sauvegarder(os);
          os << "\n";
      }
      tmp = tmp->GetNextCase(); // on passe au trajet suivant
    }
    os.close();
    if (i==0){ // ici on est sur que le catalogue ne contient aucun trajet composé
      cout << "votre catalogue ne contient aucun trajet composée" << endl;
    }
  }
}

void Catalogue :: AfficherCatalogue() const
// Algorithme : on regarde si le pointeur sur la ListeChainée du catalogue est nullptr si il est null c'est que il n'y a aucun trajet
// catalogue sinon on les affiche.
//
{
  if (listeTrajet->GetFirstCase() ==nullptr){ // ici on dit que il n'y a aucun trajet dans le catalogue
     cout << "Aucun trajet disponible, VEUILLEZ les ajouter svp" <<endl;
  }
  else {  // ici on informe l'utilisateur que nous allons afficher les trajets du catalogue
    cout << "Voici tous les trajets disponibles dans le catalogue " <<endl;
  }
  listeTrajet->Afficher();
} //----- Fin de Méthode AfficherCatalogue

void Catalogue :: AjouterTrajet( Trajet* unTrajet)
// Algorithme : on fait appel à la méthode Inserer de la classe liste pour ajouter dans notre ListeChainee le trajet qui est passé en paramètre
//
{
   listeTrajet->Inserer(unTrajet);
} //----- Fin de Méthode AjouterTrajet

void Catalogue :: ChercherTrajetSimplement(const char * Depart,const char * Arrivee) const
// Algorithme : ici on fait un parcours de l'ensemble des trajets du catalogue si un des trajets a le meme départ et arrivée que ceux voulu alors
// on l'affiche
//
{
  Case * tmp = listeTrajet->GetFirstCase(); //  on prend le premier trajet
  int i = 0;
  while (tmp !=nullptr){ // tant qu'on est pas arrivé à la fin de la liste alors on rentre dans la boucle
    if ( (strcmp(Depart,tmp->GetTrajetActuel()->GetDepart())==0) && ( strcmp(Arrivee,tmp->GetTrajetActuel()->GetArrivee())==0 ) ){ // ici on regarde si le trajet tmp sur lequel on pointe à la meme arrivée et meme depart que le paramètre
           tmp->Afficher(); // si il a le meme départ et arrivée
           cout << endl;
           i++; // on compte combien on a ajouté d'éléments
    }
    tmp = tmp->GetNextCase(); // on passe au trajet suivant
  }
  if (i != 0){   // si on a trouvé au moins un trajet alors on affiche le message suivant
     cout << "Ci-dessus les trajets simples pour le voyage recherché:" <<endl;
     //liste->Afficher();
  }
  else{   // si on a trouvé aucun trajet alors on affiche le message suivant
    cout << "Aucun trajet simple n'est disponible pour le voyage recherché :/" <<endl;
  }
} //----- Fin de Méthode ChercherTrajetSimplement

void Catalogue :: ChercherTrajetAvancee(const char * Depart,const char * Arrivee) const
// Algorithme : ici on initialise la liste chainée avec le premier trajet qui doit forcément avoir le meme départ qui celui en paramètre puis on cherche en profondeur l'ensemble des combinaisons possibles
//
{
    Case * tmp = listeTrajet->GetFirstCase(); // on prend le premier trajet (il est contenue dans la première case)
    while (tmp != nullptr){
       if (strcmp(tmp->GetTrajetActuel()->GetDepart(),Depart) == 0){ // pour chaque trajet de la liste on  regarde si il a le meme départ
           ListeChainee * listeTemporaire = new ListeChainee();
           listeTemporaire->Inserer(tmp->GetTrajetActuel());
           RechercheRecursive(listeTemporaire,tmp->GetTrajetActuel()->GetArrivee(),Arrivee); // on recherche en profondeur pour arriver à trouver une combinaison si c'est possible
           while(listeTemporaire->GetFirstCase()!=nullptr){ // ici on retire le dernier élement à chaque fois jusqu'il n'y ait plus d'éléments à afficher
             listeTemporaire->RetirerDernierElement();
           }
           delete listeTemporaire; // on fait appel au destructeur de la liste
       }
       tmp = tmp->GetNextCase(); // on passe au trajet suivant
    }
} //----- Fin de Méthode ChercherTrajetAvancee

void Catalogue :: RechercheRecursive( ListeChainee * listeTemporaire,const char * DepartTemporaire,const char * ArriveeFinale) const
// Algorithme : on cherche en profondeur les combinaisons possibles qui pourront former un trajet avec des escales pour la destination cherché
//
{
    Case * tmp = listeTrajet->GetFirstCase();
     while (tmp != nullptr){
        if (strcmp(tmp->GetTrajetActuel()->GetDepart(),DepartTemporaire) == 0){ // on rentre ici si on a le départ temporaire qu'on cherche il est égal au trajet actuellement pointé
          if(listeTemporaire!=nullptr){
            while(strcmp(listeTemporaire->GetLastCase()->GetTrajetActuel()->GetArrivee(),tmp->GetTrajetActuel()->GetDepart())!=0){ // la boucle vérifie que le départ du trajet qu'on veut insérer correspond forcément à l'arrivée du dernier trajet arrivé sur la liste avant l'insertion
              listeTemporaire->RetirerDernierElement();
            }
          }
          listeTemporaire->Inserer(tmp->GetTrajetActuel()); // on l'insère dans la liste

            if (strcmp(tmp->GetTrajetActuel()->GetArrivee(),ArriveeFinale) == 0){  // si on est arrivée à trouver que le trajet actuellement pointé à la meme arrivée alors on l'affiche car c'est une combinaison
                listeTemporaire->Afficher(2);
                listeTemporaire->RetirerDernierElement(); // après l'avoir affiché on le retire pour poursuivre la recherche d'autres combinaisons
            }
            else{ // on cherche ici d'avantages de combinaisons contenant le trajet actuellement pointé
                RechercheRecursive( listeTemporaire,tmp->GetTrajetActuel()->GetArrivee(),ArriveeFinale);
            }
        }
        tmp= tmp->GetNextCase(); // on passe au trajet suivant
    }
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue :: Catalogue( ListeChainee * ListeTrajet )
// Algorithme : permet de définir l'attribut contenant la liste des Trajets à partir du pointeur fournit en paramètre
//
{
  #ifdef MAP
    cout << "Appel au constructeur principal de <ListeChainee>" << endl;
  #endif
  listeTrajet = ListeTrajet;
} //----- Fin de Catalogue (constructeur)




Catalogue :: Catalogue ( const Catalogue & unCatalogue )
// Algorithme : on fait appel au destructeur de la classe car on va pas utiliser le constructeur par copie de catalogue
//
{
  #ifdef MAP
    cout << "Appel au constructeur par copie de <Liste>, Veuillez appeler le constructeur principal svp" << endl;
  #endif
  delete this; // ici on fait appel au destruteur de la classe car on va pas utiliser le constructeur par copie dans notre projet

} //----- Fin de Catalogue (constructeur de copie)


Catalogue :: Catalogue ( )
// Algorithme : il permet d'initialiser un catalogue vide en appelant le constructeur par défaut
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Catalogue>" << endl;
#endif
listeTrajet = new ListeChainee(); // on initialise une liste chainée vide

} //----- Fin de Catalogue (constructeur par défaut)


Catalogue :: ~Catalogue ( )
// Algorithme : on fait appel a au destructeur de la classe ListeChainee pour libérer la mémoire
//
{
  #ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
  #endif
  delete listeTrajet; // on fait appel au destructeur de la classe ListeChainée qui permet d'enlever


} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
