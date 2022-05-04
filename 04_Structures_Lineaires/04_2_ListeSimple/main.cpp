//---------------------------------------------------------
// Demo           : 04_2_ListeSimple
// Fichier        : main.cpp
// Version        : 02 - 2022.05.04
// Auteur(s)      : BREGUET Guy-Michel
// But            : Liste dynamique avec exceptions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

#include <string>
#include <cctype>    // toupper
#include "ListeSimple.hpp"
 
using namespace std;

//---------------------------------------------------------
// param en copie pour traiter des constantes si utile
string majusculiser(string chaine) {
   for (char& c : chaine)
      c = (char)toupper(c);
   return chaine;
}

//---------------------------------------------------------
int main () {
   // Instanciation d'une liste chainée liste
   Liste<string> liste;
    
   // Insertion de six noeuds dans la liste
   liste.inserer("Marcel");
   liste.inserer("Robert");
   liste.inserer("Sara");
   liste.inserer("Jean");
   liste.inserer("Philippe");
   liste.inserer("Sonia");
   liste.inserer("Michel");
   cout << "Liste  : " << liste           << endl;
   cout << "Taille : " << liste.taille()  << endl;
   cout << endl;

   cout << "chercher un nom" << endl;
   if (string* ptrNom = liste.ptrElement("Sara"s))
      cout << "ptrNom-> : " << *ptrNom << endl;
   else
      cout << "ptrNom-> : PAS TROUVE" << endl;
   cout << endl;

   cout << "parcourir => majusculier" << endl;
   liste.parcourir(majusculiser);
   cout << "Liste  : " << liste           << endl;
   cout << "Taille : " << liste.taille()  << endl;
   cout << endl;

   // Supprimer tous les éléments
   cout << "Supprimer tous les éléments" << endl;
   while (not liste.estVide()) {
      cout << liste.premier() << endl;
      liste.supprimer();
   }
   cout << "Liste  : " << liste           << endl;
   cout << "Taille : " << liste.taille()  << endl;

   cout << endl;
   return EXIT_SUCCESS;
}

//      Liste  : (Michel, Sonia, Philippe, Jean, Sara, Robert, Marcel)
//      Taille : 7
//
//      chercher un nom
//      ptrNom-> : Sara
//
//      parcourir => majusculier
//      Liste  : (MICHEL, SONIA, PHILIPPE, JEAN, SARA, ROBERT, MARCEL)
//      Taille : 7
//
//      Supprimer tous les éléments
//      MICHEL
//      SONIA
//      PHILIPPE
//      JEAN
//      SARA
//      ROBERT
//      MARCEL
//      Liste  : ()
//      Taille : 0
