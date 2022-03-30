//---------------------------------------------------------
// Fichier        : 04_Reservation_Dynamique.cpp
// Version        : 01 - 2022-03-29
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer quelques cas de réservation mémoire
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
// /!\ cette fonction est fausse !!
//---------------------------------------------------------
template <typename T>
void afficher(const T tab[]) {
   const size_t TAILLE = sizeof(tab) / sizeof(tab[0]);
   afficher(tab, TAILLE);
}

//---------------------------------------------------------
// /!\ cette fonction est fausse !!
//---------------------------------------------------------
template <typename T>
T* resLocal(size_t taille, const T& vInit) {

   T tab[taille]; // réservation locale

   // initialisation
   for (size_t i=0; i<taille; ++i)
      tab[i] = vInit;

   // retour de l'adresse
   return (T*)tab;
}

//---------------------------------------------------------
template <typename T>
T* resDyn(size_t taille, const T& vInit) {

   T* tab = new T[taille]; // réservation dynamique

   // initialisation
   for (size_t i=0; i<taille; ++i)
      tab[i] = vInit;

   // retour de l'adresse
   return (T*)tab;
}

//---------------------------------------------------------
int main() {

   int tab[] = {4, 8, 3, 9, 8, 2, 1, 5, 6};
   size_t TAILLE = sizeof(tab) / sizeof(tab[0]);

   cout << "-------------------------------------------" << endl;
   cout << "tableau de travail"        << endl;
   afficher(tab, TAILLE);
   cout << endl;

   cout << "-------------------------------------------" << endl;
   cout << "taille determine en interne à la fonction"   << endl;
   afficher(tab);
   cout << endl;

   cout << "-------------------------------------------" << endl;
   cout << "reservation locale"                          << endl;
   unsigned* tab10Unsigned = resLocal<unsigned>(10, 3);
   afficher(tab10Unsigned, 10);
   delete[] tab10Unsigned; // ne pas oublier ;)
   cout << endl;

   cout << "-------------------------------------------" << endl;
   cout << "reservation dynamique"                       << endl;
   short* tab10Short = resDyn<short>(10, 3);
   afficher(tab10Short, 10);
   delete[] tab10Short; // ne pas oublier ;)
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

//      -------------------------------------------
//      tableau de travail
//      [4, 8, 3, 9, 8, 2, 1, 5, 6]
//      -------------------------------------------
//      taille determine en interne à la fonction
//      [4, 8]
//      -------------------------------------------
//      reservation locale
//      [16215, 1, 1384011408, 32760, 3220173312, 32759, 11753, 1, 1384011408, 32760]
//      -------------------------------------------
//      reservation dynamique
//      [3, 3, 3, 3, 3, 3, 3, 3, 3, 3]
//      Program ended with exit code: 0
