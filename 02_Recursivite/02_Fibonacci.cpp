//---------------------------------------------------------
// Fichier        : 02_Fibonacci.cpp
// Version        : 01 - 2022-01-27
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de Fibonacci
//                : en mode récursif
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
unsigned Fibo(unsigned n) {

   // nbre d'appels
   static unsigned appels = 0;
   cout << ++appels << ") " << " n=" << n << endl;

   // cas trivial
   if (n <= 1)
      return 1;

   // appel récursif
   return Fibo(n-1) + Fibo(n-2);
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Fibonacci" << endl;

   unsigned fibo = Fibo(9);
   cout << endl;
   cout << "Fibo(9) = " << fibo << endl;

   return EXIT_SUCCESS;
}
