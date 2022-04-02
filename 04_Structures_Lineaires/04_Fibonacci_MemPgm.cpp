//---------------------------------------------------------
// Fichier        : 04_Fibonacci_MemPgm.cpp
// Version        : 01 - 2022-04-02
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de Fibonacci
//                : en mode récursif memory porgramming
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
   if (n <= 2)
      return 1;

   // appel récursif
   return fibo_rec(n-2) + fibo_rec(n-1);
}

//------------------------------------------------------
// récursif memory programming
unsigned fibo_mem(unsigned n) {

   static unsigned* memory  = new unsigned[n+1];

   static bool     ready = false;
   static unsigned last  = n;
   if (not ready) {
      fill(memory, memory + n, 0);
      memory[1] = 1;
      ready = true;
   }

   cout << string(last-n, '.');
   cout << " fibo(" << n << ")";
   ++nbreAppelsMem;

   // cas trivial
   if (n <= 2) {
      cout << " <= 1" << endl;
      return 1;
   }


   // cas mémorisé
   if(memory[n]) {
      cout << " <= memory[" << n << "] = " << memory[n] << endl;
      return memory[n];
   }

   cout << endl;

   // appel récursif et mémoriser la réponse
   memory[n] = fibo_mem(n-2) + fibo_mem(n-1);

   // dernier appel => libérer la mémoire
   if (n == last) {
      unsigned tmp = memory[n];
      delete[] memory;
      cout << endl << "delete memory" << endl;
      return tmp;
   }

   return memory[n];
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Fibonacci recursif" << endl;
   cout << "fibo_rec(12)   : "  << fibo_rec(12)   << endl;
   cout << "nbre appels    : "  << nbreAppelsRec  << endl;
   cout << endl;

   cout << "Fibonacci memory" << endl;
   cout << "fibo_mem(12)   : "  << endl << fibo_mem(12)   << endl;
   cout << "nbre appels    : "  << nbreAppelsMem  << endl;
   cout << endl;

   return EXIT_SUCCESS;
}

//    Fibonacci recursif
//    fibo_rec(12)   : 144
//    nbre appels    : 287
//    
//    Fibonacci memory
//    fibo_mem(12)   : 
//     fibo(12)
//    .. fibo(10)
//    .... fibo(8)
//    ...... fibo(6)
//    ........ fibo(4)
//    .......... fibo(2) <= 1
//    ......... fibo(3)
//    ........... fibo(1) <= 1
//    .......... fibo(2) <= 1
//    ....... fibo(5)
//    ......... fibo(3) <= memory[3] = 2
//    ........ fibo(4) <= memory[4] = 3
//    ..... fibo(7)
//    ....... fibo(5) <= memory[5] = 5
//    ...... fibo(6) <= memory[6] = 8
//    ... fibo(9)
//    ..... fibo(7) <= memory[7] = 13
//    .... fibo(8) <= memory[8] = 21
//    . fibo(11)
//    ... fibo(9) <= memory[9] = 34
//    .. fibo(10) <= memory[10] = 55
//    
//    delete memory
//    144
//    nbre appels    : 21
//    
