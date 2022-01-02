/*************************************************************************
                            TrajetSimple  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
#include <string>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool TrajetSimple :: EstUnTrajetSimple()
//
// Algorithme : elle retourne toujours true ici car l'objet qui fait appel est de type TrajetSimple.
//
{
  return true;
}

void TrajetSimple :: Sauvegarder( ofstream & os)
//
// Algorithme : elle permet de sauvegarder le trajet qui fait appel à cette méthode dans le canal supposé ouvert qui est passé en paramètre.
//
{
  os << depart << "$" << arrivee << "$" << moyenTransport;
}

char * TrajetSimple :: GetMoyenTransport(){
// Algorithme : elle permet de retourner un pointeur sur la chaine de caractères qui représente le moyen de transport
//
  return moyenTransport;
}
void TrajetSimple :: Afficher() const
// Algorithme : elle permet d'afficher toutes les informations du trajet simple qui fait appel à cette méthode
//
{
   cout << "de "<< depart << " à " << arrivee << " en " << moyenTransport ;
} //----- Fin de Méthode GetMoyenTransport


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char * Depart,const char * Arrivee,const char * MoyenTransport) :
     Trajet(Depart,Arrivee)
// Algorithme : il permet d'allouer la mémoire pour tous les attributs de la classe en copiant
//les chaines de caractères dans les espaces mémoires alloués.
//
{
  #ifdef MAP
    cout << "Appel au constructeur par  de <Trajet>" << endl;
  #endif
  moyenTransport = new char[strlen(MoyenTransport)+1]; // allocation de la mémoire pour l'attribut moyenTransport;
  strcpy(moyenTransport,MoyenTransport); // copie de la chaine de caractere de moyenTransport dans l'espace mémoire alloué
} //----- Fin de TrajetSimple (constructeur)


TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajet )
// Algorithme : comme ici on a pas besoin du constructeur par copie alors on annule son appel
//
{
  #ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>, veuillez appeler le constructeur principal !!" << endl;
  #endif
  delete this; // comme ici on a pas besoin du constructeur par copie alors on annule son appel
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple( ) :
     Trajet()
// Algorithme : il permet d'allouer la mémoire pour tous les attributs de la classe
// et permet de les initialiser avec des chaines de caractères vides
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Trajet>" << endl;
#endif
moyenTransport = new char[1];// allocation de la mémoire pour l'attribut moyenTransport;
moyenTransport[0] = '\0'; // on met la chaine vide dans l'espace alloué
} //----- Fin de TrajetSimple (constructeur par défaut)


TrajetSimple :: ~TrajetSimple ( )
// Algorithme : on libère l'espace mémoire de tout les attributs que ce moyenTransport,depart ainsi que arrivee,
// en faisant des delete[] puisque c'est des tableaux
//
{
  #ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
  #endif
  if(moyenTransport!=nullptr)
    delete[] moyenTransport; // libération de l'attribut moyen de transport
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
