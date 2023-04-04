//---------------------------------------------------------
// Fichier        : 04_0_Trace_Emplace.cpp
// Version        : 01 - 2023-04-04
// Auteur(s)      : BREGUET Guy-Michel
// But            : comparer constructeur, push_back et emplace
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//---------------------------------------------------------
class Trace {
   friend ostream& operator<< (ostream& os, const Trace& t) {
      return os << t.data;
   }

public:
   Trace()           : data(0)               { cout << "C0(" << data << ") ";   }

   Trace(int data)   : data(data)            { cout << "Ci(" << data << ") ";   }

   Trace(const Trace& other)                 { this->data = other.data;
                                               cout << "CC(" << data << ") ";   }

   ~Trace()                                  { cout << "D("  << data << ") ";   }

   Trace& operator=(const Trace& other)      { this->data = other.data;
                                               cout << "=C("  << data << ") ";
                                               return *this;                    }
private:
   int data;
};


//---------------------------------------------------------
int main() {

   {
      cout << "----------------------------------------" << endl;
      cout << "affectation(objet)"                       << endl;
      cout << "----------------------------------------" << endl;
      const size_t TAILLE = 2;
      vector<Trace> v(TAILLE);                     // C0(0) C0(0)
      for (size_t i=0; i<TAILLE; ++i)
         v.at(i) = Trace(i);                       // Ci(0) =C(0) D(0) Ci(1) =C(1) D(1)
      cout << endl;
   }                                               // D(1) D(0)

   {
      cout << endl;
      cout << "----------------------------------------" << endl;
      cout << "push_back(objet)"                         << endl;
      cout << "----------------------------------------" << endl;
      const size_t TAILLE = 2;
      vector<Trace> v;                             // pas de construction
      v.reserve(TAILLE);                           // pas de construction
      for (size_t i=0; i<TAILLE; ++i)
         v.push_back(Trace(i));                    // Ci(0) CC(0) D(0) Ci(1) CC(1) D(1)
      cout << endl;
   }                                               // D(1) D(0)

   {
      cout << endl;
      cout << "----------------------------------------" << endl;
      cout << "emplace_back(valeur)"                     << endl;
      cout << "----------------------------------------" << endl;
      const size_t TAILLE = 2;
      vector<Trace> v;                             // pas de construction
      v.reserve(TAILLE);                           // pas de construction
      for (size_t i=0; i<TAILLE; ++i)
         v.emplace_back(i);                        // Ci(0) Ci(1)
      cout << endl;
   }                                               // D(1) D(0)

   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

//      ----------------------------------------
//      affectation(objet)
//      ----------------------------------------
//      C0(0) C0(0) Ci(0) =C(0) D(0) Ci(1) =C(1) D(1)
//      D(1) D(0)
//      ----------------------------------------
//      push_back(objet)
//      ----------------------------------------
//      Ci(0) CC(0) D(0) Ci(1) CC(1) D(1)
//      D(1) D(0)
//      ----------------------------------------
//      emplace_back(valeur)
//      ----------------------------------------
//      Ci(0) Ci(1)
//      D(1) D(0)
//      ----------------------------------------
//      sortie de main
//      ----------------------------------------


