//---------------------------------------------------------
// Fichier        : 03_Pointeurs.cpp
// Version        : 01 - 2022-03-15
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'utilisation basic de pointeurs
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


//---------------------------------------------------------
int main() {

   int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int* ptr = tab;

   cout << "-------------------------------------" << endl;
   cout << "adresse du tableau ..."                << endl;
   cout << "-------------------------------------" << endl;
   cout << " tab           : "   << (void*)tab     << endl;
   cout << "&tab           : "   << &tab           << endl;
   cout << " ptr (contenu) : "   <<  ptr           << endl;
   cout << "&ptr (adresse) : "   << &ptr           << endl;
   cout << "*ptr (ref)     : "   << *ptr           << endl;
   cout << endl;

   cout << "-------------------------------------" << endl;
   cout << "élément d'un tableau ..."              << endl;
   cout << "-------------------------------------" << endl;
   cout << "&tab[2]        : "   << &tab[2]        << endl;
   cout << " tab+2         : "   <<  tab+2         << endl;
   cout << " ptr+2         : "   <<  ptr+2         << endl;
   cout << " tab[2]        : "   <<  tab[2]        << endl;
   cout << " ptr[2]        : "   <<  ptr[2]        << endl;
   cout << "*(tab+2)       : "   << *(tab+2)       << endl;

   cout << "*(2+tab)       : "   << *(2+tab)       << endl;
   cout << " 2[ptr]        : "   <<  2[ptr]        << endl;
   cout << endl;

   cout << "-------------------------------------" << endl;
   cout << "décallage ..."                         << endl;
   cout << "-------------------------------------" << endl;
   ptr += 2;
   cout << "ptr += 2" << endl;
   cout << "*(tab+2)       : "   << *(tab+2)       << endl;
   cout << "*ptr           : "   << *ptr           << endl;
   cout << " ptr[0]        : "   <<  ptr[0]        << endl;
   cout << "*(ptr-1)       : "   << *(ptr-1)       << endl;
   cout << " ptr[-1]       : "   <<  ptr[-1]       << endl;
   cout << endl;

   cout << "-------------------------------------" << endl;
   cout << "distance ..."                          << endl;
   cout << "-------------------------------------" << endl;
   cout << "&tab[6] - tab  : "   << &tab[6] - tab  << endl;
   cout << "sizeof(tab)    : "   << sizeof(tab)    << " /!\\ "
        << "ne fonctionne pas si tab est un ptr (param fct)" << endl;
   cout << "sizeof(int)    : "   << sizeof(int)    << endl;
   cout << "taille         : "   << sizeof(tab) / sizeof(int)    << endl;
   cout << endl;

   cout << "-------------------------------------" << endl;
   cout << "ne compile pas ..."                    << endl;
   cout << "-------------------------------------" << endl;
   cout << "ptr *= 3       : "   << endl;    // ptr *= 3;
   cout << "ptr += ptr     : "   << endl;    // ptr += ptr;
   cout << endl;

   return EXIT_SUCCESS;
}

//      -------------------------------------
//      adresse du tableau ...
//      -------------------------------------
//       tab           : 0x7ff7bfeff2a0
//      &tab           : 0x7ff7bfeff2a0
//       ptr (contenu) : 0x7ff7bfeff2a0
//      &ptr (adresse) : 0x7ff7bfeff290
//      *ptr (ref)     : 0
//
//      -------------------------------------
//      élément d'un tableau ...
//      -------------------------------------
//      &tab[2]        : 0x7ff7bfeff2a8
//       tab+2         : 0x7ff7bfeff2a8
//       ptr+2         : 0x7ff7bfeff2a8
//       tab[2]        : 2
//       ptr[2]        : 2
//      *(tab+2)       : 2
//      *(2+tab)       : 2
//       2[ptr]        : 2
//
//      -------------------------------------
//      décallage ...
//      -------------------------------------
//      ptr += 2
//      *(tab+2)       : 2
//      *ptr           : 2
//       ptr[0]        : 2
//      *(ptr-1)       : 1
//       ptr[-1]       : 1
//
//      -------------------------------------
//      distance ...
//      -------------------------------------
//      &tab[6] - tab  : 6
//      sizeof(tab)    : 40 /!\ ne fonctionne pas si tab est un ptr (param fct)
//      sizeof(int)    : 4
//      taille         : 10
//
//      -------------------------------------
//      ne compile pas ...
//      -------------------------------------
//      ptr *= 3       :
//      ptr += ptr     :
