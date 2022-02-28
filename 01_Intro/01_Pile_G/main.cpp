//---------------------------------------------------------
// Demo           : 01_Pile_G
// Fichier        : main.cpp
// Version        : 01 - 2022.02.28
// Auteur(s)      : BREGUET Guy-Michel
// But            : Pile générique avec exceptions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

#include "Pile_G.hpp"

using namespace std;

//---------------------------------------------------
int main() {

   cout << "-------------------------------" << endl;
   cout << "empiler 10 valeurs ..."          << endl;
   Pile<int> pile(10);
   int i=0;
   while (not pile.estPleine()) {
      cout << "empiler("<< i << ")"          << endl;
      pile.empiler(i++);
   }

   cout << endl;
   cout << "-------------------------------" << endl;
   while (not pile.estVide()) {
      cout << "sommet : " << pile.sommet() << endl;
      pile.depiler();
   }

   try {
      int top = pile.sommet();
      cout << "sommet : " << top << endl;
   }
   catch (Pile_Vide e) {
      cout << "/!\\ la pile est vide" << endl;
   }

   return EXIT_SUCCESS;
}

//    -------------------------------
//    empiler 10 valeurs ...
//    empiler(0)
//    empiler(1)
//    empiler(2)
//    empiler(3)
//    empiler(4)
//    empiler(5)
//    empiler(6)
//    empiler(7)
//    empiler(8)
//    empiler(9)
//    
//    -------------------------------
//    lecture : at() et []
//    pile[5]    : 5
//    pile.at(5) : 5
//    
//    -------------------------------
//    ecriture : at() et []
//    pile[5]    = 10
//    pile[5]    : 10
//    pile.at(5) = 20
//    pile.at(5) : 20
//    
//    -------------------------------
//    dernier : 9
//    dernier : 8
//    dernier : 7
//    dernier : 6
//    dernier : 20
//    dernier : 4
//    dernier : 3
//    dernier : 2
//    dernier : 1
//    dernier : 0
