/*************************************************************************
                            Case  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Case> (fichier Case.h) ----------------
#if ! defined ( CASE_H )
#define CASE_H
#include <iostream>
using namespace std;
#include "Trajet.h"

// Rôle de la classe <Case>
// elle permet d'initialiser une case qui contiendra le trajet ainsi que le pointeur sur la case suivante, cette classe sera utilisée
// dans la classe ListeChainee
//------------------------------------------------------------------------

class Case
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Mode d'emploi : permet d'afficher le trajet contenue dans la case qui fait appel à cette méthode
    // Contrat : Aucun
    //

    void SetSuivant( Case * Suivant);
    // Mode d'emploi : permet de modifier le pointeur sur la case suivante de la case qui fait appel à cette méthode
    // Contrat :Aucun
    //

    Case * GetNextCase() const ;
    // Mode d'emploi : permet de retourner un pointeur sur la case suivante de la case qui fait appel à cette méthode
    // Contrat : Aucun
    //

    Trajet * GetTrajetActuel() const ;
    // Mode d'emploi : permet de retourner un pointeur sur le trajet qui est actuellement dans la case qui fait appel à cette méthode
    // Contrat : Aucun
    //
    void setTrajet(Trajet * unTrajet=nullptr);
    // Mode d'emploi : permet de modifier le pointeur leTrajet
    // Contrat : Aucun
    //
//-------------------------------------------- Constructeurs - destructeur
    Case( Trajet* unTrajet, Case* Suivant = nullptr );
    // Mode d'emploi  :  permet d'instancier le constructeur principal qui permet de créer
    //une case qui contient un pointeur sur un trajet et  un pointeur sur la case suivante à la case actuelle.
    //
    // Contrat : Aucun
    //

    Case( const Case & uneCase ) ;
    // Mode d'emploi (constructeur de copie) : permet d'instancier le constructeur de copie qui permet de créer
    //une case qui contient un pointeur sur un trajet et  un pointeur sur la case suivante à partir du trajet et la case pointé dans la case passé en paramètre.
    //
    // Contrat :Aucun
    //

    Case( );
    // Mode d'emploi : constructeur par défaut qui permet de créer une case qui contient un pointeur sur un trajet et un pointeur sur une case suivante
    // lors d'un appel sans paramètre
    // Contrat : Aucun
    //

    virtual ~Case ( );
    // Mode d'emploi : permet de libérer l'espace mémoire utilisée par l'objet this qui fait appel à cette méthode
    //
    // Contrat :Aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  Trajet * leTrajet; // pointeur sur le trajet que l'on veut stocker dans la case
  Case * trajetSuivant; // pointeur sur la case suivante qui contient le trajet suivant
};

#endif // CASE_H
