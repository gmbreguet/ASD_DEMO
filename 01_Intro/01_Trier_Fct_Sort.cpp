//---------------------------------------------------------
// Fichier        : 01_Trier_Fct_Sort.cpp
// Version        : 01 - 2023-02-28
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
vector<T> trier(vector<T> v, Fonction fct) {
   fct(v.begin(), v.end());
   return v;
}

//------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {
   
   {
      cout << "----------------" << endl;
      cout << "avec des entiers" << endl;
      cout << "----------------" << endl;
      const vector<int> v1 = {1, 4, 3, 8, 5, 9, 2};
      cout << v1 << endl;
      
      vector<int> v2 = trier(v1, sort<vector<int>::iterator>);
      cout << v2 << endl;
   }

   cout << endl;
   
   {
      cout << "----------------" << endl;
      cout << "avec des doubles" << endl;
      cout << "----------------" << endl;
      const vector<double> v1 = {1.1, 4.4, 3.3, 8.8, 5.5, 9.9, 2.2};
      cout << v1 << endl;
      
      vector<double> v2 = trier(v1, sort<vector<double>::iterator>);
      cout << v2 << endl;
   }

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

//      ----------------
//      avec des entiers
//      ----------------
//      [1, 4, 3, 8, 5, 9, 2]
//      [1, 2, 3, 4, 5, 8, 9]
//
//      ----------------
//      avec des doubles
//      ----------------
//      [1.1, 4.4, 3.3, 8.8, 5.5, 9.9, 2.2]
//      [1.1, 2.2, 3.3, 4.4, 5.5, 8.8, 9.9]
