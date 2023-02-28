//---------------------------------------------------------
// Fichier        : 02_Sort_G.cpp
// Version        : 01 - 2023-02-28
// Auteur(s)      : BREGUET Guy-Michel
// But            : sort générique en paramètre générique
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
ostream& operator<< (ostream& os, const vector<int>& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v.at(i);
   }
   os << "]";
   return os;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   vector<int> v = {1, 4, 3, 8, 5, 9, 2};
   cout << v << endl;
   cout << trier<int>(v, sort<vector<int>::iterator>);

   return EXIT_SUCCESS;
}
