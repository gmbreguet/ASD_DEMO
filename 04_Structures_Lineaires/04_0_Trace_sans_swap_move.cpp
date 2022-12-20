//---------------------------------------------------------
// Fichier        : 04_0_Trace_sans_swap_move.cpp
// Version        : 02 - 2022-12-20
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'effect des constructeurs et destructeurs
//                : SANS swap et move
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
Trace f1(int i)            { cout << "f1 : "; return Trace(i); }
Trace f2(Trace t)          { cout << "f2 : "; return t;        }
Trace f3(const Trace& t)   { cout << "f3 : "; return t;        }

//---------------------------------------------------------
int main() {

   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   constructeurs"                         << endl;
   cout << "----------------------------------------" << endl;
   Trace trace1a;                                cout << endl;    // C0(0)
   Trace trace1b(1);                             cout << endl;    // Ci(1)
   Trace trace1c(trace1a);                       cout << endl;    // CC(0)
   Trace trace1d(Trace(2));                      cout << endl;    // Ci(2)
   Trace trace1e(f1(3));                         cout << endl;    // f1 : Ci(3)
   Trace trace1f(f2(trace1a));                   cout << endl;    // CC(0) f2 : CC(0) D(0)
   Trace trace1g(f3(trace1a));                   cout << endl;    // f3 : CC(0)

   cout << "vect(3, Trace(2)) : ";
   vector<Trace> vect(3, Trace(2));              cout << endl;    // Ci(2) CC(2) CC(2) CC(2) D(2)

   cout << "push_back         : ";
   vect.push_back(trace1a);                      cout << endl;    // CC(0) CC(2) CC(2) CC(2) D(2) D(2) D(2)

   cout << "emplace_back      : ";
   vect.emplace_back(trace1a);                   cout << endl;    // CC(0)
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   affectations"                          << endl;
   cout << "----------------------------------------" << endl;
   Trace trace2a(2);                             cout << endl;    // Ci(2)
   trace2a = trace1a;                            cout << endl;    // =C(0)
   trace2a = f1(3);                              cout << endl;    // f1 : Ci(3) =C(3) D(3)
   trace2a = f2(trace1a);                        cout << endl;    // CC(0) f2 : CC(0) =C(0) D(0) D(0)
   trace2a = f3(trace1a);                        cout << endl;    // f3 : CC(0) =C(0) D(0)
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   destructeurs"                          << endl;
   cout << "----------------------------------------" << endl;
   Trace* ptr = new Trace(4);                                     // Ci(4)
   delete ptr;                                                    // D(4)
   ptr = nullptr;
   cout << endl << endl;

   cout << "----------------------------------------" << endl;
   cout << "   swap"                                  << endl;
   cout << "----------------------------------------" << endl;
   cout << "trace1a : " << trace1a                    << endl;    // trace1a : 0
   cout << "trace1b : " << trace1b                    << endl;    // trace1b : 1
   swap(trace1a, trace1b);                       cout << endl;    // CC(0) =C(1) =C(0) D(0)
   cout << "trace1a : " << trace1a                    << endl;    // trace1a : 1
   cout << "trace1b : " << trace1b                    << endl;    // trace1b : 0
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   déplacement"                           << endl;
   cout << "----------------------------------------" << endl;
   cout << "trace1a : " << trace1a                    << endl;    // trace1a : 1
   cout << "trace1b : " << trace1b                    << endl;    // trace1b : 0
   trace1a = std::move(trace1b);                 cout << endl;    // =C(0)
   cout << "trace1a : " << trace1a                    << endl;    // trace1a : 0
   cout << "trace1b : " << trace1b                    << endl;    // trace1b : 0
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

// D(0) D(0) D(0) D(2) D(2) D(2) D(0) D(0) D(3) D(2) D(0) D(0) D(0)
