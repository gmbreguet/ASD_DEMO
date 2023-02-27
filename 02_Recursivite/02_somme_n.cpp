//---------------------------------------------------------
// Fichier        : 02_somme_n.cpp
// Version        : 03 - 2023-02-27
// Auteur(s)      : BREGUET Guy-Michel
// But            : comparer les algorithmes de la somme
//                  des n premiers entier
//                   - de manière itérative
//                   - formule (Euclide)
//                   - version récursive
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
unsigned long sommeN_iter     (unsigned n);
unsigned long sommeN_Euclide  (unsigned n);
unsigned long sommeN_Recursive(unsigned n);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   unsigned n = 12;
   cout << "boucle   (" << n << ") = " << sommeN_iter(n)      << endl;
   cout << "Euclide  (" << n << ") = " << sommeN_Euclide(n)   << endl;
   cout << "Recursive(" << n << ") = " << sommeN_Recursive(n) << endl;

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

//------------------------------------------------------
unsigned long sommeN_Recursive(unsigned n) {
   if (n == 1)
      return 1;
   return n + sommeN_Recursive(n - 1);
}
