//---------------------------------------------------------
// Demo           : Pile_G
// Fichier        : Pile_G.h
// Version        : 02 - 2022.03.01
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
template <typename T, int capacite>
class Pile {
public:
   Pile();
   void empiler(const T& valeur);               // => exception si pleine
   void depiler();                              // => exception si vide
   T    sommet()    const;                      // => exception si vide

   bool estVide()   const;
   bool estPleine() const;

private:
   size_t taille;
   T tab[size_t(capacite)];
};

#include "Pile_G_impl.hpp"

#endif /* pile_g_h */
