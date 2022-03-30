//---------------------------------------------------------
// Fichier        : 04_Pointeurs.cpp
// Version        : 02 - 2022-03-30
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

   cout << "-------------------------------------"          << endl;
   cout << "adresse du tableau ..."                         << endl;
   cout << "-------------------------------------"          << endl;
   cout << " tab                    : "   << (void*)tab     << endl;
   cout << "&tab                    : "   << &tab           << endl;
   cout << " ptr (contenu)          : "   <<  ptr           << endl;
   cout << "&ptr (adresse)          : "   << &ptr           << endl;
   cout << "*ptr (ref)              : "   << *ptr           << endl;
   cout << endl;

   cout << "-------------------------------------"          << endl;
   cout << "élément d'un tableau ..."                       << endl;
   cout << "-------------------------------------"          << endl;
   cout << "&tab[2]                 : "   << &tab[2]        << endl;
   cout << " tab+2                  : "   <<  tab+2         << endl;
   cout << " ptr+2                  : "   <<  ptr+2         << endl;
   cout << " tab[2]                 : "   <<  tab[2]        << endl;
   cout << " ptr[2]                 : "   <<  ptr[2]        << endl;
   cout << "*(tab+2)                : "   << *(tab+2)       << endl;

   cout << "*(2+tab)                : "   << *(2+tab)       << endl;
   cout << " 2[ptr]                 : "   <<  2[ptr]        << endl;
   cout << endl;

   cout << "-------------------------------------"          << endl;
   cout << "décallage ..."                                  << endl;
   cout << "-------------------------------------"          << endl;
   ptr += 2;
   cout << "ptr += 2" << endl;
   cout << "*(tab+2)                : "   << *(tab+2)       << endl;
   cout << "*ptr                    : "   << *ptr           << endl;
   cout << " ptr[0]                 : "   <<  ptr[0]        << endl;
   cout << "*(ptr-1)                : "   << *(ptr-1)       << endl;
   cout << " ptr[-1]                : "   <<  ptr[-1]       << endl;
   cout << endl;

   cout << "-------------------------------------"          << endl;
   cout << "distance ..."                                   << endl;
   cout << "-------------------------------------"          << endl;
   cout << "&tab[6] - tab           : "   << &tab[6] - tab  << endl;
   cout << "sizeof(tab)             : "   << sizeof(tab)    << " /!\\ "
        << "ne fonctionne pas si tab est un ptr(param fct)" << endl;
   cout << "sizeof(int)             : "   << sizeof(int)    << endl;
   cout << "taille                  : "   << sizeof(tab) / sizeof(int) << endl;
   cout << endl;

   cout << "-------------------------------------"          << endl;
   cout << "pointeur void ..."                              << endl;
   cout << "-------------------------------------"          << endl;
   void* ptrV = tab+2;
   cout << "cout << *ptrV           : "   << "compile pas"  << endl;
   cout << "cout << *(int*)ptrV     : "   << *(int*)ptrV    << endl;
   cout << "cout << *(double*)ptrV  : "   << *(double*)ptrV << endl;
   cout << endl;

   cout << "-------------------------------------"          << endl;
   cout << "pointeur et const ..."                          << endl;
   cout << "-------------------------------------"          << endl;
         int variable   = 12;
   const int CONSTANTE  = 23;
   
         int*       ptr1 = &variable;           // pointeur non constant sur une variable
   const int*       ptr2 = &CONSTANTE;          // pointeur non constant sur une constante
         int* const ptr3 = &variable;           // pointeur CONSTANT sur une variable
   const int* const ptr4 = &CONSTANTE;          // pointeur CONSTANT sur une CONSTANTE

   cout << "cout << *ptr1           : "   << *ptr1          << endl;
   cout << "cout << *ptr2           : "   << *ptr2          << endl;
   cout << "cout << *ptr3           : "   << *ptr3          << endl;
   cout << "cout << *ptr4           : "   << *ptr4          << endl;
   cout << endl;

   // ou en castant ...
   
   cout << "-------------------------------------"          << endl;
   cout << "modification d'une constante ..."               << endl;
   cout << "-------------------------------------"          << endl;
   volatile const int CSTE = 12;    // une constante (accès en lecture seule)
   int* ptrCste = (int*)&CSTE;      // (int*)&CSTE pour lever la contrainte
   cout << "int* ptrCste=(int*)&CSTE  "   << endl;
   cout << "cout << CSTE            : "   << CSTE           << endl;
   cout << "cout << *ptrCste        : "   << *ptrCste       << endl;
   cout << "*ptrCste = 21"                << endl;   *ptrCste = 21;  // écriture dans la constante
   cout << "cout << *ptrCste        : "   << *ptrCste       << endl;
   cout << "cout << CSTE            : "   << CSTE           << endl;
   cout << endl;

   cout << "-------------------------------------"          << endl;
   cout << "ne compile pas ..."                             << endl;
   cout << "-------------------------------------"          << endl;
   cout << "ptr *= 3       : "            << endl;    // ptr *= 3;
   cout << "ptr += ptr     : "            << endl;    // ptr += ptr;
   cout << endl;

   return EXIT_SUCCESS;
}

//      -------------------------------------
//      adresse du tableau ...
//      -------------------------------------
//       tab                    : 0x7ff7bfeff210
//      &tab                    : 0x7ff7bfeff210
//       ptr (contenu)          : 0x7ff7bfeff210
//      &ptr (adresse)          : 0x7ff7bfeff200
//      *ptr (ref)              : 0
//
//      -------------------------------------
//      élément d'un tableau ...
//      -------------------------------------
//      &tab[2]                 : 0x7ff7bfeff218
//       tab+2                  : 0x7ff7bfeff218
//       ptr+2                  : 0x7ff7bfeff218
//       tab[2]                 : 2
//       ptr[2]                 : 2
//      *(tab+2)                : 2
//      *(2+tab)                : 2
//       2[ptr]                 : 2
//
//      -------------------------------------
//      décallage ...
//      -------------------------------------
//      ptr += 2
//      *(tab+2)                : 2
//      *ptr                    : 2
//       ptr[0]                 : 2
//      *(ptr-1)                : 1
//       ptr[-1]                : 1
//
//      -------------------------------------
//      distance ...
//      -------------------------------------
//      &tab[6] - tab           : 6
//      sizeof(tab)             : 40 /!\ ne fonctionne pas si tab est un ptr(param fct)
//      sizeof(int)             : 4
//      taille                  : 10
//
//      -------------------------------------
//      pointeur void ...
//      -------------------------------------
//      cout << *ptrV           : compile pas
//      cout << *(int*)ptrV     : 2
//      cout << *(double*)ptrV  : 6.36599e-314
//
//      -------------------------------------
//      pointeur et const ...
//      -------------------------------------
//      cout << *ptr1           : 12
//      cout << *ptr2           : 23
//      cout << *ptr3           : 12
//      cout << *ptr4           : 23
//
//      -------------------------------------
//      modification d'une constante ...
//      -------------------------------------
//      int* ptrCste=(int*)&CSTE
//      cout << CSTE            : 12
//      cout << *ptrCste        : 12
//      *ptrCste = 21
//      cout << *ptrCste        : 21
//      cout << CSTE            : 21
//
//      -------------------------------------
//      ne compile pas ...
//      -------------------------------------
//      ptr *= 3       :
//      ptr += ptr     :
//
//      Program ended with exit code: 0
