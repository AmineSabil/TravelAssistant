//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H
#include "ListeChainee.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComposee.h"
// Rôle de la classe <Catalogue>
// permet de rassembler un ensemble de trajets rentrés par l'utilisateur, et permet de proposer des parcours de voyages
//à partir des villes de départ et d'arrivée rentrées par l'utilisateur
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void LectureTrajet(char * nomDuFichier,int choix ,char * ville, char * villeSupplementaire=nullptr);
    //Mode d'emploi : permet de restituer les trajets dans le catalogue this à partir du nom de fichier en fonction de soit la ville de départ, d'arrivée, ou des 2
    // Contrat : le nom du fichier doit etre un fichier présent, choix doit etre entre 1 et 3.
    //

    void LectureTrajet(char * nomDuFichier,char sorte);
    //Mode d'emploi : permet de restituer les trajets dans le catalogue this à partir du nom de fichier en fonction du sorte voulu en paramètre
    // Contrat : le nom du fichier doit etre un fichier présent, sorte doit etre soit 'T', 'C', ou 'S'.
    //

    void  SauvegarderLesTrajetsAvecDepart(char * nomDuFichier);
    //Mode d'emploi : permet de sauvegarder les trajets dans le catalogue this dans le fichier dont le nom est fourni en paramètre en fonction d'une ville de départ qui sera saisi par l'utilisateur
    // Contrat : le nom du fichier doit etre un fichier présent
    //


    void SauvegarderLesTrajetsAvecArrivee(char * nomDuFichier);
    //Mode d'emploi : permet de sauvegarder les trajets dans le catalogue this dans le fichier dont le nom est fourni en paramètre en fonction d'une ville d'arrivée qui sera saisi par l'utilisateur
    // Contrat : le nom du fichier doit etre un fichier présent
    //

    void SauvegarderLesTrajetsAvecDepartEtArrivee(char * nomFichier);
    //Mode d'emploi : permet de sauvegarder les trajets dans le catalogue this dans le fichier dont le nom est fourni en paramètre en fonction d'une ville de départ et d'arrivée qui seront saisis par l'utilisateur
    // Contrat : le nom du fichier doit etre un fichier présent
    //

    void  SauvegarderLesTrajetsSimples(char * nomDuFichier);
    //Mode d'emploi : permet de sauvegarder les trajets simples dans le catalogue this dans le fichier dont le nom est fourni en paramètre
    // Contrat : le nom du fichier doit etre un fichier présent
    //

    void SauvegarderLesTrajetsComposes(char * nomDuFichier);
    //Mode d'emploi : permet de sauvegarder les trajets composes dans le catalogue this dans le fichier dont le nom est fourni en paramètre
    //Contrat : AUCUN

    void SauvegarderCatalogueSimplement(char * nomDuFichier);
    //Mode d'emploi : permet de sauvegarder les trajets  dans le catalogue this dans le fichier dont le nom est fourni en paramètre
    // Contrat : le nom du fichier doit etre un fichier présent
    //

    void AfficherCatalogue() const;
    // Mode d'emploi : Permet d'afficher l'ensemble des trajets contenus dans le catalogue qui fait appel à cette méthode
    // Contrat : AUCUN
    //

    void AjouterTrajet(  Trajet* unTrajet);
    // Mode d'emploi : permet d'ajouter un trajet au catalogue ( this ) qui fait appel à cette méthode
    // à partir du pointeur fourni comme paramètre
    // Contrat :AUCUN
    //

    void ChercherTrajetSimplement( const char * Depart, const char * Arrivee) const;
    // Mode d'emploi : permet de chercher l'ensemble des parcours possibles, sans combiner les trajets du catalogue,reliant  les villes
    //de départ et d'arrivée qui sont fournies comme paramètres
    // Contrat :AUCUN
    //
    void ChercherTrajetAvancee( const char * Depart, const char * Arrivee) const;
    // Mode d'emploi : permet de chercher et afficher l'ensemble des parcours possibles, en combinant les trajets du catalogue,reliant  les villes
    //de départ et d'arrivée qui sont fournies comme paramètres
    //
    // Contrat :AUCUN
    //
    void RechercheRecursive( ListeChainee * listeTemporaire,const char * DepartTemporaire,const char * ArriveeFinale) const;
    // Mode d'emploi : c'est une méthode récursive qui permet à partir d'une liste temporaire de trajets d'ajouter des trajets dans la liste en les combinant
    // jusqu'à ce que l'on soit arrivée à la destination
    // Contrat :AUCUN
    //

//-------------------------------------------- Constructeurs - destructeur

    Catalogue( ListeChainee* ListeTrajet);
    // Mode d'emploi  : permet d'instancier le constructeur principal qui permet de créer
    //un catalogue qui contiendra déja quelques trajets initialement (pointeur fournis en paramètres).
    // Contrat : Aucun
    //

    Catalogue( const Catalogue & unCatalogue ) ;
    // Mode d'emploi (constructeur de copie) :   permet de créer un catalogue qui contiendra les memes trajets que le catalogue
    // passé par référence en paramètre.
    // Contrat :AUCUN
    //

    Catalogue( );
    // Mode d'emploi : permet de créer un catalogue vide cad qui ne contient aucun trajet au début lors de son initialisation
    //
    // Contrat :AUCUN
    //

    virtual ~Catalogue ( );
    // Mode d'emploi : permet de libérer l'espace mémoire de l'objet qui fait appel à cette méthode
    // Contrat :AUCUN
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  ListeChainee * listeTrajet; // pointeur sur la liste chainée qui contient tout les trajets du catalogue
};

#endif // LISTECHAINEE_H
