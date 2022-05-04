//---------------------------------------------------------
// Demo           : 04_2_ListeSimple
// Fichier        : ListeSimple_Impl.hpp
// Version        : 02 - 2022.05.04
// Auteur(s)      : BREGUET Guy-Michel
// But            : Liste dynamique avec exceptions
// Modifications  : nommages
// Remarque(s)    : très incomplète (déplacement, copie profonde, ...)
//---------------------------------------------------------

//---------------------------------------------------
#ifndef LISTE_SIMPLE_IMPL_HPP
#define LISTE_SIMPLE_IMPL_HPP

//---------------------------------------------------
// friend
//---------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const Liste<T>& liste) {
   os << "(";
   const Noeud<T>* courant = liste.tete;
   while (courant != nullptr){
      if (courant != liste.tete)
         os << ", ";
      os << courant->donnee;
      courant = courant->suivant;
   }
   os << ")";
   return os;
}

//---------------------------------------------------
// Constructeur
template <typename T>
Liste<T>::Liste ()
:tete(NULL), longueur(0) {}
 
//---------------------------------------------------
// Destructeur
template <typename T>
Liste<T>::~Liste() {
   
   Noeud<T>* tmp = tete;
   
   while (tete) {
      tmp  = tete;
      tete = tete->suivant;
      delete tmp;
   }
}

//---------------------------------------------------
template <typename T>
T Liste<T>::premier() const{
   if (this->longueur == 0)
      throw liste_vide("Liste vide");
    return tete->donnee;
}

//---------------------------------------------------
template <typename T>
bool Liste<T>::estVide() const{
    return longueur==0;
}

//---------------------------------------------------
template <typename T>
size_t Liste<T>::taille() const{
    return longueur;
}

//---------------------------------------------------
template <typename T>
T* Liste<T>::ptrElement(const T& valeur) const {
   Noeud<T>* courant = tete;
   while (courant and valeur != courant->donnee) {
      courant = courant->suivant;
   }
   return &(courant->donnee);
}

//---------------------------------------------------
template <typename T>
void Liste<T>::inserer(const T& valeur) {
   
   Noeud<T>* nouveau = new Noeud<T> {valeur, tete};
   tete              = nouveau;
   longueur++;
}
 
//---------------------------------------------------
template <typename T>
void Liste<T>::supprimer() {
   Noeud<T>* tmp = tete;
   tete          = tete->suivant;
   delete tmp;
   longueur--;
}

//---------------------------------------------------
template <typename T>
template <typename Fonction>
void Liste<T>::parcourir(Fonction fonction) {
   Noeud<T>* courant = tete;
   while (courant) {
      courant->donnee = fonction(courant->donnee);
      courant = courant->suivant;
   }
}

#endif /* LISTE_SIMPLE_IMPL_HPP */
