//---------------------------------------------------------
// Fichier        : 03_Tri_Comptage.cpp
// Version        : 01 - 2022-03-24
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer le tri par comptage
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <cstdint>

using namespace std;

//---------------------------------------------------------
template <typename T>
void display_tab(const T tab[], int taille);

//---------------------------------------------------------
// retourne la valeur du nieme chiffre depuis la droite
// 123 : n=0 => 3, n=1 => 2, n=3 => 1
template <typename T>
class valeurChiffre {
public:
   valeurChiffre(uint8_t n) : n(n) {};
   uint8_t operator() const T& nbre) const ( return (nbre / pow(10, n) % 10; );
private:
   uint8_t n;
};

template <typename T, typename Cle>
vector<T> tri_comptage (T tableau[], size_t taille, size_t cpt, Cle cle);

//---------------------------------------------------------
int main() {

   {  // tableau d'entiers
      int tab[] = {65, 12, 23, 42, 27, 37, 45, 19, 17, 41, 76, 04, 15, 61, 33};
      int TAILLE = sizeof(tab) / sizeof(tab[0]);

      display_tab (tab, TAILLE);  cout << endl;
//      tri_comptage(tab, TAILLE);
      display_tab (tab, TAILLE);  cout << endl;
   }

//   {  // tableau de caractères
//      char chaine[] = "TRIRAPIDE";  // /!\ ajout '\0'
//      int TAILLE = sizeof(chaine) / sizeof(char) - 1;
//
//      cout << endl;
//
//      cout << chaine << endl;
//      tri_rapide(chaine, TAILLE);
//      cout << chaine << endl;
//   }

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
template <typename T, typename Cle>
vector<T> tri_comptage (T tableau[], size_t taille, size_t nCpt, Cle cle) {

   // tableau de compteurs
   vector<size_t> tabCpt(nCpt);
   
   // ... initialisés selon les valeurs du tableau
   for (size_t i=0; i<taille; ++i)
      tabCpt[ cle(tableau[i]) ] += 1;
   
   // calculer la position des indices décallés des précédents
   size_t idx = 0;
   for (size_t i=0; i<nCpt; ++i) {
      size_t tmp = tabCpt[i];
      tabCpt[i] = idx;
      idx += tmp;
   }
   
   // tableau de retour
   vector<T> resultat(taille);
      
   // copier les éléments de tableau dans le vecteur résultat au bons indices
   for (size_t i=0; i<taille; ++i) {
      resultat[ tabCpt[cle( tableau[i] ) ] ] = tableau[i];
      tabCpt[ cle(tabCpt[i]) ] += 1;
   }
   
   // tableau en retour
   return resultat;
}
