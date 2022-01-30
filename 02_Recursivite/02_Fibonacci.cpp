//---------------------------------------------------------
// Fichier        : 02_Fibonacci.cpp
// Version        : 01 - 2022-01-27
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de Fibonacci
//                : en mode récursif en itératif
// Modifications  :
// Remarque(s)    : n: 0 1 2 3 4 5  6  7
//                  f: 0 1 2 3 5 8 13 21

//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

// pour compter les appels ou les boucles
unsigned nbreAppelRec   = 0;
unsigned nbreBoucleIter = 0;

//------------------------------------------------------
// récursif
unsigned fibo_rec(unsigned n) {

   ++nbreAppelRec;

   // cas trivial
   if (n <= 2)
      return 1;

   // appel récursif
   return fibo_rec(n-2) + fibo_rec(n-1);
}

//------------------------------------------------------
// itératif
unsigned fibo_iter(unsigned n) {

   // cas trivial
   if (n <= 1)
      return 1;

   unsigned fn2;
   unsigned fn1 = 0;
   unsigned fn  = 1;

   for (size_t i=2; i<=n; ++i) {
      fn2 = fn1;
      fn1 = fn;
      fn  = fn2 + fn1;
      ++nbreBoucleIter;
   } 

   return fn;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Fibonacci recursif" << endl;
   cout << "fibo_rec(6)    : "  << fibo_rec(6)    << endl;
   cout << "nbre appels    : "  << nbreAppelRec   << endl;
   cout << endl;

   cout << "Fibonacci itératif" << endl;
   cout << "fibo_iter(6)   : "  << fibo_iter(6)   << endl;
   cout << "nbre boucles   : "  << nbreBoucleIter << endl;
   cout << endl;

   return EXIT_SUCCESS;
}
