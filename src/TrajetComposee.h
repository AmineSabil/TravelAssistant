/*************************************************************************
                            TrajetComposée -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetComposee> (fichier TrajetComposee.h) ----------------
#if ! defined ( TRAJETCOMPOSEE_H )
#define TRAJETCOMPOSEE_H
#include "ListeChainee.h"
#include "TrajetSimple.h"
#include <fstream>
// Rôle de la classe <TrajetComposee>
//elle permet d'instancier un trajet qui est d'un point a à un point b avec un ou plusieurs arrets intérmédiaires.
//
//------------------------------------------------------------------------

class TrajetComposee : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   bool EstUnTrajetSimple();
   // Mode d'emploi : elle permet de retourner true si le type du trajet (this) sur lequel on applique cette méthode est un TrajetSimple
   //et False sinon.
   // Contrat :Aucun
   //

    void Sauvegarder(ofstream & os);
    // Mode d'emploi : elle permet de sauvegarder le trajet (this) sur lequel on applique la méthode dans le canal os qui est passé dans le paramètre.
    // Contrat :Aucun
    //


    void Afficher() const;
    // Mode d'emploi : elle permet d'afficher le trajet (this) sur lequel on applique cette méthode,
    //cad on affiche les informations de l'ensemble des trajets qui le constituent
    // Contrat :Aucun
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetComposee(const char * Depart, const char * Arrivee,  ListeChainee * liste);
    // Mode d'emploi  : il permet d'instancier le constructeur principal qui permet de créer
    //un trajet qui commence d'une ville et  se termine dans une autre ville.
    // Contrat : Aucun
    //
    TrajetComposee( const TrajetComposee & unTrajet);
    // Mode d'emploi (constructeur de copie) : permet d'instancier par copie qui permet de créer un nouveau trajet composée
    // à partir d'un trajet Composée déja initialisé.
    // Contrat : aucun
    //

    TrajetComposee( );
    // Mode d'emploi : constructeur par défaut qui permet d'instancier par défaut  un nouveau trajet composée dont on a aucune information
    //
    // Contrat :Aucun
    //

    virtual ~TrajetComposee( );
    // Mode d'emploi : il permet d'instancier le destructeur  qui permet de libérer
    //le trajet composée qui fait appel à cette méthode lors du delete par exemple
    //
    // Contrat :aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
ListeChainee * listeTrajets; // pointeur sur la liste chainée qui permet de stocker un ensemble de trajets dedans
};

#endif // TRAJETCOMPOSEE_H
