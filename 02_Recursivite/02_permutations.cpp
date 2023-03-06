//---------------------------------------------------------
// Fichier        : 02_permutations.cpp
// Version        : 03 - 2023-03-06
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

   cout << "Permutations récursives" << endl;
   cout << "-----------------------" << endl << endl;

   const string CHAINE = "ABC";
   
   cout << "approche naive => O(n * n!)" << endl;
   string chaine1 = CHAINE;
   permuter1(chaine1, chaine1.size());

   cout << endl;
   cout << "double échange => O(2 * 1.71 * n!)" << endl;
   string chaine2 = CHAINE;
   permuter2(chaine2, chaine2.size());

   cout << endl;
   cout << "sans échange inutile => O(1 * 1.71 * n!)" << endl;
   string chaine3 = CHAINE;
   permuter3(chaine3, chaine3.size());

   cout << endl;
   cout << "algorithme de Heap => O(n! - 1)" << endl;
   string chaine4 = CHAINE;
   permuter4(chaine4, chaine4.size());

   return EXIT_SUCCESS;
}

//------------------------------------------------------
// approache naive
// NB : la chaine est reçue par valeur (en copie)
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
// NB : la chaine est reçue par référence => double échange
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

//      Permutations récursives
//      -----------------------
//
//      approche naive => O(n * n!)
//      1) ABC
//      2) BAC
//      3) CBA
//      4) BCA
//      5) CAB
//      6) ACB
//
//      double échange => O(2 * 1.71 * n!)
//      1) BCA
//      2) CBA
//      3) CAB
//      4) ACB
//      5) BAC
//      6) ABC
//
//      sans échange inutile => O(1 * 1.71 * n!)
//      1) BCA
//      2) CBA
//      3) CAB
//      4) ACB
//      5) BAC
//      6) ABC
//
//      algorithme de Heap => O(n! - 1)
//      1) ABC
//      2) BAC
//      3) BCA
//      4) CBA
//      5) CAB
//      6) ACB
