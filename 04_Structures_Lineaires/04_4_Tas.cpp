//---------------------------------------------------------
// Fichier        : 04_4_Tas.cpp
// Version        : 01 - 2022-05-17
// Auteur(s)      : BREGUET Guy-Michel
// But            : Sample of a Heap class implementation using vector
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <vector>

//---------------------------------------------------------
using namespace std;

//---------------------------------------------------------
template <typename T>
class Heap;

template <typename T>
ostream& operator<< (ostream& os, const Heap<T>& h);

//---------------------------------------------------------
template <typename T>
class Heap {
   friend ostream& operator<< <T>(ostream& os, const Heap<T>& h);

public:
   Heap() : heapSize(0) {};
   Heap(const vector<T>& v);

   size_t size() const { return heapSize; };

   void push(const T& e);
   void pop();
   T    top() const;

private:
   size_t parent     (size_t i) const { return (i - 1) / 2; }
   size_t right      (size_t i) const { return 2 * i + 2;   }
   size_t left       (size_t i) const { return 2 * i + 1;   }
   size_t greatest   (size_t i) const;
   void   heapifyUp  (size_t i);
   void   heapifyDown(size_t i);

   vector<T> array;
   size_t    heapSize;
};

//---------------------------------------------------------
int main() {

   // empty heap
   Heap<int> heap1;
   cout << heap1 << endl;
   cout << endl;

   for (int i=0; i<10; ++i)
      heap1.push(i);
   cout << heap1 << endl;
   cout << endl;

   // from a vecteur => heap
   vector<int> vecteur = {1, 2, 3, 4, 5, 6};
   Heap<int> heap2(vecteur);
   cout << heap2 << endl;

   cout << "heap2.top : " << heap2.top() << endl;
   heap2.pop();
   cout << heap2 << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Heap<T>& heap) {
   os << "[";
   for (size_t i=0; i<heap.size(); ++i) {
      if (i)
         os << ", ";
      os << heap.array[i];
   }
   os << "]";
   return os;
}

//---------------------------------------------------------
// Heap - PUBLIC
//---------------------------------------------------------
template <typename T>
Heap<T>::Heap(const vector<T>& v) {
   array    = v;
   heapSize = v.size();
   size_t p = parent(size()-1);
   for (int i=(int)p; i>=0; i--)
      heapifyDown(i);
}

//---------------------------------------------------------
template <typename T>
void Heap<T>::push(const T& e) {
   array.push_back(e);
   heapifyUp(array.size()-1);
   heapSize++;
}

//---------------------------------------------------------
template <typename T>
void Heap<T>::pop() {
   if (heapSize == 0)
      throw invalid_argument("Heap::pop - empty");

   swap(array[0], array[heapSize-1]);
   heapifyDown(0);
   heapSize--;
}

//---------------------------------------------------------
template <typename T>
T Heap<T>::top() const {
   if (heapSize == 0)
      throw invalid_argument("Heap::pop - empty");

   return array[0];
}

//---------------------------------------------------------
// Heap - PRIVATE
//---------------------------------------------------------
template <typename T>
void Heap<T>::heapifyUp(size_t i) {
   while (i > 0 and array[parent(i)] < array[i]) {
      swap(array[i], array[parent(i)]);
      i = parent(i);
   }
}

//---------------------------------------------------------
template <typename T>
void Heap<T>::heapifyDown(size_t i) {
   while(left(i) < size() and array[greatest(i)] > array[i]) {
      swap(array[greatest(i)], array[i]);
      i = greatest(i);
   }
}

//---------------------------------------------------------
template <typename T>
size_t Heap<T>::greatest(size_t i) const {
   if (right(i) < size() and array[right(i)] > array[left(i)])
      return right(i);
   else
      return left(i);
}

