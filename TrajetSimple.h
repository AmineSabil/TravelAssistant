/*************************************************************************
                            TrajetSimple  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
#include "Trajet.h"
#include <fstream>

// Rôle de la classe <TrajetSimple>
// elle permet d'instancier un trajet qui est d'un point a à un point b sans arret intérmédiaire.
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool EstUnTrajetSimple();
    // Mode d'emploi : elle permet de retourner true pour savoir le type du trajet qui fait appel à cette méthode. elle renvoie toujours true dans ce cas.
    // Contrat : Aucun

    void Sauvegarder( ofstream & os);
    // Mode d'emploi : elle permet de sauvegarder le trajet simple qui fait appel à cette méthode dans le canal supposé ouvert qui est passé en paramètre
    // Contrat : Aucun
    //
    //


     void Afficher() const;
    // Mode d'emploi : elle permet d'afficher le trajet (this) sur lequel on applique cette méthode, cad son départ,arrivée
    // Contrat : Aucun
    //

   char * GetMoyenTransport();
   // Mode d'emploi : permet d'avoir le moyen de transport du trajet simple qui fait appel à cette méthode
   //
   // Contrat :Aucun
   //
//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const char * Depart, const char * Arrivee,const char * MoyenTransport);
    // Mode d'emploi  : il permet d'instancier le constructeur principal qui permet de créer
    //un trajet simple qui commence d'une ville et se termine dans une autre ville sans arret intérmédiaire.
    // Contrat : Aucun
    //
    TrajetSimple( const TrajetSimple & unTrajet);
    // Mode d'emploi (constructeur de copie) :il permet d'instancier le constructeur de copie qui permet de créer
    //un trajet simple qui commence d'une ville et se termine dans une autre ville sans arret intérmédiaire à partir d'un trajet simple déja éxistant.
    // Contrat : Aucun
    //

    TrajetSimple( );
    // Mode d'emploi :il permet d'instancier le constructeur principal qui permet de créer
    //un trajet simple qui commence d'une ville et se termine dans une autre ville sans arret intérmédiaire.
    // Contrat : Aucun
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi :il permet d'instancier le destructeur  qui permet de libérer
    //le trajet simple qui fait appel à cette méthode.
    // Contrat :Aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  char * moyenTransport; // pointeur sur la chaine de caractères qui représente le moyen de transport du trajet simple
};

#endif // TRAJETSIMPLE_H
