//---------------------------------------------------------
// Fichier        : 03_nth_elemente.cpp
// Version        : 01 - 2022.04.11
// Auteur(s)      : BREGUET Guy-Michel
// But            : démo et complément de algorithm::nth_element
// Modifications  :
// Remarque(s)    : https://www.cplusplus.com/reference/algorithm/nth_element
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <algorithm>    // nth_element
#include <vector>

using namespace std;

//---------------------------------------------------
template <typename Iterator>
void afficher (Iterator first, Iterator last);

//---------------------------------------------------
template <typename T>
bool lowerThan(const T& lhs, const T& rhs) {
   return lhs > rhs;
}

//---------------------------------------------------
template <typename T>
bool greaterThan(const T& lhs, const T& rhs) {
   return lhs > rhs;
}

//---------------------------------------------------
// exemples de using génériques
using VectInt        = vector<int>;
using VectDouble     = vector<double>;

//---------------------------------------------------
template <typename Iterator, typename Fonction>
void test (Iterator first, Iterator nth, Iterator last, Fonction fonction) {
   cout << "---------------------" << endl;
   afficher(first, last); cout << endl;
   nth_element(first, nth, last, fonction);
   afficher(first, last); cout << endl;
}

//---------------------------------------------------
int main() {

   // vecteurs à traiter
   int tabInt[]         = {4,   8,   3,   9,   8,   2,   1,   5,   6};
   const size_t TAILLE  = sizeof(tabInt) / sizeof(tabInt[0]);
   VectInt     vInt     = {4,   8,   3,   9,   8,   2,   1,   5,   6};
   VectDouble  vDouble  = {4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1};

   test(tabInt,          tabInt+2,          tabInt+TAILLE,  lowerThan<int>);
   test(vInt.begin(),    vInt.begin()+2,    vInt.end(),     greaterThan<int>);
   test(vDouble.begin(), vDouble.begin()+2, vDouble.end(),  greaterThan<double>);
   
   return EXIT_SUCCESS;
}

//---------------------------------------------------
template <typename Iterator>
void afficher (Iterator first, Iterator last) {
   cout << "[";
   for (auto crt=first; crt!=last; ++crt) {
      if (crt != first)
         cout << ", ";
      cout << *crt;
   }
   cout << "]";
}

//      ---------------------
//      [4, 8, 3, 9, 8, 2, 1, 5, 6]
//      [1, 2, 3, 4, 5, 6, 9, 8, 8]
//      ---------------------
//      [4, 8, 3, 9, 8, 2, 1, 5, 6]
//      [1, 2, 3, 4, 5, 6, 9, 8, 8]
//      ---------------------
//      [4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1]
//      [1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 9.1, 8.1, 8.1]
