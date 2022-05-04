//---------------------------------------------------------
// Fichier        : 04_2_Iterateur_Tableau.cpp
// Version        : 01 - 2022-05-04
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe Tableau avec iterateurs
// Modifications  :
// Remarque(s)    :
// https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
//---------------------------------------------------------
#include <iostream>
#include <cstdlib>

//---------------------------------------------------------
using namespace std;

//---------------------------------------------------------
//    Iterateur
//---------------------------------------------------------
using difference_type = std::ptrdiff_t;

template <typename T>
class Iterateur {
private:
   T*          ptr;
public:

   // debug
   void put() const { cout << (void*)ptr; }
   
   // constructeurs et destructeur
   Iterateur(const Iterateur<T>& it)                           = default;
   Iterateur(T* ptr = nullptr)                                 { this->ptr = ptr; }
  ~Iterateur()                                                 {}
      
   // operateurs
   Iterateur<T>& operator= (const Iterateur<T>& it)            = default;
   Iterateur<T>& operator= (T* ptr)                            { this->ptr = ptr; return *this; }
      
   Iterateur<T>& operator++()                                  {                  ++ptr; return *this; }
   Iterateur<T>& operator--()                                  {                  --ptr; return *this; }
   Iterateur<T>  operator++(int)                               { auto tmp(*this); ++ptr; return tmp;   }
   Iterateur<T>  operator--(int)                               { auto tmp(*this); --ptr; return tmp;   }

   Iterateur<T>  operator+ (const difference_type mvt) const   { ptr += mvt; return *this;             }
   Iterateur<T>  operator- (const difference_type mvt) const   { ptr -= mvt; return *this;             }
   
         T& operator*  ()                                         { return *ptr; }
   const T& operator*  () const                                   { return *ptr; }
                  
   bool     operator== (const Iterateur& rhs) const            { return this->ptr == rhs.ptr; }
   bool     operator!= (const Iterateur& rhs) const            { return this->ptr != rhs.ptr; }
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
   using TabIterateur       = Iterateur<T>;
   using TabIterateur_Const = Iterateur<const T>;
   
   TabIterateur      begin()          { return TabIterateur(data); }
   TabIterateur      end()            { return TabIterateur(data + taille); }

   TabIterateur_Const cbegin() const  { return TabIterateur_Const( (const T*)(data) ); }
   TabIterateur_Const cend()   const  { return TabIterateur_Const( (const T*)(data + taille) ); }

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
   
   Tableau<int>::TabIterateur it = tab.begin();
   cout << "*it   : " << *it     << endl;
   ++it;
   cout << "*it   : " << *it     << endl;
   it++;
   cout << "*it   : " << *it     << endl;
   cout << "*it+2 : " << *it + 2 << endl;

   cout << endl;
 
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}
