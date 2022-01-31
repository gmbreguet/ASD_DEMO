//---------------------------------------------------------
// Fichier        : 01_PGCD_Euclide.cpp
// Version        : 01 - 2021-12-05
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme PGCD par Euclide
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//------------------------------------------------------
int PGCD(int a, int b) {

   const size_t W = 4;
   int r;

   cout << "   a   b   r" << endl;
   cout << setw(W) << a
        << setw(W) << b << endl;

   while((r = a % b)) {
      a = b;
      b = r;
      cout << setw(W) << a
           << setw(W) << b
           << setw(W) << r << endl;
   }

   cout << setw(W) << a
       << setw(W) << b
       << setw(W) << r << endl;

  return b;

}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   PGCD(17, 7);

   return EXIT_SUCCESS;
}  // main
