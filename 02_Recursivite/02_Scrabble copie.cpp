//---------------------------------------------------------
// Fichier        : 02_Scrable.cpp
// Version        : 01 - 2022-01-30
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer les algorithmes recursifs générant
//                : toutes les combinaisons d'une série de lettres
// Modifications  :
// Remarque(s)    : dans les algorithmes, la valeur 1 correspond à S[0]]
//                  raison pour laquelle il y a un epscae " ABC" 
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <string>       // chaine
#include <algorithm>    // swap

using namespace std;

//------------------------------------------------------
// approache naive
// NB : la chaine est reçue par valeur
void permuter1(string S, size_t n) {

   // afficher les aappels et les résultats intermédiaires
   static unsigned nbreAppels;

   if (n==1) {
      // traiter S
      cout << ++nbreAppels << ") " << S << endl;
   }
   else {
      for (size_t i=1; i<=n; ++i) {
         permuter1(S, n-1);
         swap(S[i], S[n]);
      } // for
   } // else
}

//------------------------------------------------------
// sans échange inutile
// NB : la chaine est reçue par valeur
void permuter2(string S, size_t n) {

   // afficher les aappels et les résultats intermédiaires
   static unsigned nbreAppels;

   if (n==1) {
      // traiter S
      cout << ++nbreAppels << ") " << S << endl;
   }
   else {
      for (size_t i=1; i<n; ++i) {
         swap(S[i], S[n]);
         permuter2(S, n-1);
         swap(S[i], S[n]);
      } // for
      permuter2(S, n-1);
   } // else
} // permuter

//------------------------------------------------------
// algorithme de Heap
void permuter3(string S, size_t n) {

   // afficher les aappels et les résultats intermédiaires
   static unsigned nbreAppels;

   if (n==1) {
      // traiter S
      cout << ++nbreAppels << ") " << S << endl;
   }
   else {
      permuter3(S, n-1);

      for (size_t i=1; i<n; ++i) {

         if (n % 2)
            swap(S[i], S[n]);
         else
            swap(S[1], S[n]);

         permuter3(S, n-1);
      } // for
   } // else
} // permuter

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Scrable récursif" << endl;
   cout << "----------------" << endl << endl;

   cout << "approche naive" << endl;
   permuter1(" ABC"s, 3);

   cout << endl;
   cout << "sans échange inutile" << endl;
   permuter2(" ABC"s, 3);

   cout << endl;
   cout << "algorithme de Heap" << endl;
   permuter3(" ABC"s, 3);

   return EXIT_SUCCESS;
}
