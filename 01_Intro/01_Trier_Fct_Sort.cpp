//---------------------------------------------------------
// Fichier        : 01_Trier_Fct_Sort.cpp
// Version        : 02 - 2023-03-02
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'utilisation d'une fonction de tri générique
//                  passée en paramètre d'une fonction générique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//------------------------------------------------------
template <typename T, typename Fonction>
void trier(vector<T>& vect,
           Fonction   fct) {
   cout << "void trier(vector<T>& v, Fonction fct)" << endl;
   fct(vect.begin(), vect.end());
}

//------------------------------------------------------
template <typename T, typename Fonction>
void trier(typename vector<T>::iterator begin,
           typename vector<T>::iterator end,
           Fonction                     fct) {
   cout << "void trier(typename vector<T>::iterator begin, typename vector<T>::iterator end, Fonction fct)" << endl;
   fct(begin, end);
}


//------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {
   
   cout << "-------------------" << endl;
   cout << "vector<T>"           << endl;
   cout << "-------------------" << endl;
   vector<int> v1 = {1, 4, 3, 8, 5, 9, 2};
   cout << v1 << endl;
   trier<int>(v1, sort<vector<int>::iterator>);
   cout << v1 << endl << endl;

   
   cout << "-------------------" << endl;
   cout << "vector<T>::iterator" << endl;
   cout << "-------------------" << endl;
   vector<double> v2 = {1.1, 4.4, 3.3, 8.8, 5.5, 9.9, 2.2};
   cout << v2 << endl;
   trier<double>(v2.begin(), v2.end(), sort<vector<double>::iterator>);
   cout << v2 << endl << endl;

   return EXIT_SUCCESS;
}

//------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v.at(i);
   }
   os << "]";
   return os;
}

//      -------------------
//      vector<T>
//      -------------------
//      [1, 4, 3, 8, 5, 9, 2]
//      void trier(vector<T>& v, Fonction fct)
//      [1, 2, 3, 4, 5, 8, 9]
//
//      -------------------
//      vector<T>::iterator
//      -------------------
//      [1.1, 4.4, 3.3, 8.8, 5.5, 9.9, 2.2]
//      void trier(typename vector<T>::iterator begin, typename vector<T>::iterator end, Fonction fct)
//      [1.1, 2.2, 3.3, 4.4, 5.5, 8.8, 9.9]
