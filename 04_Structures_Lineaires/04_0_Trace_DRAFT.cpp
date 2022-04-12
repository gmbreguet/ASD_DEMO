//---------------------------------------------------------
// Fichier        : 04_Trace_sans_move.cpp
// Version        : 01 - 2022-04-11
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'effect des constructeurs et destructeurs
// Modifications  :
// Remarque(s)    : SANS l'opérateur de déplacement
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//---------------------------------------------------------
class Trace {
   friend ostream& operator<< (ostream& os, const Trace& o);
public:
   Trace()           : data(0)            { cout  << "C0(" << data << ") "; }
   Trace(int data) : data(data)           { cout  << "C("  << data << ") "; }
   Trace(const Trace& other)              { this->data = other.data;
                                            cout << "CC("  << data << ") "; }
   ~Trace()                               { cout  << "D("  << data << ") "; }
   Trace& operator=(const Trace& other)   { this->data = other.data;
                                            cout << "=("  << data << ") ";
                                            return *this;                   }
private:
   int data;
};

//---------------------------------------------------------
void f1(int i) {
   Trace tracef1(i);
}

//---------------------------------------------------------
void f2(int i) {
   static Trace tracef2(i);
}

//---------------------------------------------------------
Trace* f3(int i) {
   Trace* ptr = new Trace(i);
   return ptr;
}

//---------------------------------------------------------
Trace trace(0);

//---------------------------------------------------------
int main() {

   //------------------------------------------------------
   cout << endl << "1) --------------------------" << endl;
   Trace trace1(1);
   cout << endl;

   //------------------------------------------------------
   cout << endl << "2) --------------------------" << endl;
   {
      Trace trace2(2);
      cout << endl;
      trace2 = trace1;
      cout << endl;
   }
   cout << endl;

   //------------------------------------------------------
   cout << endl << "3) -----------------------------------" << endl;
   f1(3);
   cout << endl << "4) -----------------------------------" << endl;
   f1(4);
   cout << endl;

   //------------------------------------------------------
   cout << endl << "5) -----------------------------------" << endl;
   f2(5);
   cout << endl;
   cout << endl << "6) -----------------------------------" << endl;
   f2(6);
   cout << endl;

   //------------------------------------------------------
   cout << endl << "7) -----------------------------------" << endl;
   Trace* trace7 = f3(7);
   delete trace7;
   trace7 = nullptr;
   cout << endl;

   //------------------------------------------------------
   cout << endl << "8) -----------------------------------" << endl;
   {
      vector<Trace> trace8;
   }
   cout << endl;

   //------------------------------------------------------
   cout << endl << "9) -----------------------------------" << endl;
   {
      vector<Trace> trace9(3);
   }
   cout << endl;

   //------------------------------------------------------
   cout << endl << "10) ---------------------------------" << endl;
   {
      vector<Trace> trace10(3, Trace(10));
      cout << endl;
      cout << "=> resize(5)" << endl;
      trace10.resize(5);
      cout << endl;
      cout << "=> resize(2)" << endl;
      trace10.resize(2);
      cout << endl;
      cout << "=> sortie {}" << endl;
   }
   cout << endl;

   //------------------------------------------------------
   cout << endl << "main) -------------------------------" << endl;
   return EXIT_SUCCESS;
}

//      C(0)
//      1) --------------------------
//      C(1)
//
//      2) --------------------------
//      C(2)
//      =(1)
//      D(1)
//
//      3) -----------------------------------
//      C(3) D(3)
//      4) -----------------------------------
//      C(4) D(4)
//
//      5) -----------------------------------
//      C(5)
//
//      6) -----------------------------------
//
//
//      7) -----------------------------------
//      C(7) D(7)
//
//      8) -----------------------------------
//
//
//      9) -----------------------------------
//      C0(0) C0(0) C0(0) D(0) D(0) D(0)
//
//      10) ---------------------------------
//      C(10) CC(10) CC(10) CC(10) D(10)
//      => resize(5)
//      C0(0) C0(0) CC(10) CC(10) CC(10) D(10) D(10) D(10)
//      => resize(2)
//      D(0) D(0) D(10)
//      => sortie {}
//      D(10) D(10)
//
//      main) -------------------------------
//      D(1) D(5) D(0) Program ended with exit code: 0
