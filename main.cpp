#include<iostream>
#include "linked.h"
using namespace std ;

int main(){ 

Linked l;

l.addnode(1);
l.addnode(2);
l.addnode(3);
l.addnode(4);
l.addnode(5);
l.display();
cout<<"================"<<endl;
//l.remove();
//l.removeAll();
//l.addnodeAfter(5,10);
l.addNodeBefore(2,8);
l.display();
l.getcounter();
l.founddata(4);

  return 0;
}