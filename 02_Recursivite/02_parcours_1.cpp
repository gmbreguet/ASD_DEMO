//---------------------------------------------------------
// Fichier        : 02-22_soc.cpp
// Version        : 01 - 2022-03-15
// Auteur(s)      : BREGUET Guy-Michel
// But            : exercices récursivité
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//------------------------------------------------------
unsigned cnt1 = 0;
void f1 (unsigned n) {
   if (n) {
      unsigned id = cnt1++;

      // affichage AVANT les appels récursifs
      cout << id << " ";

      f1(n-1);
      f1(n-1);
   }
}

//------------------------------------------------------
unsigned cnt2 = 0;
void f2 (unsigned n) {
   if (n) {
      unsigned id = cnt2++;

      f2(n-1);

      // affichage ENTRE les appels récursifs
      cout << id << " ";

      f2(n-1);
   }
}

//------------------------------------------------------
unsigned cnt3 = 0;
void f3 (unsigned n) {
   if (n) {
      unsigned id = cnt3++;

      f3(n-1);
      f3(n-1);

      // affichage APRES les appels récursifs
      cout << id << " ";
   }
}

//------------------------------------------------------
int main () {

   cout << "f1(3) : ";
   f1(3);

   cout << endl;
   cout << "f2(3) : ";
   f2(3);

   cout << endl;
   cout << "f3(3) : ";
   f3(3);

   cout << endl << endl;
   return EXIT_SUCCESS;
}

//      f1(3) : 0 1 2 3 4 5 6
//      f2(3) : 2 1 3 0 5 4 6
//      f3(3) : 2 3 1 5 6 4 0
