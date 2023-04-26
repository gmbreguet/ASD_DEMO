//---------------------------------------------------------
// Demo           : 04_2_List_G
// Fichier        : List_G_Impl.hpp
// Version        : 04 - 2023.04.26
// Auteur(s)      : BREGUET Guy-Michel
// But            : forward list
// Modifications  :
// Remarque(s)    : basic methods only
//---------------------------------------------------------

//---------------------------------------------------
#ifndef LIST_G_IMPL_HPP
#define LIST_G_IMPL_HPP

//---------------------------------------------------
// friend
//---------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const List_G<T>& list) {
   os << "size    : " << list.size()   << std::endl;
   os << "content : [";
   const Cell<T>* ptrCell = list.head;
   while (ptrCell != nullptr){
      if (ptrCell != list.head)
         os << ", ";
      os << *ptrCell;
      ptrCell = ptrCell->next;
   }
   os << "]";
   return os;
}

//---------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const Cell<T>& cell) {
   return os << &cell << " => " << cell.data;
}

//---------------------------------------------------
// private
//---------------------------------------------------
template <typename T>
Cell<T>* List_G<T>::createCell (const T& value,
                                Cell<T>* next)  {
   Cell<T>* ptrNewCell;

   // memory allocation
   try {
      ptrNewCell = (Cell<T>*)::operator new(sizeof(Cell<T>));
   }
   catch (std::bad_alloc& ba) {
      throw ListMemFull("memory full");
   }

   // create an empty cell
   try {
      new(ptrNewCell) Cell<T>{value, next};
   }
   catch(...) {
      delete ptrNewCell;
      throw;
   }

   return ptrNewCell;
}

//---------------------------------------------------
template <typename T>
List_G<T>::List_G ()
:head(nullptr), nElement(0) {}

//---------------------------------------------------
template <typename T>
void List_G<T>::push_front(const T& value) {
   Cell<T>* ptrNew = createCell(value, head);
   head            = ptrNew;
   nElement++;
}

//---------------------------------------------------
template <typename T>
void List_G<T>::pop_front() {
   if (empty())
      throw ListIsEmpty("List is empty");
   Cell<T>* tmp   = head;
   head           = head->next;
   delete tmp;
   nElement--;
}

//---------------------------------------------------
template <typename T>
void List_G<T>::clear() noexcept {
   while(not this->empty())
      pop_front();
   this->nElement = 0;
}

//---------------------------------------------------
template <typename T>
List_G<T>::~List_G() {
   clear();
}

//---------------------------------------------------
template <typename T>
T List_G<T>::front() const {
   if (this->nElement == 0)
      throw ListIsEmpty("List is empty");
    return head->data;
}

//---------------------------------------------------
template <typename T>
bool List_G<T>::empty() const noexcept {
    return nElement == 0;
}

//---------------------------------------------------
template <typename T>
size_t List_G<T>::size() const noexcept {
    return nElement;
}

//---------------------------------------------------
template <typename T>
T* List_G<T>::find(const T& value) const {
   Cell<T>* crt = head;
   while (crt and value != crt->data) {
      crt = crt->next;
   }
   return &(crt->data);
}

//---------------------------------------------------
template <typename T>
template <typename Fonction>
void List_G<T>::for_each(Fonction fonction) {
   Cell<T>* crt = head;
   while (crt) {
      crt->data = fonction(crt->data);
      crt = crt->next;
   }
}

#endif /* List_G_IMPL_HPP */
