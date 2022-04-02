//---------------------------------------------------------
// Fichier        : 04_Fibonacci_MemPgm.cpp
// Version        : 01 - 2022-04-02
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de Fibonacci
//                : en mode récursif tableau porgramming
// Modifications  :
// Remarque(s)    : n: 0 1 2 3 4 5  6  7
//                  f: 0 1 2 3 5 8 13 21

//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <algorithm>    // fill
#include <string>       // sous-appels

using namespace std;

// pour compter les appels ou les boucles
unsigned nbreAppelsRec  = 0;
unsigned nbreAppelsMem  = 0;

//------------------------------------------------------
// récursif
unsigned fibo_rec(unsigned n) {

   ++nbreAppelsRec;

   // cas trivial
   if (n < 2)
      return n;

   // appel récursif
   return fibo_rec(n-2) + fibo_rec(n-1);
}

//------------------------------------------------------
// récursif tableau programming
unsigned fibo_mem(unsigned n) {

   // tableau de mémorisation
   static unsigned* tableau  = new unsigned[n+1];

   static bool     pret    = false;
   static unsigned dernier = n;
   if (not pret) {
      tableau[0] = 0;                  // valeurs ...
      tableau[1] = 1;                  // ... initiales
      fill(tableau+2, tableau + n, 0); // reste à 0
      pret = true;
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

   // appels récursifs et mémorisation la réponse
   tableau[n] = fibo_mem(n-2) + fibo_mem(n-1);

   // dernier appel
   // => libérer la mémoire
   if (n == dernier) {
      unsigned tmp = tableau[n];
      delete[] tableau;
      pret = false;
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

   const unsigned n = 12;
   cout << "fibo(" << n << ")" << endl; 
   cout << endl;

   cout << "Fibonacci recursif" << endl;
   cout << "fibo_rec(n)    : "  << fibo_rec(n)    << endl;
   cout << "nbre appels    : "  << nbreAppelsRec  << endl;
   cout << endl;

   cout << "Fibonacci tableau" << endl;
   unsigned resultat = fibo_mem(n);
   cout << endl;
   cout << "fibo_mem(n)    : "  << resultat       << endl;
   cout << "nbre appels    : "  << nbreAppelsMem  << endl;
   cout << endl;

   return EXIT_SUCCESS;
}

