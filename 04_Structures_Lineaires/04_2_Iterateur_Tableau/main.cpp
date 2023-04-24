//---------------------------------------------------------
// Demo           : 04_2_Iterateur_Tableau
// Fichier        : main.cpp
// Version        : 03 - 2023-04-24
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe Tableau avec iterateurs
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------
#include <iostream>
#include <cstdlib>

#include "Tableau.hpp"

//---------------------------------------------------------
using namespace std;

//---------------------------------------------------------
template <typename T>
void init(Tableau<T>& tab, T start = T{}) {
   for (T& v : tab)
      v = start++;
}

//---------------------------------------------------------
void afficher(const string& msg, const Tableau<int>& tab) {
   cout << msg << endl
        << tab << endl
        << endl;
}

//---------------------------------------------------------
int main() {
   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   constructeurs et affectation"          << endl;
   cout << "----------------------------------------" << endl;
   Tableau<int> tab0;
   afficher("Tableau<int> tab0", tab0);

   Tableau<int> tab1(3);
   afficher("Tableau<int> tab1(3)", tab1);

   Tableau<int> tab2(tab1);
   afficher("Tableau<int> tab2(tab1)", tab2);

   tab0 = tab2;
   afficher("tab0 = tab2", tab0);

   cout << "----------------------------------------" << endl;
   cout << "   swap"                                  << endl;
   cout << "----------------------------------------" << endl;
   tab0.swap(tab1);
   afficher("tab0 : tab0.swap(tab1)", tab0);
   afficher("tab1 :                ", tab1);

   cout << "----------------------------------------" << endl;
   cout << "   lectures et affectations .at"          << endl;
   cout << "----------------------------------------" << endl;
   cout << "tab1.at(0)  : "      << tab1.at(0)        << endl;
   cout << "tab1.at(0)  = 9";    tab1.at(0) = 9; cout << endl;
   cout << "tab1.at(0)  : "      << tab1.at(0)        << endl;
   cout << "tab1        : "      << tab1              << endl;

   cout << "tab1.at(3)  => exception"                 << endl;
//   cout << "tab1.at(3)  = "      << tab1.at(3)        << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   iterateurs"                            << endl;
   cout << "----------------------------------------" << endl;
   Tableau<int> tab(10);
   init(tab, 1);
   cout << tab << endl;    // operateur de flux avec itérateurs constants
   
   Tableau<int>::iterator it = tab.begin();
   cout << "*it   : " << *it     << endl;
   ++it;
   ++it;
   cout << "*it   : " << *it     << endl;
   it++;
   cout << "*it   : " << *it     << endl;
   cout << "*it+2 : " << *it + 2 << endl;

   return EXIT_SUCCESS;
}


