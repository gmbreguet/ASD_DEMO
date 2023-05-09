//---------------------------------------------------------
// Demo           : 04_2_List_G
// Fichier        : ForwardList.hpp
// Version        : 05 - 2023.05.09
// Auteur(s)      : BREGUET Guy-Michel
// But            : forward list
// Modifications  :
// Remarque(s)    : basic methods only
//---------------------------------------------------------

#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP

//-------------------------------------------------
#include <iostream>
#include <string>
#include <exception>
#include <memory>       // destroy_at

//-------------------------------------------------
class ListIsEmpty : public std::runtime_error {
public:
   explicit ListIsEmpty(const std::string& s) : std::runtime_error(s) {}
   explicit ListIsEmpty(const char*        s) : std::runtime_error(s) {}
};

//---------------------------------------------------
class ListMemFull : public std::runtime_error {
public:
   explicit ListMemFull(const std::string& s) : std::runtime_error(s) {}
   explicit ListMemFull(const char*        s) : std::runtime_error(s) {}
};

//---------------------------------------------------
template <typename T>
class ForwardList;

//---------------------------------------------------
template <typename T>
struct Cell {
   T        data;
   Cell<T>* next;
};
 
//---------------------------------------------------
// operator <<
template <typename T>
std::ostream& operator<< (std::ostream& os, const ForwardList<T>& list);

//---------------------------------------------------
// operator <<
template <typename T>
std::ostream& operator<< (std::ostream& os, const Cell<T>& cell);

//---------------------------------------------------
// class List
template <typename T>
class ForwardList {
   friend std::ostream& operator<< <T>(std::ostream& os, const ForwardList<T>& list);
   friend std::ostream& operator<< <T>(std::ostream& os, const Cell<T>&        cell);

public:
   ForwardList();
  ~ForwardList();

   void     push_front(const T& value);
   void     pop_front();
   void     clear()     noexcept;

   bool     empty()     const noexcept;
   size_t   size()      const noexcept;

         T& front();
   const T& front()     const;

         T* find(const T& value);
   const T* find(const T& value) const;

   template<typename Fonction>
   void for_each(Fonction fonction);

private:
   Cell<T>*    createCell(const T& value = T(),
                          Cell<T>* next  = nullptr);
   Cell<T>*    head;
   size_t      nElement;
};

#include "ForwardList_Impl.hpp"

#endif /* FORWARDLIST_HPP */

