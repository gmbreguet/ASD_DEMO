//---------------------------------------------------------
// Demo           : 04_2_ListeSimple
// Fichier        : ListeListeSimple.h
// Version        : 02 - 2022.05.04
// Auteur(s)      : BREGUET Guy-Michel
// But            : Liste dynamique avec exceptions
// Modifications  : nommages
// Remarque(s)    : très incomplète (déplacement, copie profonde, ...)
//---------------------------------------------------------

#ifndef LISTE_SIMPLE_HPP
#define LISTE_SIMPLE_HPP

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
// operator <<
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

#include "ListeSimple_Impl.hpp"

#endif /* LISTE_SIMPLE_HPP */

