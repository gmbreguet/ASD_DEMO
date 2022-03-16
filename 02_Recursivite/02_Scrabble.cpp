//---------------------------------------------------------
// Fichier        : 02_Scrable.cpp
// Version        : 02 - 2022-03-09
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer les algorithmes recursifs générant
//                : toutes les combinaisons d'une série de lettres
// Modifications  :
// Remarque(s)    :  
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <string>       // chaine
#include <algorithm>    // swap

using namespace std;

//------------------------------------------------------
// approache naive
// nbre échanges : n * n!
// NB : la chaine est reçue par valeur
void permuter1(string S, size_t n);

//------------------------------------------------------
// double échange
// nbre échanges : 2 * 1.71 * n!
void permuter2(string& S, size_t n);

//------------------------------------------------------
// sans échange inutile
// nbre échanges : 2 * (n! - 1)
void permuter3(string& S, size_t n);

//------------------------------------------------------
// algorithme de Heap
// nbre échanges : n! - 1
// https://fr.wikipedia.org/wiki/Algorithme_de_Heap
void permuter4(string& S, size_t n);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "Scrabble récursif" << endl;
   cout << "----------------" << endl << endl;

   const string CHAINE = "ABC";
   
   cout << "approche naive" << endl;
   string chaine1 = CHAINE;
   permuter1(chaine1, 3);

   cout << endl;
   cout << "double échange" << endl;
   string chaine2 = CHAINE;
   permuter2(chaine2, 3);

   cout << endl;
   cout << "sans échange inutile" << endl;
   string chaine3 = CHAINE;
   permuter3(chaine3, 3);

   cout << endl;
   cout << "algorithme de Heap" << endl;
   string chaine4 = CHAINE;
   permuter4(chaine4, 3);

   return EXIT_SUCCESS;
}

//------------------------------------------------------
// approache naive
// NB : la chaine est reçue par valeur
void permuter1(string S, size_t n) {

   // afficher les appels et les résultats intermédiaires
   static unsigned listeAppels;

   if (n <= 1) {
      // traiter S
      cout << ++listeAppels << ") " << S << endl;
   }
   else {
      for (size_t i=0; i<n; ++i) {
         permuter1(S, n-1);
         swap(S[i], S[n-1]);
      } // for
   } // else
} // permuter1

//------------------------------------------------------
// double échange
void permuter2(string& S, size_t n) {

   // afficher les appels et les résultats intermédiaires
   static unsigned listeAppels;

   if (n <= 1) {
      // traiter S
      cout << ++listeAppels << ") " << S << endl;
   }
   else {
      for (size_t i=0; i<n; ++i) {
         swap(S[i], S[n-1]);
         permuter2(S, n-1);
         swap(S[i], S[n-1]);  // remettre 1ere et dernière comme précédemment
      } // for
   } // else
} // permuter2

//------------------------------------------------------
// sans échange inutile
// swap(S[i], S[n]) lorsque i = n
void permuter3(string& S, size_t n) {

   // afficher les appels et les résultats intermédiaires
   static unsigned listeAppels;

   if (n <= 1) {
      // traiter S
      cout << ++listeAppels << ") " << S << endl;
   }
   else {
      for (size_t i=0; i<n-1; ++i) {
         swap(S[i], S[n-1]);
         permuter3(S, n-1);
         swap(S[i], S[n-1]);  // remettre 1ere et dernière comme précédemment
      } // for
      permuter3(S, n-1);
   } // else
} // permuter3

//------------------------------------------------------
// algorithme de Heap
// https://fr.wikipedia.org/wiki/Algorithme_de_Heap
void permuter4(string& S, size_t n) {

   // afficher les appels et les résultats intermédiaires
   static unsigned listeAppels;

   if (n <= 1) {
      // traiter S
      cout << ++listeAppels << ") " << S << endl;
   }
   else {
      permuter4(S, n-1);

      for (size_t i=0; i<n-1; ++i) {

         if (n % 2)  // impair
            swap(S[1], S[n-1]);
         else  // pair
            swap(S[i], S[n-1]);

         permuter4(S, n-1);
      } // for
   } // else
} // permuter4
