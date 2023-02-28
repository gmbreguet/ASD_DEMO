//---------------------------------------------------------
// Fichier        : 02_Fibonacci.cpp
// Version        : 03 - 2023-02-28
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de Fibonacci
//                : en mode itératif, récursif et avec mémorisation
// Modifications  : ajouter Golden Ratio
// Remarque(s)    :   n  : 0 1 2 3 4 5 6  7  8  9 10 11  12
//                  f(n) : 0 1 1 2 3 5 8 13 21 34 55 89 144
//                  https://www.youtube.com/watch?v=P8Xa2BitN3I
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

// pour compter les appels ou les boucles
unsigned nbreBouclesIter   = 0;
unsigned nbreAppelsRec     = 0;
unsigned nbreAppelsDyn     = 0;

//------------------------------------------------------
// itératif => O(n)
unsigned fibo_iter(unsigned n, bool showGoldenRatio = false) {

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
      ++nbreBouclesIter;
      
      if (showGoldenRatio)
         cout << (double)fn / fn1 << endl;
   } 

   return fn;
}

//------------------------------------------------------
// récursif => O(2^n)
unsigned fibo_rec(unsigned n) {

   ++nbreAppelsRec;

   // cas trivial
   if (n < 2)
      return n;

   // appels récursifs
   return fibo_rec(n-2) + fibo_rec(n-1);
}

//------------------------------------------------------
// récursif (mémorisation) => O(2*n) => O(n)
using Memo = map<unsigned, unsigned>;
unsigned fibo_dyn(unsigned n,
                  Memo&    memo) {

   ++nbreAppelsDyn;

   // cas trivial
   if (n < 2)
      return n;

   // est-ce déja calculé
   if ( memo.find(n) != memo.end() )
      return memo.at(n);

   // appels récursifs et memorisation
   memo.emplace(n, fibo_dyn(n-2, memo) + fibo_dyn(n-1, memo));

   // returne  la valeur mémorisée
   return memo.at(n); 
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   const unsigned n = 12;
   unsigned       resultat;

   cout << "Fibonacci(" << n << ")"                   << endl;
   cout << "  n  : 0 1 2 3 4 5 6  7  8  9 10 11  12"  << endl;
   cout << "f(n) : 0 1 1 2 3 5 8 13 21 34 55 89 144"  << endl;
   cout << endl;

   cout << "Fibonacci itératif => O(n)"               << endl;
   resultat = fibo_iter(n);
   cout << "fibo(n)      : "    << resultat           << endl; 
   cout << "nbre boucles : "    << nbreBouclesIter    << endl;
   cout << endl; 

   cout << "Fibonacci recursif => O(2^n)"             << endl;
   resultat = fibo_rec(n);
   cout << "fibo(n)     : "    << resultat            << endl; 
   cout << "nbre appels : "    << nbreAppelsRec       << endl;
   cout << endl; 

   cout << "Fibonacci avec mémorisation => O(n)"      << endl;
   Memo memo;
   resultat = fibo_dyn(n, memo);
   cout << "fibo(n)     : "    << resultat            << endl; 
   cout << "nbre appels : "    << nbreAppelsDyn       << endl;
   cout << endl; 

   cout << "Fibonacci - Golden Ratio"                       << endl;
   fibo_iter(n, true);
   cout << endl;

   cout << endl;
   return EXIT_SUCCESS;
}

//      Fibonacci(12)
//        n  : 0 1 2 3 4 5 6  7  8  9 10 11  12
//      f(n) : 0 1 1 2 3 5 8 13 21 34 55 89 144
//
//      Fibonacci itératif => O(n)
//      fibo(n)      : 144
//      nbre boucles : 11
//
//      Fibonacci recursif => O(2^n)
//      fibo(n)     : 144
//      nbre appels : 465
//
//      Fibonacci avec mémorisation => O(2*n) => O(n)
//      fibo(n)     : 144
//      nbre appels : 23
//
//      Fibonacci - Golden Ratio
//      1
//      2
//      1.5
//      1.66667
//      1.6
//      1.625
//      1.61538
//      1.61905
//      1.61765
//      1.61818
//      1.61798
