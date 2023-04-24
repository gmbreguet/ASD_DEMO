//---------------------------------------------------------
// Demo           : 04_2_Iterateur_Tableau
// Fichier        : Tab_Iterateur.hpp
// Version        : 03 - 2023-04-24
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe random iterateur
// Modifications  :
// Remarque(s)    : https://cplusplus.com/reference/iterator/iterator/
//                : /!\ les tags sont dépréciés
//---------------------------------------------------------

#ifndef ITERATEUR_TABLEAU_H
#define ITERATEUR_TABLEAU_H

#include <iterator>

//---------------------------------------------------------
template <typename T>
class Iterateur : public std::iterator<std::random_access_iterator_tag, T> {
public:
   // constructeurs et destructeur
   Iterateur(const Iterateur<T>& it)                           = default;
   Iterateur(T* ptr = nullptr)                                 { this->ptr = ptr; }
  ~Iterateur()                                                 {}
      
   // operateurs
   operator bool() const                                       { return ptr; }
   Iterateur<T>& operator= (const Iterateur<T>& it)            = default;
   Iterateur<T>& operator= (T* ptr)                            { this->ptr = ptr; return *this; }
      
   Iterateur<T>& operator++ ()                                 {                  ++ptr; return *this; }
   Iterateur<T>& operator-- ()                                 {                  --ptr; return *this; }
   Iterateur<T>  operator++ (int)                              { auto tmp(*this); ++ptr; return tmp; }
   Iterateur<T>  operator-- (int)                              { auto tmp(*this); --ptr; return tmp; }

   Iterateur<T>  operator+  (const std::ptrdiff_t mvt) const   { ptr += mvt; return *this; }
   Iterateur<T>  operator-  (const std::ptrdiff_t mvt) const   { ptr -= mvt; return *this; }
   
         T& operator* ()                                       { return *ptr; }
   const T& operator* () const                                 { return *ptr; }
                  
   bool operator== (const Iterateur& rhs) const                { return this->ptr == rhs.ptr; }
   bool operator!= (const Iterateur& rhs) const                { return not(*this == rhs);    }
   bool operator<  (const Iterateur& rhs) const                { return this->ptr < rhs.ptr;  }
   bool operator>  (const Iterateur& rhs) const                { return       rhs < *this;    }
   bool operator<= (const Iterateur& rhs) const                { return not(*this > rhs);     }
   bool operator>= (const Iterateur& rhs) const                { return not(*this < rhs);     }

private:
   T* ptr;
};

#endif