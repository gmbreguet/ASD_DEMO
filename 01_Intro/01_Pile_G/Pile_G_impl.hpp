//---------------------------------------------------------
// Demo           : Pile_G
// Fichier        : Pile_G_Impl.h
// Version        : 01 - 2022.02.28
// Auteur(s)      : BREGUET Guy-Michel
// But            : Pile générique avec exceptions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef pile_g_impl_h
#define pile_g_impl_h

//---------------------------------------------------
template <typename T, int capacite>
Pile<T, capacite>::Pile() {
   taille = 0;
}

//---------------------------------------------------
template <typename T, int capacite>
void Pile<T, capacite>::empiler(const T& valeur) {
   if (taille >= capacite)
      throw Pile_Pleine();
   tab[taille++] = valeur;
}

//---------------------------------------------------
template <typename T, int capacite>
void Pile<T, capacite>::depiler() {
   if (taille == 0)
      throw Pile_Vide();
   --taille;
}

//---------------------------------------------------
template <typename T, int capacite>
T Pile<T, capacite>::sommet() const {
   if (taille == 0)
      throw Pile_Vide();
   return tab[taille-1];
}

//---------------------------------------------------
template <typename T, int capacite>
bool Pile<T, capacite>::estVide() const {
   return taille==0;
}

//---------------------------------------------------
template <typename T, int capacite>
bool Pile<T, capacite>::estPleine() const  {
   return taille == capacite;
}

#endif /* pile_g_impl_h */
