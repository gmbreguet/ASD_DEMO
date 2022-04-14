//---------------------------------------------------------
// Fichier        : 04_0_Fibonacci_Memorisation.cpp
// Version        : 01 - 2022-04-02
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de Fibonacci
//                : en mode récursif tableau programming
// Modifications  :
// Remarque(s)    :   n  : 0 1 2 3 4 5 6  7  8  9 10 11  12
//                  f(n) : 0 1 1 2 3 5 8 13 21 34 55 89 144

//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <algorithm>    // fill
#include <string>       // représentation des appels récursifs

using namespace std;

// pour compter les appels ou les boucles
unsigned nbreAppelsRec  = 0;
unsigned nbreAppelsMem  = 0;

//------------------------------------------------------
// récursif
// O(n^2)
unsigned fibo_rec(unsigned n) {

   ++nbreAppelsRec;

   // cas trivial
   if (n < 2)
      return n;

   // appels récursifs
   return fibo_rec(n-2) + fibo_rec(n-1);
}

//------------------------------------------------------
// récursif avec mémorisation
// => O(n)
unsigned fibo_mem(unsigned n) {

   // tableau de mémorisation
   static unsigned* tableau  = new unsigned[n+1];

   static bool     pret    = false;
   static unsigned dernier = n;
   if (not pret) {                     // (re)préparation
      dernier    = n;
      tableau[0] = 0;                  // valeurs ...
      tableau[1] = 1;                  // ... initiales
      fill(tableau+2, tableau + n, 0); // reste à 0
      pret       = true;
   }

   // affichage du déroulement
   cout << string(2*(dernier-n), '.');
   cout << " fibo(" << n << ")";
   ++nbreAppelsMem;

   // cas trivial
   if (n < 2) {
      cout << " <= " << n << endl;
      return n;
   }

   // cas déjà mémorisés
   // => pas d'appel récursif
   if(tableau[n]) {
      cout << " <= tableau[" << n << "] = " << tableau[n] << endl;
      return tableau[n];
   }

   cout << endl;

   // appels récursifs et mémorisation de la réponse
   tableau[n] = fibo_mem(n-2) + fibo_mem(n-1);

   // dernier appel
   // => libérer la mémoire
   if (n == dernier) {
      unsigned tmp = tableau[n];
      delete[] tableau;
      tableau = nullptr;
      pret    = false;
      cout << "libération du tableau" << endl;
      return tmp;
   }

   // retour de la nouvelle valeur mémorisée
   return tableau[n];
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   const unsigned n = 10;
   cout << "fibo(" << n << ")" << endl; 
   cout << "  n  : 0 1 2 3 4 5 6  7  8  9 10 11  12" << endl;
   cout << "f(n) : 0 1 1 2 3 5 8 13 21 34 55 89 144" << endl;
   cout << endl;

   cout << "Fibonacci recursif : O(n^2)" << endl;
   cout << "fibo_rec(n)    : "  << fibo_rec(n)    << endl;
   cout << "nbre appels    : "  << nbreAppelsRec  << endl;
   cout << endl;

   cout << "Fibonacci avec memorisation : O(n)" << endl;
   unsigned resultat = fibo_mem(n);
   cout << endl;
   cout << "fibo_mem(n)    : "  << resultat       << endl;
   cout << "nbre appels    : "  << nbreAppelsMem  << endl;
   cout << endl;

   return EXIT_SUCCESS;
}

//    fibo(10)
//      n  : 0 1 2 3 4 5 6  7  8  9 10 11  12
//    f(n) : 0 1 1 2 3 5 8 13 21 34 55 89 144
//    
//    Fibonacci recursif : O(n^2)
//    fibo_rec(n)    : 55
//    nbre appels    : 177
//    
//    Fibonacci avec memorisation : O(n)
//     fibo(10)
//    .... fibo(8)
//    ........ fibo(6)
//    ............ fibo(4)
//    ................ fibo(2)
//    .................... fibo(0) <= 0
//    .................. fibo(1) <= 1
//    .............. fibo(3)
//    .................. fibo(1) <= 1
//    ................ fibo(2) <= tableau[2] = 1
//    .......... fibo(5)
//    .............. fibo(3) <= tableau[3] = 2
//    ............ fibo(4) <= tableau[4] = 3
//    ...... fibo(7)
//    .......... fibo(5) <= tableau[5] = 5
//    ........ fibo(6) <= tableau[6] = 8
//    .. fibo(9)
//    ...... fibo(7) <= tableau[7] = 13
//    .... fibo(8) <= tableau[8] = 21
//    libération du tableau
//    
//    fibo_mem(n)    : 55
//    nbre appels    : 19
//    
