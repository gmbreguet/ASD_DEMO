//---------------------------------------------------------
// Fichier        : 04_Trace_avec_swap_move.cpp
// Version        : 02 - 2022-04-11
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'effect des constructeurs et destructeurs
//                : avec swap et move
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//---------------------------------------------------------
class Trace {
   friend ostream& operator<< (ostream& os, const Trace& t)
                                             { return os << t.data;             }
public:
   Trace()           : data(0)               { cout << "C0(" << data << ") ";   }

   Trace(int data)   : data(data)            { cout << "Ci(" << data << ") ";   }

   Trace(const Trace& other)                 { this->data = other.data;
                                               cout << "CC(" << data << ") ";   }
   Trace(Trace&& other) noexcept
   : data(other.data)                        { other.data = 0;
                                               cout << "CD(" << data << ") ";   }

   ~Trace()                                  { cout << "D("  << data << ") ";   }

   void swap(Trace& other) noexcept          { using std::swap;
                                               std::swap(data, other.data);
                                               cout << "swap(" << data << ") "; }

   Trace& operator=(const Trace& other)      { this->data = other.data;
                                               cout << "=C("  << data << ") ";
                                               return *this;                    }

   Trace& operator=(Trace&& other) noexcept  { this->swap(other);
                                               cout << "=D(" << data << ") ";
                                               return *this;                    }
private:
   int data;
};

//---------------------------------------------------------
// pas utilisé dans ce code
void swap(Trace& lhs, Trace& rhs) noexcept   { lhs.swap(rhs); }

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
   Trace trace1a;                                cout << endl;
   Trace trace1b(1);                             cout << endl;
   Trace trace1c(trace1a);                       cout << endl;
   Trace trace1d(Trace(2));                      cout << endl;
   Trace trace1e(f1(3));                         cout << endl;
   Trace trace1f(f2(trace1a));                   cout << endl;
   Trace trace1g(f3(trace1a));                   cout << endl;

   cout << "vect(3, Trace(2)) : ";
   vector<Trace> vect(3, Trace(2));              cout << endl;

   cout << "push_back         : ";
   vect.push_back(trace1a);                      cout << endl;

   cout << "emplace_back      : ";
   vect.emplace_back(trace1a);                   cout << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   affectations"                          << endl;
   cout << "----------------------------------------" << endl;
   Trace trace2a(2);                             cout << endl;
   trace2a = trace1a;                            cout << endl;
   trace2a = f1(3);                              cout << endl;
   trace2a = f2(trace1a);                        cout << endl;
   trace2a = f3(trace1a);                        cout << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   destructeurs"                          << endl;
   cout << "----------------------------------------" << endl;
   Trace* ptr = new Trace(4);
   delete ptr;
   ptr = nullptr;
   cout << endl << endl;

   cout << "----------------------------------------" << endl;
   cout << "   swap"                                  << endl;
   cout << "----------------------------------------" << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   trace1a.swap(trace1b);                        cout << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   déplacement"                           << endl;
   cout << "----------------------------------------" << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   trace1a = std::move(trace1b);                 cout << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

//      ----------------------------------------
//         constructeurs
//      ----------------------------------------
//      C0(0)
//      Ci(1)
//      CC(0)
//      Ci(2)
//      f1 : Ci(3)
//      CC(0) f2 : CD(0) D(0)
//      f3 : CC(0)
//      vect(3, Trace(2)) : Ci(2) CC(2) CC(2) CC(2) D(2)
//      push_back         : CC(0) CD(2) CD(2) CD(2) D(0) D(0) D(0)
//      emplace_back      : CC(0)
//
//      ----------------------------------------
//         affectations
//      ----------------------------------------
//      Ci(2)
//      =C(0)
//      f1 : Ci(3) swap(3) =D(3) D(0)
//      CC(0) f2 : CD(0) swap(0) =D(0) D(3) D(0)
//      f3 : CC(0) swap(0) =D(0) D(0)
//
//      ----------------------------------------
//         destructeurs
//      ----------------------------------------
//      Ci(4) D(4)
//
//      ----------------------------------------
//         swap
//      ----------------------------------------
//      trace1a : 0
//      trace1b : 1
//      swap(1)
//      trace1a : 1
//      trace1b : 0
//
//      ----------------------------------------
//         déplacement
//      ----------------------------------------
//      trace1a : 1
//      trace1b : 0
//      swap(0) =D(0)
//      trace1a : 0
//      trace1b : 1
//
//      ----------------------------------------
//         sortie de main
//      ----------------------------------------
//      D(0) D(0) D(0) D(2) D(2) D(2) D(0) D(0) D(3) D(2) D(0) D(1) D(0) Program ended with exit code: 0
