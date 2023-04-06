//---------------------------------------------------------
// Demo           : 04_2_ListeSimple
// Fichier        : main.cpp
// Version        : 03 - 2023.04.06
// Auteur(s)      : BREGUET Guy-Michel
// But            : Liste dynamique avec exceptions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

#include <string>
#include <cctype>    // toupper
#include "List_G.hpp"
 
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
   List_G<string> liste;
    
   cout << "Insertion de noms dans la liste" << endl;
   for (const string& nom : {"Marcel", "Robert", "Sara", "Jean", "Philippe", "Sonia", "Michel"} ) {
      cout << nom << " => liste" << endl;
      liste.add(nom);
   }

   cout << endl;
   cout << "Liste  : " << liste           << endl;
   cout << "Taille : " << liste.size()  << endl;
   cout << endl;

   cout << "chercher un nom" << endl;
   if (string* ptrNom = liste.ptrElement("Sara"s))
      cout << "ptrNom-> : " << *ptrNom << endl;
   else
      cout << "ptrNom-> : PAS TROUVE" << endl;
   cout << endl;

   cout << "parcourir => majusculier" << endl;
   liste.forEach(majusculiser);
   cout << "Liste  : " << liste           << endl;
   cout << "Taille : " << liste.size()  << endl;
   cout << endl;

   // Elément en tête
   cout << "Elément en tête de liste" << endl;
   cout << liste.first() << endl;
   cout << endl;

   // Supprimer tous les éléments
   cout << "Supprimer tous les éléments" << endl;
   while (not liste.isEmpty()) {
      cout << liste.first() << endl;
      liste.remove();
   }

   cout << endl;
   cout << "Liste  : " << liste           << endl;
   cout << "Taille : " << liste.size()    << endl;

   cout << endl;
   return EXIT_SUCCESS;
}

//      Insertion de noms dans la liste
//      Marcel => liste
//      Robert => liste
//      Sara => liste
//      Jean => liste
//      Philippe => liste
//      Sonia => liste
//      Michel => liste
//
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
//      Elément en tête de liste
//      MICHEL
//
//      Supprimer tous les éléments
//      MICHEL
//      SONIA
//      PHILIPPE
//      JEAN
//      SARA
//      ROBERT
//      MARCEL
//
//      Liste  : ()
//      Taille : 0



