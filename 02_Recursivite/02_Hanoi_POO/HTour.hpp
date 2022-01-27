#ifndef TOURSHANOI_TOUR_CLASS
#define TOURSHANOI_TOUR_CLASS
#include <string>
using namespace std;

/**
  Une Tour avec ses disques
*/
#include "HDisque.hpp"
const int NMAXDISQUES = 10;
class HTour
{
  public:
    HTour();
    HTour(int n, bool vide);
    HDisque getDisque(int k) const;
    int sommet() const;
    void push(const HDisque& d);
    void pop();
    void assign(int taille, bool vide);
  private:
    HDisque m_pilier[NMAXDISQUES]; // le pilier
    int m_top; // indice du sommet
    int m_dim; // dimension du socle
};
#include "HTour.cpp"
#endif
