/*************************************************************************
                            Trajet  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char * Trajet :: GetDepart()const
// Algorithme : retourne la chaine de caractères représentant la ville de départ du trajet.
//
{
  return depart;
}
char * Trajet :: GetArrivee()const
// Algorithme :retourne la chaine de caractères représentant la ville d'arrivée du trajet.
//
{
  return arrivee;
}

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet (const char * Depart,const char * Arrivee)
// Algorithme : création de l'espace mémoire pour la ville de départ et d'arrivée (qui sont des attributs de la classe) et on copie leurs valeurs qui sont
// données dans les paramètres dans l'espace mémoire allouée.
//
{
  #ifdef MAP
    cout << "Appel au constructeur par  de <Trajet>" << endl;
  #endif
  depart = new char[strlen(Depart)+1]; // allocation de la mémoire pour la ville de départ
  strcpy(depart,Depart);
  arrivee = new char[strlen(Arrivee)+1]; // allocation de la mémoire pour la ville d'arrivée
  strcpy(arrivee,Arrivee);
} //----- Fin de Trajet (constructeur)


Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme : création de l'espace mémoire pour la ville de départ et d'arrivée (qui sont des attributs de la classe)
// on copie les villes dans l'espace mémoire alloué à partir du trajet passé en paramètre.
//
{
  #ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
  #endif
  depart = new char[strlen(unTrajet.depart)+1];// allocation de la mémoire pour la ville de départ
  strcpy(depart,unTrajet.depart);
  arrivee = new char[strlen(unTrajet.arrivee)+1];// allocation de la mémoire pour la ville d'arrivée
  strcpy(depart,unTrajet.arrivee );
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet ( )
// Algorithme :création de l'espace mémoire pour un constructeur par défaut il contient des chaines vides comme attribut départ et arrivée
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Trajet>" << endl;
#endif
depart = new char[1];// allocation de la mémoire pour la ville de départ
arrivee[0] = '\0';
arrivee = new char[1];// allocation de la mémoire pour la ville d'arrivée
arrivee[0] = '\0';
} //----- Fin de Trajet (constructeur par défaut)


Trajet:: ~Trajet ( )
// Algorithme : il permet de libérer l'espace mémoire alloué pendant l'instanciation au début
//
{
  #ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
  #endif
  if(depart!=nullptr)
    delete[] depart;// on libère l'espace allouée pour la chaine de caractères de la ville de départ
  if(arrivee!=nullptr)
    delete[] arrivee; // on libère l'espace allouée pour la chaine de caractères de la ville d'arrivées
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
