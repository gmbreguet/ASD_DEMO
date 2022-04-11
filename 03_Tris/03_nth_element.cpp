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
#include <list>

using namespace std;

//---------------------------------------------------
template <typename Iterator>
void afficher (const Iterator first, const Iterator last);

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
template <typename Iterator, typename Fonction>
void test (Iterator first, Iterator nth, Iterator last, Fonction fonction) {
   cout << "---------------------" << endl;
   afficher(first, last); cout << endl;
   nth_element(first, nth, last, fonction);
   afficher(first, last); cout << endl;
}

//---------------------------------------------------
// différentes structures de données
template <typename T, int taille>
using TabC        = T[taille];
using VectInt     = vector<int>;
using VectDouble  = vector<double>;
using ListChar    = list<char>;

//---------------------------------------------------
int main() {

   // vecteurs à traiter
   const size_t TAILLE  = 10;
   TabC<int, TAILLE> tab10Int = {4,   8,   3,   9,   8,   2,   1,   5,   6};
   VectInt           vInt     = {4,   8,   3,   9,   8,   2,   1,   5,   6};
   VectDouble        vDouble  = {4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1};
   ListChar          lChar    = {'b', 'o', 'n', 'j', 'o', 'u', 'r', ' ', 'a', ' ', 't', 'o', 'u', 's'};

   test(tab10Int,        tab10Int+2,        tab10Int+TAILLE, lowerThan<int>);
   test(vInt.begin(),    vInt.begin()+2,    vInt.end(),      greaterThan<int>);
   test(vDouble.begin(), vDouble.begin()+2, vDouble.end(),   greaterThan<double>);
   
   
   // les itérateurs attendus par nth_element sont de type random_access_iterator
   // https://www.cplusplus.com/reference/iterator/RandomAccessIterator/?kw=RandomAccessIterator
   // Random-access iterators are iterators that can be used to access elements at an arbitrary
   // offset position relative to the element they point to, offering the same functionality as pointers
   // => typiquement pas des listes
   
   // ListChar::iterator ito = find(lChar.begin(), lChar.end(), 'o');
   // test(lChar.begin(),   lChar.begin()+2,   lChar.end(),     lowerThan<char>);
   // => le lChar.begin()+2 ne passe pas la compilation
   
   // cout << *ito << endl;
   // test(lChar.begin(),   ito,               lChar.end(),     lowerThan<char>);
   // => auto ito ... sera de type iterator (pas random itearator)
   // => ne passe pas la compilation

   return EXIT_SUCCESS;
}

//---------------------------------------------------
template <typename Iterator>
void afficher (const Iterator first, const Iterator last) {
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
//      [9, 8, 8, 6, 3, 2, 1, 5, 4]
//      ---------------------
//      [4, 8, 3, 9, 8, 2, 1, 5, 6]
//      [9, 8, 8, 6, 3, 2, 1, 5, 4]
//      ---------------------
//      [4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1]
//      [9.1, 8.1, 8.1, 6.1, 3.1, 2.1, 1.1, 5.1, 4.1]
