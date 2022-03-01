//---------------------------------------------------------
// Fichier        : 01_complexite_alternative.cpp
// Version        : 01 - 2022-03-01
// Auteur(s)      : BREGUET Guy-Michel
// But            : Etude d'unbe conplexité altrnative
//                  avec des moyennes pondérées
// Modifications  :
// Remarque(s)    : NILL
// Application    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   int N = 10'000;
   int k = 0;

   for (int i=0; i<N; ++i) {
      if (i%2) {
         ++k;  // O(1)
      }  // 0.5 * O(1)
      else {
         for (int j=N; j>0; j/=2) {
            ++k;  // O(1)
         }  // O(log(N))
      }  // 0.5 * O(log(N))

      // 0.5 * O(1) + 0.5 * O(log(N))
      // 0.5 * (O(1) + O(log(N))
      // => O(log(N)

   }  // N * O(log(N) => O (N * log(N))

   return EXIT_SUCCESS;
}  // main
