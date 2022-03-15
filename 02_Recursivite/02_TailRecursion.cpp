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
unsigned sommeChiffre_iter(unsigned n);

//------------------------------------------------------
// récursif
unsigned sommeChiffre_rec(unsigned n);

//------------------------------------------------------
// recursion terminale (tail recursion)
unsigned sommeChiffre_tailRec  (unsigned n);
unsigned sommeChiffre_tailRec_R(unsigned n, unsigned somme);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   unsigned valeur = 4958;
   cout << "iteratif       : "  << valeur << " = " << sommeChiffre_iter(valeur)     << endl;
   cout << "recursif       : "  << valeur << " = " << sommeChiffre_rec(valeur)      << endl;
   cout << "tail recursion : "  << valeur << " = " << sommeChiffre_tailRec(valeur)  << endl;

   return EXIT_SUCCESS;
}

//------------------------------------------------------
// itératif
unsigned sommeChiffre_iter(unsigned n) {
   unsigned resultat = 0;
   while (n > 0) {
      resultat += n % 10;
      n /= 10;
   }
   return resultat;
}
//------------------------------------------------------
// récursif
unsigned sommeChiffre_rec(unsigned n) {
   if (n < 10)
      return n;
   return n % 10 + sommeChiffre_rec(n / 10);
}

//------------------------------------------------------
// recursion terminale (tail recursion)
unsigned sommeChiffre_tailRec(unsigned n) {
   if (n < 10)
      return n;
   return sommeChiffre_tailRec_R(n, 0);
}

//------------------------------------------------------
unsigned sommeChiffre_tailRec_R(unsigned n, unsigned somme) {
   if (n == 0)
      return somme;
   return sommeChiffre_tailRec_R(n / 10, somme + n % 10);
}
