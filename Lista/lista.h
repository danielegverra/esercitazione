#include <iostream>

using namespace std;

template <class T>
class lista;

template <class T>
class nodo {

public:

  friend class lista<T>;

  nodo() {
    prev = nullptr;
    next = nullptr;
  };
  nodo(T el) {
    prev = nullptr;
    next = nullptr;
    e = el;
  };

  T e;
  nodo<T> *prev;
  nodo<T> *next;
};

template <class T>
class lista {

public:

  typedef nodo<T> *position;
  typedef T value_type;

  //costruttore
  lista();

  //metodi
  bool empty();
  bool end(position pos);

  value_type read(position pos);
  void write(T elem, position pos);
  
  position begin();
  position next(position pos);
  position prev(position pos);

  void insert(T el, position pos);
  void erase(position pos);

  //funzioni di servizio
  void print();

  //sovraccarico operatori
  lista<T>& operator=(const lista<T> &e);

  //friend ostream& operator<<(ostream& os, const lista<T>& t);


  nodo<T> *head;
  int lunghezza;

};

template <class T>
lista<T>::lista()
{
  lunghezza = 0;
}

template <class T>
bool lista<T>::empty()
{
  return (lunghezza==0);
}

template <class T>
typename lista<T>::value_type lista<T>::read(position pos)
{
  return pos->e;
}


template <class T>
void lista<T>::write(value_type elem, position pos)
{
  pos->e=elem;
}

template <class T>
typename lista<T>::position lista<T>::begin()
{
  return head;
}

template <class T>
typename lista<T>::position lista<T>::next(position pos)
{
  if(pos->next != nullptr)
  {
    return pos->next;
  } else {
    return pos;
  }
}

template <class T>
void lista<T>::erase(position pos)
{
  
  if(!empty())
  {
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    pos = nullptr;
    lunghezza--;
  }

}

template <class T>
typename lista<T>::position lista<T>::prev(position pos)
{
  if(pos->prev != nullptr)
  {
    return pos->prev;
  } else {
    return pos;
  }
}

template <class T>
void lista<T>::insert(value_type el, position pos)
{

  if(this->empty())
  {
    nodo<T> * temp = new nodo<T>;
    temp->next = nullptr;
    temp->prev=nullptr;
    temp->e = el;
    //std::cout << temp->e;
    head = temp;
    //delete temp; devo sovraccaricare operator =
  } else 
  {
    if(pos == this->head)
    {
      nodo<T> * temp = new nodo<T>;
      temp->next = head;
      temp->prev = nullptr;
      temp->e = el;
      head = temp;
    }
    else 
    {
      nodo<T> * temp = new nodo<T>;
      cout << head;
      temp = head;
      int i=0;
      while(i<lunghezza && temp->next != nullptr)
      {
        temp = temp->next;
        //cout << "\n i++";
        i++;
      }
      nodo<T> * newvalue = new nodo<T>;
      newvalue->next = nullptr;
      newvalue->prev = temp;
      temp->next = newvalue;
      newvalue->e = el;
      
    }
  }



  /*

  [3]
  [1] [3]

	//creo un nuovo nodo
	position newnode = new nodo<T>(el);
	position temp = new nodo<T>;
  temp=head;

  while(temp!=pos) {
    temp = temp->next;
  }

  temp->e=el;


  */
	lunghezza++;


}

// [2]

template <class T>
void lista<T>::print()
{
  nodo<T> * temp = head;

  for (int i = 0; i<lunghezza; i++)
  {
    cout << "[ " << read(temp) << " ] ";
    temp = temp->next;
  }

}

template <class T>
lista<T>& lista<T>::operator=(const lista<T> &e)
{
  lista<T> c;
  nodo<T> * temp = head;
  int i = 0;

  while(i < e->lunghezza)
  {
    c.insert(e.read(temp), temp);
  }

  return c;
}