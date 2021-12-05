//---------------------------------------------------------
// Fichier        : 01_somme_n.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-05
// But            : démontrer l'algorithme PGCD par Euclide
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
int PGDC(int a, int b) {
   int r;
   while( r = a % b ) {
      a = b;
      b = r;
   }
   return b;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   int a = 49;
   int b =  7;
   cout << "PGDC(" << a << ", " << b << ") = " << PGDC(a, b) << endl;

   return EXIT_SUCCESS;
}  // main
