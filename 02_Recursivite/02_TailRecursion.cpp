//---------------------------------------------------------
// Fichier        : 02_SommeChiffres.cpp
// Version        : 01 - 2022-03-15
// Auteur(s)      : BREGUET Guy-Michel
// But            : somme des chiffres d'un nombre
//                : en mode itératif, récursif et récursion terminale
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
// itératif
unsigned sommeChiffres_iter(unsigned n);

//------------------------------------------------------
// récursif
unsigned sommeChiffres_rec(unsigned n);

//------------------------------------------------------
// recursion terminale (tail recursion)
unsigned sommeChiffres_tailRec  (unsigned n);
unsigned sommeChiffres_tailRec_R(unsigned n, unsigned somme);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   unsigned valeur = 4958;
   cout << "somme des chiffres : " << valeur << endl;
   cout << "iteratif       : "  << " => " << sommeChiffres_iter(valeur)     << endl;
   cout << "recursif       : "  << " => " << sommeChiffres_rec(valeur)      << endl;
   cout << "tail recursion : "  << " => " << sommeChiffres_tailRec(valeur)  << endl;

   return EXIT_SUCCESS;
}

//------------------------------------------------------
// itératif
unsigned sommeChiffres_iter(unsigned n) {
   unsigned resultat = 0;
   while (n > 0) {
      resultat += n % 10;
      n /= 10;
   }
   return resultat;
}
//------------------------------------------------------
// récursif
unsigned sommeChiffres_rec(unsigned n) {
   if (n < 10)
      return n;
   return n % 10 + sommeChiffres_rec(n / 10);
}

//------------------------------------------------------
// recursion terminale (tail recursion)
unsigned sommeChiffres_tailRec(unsigned n) {
   if (n < 10)
      return n;
   return sommeChiffres_tailRec_R(n, 0);
}

//------------------------------------------------------
unsigned sommeChiffres_tailRec_R(unsigned n, unsigned somme) {
   if (n == 0)
      return somme;
   return sommeChiffres_tailRec_R(n / 10, somme + n % 10);
}

//      somme des chiffres : 4958
//      iteratif       :  => 26
//      recursif       :  => 26
//      tail recursion :  => 26
