//---------------------------------------------------------
// Fichier        : Trace.cpp
// Version        : 04 - 2022-12-20
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'effect des constructeurs et destructeurs
//                : AVEC swap et move
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>

//---------------------------------------------------------
class Trace {
   friend std::ostream& operator<< (std::ostream& os, const Trace& t)
                                             { return os << t.data;             }
public:
   Trace()           : data(0)               { std::cout << "C0(" << data << ") ";   }

   Trace(int data)   : data(data)            { std::cout << "Ci(" << data << ") ";   }

   Trace(const Trace& other)                 { this->data = other.data;
                                               std::cout << "CC(" << data << ") ";   }
   Trace(Trace&& other) noexcept
   : data(other.data)                        { other.data = 0;
                                               std::cout << "CD(" << data << ") ";   }

   ~Trace()                                  { std::cout << "D("  << data << ") ";   }

   void swap(Trace& other) noexcept          { // using std::swap;
                                               std::swap(data, other.data);
                                               std::cout << "swap(" << data << ") "; }

   Trace& operator=(const Trace& other)      { this->data = other.data;
                                               std::cout << "=C("  << data << ") ";
                                               return *this;                    }

   Trace& operator=(Trace&& other) noexcept  { this->swap(other);
                                               std::cout << "=D(" << data << ") ";
                                               return *this;                    }
private:
   int data;
};
