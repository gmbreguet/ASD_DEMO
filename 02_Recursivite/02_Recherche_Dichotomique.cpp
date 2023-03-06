//---------------------------------------------------------
// Fichier        : 02_Recherche_Dichotomique.cpp
// Version        : 02 - 2023-02-28
// Auteur(s)      : BREGUET Guy-Michel
// But            : recherche dichotomique
//                : en mode itératif et récursif
// Modifications  :
// Remarque(s)    :

//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
template <typename T>
string toString(const T tab[], size_t taille);

//------------------------------------------------------
// itératif (séquentiel)
template <typename T>
int recherche_Seq(const T  tab[],
                  size_t   debut,
                  size_t   fin,
                  const T& valeur);

//------------------------------------------------------
// itératif (demi tableau)
template <typename T>
int rechercheDicho_iter(const T  tab[],
                        size_t   debut,
                        size_t   fin,
                        const T& valeur);

//------------------------------------------------------
// récursif (tableau)
template <typename T>
int rechercheDicho_rec(const T  tab[],
                       size_t   debut,
                       size_t   fin,
                       const T& valeur);

//------------------------------------------------------
template <typename T, typename Fonction>
void test(const T tab[], size_t taille, const T& valeur, Fonction fct);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   // tableau de travail
   const int TAB[] = {1, 3, 6, 8, 12, 14, 23, 45, 65, 84};
   const size_t TAILLE = sizeof(TAB) / sizeof(int);
   cout << toString(TAB, TAILLE) << endl;
   
   cout << endl;
   cout << "recherche séquentielle => O(n)" << endl;
   test(TAB, TAILLE, 7, recherche_Seq<int>);          // pas trouvé
   test(TAB, TAILLE, 8, recherche_Seq<int>);          // trouvé

   cout << endl;
   cout << "recherche iterative => O(log(n))" << endl;
   test(TAB, TAILLE, 7, rechercheDicho_iter<int>);   // pas trouvé
   test(TAB, TAILLE, 8, rechercheDicho_iter<int>);   // trouvé

   cout << endl;
   cout << "recherche recursive => O(log(n))" << endl;
   test(TAB, TAILLE, 7, rechercheDicho_rec<int>);    // pas trouvé
   test(TAB, TAILLE, 8, rechercheDicho_rec<int>);    // trouvé

   cout << "fin ..." << endl;
   return EXIT_SUCCESS;
}

//------------------------------------------------------
template <typename T, typename Fonction>
void test(const T tab[], size_t taille, const T& valeur, Fonction fct) {

   int indice = fct(tab, 0, taille - 1, valeur);

   cout << "=> " << valeur;
   
   if (indice == -1)
      cout << " pas trouvé";
   else
      cout << " trouvé a tab[" << indice << "]";
   
   cout << endl;
}

//------------------------------------------------------
template <typename T>
string toString(const T tab[], size_t taille) {
   
   string resultat = "[";
   for (size_t i=0; i<taille; ++i) {
      if (i)
         resultat += ", ";
      resultat += to_string(tab[i]);
   }
   resultat += "]";
   return resultat;
}

//------------------------------------------------------
// iteratif (séquentiel)
template <typename T>
int recherche_Seq(const T  tab[],
                  size_t   debut,
                  size_t   fin,
                  const T& valeur) {

   size_t crt = debut;
   while (tab[crt] < valeur and crt <= fin) {
      ++crt;
   } // while
   
   if (tab[crt] == valeur)
      return (int)crt;
   else
      return -1;
}

//------------------------------------------------------
// iteratif (demi tableau)
template <typename T>
int rechercheDicho_iter(const T  tab[],
                        size_t   debut,
                        size_t   fin,
                        const T& valeur) {

   while (debut <= fin) {
      size_t milieu = debut + (fin - debut) / 2;

      if (tab[milieu] == valeur)
         return (int)milieu;

      // prendre la moitié gauche
      if(tab[milieu] > valeur)
         fin = milieu - 1;

      // prendre la moitié droite
      else
         debut = milieu + 1;
      
   } // while
   
   // pas trouvé
   return -1;
}

//------------------------------------------------------
// récursif (tableau)
template <typename T>
int rechercheDicho_rec(const T  tab[],
                       size_t   debut,
                       size_t   fin,
                       const T& valeur) {

   if (debut <= fin) {
      size_t milieu = debut + (fin - debut) / 2;

      if (tab[milieu] == valeur)
         return (int)milieu;

      // prendre la moitié gauche
      if(tab[milieu] > valeur)
         return rechercheDicho_rec(tab, debut, milieu - 1, valeur);

      // prendre la moitié droite
      else
         return rechercheDicho_rec(tab, milieu + 1, fin, valeur);
   }
   
   // pas trouvé
   // NB : le cas trivial ici pour éviter un warning du compilateur
   // demandant une valeur à retourner
   return -1;
}

