//---------------------------------------------------------
// Fichier        : 01_somme_n.cpp
// Version        : 01 - 2021-12-05
// Auteur(s)      : BREGUET Guy-Michel
// But            : comparer les algorithmes de la somme
//                  des n premiers entier
//                   - de manière itérative
//                   - formule (Euclide) 
// Modifications  :
// Remarque(s)    : NILL
// Application    : combien de couples (x,y)
//                : tel que 1 <= x < y <= 20
//                : => n(n+1)/2 => 19*20/2 => 190
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
int sommeN_iter(int n);
int sommeN_Euclide(int n);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   int n = 12;
   cout << "boucle (" << n << ") = " << sommeN_iter(n)      << endl;
   cout << "Euclide(" << n << ") = " << sommeN_Euclide(n)   << endl;

   return EXIT_SUCCESS;
}  // main

//------------------------------------------------------
int sommeN_iter(int n) {
   int s = 0;
   for (int i=0; i<=n; ++i)
      s += i;
   return s;
}

//------------------------------------------------------
int sommeN_Euclide(int n) {
   return n * (n + 1) / 2;
}
