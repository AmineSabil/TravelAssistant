/*************************************************************************
                            Trajet  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H
#include <iostream>
using namespace std;
// Rôle de la classe <Ensemble>
//Elle permet d'initialiser la classe  abstraite Trajet dont hérite 2 classes qui sont TrajetComposée et TrajetSimple
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool EstUnTrajetSimple()=0;
    // Mode d'emploi :
    // elle permet de renvoyer true si le trajet sur lequel on applique cette méthode est de type trajet simple et false si il est d'un autre type de trajet
    // Contrat : Aucun

    virtual void Sauvegarder(std :: ofstream & os) = 0;
    //
    // Mode d'emploi :
    // elle permet d'afficher le trajet sur lequel on applique cette méthode
    // Contrat : Aucun
    //

    virtual void Afficher() const = 0;
    //
    // Mode d'emploi :
    // elle permet d'afficher le trajet sur lequel on applique cette méthode
    // Contrat : Aucun
    //

    char * GetDepart()const;
    //
    // Mode d'emploi :
    // elle permet d'afficher le départ du trajet sur lequel on appliue cette méthode
    // Contrat :Aucun
    //

    char * GetArrivee()const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //elle permet d'afficher l'arrivée du trajet sur lequel on applique cette méthode
    // Contrat :
    //
//-------------------------------------------- Constructeurs - destructeur
    Trajet(const char * Depart, const char * Arrivee);
    // Mode d'emploi  : il permet d'instancier le constructeur principal qui permet de créer
    //un trajet qui commence d'une ville et se termine dans une autre ville.
    //
    // Contrat : Aucun
    //
    Trajet( const Trajet & unTrajet);
    // Mode d'emploi (constructeur de copie) : permet d'instancier
    //il permet d'instancier le constructeur de copie qui permet de créer
    //un trajet qui commence d'une ville et se termine dans une autre ville qui sont les memes que ceux dui trajet en paramètres.
    // Contrat : Aucun
    //

    Trajet( );
    // Mode d'emploi :il permet d'instancier le constructeur de copie qui permet de créer
    //un trajet qui commence d'une ville et se termine dans une autre ville.
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi : c'est le destructeur  qui permet de détruire et libérer la mémoire
    //du trajet qui fait appelle à cette méthode.
    // Contrat : Aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  char * depart;  //pointeur sur une chaine de caracteres représentant la ville de départ.
  char * arrivee; // pointeur sur une chaine de caracteres représentant la ville d'arrivée.
};

#endif // TRAJET_H
