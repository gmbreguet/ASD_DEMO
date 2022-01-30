//---------------------------------------------------------
// Fichier        : 02_Factorielle.cpp
// Version        : 01 - 2022-01-27
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme du calcul factoriel
//                  récursif et itératif
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
unsigned facto_rec(unsigned n) {

   // nbre d'appels
   static unsigned appels = 0;
   cout << ++appels << ") " << " n=" << n << endl;

   // cas trivial
   if (n == 0)
      return 1;

   // appel récursif
   return n * facto_rec( n - 1 );
}

//------------------------------------------------------
unsigned facto_iter(unsigned n) {

   unsigned resultat = 1;

   while(n > 1) {
      resultat *= n--;
   }

   return resultat;
}
//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Factorielle récursif" << endl;

   unsigned factorielle_rec  = facto_rec(6);
   cout << endl;
   unsigned factorielle_iter = facto_iter(6);

   cout << "facto(6) = " << factorielle_rec  << endl;
   cout << "facto(6) = " << factorielle_iter << endl;


   return EXIT_SUCCESS;
}
