/*************************************************************************
                            ListeChainée  -  description
                             -------------------
    début                : 17/11/2020
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ListeChainée> (fichier ListeChainée.h) ----------------
#if ! defined ( LISTECHAINEE_H )
#define LISTECHAINEE_H
#include "Case.h"
#include "TrajetSimple.h"
// Rôle de la classe <ListeChainee>
//crée une structure de donnée qui est la liste chainée qui contiendra des cases contenant
// des trajets ainsi que des pointeurs vers les cases suivantes
//------------------------------------------------------------------------

class ListeChainee
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int GetNbTrajets() const;
    //Mode d'emploi : renvoie un nombre entier qui est le nombre de trajets contenus dans la liste qui fait appel à cette méthode
    // Contrat : Aucun
    //

    bool EstVide();
    //Mode d'emploi : permet de dire si la liste ne contient aucun trajet ou non.
    // Contrat :  Aucun
    //

    void Afficher(int i=0) const;
    // Mode d'emploi : permet d'afficher l'ensemble des trajets contenus dans les cases de la listeChainée qui fait appel
    // à cette méthode
    // Contrat :Aucun
    //

    void Inserer(  Trajet* unTrajet);
    // Mode d'emploi : permet d'insérer en fin de la liste qui fait appel à cette méthode
    // une case qui contient un pointeur sur un trajet qui est donné comme paramètre
    //
    // Contrat : Aucun
    //

    Case * GetFirstCase();
    // Mode d'emploi : permet de retourner pointeur sur la première case de la liste chainée qui fait appel à cette méthode
    // Contrat : Aucun
    //

    Case * GetLastCase();
    // Mode d'emploi : permet de retourner pointeur sur la dernière case de la liste chainée qui fait appel à cette méthode
    // Contrat : Aucun
    //

   void RetirerDernierElement();
   // Mode d'emploi : permet de retirer le pointeur sur la dernière case de la liste chainée qui fait
   // appel à cette méthode
   // Contrat : Aucun
   //

//-------------------------------------------- Constructeurs - destructeur

    ListeChainee( Trajet* trajetDebut);
    // Mode d'emploi  : permet de créer une liste chainée qui ne contient qu'une case,cette case contiendra le pointeur vers le premier trajet qui est donnée
    // comme paramètre de la méthode.
    // Contrat : Aucun
    //

    ListeChainee( const ListeChainee & uneListe ) ;
    // Mode d'emploi (constructeur de copie) : permet de créer une nouvelle liste chainee à partir d'une liste chainée
    //passé en paramètre
    // Contrat :Aucun
    //

    ListeChainee( );
    // Mode d'emploi : permet d'initialiser une liste chainée vide qui ne contient aucune case cad aucun trajet
    //
    // Contrat :
    //

    virtual ~ListeChainee ( );
    // Mode d'emploi : permet de libérer l'espace mémoire utilisé par la liste chainée qui fait appel à cette méthode
    // Contrat : Aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  Case * debut; // pointeur sur la première case de la ListeChainée
  Case * fin; // pointeur sur la dernière case de la ListeChainée
};

#endif // LISTECHAINEE_H
