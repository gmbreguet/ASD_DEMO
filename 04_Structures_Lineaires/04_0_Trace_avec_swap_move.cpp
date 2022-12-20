//---------------------------------------------------------
// Fichier        : 04_0_Trace_avec_swap_move.cpp
// Version        : 04 - 2022-12-20
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'effect des constructeurs et destructeurs
//                : AVEC swap et move
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

   void swap(Trace& other) noexcept          { // using std::swap;
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
   Trace trace1a;                                cout << endl;    // C0(0)
   Trace trace1b(1);                             cout << endl;    // Ci(1)
   Trace trace1c(trace1a);                       cout << endl;    // CC(0)
   Trace trace1d(Trace(2));                      cout << endl;    // Ci(2)
   Trace trace1e(f1(3));                         cout << endl;    // f1 : Ci(3)
   Trace trace1f(f2(trace1a));                   cout << endl;    // CC(0) f2 : CD(0) D(0)
   Trace trace1g(f3(trace1a));                   cout << endl;    // f3 : CC(0)
   Trace trace1h(std::move(trace1e));            cout << endl;    // CD(3)

   cout << "vect(3, Trace(2)) : ";
   vector<Trace> vect(3, Trace(2));              cout << endl;    // Ci(2) CC(2) CC(2) CC(2) D(2)

   cout << "push_back         : ";
   vect.push_back(trace1a);                      cout << endl;    // CC(0) CD(2) CD(2) CD(2) D(0) D(0) D(0)

   cout << "emplace_back      : ";
   vect.emplace_back(trace1a);                   cout << endl;    // CC(0)
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   affectations"                          << endl;
   cout << "----------------------------------------" << endl;
   Trace trace2a(2);                             cout << endl;    // Ci(2)
   trace2a = trace1a;                            cout << endl;    // =C(0)
   trace2a = f1(3);                              cout << endl;    // f1 : Ci(3) swap(3) =D(3) D(0)
   trace2a = f2(trace1a);                        cout << endl;    // CC(0) f2 : CD(0) swap(0) =D(0) D(3) D(0)
   trace2a = f3(trace1a);                        cout << endl;    // f3 : CC(0) swap(0) =D(0) D(0)
   trace2a = std::move(trace1a);                 cout << endl;    // swap(0) =D(0)
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
   trace1a.swap(trace1b);                        cout << endl;    // swap(1)
   cout << "trace1a : " << trace1a                    << endl;    // trace1a : 1
   cout << "trace1b : " << trace1b                    << endl;    // trace1b : 0
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   déplacement"                           << endl;
   cout << "----------------------------------------" << endl;
   cout << "trace1a : " << trace1a                    << endl;    // trace1a : 1
   cout << "trace1b : " << trace1b                    << endl;    // trace1b : 0
   trace1a = std::move(trace1b);                 cout << endl;    // swap(0) =D(0)
   cout << "trace1a : " << trace1a                    << endl;    // trace1a : 0
   cout << "trace1b : " << trace1b                    << endl;    // trace1b : 1
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   construction en place / déplacement"   << endl;
   cout << "----------------------------------------" << endl;
   Trace* ptr2a = reinterpret_cast<Trace*>(::operator new(sizeof(Trace)));
   Trace* ptr2b = reinterpret_cast<Trace*>(::operator new(sizeof(Trace)));

   new(ptr2a) Trace(trace1b);                // en place          // CC(1)
   new(ptr2b) Trace(std::move(*ptr2a));      // par déplacement   // CD(1)
   cout << endl;

   cout << "ptr2a -> " << *ptr2a                      << endl;    // ptr2a -> 0
   cout << "ptr2b -> " << *ptr2b                      << endl;    // ptr2b -> 1

   delete(ptr2a);    ptr2a = nullptr;                             // D(0)
   delete(ptr2b);    ptr2b = nullptr;                             // D(1)
   cout << endl;

   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}

// D(0) D(0) D(0) D(2) D(2) D(2) D(3) D(0) D(0) D(0) D(2) D(0) D(1) D(0)
