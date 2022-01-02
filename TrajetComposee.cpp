/*************************************************************************
                            TrajetComposee  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetComposee> (fichier TrajetComposee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetComposee.h"
#include <fstream>
#include <string>
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool TrajetComposee :: EstUnTrajetSimple()
//
// Algorithme : elle retourne false car ce n'est pas un trajet de type TrajetSimple
//
{
  return false;
}
void TrajetComposee :: Sauvegarder( ofstream & os)
//
// Algorithme : elle permet de Sauvegarder dans le fichier qui est ouvert par le canal donné comme paramètre
//
{
  os << "TC" << listeTrajets->GetNbTrajets() << ":" << depart << "$" << arrivee << "|";
  Case * tmp = listeTrajets->GetFirstCase(); // on prend le premier sous trajet si il existe.
  while (tmp!=nullptr){ // tant qu'on a un sous trajet on rentre dans la boucle
      tmp->GetTrajetActuel()->Sauvegarder(os); // on fait appel un appel à la meme méthode Sauvegarder du trajet
      tmp = tmp->GetNextCase(); // on passe au trajet suivant.
      os << "|";
  }
}

void TrajetComposee :: Afficher() const
// Algorithme : elle permet d'afficher toutes les informations du trajet composée qui fait appel à cette méthode
//
{
   Case * tmp = listeTrajets->GetFirstCase(); // on prend la première case de la liste chainée
   while (tmp != nullptr){ // tant qu'on a des cases non nulles on affiche le trajet contenue dans la case
      tmp->Afficher();
      tmp = tmp->GetNextCase();
      if(tmp != nullptr)
          cout<< " - ";
   }
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
TrajetComposee:: TrajetComposee (const char * Depart,const char * Arrivee, ListeChainee * liste) :
     Trajet(Depart,Arrivee)
// Algorithme : on pointe vers la liste des trajets,l'arrivée,et le départ qui sont données en paramètres
//
{
  #ifdef MAP
    cout << "Appel au constructeur par  de <Trajet>" << endl;
  #endif
  listeTrajets = liste; // on pointe vers la liste chainée des trajets contenues dans les paramètres
} //----- Fin de TrajetComposee (constructeur)


TrajetComposee::TrajetComposee( const TrajetComposee & unTrajet )/*:
    Trajet(unTrajet)*/
// Algorithme : on ne l'utilise pas juste on fait appel au destructeur si jamais il y'a appel à ce constructeur
//
{
  #ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>, veuillez appeler le constructeur principal !!" << endl;
  #endif
  //listeTrajets=new ListeChainee(*(unTrajet.listeTrajets));
  cout << " veuillez appeler le constructeur principal, celui avec les paramètres !!" << endl;
  delete this; // on fait appel au destructeur de la classe pour libérer cette espace mémoire lorsqu'on fait appel à ce constructeur
} //----- Fin de TrajetComposee (constructeur de copie)


TrajetComposee::TrajetComposee( ) :
     Trajet()
// Algorithme : on ne l'utilise pas juste on fait appel au destructeur si jamais il y'a appel à ce constructeur
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Trajet>" << endl;
#endif
cout << " veuillez appeler le constructeur principal, celui avec les paramètres !!" << endl;
delete this; // on fait appel au destructeur de la classe pour libérer cette espace mémoire lorsqu'on fait appel à ce constructeur
} //----- Fin de TrajetComposee (constructeur par défaut)


TrajetComposee :: ~TrajetComposee ( )
// Algorithme : permet de libérer les espaces mémoires alloués pour la liste des trajets, ainsi que il fait appel implicite au destructeur de la classe Trajet
//
{
  #ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
  #endif
  delete listeTrajets; // on libère l'espace mémoire alloué pour la liste des trajets
} //----- Fin de ~TrajetComposee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
