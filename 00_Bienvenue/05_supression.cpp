//---------------------------------------------------------
// Fichier        : 05_supression.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-05
// But            : comparer des algorithmes de supression
//                  en O(n) et O(n^2)
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

//------------------------------------------------------
#define TRACE_ON 1
#define TRACE if (TRACE_ON) cout << "."
//------------------------------------------------------

using namespace std;

using Type      = int;
using Vecteur1D = vector<Type>;


//------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur1D& v);

//------------------------------------------------------
void supprimerPos       (Vecteur1D& v, size_t pos);
void supprimerValeur_On1(Vecteur1D& v, const Type& valeur);
void supprimerValeur_On2(Vecteur1D& v, const Type& valeur);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   const Vecteur1D VECTEUR = {1, 2, 3, 1, 2, 3, 1, 1, 2, 3};
   Vecteur1D vecteur;   // vecteur de travail

   cout << "-------------------------------------" << endl;
   cout << "supprimerPos(v, 2) => O(n)"            << endl;
   vecteur = VECTEUR;
   cout << "v : " << vecteur                       << endl;
   supprimerPos(vecteur, 2);                  cout << endl;
   cout << "v : " << vecteur                       << endl;

   cout << "-------------------------------------" << endl;
   cout << "supprimerValeur_On2(v, 1) => O(n^2)"   << endl;
   vecteur = VECTEUR;
   cout << "v : " << vecteur                       << endl;
   supprimerValeur_On2(vecteur, 1);           cout << endl;
   cout << "v : " << vecteur                       << endl;

   cout << "-------------------------------------" << endl;
   cout << "supprimerValeur_On1(v, 1) => O(n)"     << endl;
   vecteur = VECTEUR;
   cout << "v : " << vecteur                       << endl;
   supprimerValeur_On1(vecteur, 1);           cout << endl;
   cout << "v : " << vecteur                       << endl;

}  // main


//------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur1D& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
void supprimerPos(Vecteur1D&  v, size_t pos) {

   // ne rien faire si vide ou pos mal positionné
   if (v.empty() or pos >= v.size())
      return;

   // décaler toutes les valeurs adjacentes
   for (size_t i=pos; i<v.size()-1; ++i) {
      v[i] = v[i+1];
      TRACE;
   }

   // mise à jour de la taille
   v.resize(v.size()-1);
}

//------------------------------------------------------
// cet algorithme est fonctionnel mais à cause de ses deux
// boucles imbriquées, nous avons une complexité O(n2) ;(
//------------------------------------------------------
void supprimerValeur_On2(Vecteur1D& v, const Type& valeur){

   // parcourir tout le tableau
   for (size_t i=0; i<v.size(); ++i) {

      // si la valeur est trouvée
      if (v[i] == valeur)  {

         // décaler toutes les valeurs adjacentes
         supprimerPos(v, i);

//       // si le code était dans la fonction
//       for (size_t j=i; j<v.size()-1; ++j) {
//          v[j] = v[j+1];
//       }
//       v.resize(v.size() - 1);

         --i;  // retester la nouvelle valeur en v[i]
      }  // if
   } // for
}


//------------------------------------------------------
// algorithme avec un seul passage - O(n)
void supprimerValeur_On1(Vecteur1D& v, const Type& valeur) {

   // position de lecture et d'écriture
   size_t posLecture  = 0;
   size_t posEcriture = 0;

   while(posLecture < v.size()) {
      if (v[posLecture] != valeur) {
         v[posEcriture] = v[posLecture];
         ++posEcriture;
      }
      ++posLecture;
      TRACE;
   }

   // mise à jour de la taille
   v.resize(posEcriture);
}

