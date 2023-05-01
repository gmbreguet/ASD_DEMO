//---------------------------------------------------------
// Fichier        : 03_Tri_Rapide.cpp
// Version        : 02 - 2022-05-07
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer le tri rapide
// Modifications  : affichages des résultats intermédiaires
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <algorithm> // swap
#include <string>

using namespace std;

//---------------------------------------------------------
void display_ind(int taille);

//---------------------------------------------------------
template <typename T>
void display_tab(const T tab[], int taille);

//---------------------------------------------------------
template <typename T>
int partition (T tableau[], int debut, int fin);

template <typename T>
void tri_rapide (T tableau[], int taille, bool trace=false);

template <typename T>
void tri_rapide_rec (T tableau[], int taille, int debut, int fin, bool trace=false);

//---------------------------------------------------------
int main() {

   {  // tableau d'entiers
      int tab[] = {5, 7, 4, 3, 2, 8, 9, 1, 6};
      int TAILLE = sizeof(tab) / sizeof(tab[0]);

      display_ind(TAILLE);
      display_tab(tab, TAILLE);  cout << endl;
      cout << endl;
      tri_rapide (tab, TAILLE, true);
      cout << endl;
      display_tab(tab, TAILLE);  cout << endl;
   }

   {  // tableau de caractères
      char chaine[] = "TRIRAPIDE";  // /!\ ajout '\0'
      int TAILLE = sizeof(chaine) / sizeof(chaine[0]) - 1;

      cout << endl;

      cout << chaine << endl;
      tri_rapide(chaine, TAILLE, true);
      cout << chaine << endl;
   }

   {  // tableau de caractères
      char chaine[] = "PARTITION";  // /!\ ajout '\0'
      int TAILLE = sizeof(chaine) / sizeof(chaine[0]) - 1;

      cout << endl;

      cout << chaine << endl;
      tri_rapide(chaine, TAILLE, true);
      cout << chaine << endl;
   }

   cout << endl;
   return EXIT_SUCCESS;
}

//---------------------------------------------------------
void display_ind(int taille) {
   for (int i=0; i<taille; ++i)
      cout << " " << i << " ";
   cout << endl;
}

//---------------------------------------------------------
template <typename T>
void display_tab (const T tab[], int taille) {
   cout << "[";
   for (int i=0; i<taille; ++i) {
      if (i)
         cout << ", ";
      cout << tab[i];
   }
   cout << "]";
}

//---------------------------------------------------------
template <typename T>
int partition (T tableau[], int debut, int fin) {

   int p = fin;
   int i = debut;
   int j = p-1;

   while(true) {
      // avancer i
      while (tableau[i] < tableau[p])
         ++i;

      // reculer j
      while (debut <= j and tableau[j] > tableau[p])
         --j;

      // indices rejoints ou croisés
      if (i >= j)
         break;

      // échanger les valeurs
      swap(tableau[i], tableau[j]);
   }

   // mettre la valeur de pivot à sa place
   swap(tableau[i], tableau[p]);

   return i;
}

//---------------------------------------------------------
template <typename T>
void tri_rapide (T tableau[], int taille, bool trace) {
   tri_rapide_rec(tableau, taille, 0, taille-1, trace);
}

//---------------------------------------------------------
template <typename T>
void tri_rapide_rec(T tableau[], int taille, int debut, int fin, bool trace) {
   if(debut < fin) {
      // pivot systématiquement en position hi
      int pivot = partition(tableau, debut, fin);

      // affiche les résultats intermédiaires de la partition
      if (trace) {
         cout << debut << " " << pivot << " " << fin << "    ";
         display_tab(tableau, taille);
         cout << endl;
      }

      // appels récursifs
      tri_rapide_rec(tableau, taille, debut,   pivot-1, trace);
      tri_rapide_rec(tableau, taille, pivot+1, fin    , trace);
   }

   // cas simples
   if (debut == fin and trace) {
      cout << debut << " " << debut << " " << fin << "    ";
      display_tab(tableau, taille);
      cout << endl;
   }
}

//      0  1  2  3  4  5  6  7  8
//      [5, 7, 4, 3, 2, 8, 9, 1, 6]
//
//      0 5 8    [5, 1, 4, 3, 2, 6, 9, 7, 8]
//      0 1 4    [1, 2, 4, 3, 5, 6, 9, 7, 8]
//      0 0 0    [1, 2, 4, 3, 5, 6, 9, 7, 8]
//      2 4 4    [1, 2, 4, 3, 5, 6, 9, 7, 8]
//      2 2 3    [1, 2, 3, 4, 5, 6, 9, 7, 8]
//      3 3 3    [1, 2, 3, 4, 5, 6, 9, 7, 8]
//      6 7 8    [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      6 6 6    [1, 2, 3, 4, 5, 6, 7, 8, 9]
//      8 8 8    [1, 2, 3, 4, 5, 6, 7, 8, 9]
//
//      [1, 2, 3, 4, 5, 6, 7, 8, 9]
//
//      TRIRAPIDE
//      0 2 8    [D, A, E, R, R, P, I, T, I]
//      0 0 1    [A, D, E, R, R, P, I, T, I]
//      1 1 1    [A, D, E, R, R, P, I, T, I]
//      3 3 8    [A, D, E, I, R, P, R, T, I]
//      4 4 8    [A, D, E, I, I, P, R, T, R]
//      5 6 8    [A, D, E, I, I, P, R, T, R]
//      5 5 5    [A, D, E, I, I, P, R, T, R]
//      7 7 8    [A, D, E, I, I, P, R, R, T]
//      8 8 8    [A, D, E, I, I, P, R, R, T]
//      ADEIIPRRT
