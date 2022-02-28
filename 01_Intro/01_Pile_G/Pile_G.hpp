//---------------------------------------------------------
// Demo           : Pile_G
// Fichier        : Pile_G.h
// Version        : 01 - 2022.02.28
// Auteur(s)      : BREGUET Guy-Michel
// But            : Pile générique avec exceptions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef pile_g_h
#define pile_g_h

#include <vector>

//---------------------------------------------------
// Exception
class Pile_Vide{};
class Pile_Pleine{};

//---------------------------------------------------
template <typename T>
class Pile {
public:
   Pile(size_t capacite);
   void empiler(const T& valeur);               // => exception si pleine
   void depiler();                              // => exception si vide
   T    sommet() const;                         // => exception si vide

   bool estVide()   const;
   bool estPleine() const;

private:
   const size_t capacite; 
         size_t taille;
   std::vector<T> tab;
};

#include "Pile_G_impl.hpp"

#endif /* pile_g_h */
