//---------------------------------------------------------
// Fichier        : 03_Tri_Rapide.cpp
// Version        : 01 - 2022-03-24
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer le tri rapide
// Modifications  :
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
void tri_rapide (T tableau[], int taille);

template <typename T>
void tri_rapide_rec (T tableau[], int debut, int fin);

//---------------------------------------------------------
int main() {

   {  // tableau d'entiers
      int tab[] = {9, 4, 2, 6, 5, 7, 1, 3, 8};
      int TAILLE = sizeof(tab) / sizeof(int);

      display_ind(TAILLE);
      display_tab(tab, TAILLE);  cout << endl;
      tri_rapide (tab, TAILLE);
      display_tab(tab, TAILLE);  cout << endl;
   }

   {  // tableau de caractères
      // char chaine[] = "TRIRAPIDE";  // /!\ ajout '\0'
      // int TAILLE = sizeof(chaine) / sizeof(char) - 1;

      char chaine[] = {'T', 'R', 'I', 'R', 'A', 'P', 'I', 'D', 'E'};
      int TAILLE = sizeof(chaine) / sizeof(char);

      cout << endl;

      cout << chaine << endl;
      tri_rapide(chaine, TAILLE);
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
int partition (T tab[], int debut, int fin) {

   int p = fin;
   int i = debut;
   int j = p-1;

   while(true) {
      while (tab[i] < tab[p])
         ++i;

      while (debut <= j and tab[j] > tab[p])
         --j;

      if (i >= j)
         break;

      // échanger les valeurs
      swap(tab[i], tab[j]);
   }

   // mettre la valeur de pivot à sa place
   swap(tab[i], tab[p]);

   // affiche les résultats intermédiaires de la partition
   cout << debut << " " << i << " " << fin << endl;

   return i;
}

//---------------------------------------------------------
template <typename T>
void tri_rapide (T tableau[], int taille) {
   tri_rapide_rec(tableau, 0, taille-1);
}

//---------------------------------------------------------
template <typename T>
void tri_rapide_rec(T tableau[], int debut, int fin) {
   if(debut < fin) {
      int pivot = partition(tableau, debut, fin);

      tri_rapide_rec(tableau, debut,   pivot-1);
      tri_rapide_rec(tableau, pivot+1, fin    );
   }
}
