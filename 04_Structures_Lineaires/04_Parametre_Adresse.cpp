//---------------------------------------------------------
// Fichier        : 04_Parametre_Adresse.cpp
// Version        : 01 - 2022-03-30
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer le passage par adresse
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------
// fonctions auxiliaires
template <typename T>
void afficher(const T tab[], size_t taille);

//---------------------------------------------------------
// echange par references
template <typename T>
void echanger(T& lhs, T& rhs) {
   T tmp = lhs;
   lhs   = rhs;
   rhs   = tmp;
}

//---------------------------------------------------------
// echange par adresses (pointeurs)
template <typename T>
void echanger(T* ptrLhs, T* ptrRhs) {
   T tmp   = *ptrLhs;
   *ptrLhs = *ptrRhs;
   *ptrRhs = tmp;
}

//---------------------------------------------------------
int main() {

   int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   size_t TAILLE = sizeof(tab) / sizeof(tab[0]);

   cout << "-------------------------------------------" << endl;
   cout << "tableau de travail"        << endl;
   afficher(tab, TAILLE);
   cout << endl;

   cout << endl;
   cout << "echanger(tab[2], tab[3])" << endl;
   echanger(tab[2], tab[3]);
   afficher(tab, TAILLE);
   cout << endl;

   cout << endl;
   cout << "echanger(tab+4, tab+5)" << endl;
   echanger(tab+4, tab+5);
   afficher(tab, TAILLE);
   cout << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
template <typename T>
void afficher(const T tab[], size_t taille) {
   cout << "[";
   for (size_t i=0; i<taille; ++i) {
      if (i)
         cout << ", ";
      cout << tab[i];
   }
   cout << "]";
}

//    -------------------------------------------
//    tableau de travail
//    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
//    
//    echanger(tab[2], tab[3])
//    [0, 1, 3, 2, 4, 5, 6, 7, 8, 9]
//    
//    echanger(tab+4, tab+5)
//    [0, 1, 3, 2, 5, 4, 6, 7, 8, 9]
