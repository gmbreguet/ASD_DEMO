//---------------------------------------------------------
// Fichier        : 01_somme_n.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-05
// But            : comparer les algorithmes de la somme des n premiers entier
//                   - de manière itérative
//                   - algo 
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
int sommeN_iteratif(int n);
int sommeN_Euclide (int n);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   int n = 12;
   cout << "boucle (" << n << ") = " << sommeN_iteratif(n)  << endl;
   cout << "Euclide(" << n << ") = " << sommeN_Euclide(n)   << endl;

   return EXIT_SUCCESS;
}  // main

//------------------------------------------------------
int sommeN_iteratif(int n) {
   int s = 0;
   for (int i=0; i<=n; ++i)
      s += i;
   return s;
}

//------------------------------------------------------
int sommeN_Euclide(int n) {
   return n * (n + 1) / 2;
}
