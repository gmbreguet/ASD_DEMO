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
template <typename T>
Pile<T>::Pile(size_t capacite)
: capacite(capacite) {
   taille = 0;
   tab.reserve(capacite);
}

//---------------------------------------------------
template <typename T>
void Pile<T>::empiler(const T& valeur) {
   if (taille >= capacite)
      throw Pile_Pleine();
   tab[taille++] = valeur;
}

//---------------------------------------------------
template <typename T>
void Pile<T>::depiler() {
   if (taille == 0)
      throw Pile_Vide();
   --taille;
}

//---------------------------------------------------
template <typename T>
T Pile<T>::sommet() const {
   if (taille == 0)
      throw Pile_Vide();
   return tab[taille-1];
}

//---------------------------------------------------
template <typename T>
bool Pile<T>::estVide() const {
   return taille==0;
}

//---------------------------------------------------
template <typename T>
bool Pile<T>::estPleine() const  {
   return taille == capacite;
}

#endif /* pile_g_impl_h */
