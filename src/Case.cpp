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
#include "Case.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Case :: Afficher() const
// Algorithme : affiche les informations sur le trajet contenu dans la case (this) qui fait appel à cette méthode
//
{
  leTrajet->Afficher();
} //----- Fin de Méthode Afficher

void Case :: SetSuivant( Case * Suivant)
// Algorithme : modifie la case pointé pour la case suivante
//
{
  trajetSuivant = Suivant; // ici on modifie la case pointé pour la case suivante
} //----- Fin de Méthode SetSuivant

Case * Case :: GetNextCase() const
// Algorithme : retourne un pointeur sur la case suivante à la case qui fait appel à la méthode
//
{
  return trajetSuivant;
} //----- Fin de Méthode SetSuivant

Trajet * Case :: GetTrajetActuel() const
// Algorithme : retourne un pointeur sur le trajet actuellement présent dans la case
//
{
  return leTrajet;
}
void Case :: setTrajet(Trajet * unTrajet)
// Algorithme : modifie l'attribut 'trajet * leTrajet'
//
{
  leTrajet=unTrajet;
}
//----- Fin de Méthode SetSuivant

//-------------------------------------------- Constructeurs - destructeur
Case :: Case( Trajet* unTrajet, Case* Suivant )
// Algorithme : permet d'initiliaser les attributs de la classe Case en donnant des trajets et un pointeur vers la case suivante
//
{
  #ifdef MAP
    cout << "Appel au constructeur par  de <Case>" << endl;
  #endif
  leTrajet = unTrajet; // on initialise le pointeur vers le trajet donné en paramètre
  trajetSuivant = Suivant; // on initialise le pointeur vers la case suivante à la case qu'on veut créer
 } //----- Fin de Trajet (constructeur)


Case::Case ( const Case & uneCase )
// Algorithme : on fait appel au destructeur de la classe car en aucun on va faire appel à ce constructeur par copie
//
{
  #ifdef MAP
    cout << "Appel au constructeur de copie de <Case>, veuillez appeler le constructeur principal" << endl;
  #endif
  delete this; // ici on appel le destructeur pour ne pas instancier et occuper de la mémoire;
} //----- Fin de Case (constructeur de copie)


Case:: Case ( )
// Algorithme :  on fait appel au destructeur de la classe car en aucun on va faire appel à ce constructeur par défaut
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Case>, veuillez appeler le constructeur avec paramètre" << endl;
#endif
delete this; // ici on appel le destructeur pour ne pas instancier et occuper de la mémoire;

} //----- Fin de Case (constructeur par défaut)


Case :: ~Case ( )
// Algorithme : on libère l'espace mémoire utilisée pour chacun des attributs de la classe
//
{
  #ifdef MAP
    cout << "Appel au destructeur de <Case>" << endl;
  #endif
  if(leTrajet !=nullptr)
    delete leTrajet;// on libère le trajet actuellement pointée
  if (trajetSuivant != nullptr){ // si on a une case suivant alors on la libère aussi en faisant appel à son destructeur
         delete trajetSuivant; // trajet->~Case ( );

  }

} //----- Fin de ~Case


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
