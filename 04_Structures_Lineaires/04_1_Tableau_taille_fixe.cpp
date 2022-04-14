//---------------------------------------------------------
// Fichier        : 04_Tableau_taille_fixe.cpp
// Version        : 01 - 2022-04-12
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe
//                : Tableau à taille fixe
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

//---------------------------------------------------------
using namespace std;
using std::byte;

//---------------------------------------------------------
template <typename T>
class Tableau;

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Tableau<T>& tab) {
   os << "[";
   for (size_t i=0; i<tab.size(); ++i) {
      if (i)
         os << ", ";
      os << tab.at(i);
   }
   os << "]";
   return os;
}

//---------------------------------------------------------
template <typename T>
class Tableau {
   friend ostream& operator<< <T>(ostream& os, const Tableau<T>& tab);

public:
   //------------------------------------------------------
   Tableau() noexcept : taille(0), data(nullptr) {};

   //------------------------------------------------------
   Tableau(size_t n)  : Tableau() {
      data = reinterpret_cast<byte*>(::operator new(n*sizeof(T)));
      for(; taille<n; ++taille)
         new(ptr(taille)) T{};
   }

   //------------------------------------------------------
   ~Tableau() {
      for(size_t i=0; i<taille; ++i)
         destroy_at(ptr(i));
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
      return *(reinterpret_cast<T*>(ptr(i)));
   }

   //------------------------------------------------------
   const T& at(size_t i) const {
      if (i>=taille)
         throw out_of_range("Tableau::at");
      return *(reinterpret_cast<T*>(ptr(i)));
   }

private:
   //------------------------------------------------------
   byte* ptr(size_t i) const {
      return data + i*sizeof(T);
   }

   //------------------------------------------------------
   size_t   taille;
   byte*    data;
};

//---------------------------------------------------------
int main() {
   
   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   constructeurs"                         << endl;
   cout << "----------------------------------------" << endl;
   Tableau<int> tab0;
   Tableau<int> tab1(3);
   cout << "tab0        : " << tab0                   << endl;
   cout << "tab1        : " << tab1                   << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   lectures et affectations .at"          << endl;
   cout << "----------------------------------------" << endl;
   cout << "tab1.at(0)  : "      << tab1.at(0)        << endl;
   cout << "tab1.at(0)  = 9";    tab1.at(0) = 9; cout << endl;
   cout << "tab1.at(0)  : "      << tab1.at(0)        << endl;
   cout << "tab1        : "      << tab1              << endl;
   cout << "tab1.at(3)  = "      << tab1.at(3)        << endl;
   cout << endl;
 
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

//      ----------------------------------------
//         constructeurs
//      ----------------------------------------
//      tab0        : []
//      tab1        : [0, 0, 0]
//
//      ----------------------------------------
//         lectures et affectations .at
//      ----------------------------------------
//      tab1.at(0)  : 0
//      tab1.at(0)  = 9
//      tab1.at(0)  : 9
//      tab1        : [9, 0, 0]
//      tab1.at(3)  = libc++abi: terminating with uncaught exception of type std::out_of_range: Oops
//      terminating with uncaught exception of type std::out_of_range: Oops
//      (lldb)
