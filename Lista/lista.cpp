#include <iostream>

#include "linkedlist.h"
//#include "vectorlist.h"

using namespace std;


int main() {

  lista<int> a;


 

  a.insert(11, a.begin());


  a.insert(88, a.next(a.begin()));

  a.insert(122, a.next(a.next(a.begin())));

  a.print();


  //a.erase(a.next(a.begin()));

  //a.print();


} 

