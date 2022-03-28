//---------------------------------------------------------
// Fichier        : 03_Parcours.cpp
// Version        : 01 - 2022-03-24
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer comment passer une fonction en paramètre
//                : - en C
//                : - en C++
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//---------------------------------------------------------
// en C
//---------------------------------------------------------
void parcourir(int tab[], size_t taille, int(*fct)(int)) {
   for (size_t i=0; i<taille; ++i)
      tab[i] = fct(tab[i]);
}

//---------------------------------------------------------
int plus1 (int v) {
   return v + 1;
}

//---------------------------------------------------------
int put (int v) {
   cout << v;
   return v;
}

//---------------------------------------------------------
// generic en C++
//---------------------------------------------------------
template <typename T, typename Fonction>
void parcourir(vector<T>& v, Fonction fonction) {
   for (T& e : v)
      e = fonction(e);
}

//---------------------------------------------------------
template <typename T>
T plus1 (const T& t) {
   return t + 1;
}

//---------------------------------------------------------
template <typename T>
T put (const T& t) {
   cout << t;
   return t;
}

//---------------------------------------------------------
int main() {

   //------------------------------------------------------
   cout << "exemple en C" << endl;
   int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
   const size_t TAILLE = sizeof(tab) / sizeof(tab[0]);

   parcourir(tab, TAILLE, put);
   cout << endl;
   parcourir(tab, TAILLE, plus1);
   parcourir(tab, TAILLE, put);
   cout << endl;

   cout << endl;

   //------------------------------------------------------
   cout << "exemple en C++" << endl;
   vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};

   parcourir(v, put<int>);
   cout << endl;
   parcourir(v, plus1<int>);
   parcourir(v, put<int>);
   cout << endl;

   cout << endl;
   return EXIT_SUCCESS;
}

