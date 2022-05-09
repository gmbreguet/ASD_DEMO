//---------------------------------------------------------
// Fichier        : 03_Tri_Fusion.cpp
// Version        : 01 - 2022-05-07
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithm de tri par fusion
// Modifications  :
// Remarque(s)    : utilise le merge de algorithme
//                : https://www.cplusplus.com/reference/algorithm/merge
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T> v) {
   os << "[";
   for (auto it=v.begin(); it!=v.end(); ++it) {
      if (it!=v.begin())
         os << ", ";
      os << *it;
   }
   os << "]";
   return os;
}

//---------------------------------------------------------
// https://www.cplusplus.com/reference/algorithm/merge
template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator fusionner(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result) {

   while (true) {
    if (first1==last1) return std::copy(first2, last2, result);
    if (first2==last2) return std::copy(first1, last1, result);
    *result++ = (*first2 < *first1)? *first2++ : *first1++;
  }
}

//------------------------------------------------------
// inspiré de : https://www.delftstack.com/fr/howto/cpp/merge-sort-in-cpp/
template <typename T>
void tri_fusion(vector<T>& tab) {

   // cas trivial
   if (tab.size() <= 1) {
      return;
   }
   
   auto it = tab.begin() + tab.size() / 2;
   vector<T> v1 (tab.begin(), it);
   vector<T> v2 (it,          tab.end());

   tri_fusion(v1);
   tri_fusion(v2);
   
   fusionner(v1.begin(), v1.end(),
             v2.begin(), v2.end(),
             tab.begin() );

   cout << tab << endl;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   vector<int> tab = {5, 6, 4, 3, 2, 7, 9, 1, 8};
   cout << tab       << endl;

   tri_fusion(tab);

   cout << endl;
   return EXIT_SUCCESS;
}

//      [5, 6, 4, 3, 2, 7, 9, 1, 8]
//      [5, 6]
//      [3, 4]
//      [3, 4, 5, 6]
//      [2, 7]
//      [1, 8]
//      [1, 8, 9]
//      [1, 2, 7, 8, 9]
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
