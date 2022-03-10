//---------------------------------------------------------
// Fichier        : 01_PGCD_Euclide.cpp
// Version        : 01 - 2022-01-27
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme du calcul PGCD
//                : en mode récursif
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
unsigned PGCD(unsigned a, unsigned b) {

   // nbre d'appels
   static unsigned appels = 0;
   cout << ++appels << ") " << " a=" << a << " b=" << b << endl;

   // cas trivial
   if (b == 0)
      return a;

   // appel récursif
   return PGCD(b, a%b);
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "PGCD (Euclide) récursif" << endl;

   unsigned pgcd = PGCD(8, 5);
//   unsigned pgcd = PGCD(34, 21);
   cout << endl;
   cout << "PGCD(34, 21) = " << pgcd << endl;

   return EXIT_SUCCESS;
}

//      PGCD (Euclide) récursif
//      1)  a=34 b=21
//      2)  a=21 b=13
//      3)  a=13 b=8
//      4)  a=8 b=5
//      5)  a=5 b=3
//      6)  a=3 b=2
//      7)  a=2 b=1
//      8)  a=1 b=0
//
//      PGCD(34, 21) = 1
