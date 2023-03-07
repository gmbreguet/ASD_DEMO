//---------------------------------------------------------
// Fichier        : 02_Factorielle.cpp
// Version        : 02 - 2023-03-07
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme du calcul factoriel
//                  récursif, itératif et récursion terminale
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
unsigned facto_rec(unsigned n);

//------------------------------------------------------
unsigned facto_iter(unsigned n);

//------------------------------------------------------
// tail recursion / récursion terminale
unsigned facto   (unsigned n);
unsigned facto_TR(unsigned n, unsigned resultat);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Factorielle récursif" << endl;

   unsigned factorielle_rec  = facto_rec(6);
   cout << endl;

   unsigned factorielle_iter = facto_iter(6);
   cout << endl;

   unsigned factorielle_TR   = facto(6);
   cout << endl;

   cout << "facto(6) = " << factorielle_rec  << endl;
   cout << "facto(6) = " << factorielle_iter << endl;
   cout << "facto(6) = " << factorielle_TR   << endl;


   return EXIT_SUCCESS;
}

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
unsigned facto(unsigned int n) {
   return facto_TR(n, 1);
}

//------------------------------------------------------
unsigned facto_TR(unsigned int n, unsigned int resultat) {
    if (n <= 1)
        return resultat;
    return facto_TR(n - 1, n * resultat);
}
