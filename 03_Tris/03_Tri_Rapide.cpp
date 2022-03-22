//---------------------------------------------------------
// Fichier        : 03_Tri_Rapide.cpp
// Version        : 01 - 2022-03-22
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de tri rapide
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <algorithm>    // swap

using namespace std;

//---------------------------------------------------------
template <typename T>
void display(const T tab[], size_t taille);

//---------------------------------------------------------
template <typename T>
size_t partition(T tab[], size_t lo, size_t hi) {

   size_t i = lo;
   size_t j = hi - 1;

   while(true) {

      // chercher élément qui devrait être à droite du pivot
      while (tab[i] < tab[hi])
         ++i;

      // chercher élément qui devrait être à gauche du pivot
      while (j > lo and tab[j] > tab[hi])
         --j;

      if (i >= j)
         break;

      swap (tab[i], tab[j]);
   }

   return i;
}

//---------------------------------------------------------
template <typename T>
void quickSort(T tab[], size_t taille) {
   quickSort_rec(tab, 0, taille-1);
}

//---------------------------------------------------------
template <typename T>
void quickSort_rec(T tab[], size_t lo, size_t hi) {
   size_t iPivot = partition(tab, lo, hi);
   quickSort_rec(tab , lo,         iPivot - 1);
   quickSort_rec(tab , iPivot + 1, hi        );
}

//---------------------------------------------------------
int main() {

   {
      int tab[] = {10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
      const size_t TAILLE_TAB = sizeof(tab) / sizeof(int);
   }

   {
      char tab[] = {'T', 'R', 'I', 'R', 'A', 'P', 'I', 'D', 'E'};
      const size_t TAILLE = sizeof(tab) / sizeof(char);

      display(tab, TAILLE);   cout << endl;
      size_t i = partition(tab, 0, TAILLE-1);
      display(tab, TAILLE);   cout << endl;
      cout << "indice = " << i << endl;
   }


   return EXIT_SUCCESS;
}

//---------------------------------------------------------
template <typename T>
void display(const T tab[], size_t taille) {
   cout << "[";
   for (size_t i=0; i<taille; ++i) {
      if (i)
         cout << ", ";
      cout << tab[i];
   }
   cout << "]";
}

//       6 3 7 5 1 2 [4]
//                    |
//            3 1 [2] 4 7 [5]
//                 |       |
//               1 2 3     5 7 [6]
//                              |
//                              6 7
