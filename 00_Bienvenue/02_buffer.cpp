//---------------------------------------------------------
// Fichier        : 02_buffer.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-10-07
// But            : démontrer l'évuation du buffer de saisie
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main () {
   char  caractere;
   int   entier;
   float reel;

   //----------------------------------------
   cout << "entrer 3 caracteres : ";

   cin  >> caractere;
   cout << "caractere 1 : " << caractere << endl;

   cin  >> caractere;
   cout << "caractere 2 : " << caractere << endl;

   cin  >> caractere;
   cout << "caractere 3 : " << caractere << endl;

   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer

   //----------------------------------------
   cout << "entrer un entier : ";

   cin  >> entier;
   cout << "entier : " << entier << endl;

   cin  >> caractere;
   cout << "buffer : " << caractere << endl;

   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer

   //----------------------------------------
   cout << "entrer un reel : ";

   cin  >> reel;
   cout << "reel   : " << reel << endl;
   cin  >> caractere;
   cout << "buffer : " << caractere << endl;

   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer


   //----------------------------------------
   // fin de programme
   cout << "presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}
