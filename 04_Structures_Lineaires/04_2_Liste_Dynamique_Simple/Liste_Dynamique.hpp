//---------------------------------------------------------
// Demo           : 04_2_Liste_Dynamique
// Fichier        : Liste_Dynamique.h
// Version        : 01 - 2022.04.02
// Auteur(s)      : BREGUET Guy-Michel
// But            : Liste dynamique avec exceptions
// Modifications  :
// Remarque(s)    : très incomplète (déplacement, copie profonde, ...)
//---------------------------------------------------------

#ifndef LISTE_DYNAMIQUE_HPP
#define LISTE_DYNAMIQUE_HPP

//-------------------------------------------------
#include <iostream>
#include <string>
#include <exception>
#include <memory>       // destroy_at

//-------------------------------------------------
class liste_vide : public std::runtime_error {
public:
   explicit liste_vide(const std::string& s) : std::runtime_error(s) {}
   explicit liste_vide(const char*   s)      : std::runtime_error(s) {}
};

//---------------------------------------------------
// Déclaration
template <typename T>
class Liste;

//---------------------------------------------------
// Struct Noeud
template <typename T>
struct Noeud {
   T         donnee;
   Noeud<T>* suivant;
};
 
//---------------------------------------------------
// coperator <<
template <typename T>
std::ostream& operator<< (std::ostream& os, const Liste<T>& liste);

//---------------------------------------------------
// classe Liste
template <typename T>
class Liste {
   friend std::ostream& operator<< <T>(std::ostream& os, const Liste<T>& liste);

public:
    Liste();
   ~Liste();

   T      premier() const;
   bool   estVide() const;
   size_t taille()  const;

   T*     ptrElement(const T& valeur) const;

   void   inserer(const T& valeur);
   void   supprimer();

   template<typename Fonction>
   void   parcourir(Fonction fonction);

private:
    Noeud<T>* tete;
    size_t    longueur;
};

#include "Liste_Dynamique_Impl.hpp"

#endif /* LISTE_DYNAMIQUE_HPP */

