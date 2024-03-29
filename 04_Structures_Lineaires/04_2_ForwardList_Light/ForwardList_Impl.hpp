//---------------------------------------------------------
// Demo           : 04_2_List_G
// Fichier        : ForwardList_Impl.hpp
// Version        : 05 - 2023.05.09
// Auteur(s)      : BREGUET Guy-Michel
// But            : forward list
// Modifications  :
// Remarque(s)    : basic methods only
//---------------------------------------------------------

//---------------------------------------------------
#ifndef FORWARDLIST_IMPL_HPP
#define FORWARDLIST_IMPL_HPP

//---------------------------------------------------
// friend
//---------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const ForwardList<T>& list) {
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
Cell<T>* ForwardList<T>::createCell (const T& value,
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
ForwardList<T>::ForwardList ()
:head(nullptr), nElement(0) {}

//---------------------------------------------------
template <typename T>
void ForwardList<T>::push_front(const T& value) {
   Cell<T>* ptrNew = createCell(value, head);
   head            = ptrNew;
   nElement++;
}

//---------------------------------------------------
template <typename T>
void ForwardList<T>::pop_front() {
   if (empty())
      throw ListIsEmpty("List is empty");
   Cell<T>* tmp   = head;
   head           = head->next;
   std::destroy_at(tmp);
   operator delete(tmp);
   nElement--;
}

//---------------------------------------------------
template <typename T>
void ForwardList<T>::clear() noexcept {
   while(not empty())
      pop_front();
}

//---------------------------------------------------
template <typename T>
ForwardList<T>::~ForwardList() {
   clear();
}

//---------------------------------------------------
template <typename T>
bool ForwardList<T>::empty() const noexcept {
    return nElement == 0;
}

//---------------------------------------------------
template <typename T>
size_t ForwardList<T>::size() const noexcept {
    return nElement;
}

//---------------------------------------------------
template <typename T>
T& ForwardList<T>::front() {
   if (nElement == 0)
      throw ListIsEmpty("List is empty");
   return head->data;
}

//---------------------------------------------------
template <typename T>
const T& ForwardList<T>::front() const {
   if (nElement == 0)
      throw ListIsEmpty("List is empty");
   return head->data;
}

//---------------------------------------------------
template <typename T>
T* ForwardList<T>::find(const T& value) {
   Cell<T>* crt = head;
   while (crt and value != crt->data) {
      crt = crt->next;
   }
   return &(crt->data);
}

//---------------------------------------------------
template <typename T>
const T* ForwardList<T>::find(const T& value) const {
   Cell<T>* crt = head;
   while (crt and value != crt->data) {
      crt = crt->next;
   }
   return &(crt->data);
}

//---------------------------------------------------
template <typename T>
template <typename Fonction>
void ForwardList<T>::for_each(Fonction fonction) {
   Cell<T>* crt = head;
   while (crt) {
      crt->data = fonction(crt->data);
      crt = crt->next;
   }
}

#endif /* FORWARDLIST_IMPL_HPP */
