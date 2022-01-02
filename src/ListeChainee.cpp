/*************************************************************************
                            Trajet  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Case> (fichier Case.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool ListeChainee :: EstVide()
// Algorithme : retourne true si la liste chainée qui fait appel à cette méthode est vide et false sinon.
//
{
  if(debut==nullptr)
    return true;
  else
    return false;
}

int ListeChainee :: GetNbTrajets() const
// Algorithme : retourne la taille de la liste cad le nombre de trajets contenus dans la liste qui fait appel à cette méthode.
//
{
  Case * tmp = debut;
  int i = 0;
  while (tmp != nullptr){
       i++;
       tmp = tmp->GetNextCase();
  }
  return i;
}

void ListeChainee :: Afficher(int i) const
// Algorithme : on affiche avec une boucle tout les trajets contenus dans la liste chainée
//
{
  Case * tmp= debut; // on prend la première case
  while (tmp != nullptr){ // on parcoure les cases tant que on a des cases alors on affiche
     cout << " - ";
     tmp->Afficher();
     if (tmp!=nullptr){
       cout << " - ";
     }
     if (i==0){ // ici on a fait ca pour différencer l'affichage entre l'affichage des trajets simples et composés
           cout<< endl;
     }
     tmp = tmp->GetNextCase();
  }
  if (i !=0 ){
    cout << endl;
  }
} //----- Fin de Méthode Afficher

Case * ListeChainee :: GetLastCase()
// Algorithme : retourne le pointeur sur la derniere case de la liste chainée
//
{
   return fin;
} //----- Fin de Méthode GetLastCase

void ListeChainee :: Inserer( Trajet* unTrajet)
//
// Algorithme : il permet d'insérer un trajet dans la liste chainée qui fait appel à cette méthode
//
{
  if (debut == nullptr){ // ici on est sur que la liste est vide
    debut  = new Case( unTrajet ); // on crée une case contenant le trajet et on l'ajoute
    debut->SetSuivant(nullptr);
    fin = debut;  // on pointe sur la meme case qui ajoute
  }
  else{
      Case * tmp = new Case(unTrajet); // on ajoute ici la case à la fin
      fin->SetSuivant(tmp);
      fin = tmp; // on pointe sur la case
  }
} //----- Fin de Méthode Inserer

Case * ListeChainee :: GetFirstCase()
//
// Algorithme : on retourne le pointeur sur la première case de la liste chainée
//
{
   return debut;
} //----- Fin de Méthode GetFirstCase

void ListeChainee :: RetirerDernierElement()
//
// Algorithme : on retire la derniere case de la liste chainée si la liste n'est pas vide et si elle est vide on fait rien sinon
//
{
  if (debut!= nullptr){
    Case * tmp = debut;
    while ((tmp != fin) && (tmp->GetNextCase()!= fin)){ // ici à la fin de la boucle forcément on pointe sur l'avant derniere case de la liste chainée
     tmp = tmp->GetNextCase();
   }
    if(fin==tmp && debut==tmp){ // ici on est sur qu'il y'a juste un seul élément qui contient un seul trajet
     debut=nullptr;
     fin=nullptr;
     tmp->setTrajet(); // on change le trajet pour modifier le trajet pointé comme ca on peut détruire la case
     delete tmp; // on detruit la case ici;
    }
    else{
     tmp->GetNextCase()->setTrajet();
     delete tmp->GetNextCase();
     tmp->SetSuivant(nullptr); // ici on pointe sur nullptr car elle sera la dernière
     fin = tmp;// ici on pointe plus sur la derniere case mais sur l'avant derniere
    }
  }
} //----- Fin de Méthode RetirerDernierElement

//-------------------------------------------- Constructeurs - destructeur
ListeChainee :: ListeChainee( Trajet* trajetDebut )
// Algorithme : on crée une liste chainée contenant un seul trajet
//
{
  #ifdef MAP
    cout << "Appel au constructeur principal de <ListeChainee>" << endl;
  #endif
  debut  = new Case( trajetDebut );
  fin = debut; // ici comme on a un seul trajet on pointe sur le meme trajet forcémment
} //----- Fin de ListeChainee (constructeur)




ListeChainee::ListeChainee ( const ListeChainee & uneListe )
// Algorithme : on utilise pas ce constructeur donc on fait appel directement au destructeur quand il y'a appel a cette méthode
//
{
  #ifdef MAP
    cout << "Appel au constructeur par copie de <Liste>, Veuillez appeler le constructeur principal svp" << endl;
  #endif
  delete this; // on fait appel au detructeur de la listechainee
} //----- Fin de ListeChainee (constructeur de copie)


ListeChainee:: ListeChainee ( )
// Algorithme : ici on initialise une liste chainée vide qui ne contient aucun élémnt
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <ListeChainee>" << endl;
#endif
debut = nullptr;
fin  = nullptr;

} //----- Fin de ListeChainee (constructeur par défaut)


ListeChainee :: ~ListeChainee ( )
// Algorithme : c'est le destructeur de la liste chainée qui permet de libérer l'espace mémoire pris par la liste qui fait appel à cette méthode
//
{
  #ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
  #endif
  if (debut != nullptr) // on s'assure que la liste n'est pas vide
       delete debut; // on fait appel au destructeur de Case
} //----- Fin de ~ListeChainee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
