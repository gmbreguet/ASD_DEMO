//---------------------------------------------------------
// Fichier        : 04_2_Iterateur_Tableau.cpp
// Version        : 03 - 2023-04-24
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe Tableau avec iterateurs
// Modifications  :
// Remarque(s)    : https://cplusplus.com/reference/iterator/iterator/
//                : /!\ les tags sont dépréciés
//---------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <iterator>     // std::iterator, std::input_iterator_tag

//---------------------------------------------------------
using namespace std;

//---------------------------------------------------------
//    Iterateur
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

//---------------------------------------------------------
template <typename T>
class Tableau;

//---------------------------------------------------------
// utilise des Tableau<T>::const_TabIterateur
template <typename T>
ostream& operator<< (ostream& os, const Tableau<T>& tab) {
   os << "[";
   for (auto it=tab.cbegin(); it!=tab.cend(); ++it) {
      if (it!=tab.cbegin())
         os << ", ";
      os << *it;
   }
   os << "]";
   return os;
}

//---------------------------------------------------------
//    Tableau
//---------------------------------------------------------
template <typename T>
class Tableau {
   friend ostream& operator<< <T>(ostream& os, const Tableau<T>& tab);

public:
   //------------------------------------------------------
   using iterator       = Iterateur<T>;
   using const_iterator = Iterateur<const T>;
   
   iterator       begin()         { return iterator( (T*)(data)          ); }
   iterator       end()           { return iterator( (T*)(data + taille) ); }

   const_iterator cbegin() const  { return const_iterator( (const T*)(data)          ); }
   const_iterator cend()   const  { return const_iterator( (const T*)(data + taille) ); }

   //------------------------------------------------------
   Tableau() noexcept : taille(0), data(nullptr) {};

   //------------------------------------------------------
   Tableau(size_t n)  : Tableau() {
      data = reinterpret_cast<T*>(::operator new(n*sizeof(T)));
      for(; taille<n; ++taille)
         new(data + taille) T{};
   }

   //------------------------------------------------------
   ~Tableau() {
      for(size_t i=0; i<taille; ++i)
         destroy_at(data + i);
      ::operator delete(data);
   }

   //------------------------------------------------------
   Tableau(const Tableau&)             = delete;
   Tableau& operator= (const Tableau&) = delete;

   //------------------------------------------------------
   size_t size() const noexcept {
      return taille;
   }

   //------------------------------------------------------
   T& at(size_t i) {
      if (i>=taille)
         throw out_of_range("Tableau::at");
      return *(data + i);
   }

   //------------------------------------------------------
   const T& at(size_t i) const {
      if (i>=taille)
         throw out_of_range("Tableau::at");
      return *(data + i);
   }

private:
   size_t   taille;
   T*       data;
};

//---------------------------------------------------------
template <typename T>
void init(Tableau<T>& tab, T start = T{}) {
   for (T& v : tab)
      v = start++;
}

//---------------------------------------------------------
int main() {
   Tableau<int> tab(10);
   init(tab, 1);
   cout << tab << endl;    // operateur de flux avec itérateurs constants
   
   Tableau<int>::iterator it = tab.begin();
   cout << "*it   : " << *it     << endl;
   ++it;
   ++it;
   cout << "*it   : " << *it     << endl;
   it++;
   cout << "*it   : " << *it     << endl;
   cout << "*it+2 : " << *it + 2 << endl;

   return EXIT_SUCCESS;
}

//      [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//      *it   : 1
//      *it   : 2
//      *it   : 3
//      *it+2 : 5

