//---------------------------------------------------------
// Demo           : 04_2_Iterateur_Tableau
// Fichier        : Tableau.hpp
// Version        : 03 - 2023-04-24
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe Tableau avec iterateurs
// Remarque(s)    : https://cplusplus.com/reference/iterator/iterator/
//                : /!\ les tags sont dépréciés
//---------------------------------------------------------

#ifndef TABLEAU_H
#define TABLEAU_H

#include <iostream>
#include <memory>    // destroy_at
#include "Tab_Iterateur.hpp"

//---------------------------------------------------------
template <typename T>
class Tableau;

//---------------------------------------------------------
// utilise des Tableau<T>::const_TabIterateur
template <typename T>
std::ostream& operator<< (std::ostream& os, const Tableau<T>& tab);

//---------------------------------------------------------
template <typename T>
void swap(Tableau<T>& lhs, Tableau<T>& rhs);

//---------------------------------------------------------
//    Tableau
//---------------------------------------------------------
template <typename T>
class Tableau {
   friend std::ostream& operator<< <T>(std::ostream& os, const Tableau<T>& tab);
   friend void swap <T>(Tableau<T>& lhs, Tableau<T>& rhs);    // pas obligatoire

public:
   Tableau() noexcept;
   Tableau(size_t n);
   Tableau(const Tableau&);
   Tableau& operator= (const Tableau&);

   ~Tableau();

   size_t size() const noexcept;
         T& at(size_t i);
   const T& at(size_t i) const;

   void swap(Tableau& other);

   //------------------------------------------------------
   using iterator       = Iterateur<T>;
   using const_iterator = Iterateur<const T>;

   iterator       begin();
   iterator       end();

   const_iterator cbegin() const;
   const_iterator cend()   const;

private:
   size_t   taille;
   T*       data;
};

//---------------------------------------------------------
//    friends
//---------------------------------------------------------
// utilise des Tableau<T>::const_TabIterateur
template <typename T>
std::ostream& operator<< (std::ostream& os, const Tableau<T>& tab) {
   os << "adresse : " << (const void*) &tab  << std::endl;
   os << "taille  : " << tab.size()          << std::endl;
   os << "data    : " << tab.data            << std::endl;
   os << "contenu : [";
   for (size_t i=0; i<tab.size(); ++i) {
      if (i)
         os << ", ";
      os << tab.at(i);
   }
   os << "]";
   return os;
}

//---------------------------------------------------------
//    Tableau
//---------------------------------------------------------
template <typename T>
Tableau<T>::Tableau() noexcept : taille(0), data(nullptr)
{};

//---------------------------------------------------------
template <typename T>
Tableau<T>::Tableau(size_t n) : Tableau() {
   data = reinterpret_cast<T*>(::operator new(n*sizeof(T)));
   for(; taille<n; ++taille)
      new(data + taille) T{};
}

//------------------------------------------------------
template <typename T>
Tableau<T>::Tableau(const Tableau& other)  : Tableau() {
   Tableau<T> tmp(other.taille);
   for (size_t i=0; i<taille; ++i) {
      at(i) = other.at(i);
   }
   swap(tmp);
}

//------------------------------------------------------
template <typename T>
Tableau<T>& Tableau<T>::operator= (const Tableau& other) {
   if (this == &other)
      return *this;
   Tableau<T> tmp(other);
   swap(tmp);
   return *this;
}

//---------------------------------------------------------
template <typename T>
Tableau<T>::~Tableau() {
   for(size_t i=0; i<taille; ++i)
      std::destroy_at(data + i);
   ::operator delete(data);
}

//---------------------------------------------------------
template <typename T>
size_t Tableau<T>::size() const noexcept {
   return taille;
}

//------------------------------------------------------
template <typename T>
T& Tableau<T>::at(size_t i) {
   if (i>=taille)
      throw std::out_of_range("Tableau::at");
   return *(data + i);
}

//------------------------------------------------------
template <typename T>
const T& Tableau<T>::at(size_t i) const {
   if (i>=taille)
      throw std::out_of_range("Tableau::at");
   return *(data + i);
}

//------------------------------------------------------
template <typename T>
void Tableau<T>::swap(Tableau<T>& other) {
   std::swap(taille, other.taille);
   std::swap(data,   other.data);
}

//---------------------------------------------------------
//    iterators
//---------------------------------------------------------
template <typename T>
typename Tableau<T>::iterator Tableau<T>::begin() {
   return iterator( (T*)(data));
}

//---------------------------------------------------------
template <typename T>
typename Tableau<T>::iterator Tableau<T>::end() {
   return iterator( (T*)(data + taille) );
}

//---------------------------------------------------------
template <typename T>
typename Tableau<T>::const_iterator Tableau<T>::cbegin() const  {
   return const_iterator( (const T*)(data) );
}

//---------------------------------------------------------
template <typename T>
typename Tableau<T>::const_iterator Tableau<T>::cend() const {
   return const_iterator( (const T*)(data + taille) );
}

#endif