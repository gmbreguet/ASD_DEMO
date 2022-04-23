//---------------------------------------------------------
// Fichier        : 01_somme_n.cpp
// Version        : 02 - 2022-04-23
// Auteur(s)      : BREGUET Guy-Michel
// But            : comparer les algorithmes de la somme
//                  des n premiers entier
//                   - de manière itérative
//                   - formule (Euclide) 
// Modifications  : ajout de unsigned long et unsigned
// Remarque(s)    : NILL
// Application    : combien de couples (x,y)
//                : tel que 1 <= x < y <= 20
//                : => n(n+1)/2 => 19*20/2 => 190
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
unsigned long sommeN_iter   (unsigned n);
unsigned long sommeN_Euclide(unsigned n);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   unsigned n = 12;
   cout << "boucle (" << n << ") = " << sommeN_iter(n)      << endl;
   cout << "Euclide(" << n << ") = " << sommeN_Euclide(n)   << endl;

   return EXIT_SUCCESS;
}  // main

//------------------------------------------------------
unsigned long sommeN_iter(unsigned n) {
   unsigned long s = 0;
   for (unsigned i=0; i<=n; ++i)
      s += i;
   return s;
}

//------------------------------------------------------
unsigned long sommeN_Euclide(unsigned n) {
   return (unsigned long)n * (n + 1) / 2;
}
