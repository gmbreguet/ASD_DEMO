//---------------------------------------------------------
// Fichier        : 04_1_Tableau_taille_fixe.cpp
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
ostream& operator<< (ostream& os, const Tableau<T>& tab);

//---------------------------------------------------------
template <typename T>
void swap(Tableau<T>& lhs, Tableau<T>& rhs);

//---------------------------------------------------------
template <typename T>
class Tableau {
   friend ostream& operator<< <T>(ostream& os, const Tableau<T>& tab);
   friend void     swap       <T>(Tableau<T>& lhs, Tableau<T>& rhs);    // pas obligatoire

public:
   Tableau() noexcept;
   Tableau(size_t n);
   Tableau(const Tableau& other);
   Tableau& operator= (const Tableau& other);

  ~Tableau();

   size_t size() const noexcept;
         T& at(size_t i);
   const T& at(size_t i) const;

   void swap(Tableau& other);

private:
   byte* ptr(size_t i) const;

   size_t   taille;
   byte*    data;
};

//---------------------------------------------------------
void afficher(const string& msg, const Tableau<int>& tab) {
   cout << msg << endl
        << tab << endl
        << endl;
}

//---------------------------------------------------------
int main() {
   
   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   constructeurs et affectation"          << endl;
   cout << "----------------------------------------" << endl;
   Tableau<int> tab0;
   afficher("Tableau<int> tab0", tab0);

   Tableau<int> tab1(3);
   afficher("Tableau<int> tab1(3)", tab1);

   Tableau<int> tab2(tab1);
   afficher("Tableau<int> tab2(tab1)", tab2);

   tab0 = tab2;
   afficher("tab0 = tab2", tab0);

   cout << "----------------------------------------" << endl;
   cout << "   swap"                                  << endl;
   cout << "----------------------------------------" << endl;
   tab0.swap(tab1);
   afficher("tab0 : tab0.swap(tab1)", tab0);
   afficher("tab1 :                ", tab1);

   cout << "----------------------------------------" << endl;
   cout << "   lectures et affectations .at"          << endl;
   cout << "----------------------------------------" << endl;
   cout << "tab1.at(0)  : "      << tab1.at(0)        << endl;
   cout << "tab1.at(0)  = 9";    tab1.at(0) = 9; cout << endl;
   cout << "tab1.at(0)  : "      << tab1.at(0)        << endl;
   cout << "tab1        : "      << tab1              << endl;

   cout << "tab1.at(3)  => exception"                 << endl;
   cout << "tab1.at(3)  = "      << tab1.at(3)        << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

//---------------------------------------------------------
//    friend
//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Tableau<T>& tab) {
   os << "adresse : " << (const void*) &tab  << endl;
   os << "taille  : " << tab.size()          << endl;
   os << "data    : " << tab.data            << endl;
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
template <typename T>
void swap(Tableau<T>& lhs, Tableau<T>& rhs) {
   lhs.swap(rhs);
}

//---------------------------------------------------------
//    private
//---------------------------------------------------------
template <typename T>
byte* Tableau<T>::ptr(size_t i) const {
   return data + i*sizeof(T);
}

//---------------------------------------------------------
//    public
//---------------------------------------------------------
template <typename T>
Tableau<T>::Tableau() noexcept : taille(0), data(nullptr)
{};

//------------------------------------------------------
template <typename T>
Tableau<T>::Tableau(size_t n)  : Tableau() {
   data = reinterpret_cast<byte*>(::operator new(n*sizeof(T)));
   for(; taille<n; ++taille)
      new(ptr(taille)) T{};
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

//------------------------------------------------------
template <typename T>
Tableau<T>::~Tableau() {
   for(size_t i=0; i<taille; ++i)
      destroy_at(ptr(i));
   ::operator delete(data);
}

//------------------------------------------------------
template <typename T>
size_t Tableau<T>::size() const noexcept {
   return taille;
}

//------------------------------------------------------
template <typename T>
T& Tableau<T>::at(size_t i) {
   if (i>=taille)
      throw out_of_range("Tableau::at");
   return *(reinterpret_cast<T*>(ptr(i)));
}

//------------------------------------------------------
template <typename T>
const T& Tableau<T>::at(size_t i) const {
   if (i>=taille)
      throw out_of_range("Tableau::at");
   return *(reinterpret_cast<T*>(ptr(i)));
}

//------------------------------------------------------
template <typename T>
void Tableau<T>::swap(Tableau<T>& other) {
   std::swap(taille, other.taille);
   std::swap(data,   other.data);
}