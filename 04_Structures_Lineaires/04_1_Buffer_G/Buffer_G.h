//---------------------------------------------------------
// Fichier        : Buffer_G.h
// Version        : 01 - 2022-04-20
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer une classe
//                : Buffer à taille fixe
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------


#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <memory>    // destroy_at

//---------------------------------------------------------
template <typename T>
class Buffer;

//---------------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const Buffer<T>& buffer);

//---------------------------------------------------------
template <typename T>
class Buffer {
   friend std::ostream& operator<< <T>(std::ostream& os, const Buffer<T>& buffer);

public:
   //------------------------------------------------------
   Buffer() noexcept;
   Buffer(size_t capacity);
  ~Buffer() noexcept;

   //------------------------------------------------------
   Buffer(const Buffer&)             = delete;
   Buffer& operator= (const Buffer&) = delete;

   //------------------------------------------------------
   size_t size()     const noexcept;
   size_t capacity() const noexcept;

   //------------------------------------------------------
   void push_front(T t);
   void push_back (T t) ;

   //------------------------------------------------------
   void pop_front();
   void pop_back () ;

   //------------------------------------------------------
   T back()  const;
   T front() const;

   //------------------------------------------------------
         T& at(size_t i);
   const T& at(size_t i) const;

private:
   size_t      iPhysique(size_t i)  const;

   //------------------------------------------------------
   size_t      capacite;
   size_t      taille;
   size_t      debut;
   T*          data;
};

//---------------------------------------------------------
//    friend
//---------------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const Buffer<T>& buffer) {
   os << "taille     : " << buffer.size()       << std::endl;
   os << "capacité   : " << buffer.capacity()   << std::endl;
   os << "debut      : " << buffer.debut        << std::endl;
   os << "logique    : [";
   for (size_t i=0; i<buffer.size(); ++i) {
      if (i)
         os << ", ";
      os << buffer.at(i);
   }
   os << "]" << std::endl;

   os << "physique   : [";
   for(size_t i=0; i<buffer.capacite; ++i) {
      if (i)
         os << ", ";
      os << buffer.data[i];
   }

   return os << "]";
}

//---------------------------------------------------------
//    private
//---------------------------------------------------------
template <typename T>
size_t Buffer<T>::iPhysique(size_t i) const {
   return (debut + i + capacite) % capacite;
}

//---------------------------------------------------------
//    public
//---------------------------------------------------------
template <typename T>
Buffer<T>::Buffer() noexcept :
      capacite (0),
      taille   (0),
      debut    (0),
      data     (nullptr)
{};

//------------------------------------------------------
template <typename T>
Buffer<T>::Buffer(size_t capacity) : Buffer() {
   data     = reinterpret_cast<T*>(::operator new(capacity * sizeof(T)));
   capacite = capacity;
}

//------------------------------------------------------
template <typename T>
Buffer<T>::~Buffer() noexcept {
   for(size_t i=0; i<taille; ++i)
      std::destroy_at(data + iPhysique(i));
   ::operator delete(data);
}

//------------------------------------------------------
template <typename T>
size_t Buffer<T>::size() const noexcept {
   return taille;
}

//------------------------------------------------------
template <typename T>
size_t Buffer<T>::capacity() const noexcept {
   return capacite;
}

//------------------------------------------------------
template <typename T>
void Buffer<T>::push_front(T t) {
   if (taille >= capacite)
      throw std::out_of_range("Buffer::push_front");

   size_t avant = iPhysique(capacite - 1);
//   new(data + iPhysique(debut - 1)) T(t);
   data[avant] = std::move(t);
   debut = avant;
   ++taille;
}

//------------------------------------------------------
template <typename T>
void Buffer<T>::push_back(T t) {
   if (taille >= capacite)
      throw std::out_of_range("Buffer::push_back");

//   new(data + iPhysique(taille)) T(t);
   data[iPhysique(taille)] = std::move(t);
   ++taille;
}

//------------------------------------------------------
template <typename T>
void Buffer<T>::pop_front() {
   if (taille == 0)
      throw std::out_of_range("Buffer::pop_front");

   std::destroy_at(data + iPhysique(0));
   debut = iPhysique(1);
   --taille;
}

//------------------------------------------------------
template <typename T>
void Buffer<T>::pop_back() {
   if (taille == 0)
      throw std::out_of_range("Buffer::pop_back");

   std::destroy_at(data + iPhysique(taille - 1));
   --taille;
}

//------------------------------------------------------
template <typename T>
T Buffer<T>::back()  const {
   if (taille == 0)
      throw std::out_of_range("Buffer::back");
   return at(taille - 1);
}

//------------------------------------------------------
template <typename T>
T Buffer<T>::front() const {
   if (taille == 0)
      throw std::out_of_range("Buffer::front");
   return at(0);
}

//------------------------------------------------------
template <typename T>
T& Buffer<T>::at(size_t i) {
   if (i<0 or i>=taille)
      throw std::out_of_range("Buffer::at");

   return data[iPhysique(i)];
}

//------------------------------------------------------
template <typename T>
const T& Buffer<T>::at(size_t i) const {
   if (i<0 or i>=taille)
      throw std::out_of_range("Buffer::at");

   return data[iPhysique(i)];
}

#endif
