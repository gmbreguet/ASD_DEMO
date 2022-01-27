//---------------------------------------------------------
// Fichier        : 01_Factorielle.cpp
// Version        : 01 - 2022-01-27
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme du calcul factoriel
//                : en mode récursif
// Complexité     : f(0)   => 0 appel
//                  f(1)   => 1 appel
//                  f(2)   => 2 appels
//                  f(n)   => n appels
//                  => O(n) 
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
unsigned facto(unsigned n) {

   // nbre d'appels
   static unsigned appels = 0;
   cout << ++appels << ") " << " n=" << n << endl;

   // cas trivial
   if (n == 0)
      return 1;

   // appel récursif
   return n * facto(n-1);
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Factorielle récursif" << endl;

   unsigned factorielle = facto(6);
   cout << endl;

   cout << "facto(6) = " << factorielle << endl;

   return EXIT_SUCCESS;
}
