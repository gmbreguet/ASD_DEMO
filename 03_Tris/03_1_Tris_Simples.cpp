//---------------------------------------------------------
// Fichier        : 03_Tris_Simples.cpp
// Version        : 01 - 2022-03-15
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer les tris de base
//                   - tri à bulles
//                   - tri par insertions
//                   - tri par sélection
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // swap et generate
#include <iomanip>   // setw
#include <ctime>     // alea::srand(time..)
#include <limits>    // alea::numeric_limits<int>

using namespace std;

//---------------------------------------------------------
// types de données
using Vecteur = vector<int>;
using uintll  = unsigned long long;

//---------------------------------------------------------
// fonctions auxiliaires
ostream& operator<<(ostream& os, const Vecteur& v);
int  generateur();
bool trier (Vecteur::iterator itL, Vecteur::iterator itR);

//---------------------------------------------------------
// implémentation des algorithmes de tri
uintll bubbleSort1  (Vecteur& v);
uintll bubbleSort2  (Vecteur& v);
uintll insertSort   (Vecteur& v);
uintll selectionSort(Vecteur& v);

//---------------------------------------------------------
// vecteur reçu en copie volontairment
// ptr de fonction => action à faire sur le tableau
void test(Vecteur v,                      // vecteur par copie
          uintll  (*fct) (Vecteur&),      // tri à faire sur la tableau
          const   string& msg = "",       // msg à afficher
          bool    coutVecteur = false);   // afficher vecteur? => false/true

//---------------------------------------------------------
int main() {

   // afficher ou non les tableaux
   const bool    coutVecteur     = false;

   // vecteurs de travail
   Vecteur VIDE;
   Vecteur RANDOM          = {9, 5, 2, 6, 7, 3, 4, 1, 8};
   Vecteur CROISSANT       = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   Vecteur DECROISSANT     = {9, 8, 7, 6, 5, 4, 3, 2, 1};
   Vecteur PART_CROISSANT  = {6, 7, 8, 9, 1, 2, 3, 4, 5};

   // test des tri
   cout << endl << "tri à bulles" << endl;
   test(VIDE,           bubbleSort1,   "swap", coutVecteur);
   test(RANDOM,         bubbleSort1,   "swap", coutVecteur);
   test(CROISSANT,      bubbleSort1,   "swap", coutVecteur);
   test(DECROISSANT,    bubbleSort1,   "swap", coutVecteur);
   test(PART_CROISSANT, bubbleSort1,   "swap", coutVecteur);

   cout << endl << "tri à bulles optimisé" << endl;
   test(VIDE,           bubbleSort2,   "swap", coutVecteur);
   test(RANDOM,         bubbleSort2,   "swap", coutVecteur);
   test(CROISSANT,      bubbleSort2,   "swap", coutVecteur);
   test(DECROISSANT,    bubbleSort2,   "swap", coutVecteur);
   test(PART_CROISSANT, bubbleSort2,   "swap", coutVecteur);

   cout << endl << "tri par insertion" << endl;
   test(VIDE,           insertSort,    "insertions", coutVecteur);
   test(RANDOM,         insertSort,    "insertions", coutVecteur);
   test(CROISSANT,      insertSort,    "insertions", coutVecteur);
   test(DECROISSANT,    insertSort,    "insertions", coutVecteur);
   test(PART_CROISSANT, insertSort,    "insertions", coutVecteur);

   cout << endl << "tri par selection" << endl;
   test(VIDE,           selectionSort, "permutations", coutVecteur);
   test(RANDOM,         selectionSort, "permutations", coutVecteur);
   test(CROISSANT,      selectionSort, "permutations", coutVecteur);
   test(DECROISSANT,    selectionSort, "permutations", coutVecteur);
   test(PART_CROISSANT, selectionSort, "permutations", coutVecteur);

   // création d'un grand tableau de valeurs aléatoires (algorithm)
   cout << endl << "grands tableaux" << endl;
   Vecteur TRES_GRAND(100'000);
   generate(TRES_GRAND.begin(), TRES_GRAND.end(), generateur);

   test(TRES_GRAND,     bubbleSort1);
   test(TRES_GRAND,     bubbleSort2);
   test(TRES_GRAND,     insertSort);
   test(TRES_GRAND,     selectionSort);

   // vecteur de vecteurs et utilisation de for_each pour le tri (algorithm)
   cout << "debut ... ";
   vector<Vecteur> TABS = {VIDE, RANDOM, CROISSANT, DECROISSANT, PART_CROISSANT, TRES_GRAND};
   sort(TRES_GRAND.begin(), TRES_GRAND.end());
   cout << "fin" << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
// version habituelle mais avec - i - 1 ... ;(
//---------------------------------------------------------
uintll bubbleSort0(Vecteur& v){
   unsigned long cpt = 0;
   if (v.size() > 0){    // size_t = unsigned => 0 - 1 => BCP
      for (size_t i = 0; i < v.size() - 1; ++i){
         for (size_t j = 0; j < v.size() - i - 1; ++j){
            ++cpt;   // itérations
            if (v[j] > v[j + 1]) {
               swap(v[j], v[j + 1]); // permutation
            } // if
         } // for j
      } // for i
   } // if
   return cpt;
}

//---------------------------------------------------------
uintll bubbleSort1(Vecteur& v){
   unsigned long cpt = 0;
   if (v.size() > 0){   // size_t = unsigned => 0 - 1 => BCP
      for (size_t i = 0; i < v.size() - 1; ++i){
         for (size_t j = 1; j < v.size() - i; ++j){
            ++cpt;   // itérations
            if (v[j - 1] > v[j]) {
               swap(v[j - 1], v[j]); // permutation
            } // if
         } // for j
      } // for i
   } // if
   return cpt;
}

//---------------------------------------------------------
uintll bubbleSort2(Vecteur& v){
   unsigned long cpt = 0;
   if (v.size() > 0) {
      bool fini = false;
      while (!fini){
         size_t taille = v.size();
         fini = true;
         for (size_t i = 0; i < taille - 1; ++i){
            ++cpt;   // itérations
            if (v[i] > v[i + 1]){
               swap(v[i], v[i + 1]);
               fini = false;
            } // if
         } // for
         --taille;
      } // while
   } // if
   return cpt;
}

//---------------------------------------------------------
uintll insertSort(Vecteur& v){
   unsigned long cpt = 0;
   int tmp;
   size_t j;
   for (size_t i = 1; i < v.size(); ++i) {
      tmp = v[i];
      j   = i;
      while (j >= 1 and v[j - 1] > tmp) {
         v[j] = v[j - 1];
         --j;
      } // while
      ++cpt;   // nbre d'insertion
      v[j] = tmp;
   } // for
   return cpt;
}

//---------------------------------------------------------
uintll selectionSort(vector<int>& v) {
   unsigned long cpt = 0;
   if (v.size() > 0) {
      size_t iMin;
      for (size_t i = 0; i < v.size() - 1; ++i) {
         iMin = i;
         for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[iMin])
               iMin = j;
         } // for

         ++cpt;   // permutation
         swap(v[i], v[iMin]); // permutation
      } // for
   } // if
   return cpt;
}

//---------------------------------------------------------
void test(Vecteur v,
          uintll  (*fct) (Vecteur&),
          const   string& msg,
          bool    coutVecteur) {

   const int W = 4;  // setw(W) affectations

   if (coutVecteur) {
      cout << endl;
      cout << "avant : " << v << endl;
   }

   uintll cpt = fct(v);

   if (coutVecteur) {
      cout << "apres : " << v << endl;
   }

   cout << " => " << setw(W) << cpt << " " + msg << endl;
}

//---------------------------------------------------------
ostream& operator<<(ostream& os, const Vecteur& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }

   os << "]";
   return os;
}

//---------------------------------------------------------
int generateur() {
   // initialisation du générateur
   static bool first = true;
   if (first) {
      srand((unsigned)time(NULL));
      first = false;
   }

   // generation d'une valeur aléatoire
   return rand() % numeric_limits<int>::max();
}

//---------------------------------------------------------
bool trier (Vecteur::iterator itL, Vecteur::iterator itR) {
   return *itL < *itR;
}
