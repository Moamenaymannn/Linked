#include<iostream>
using namespace std ;
#include "node.h"

class Linked { 
      private:
       Node* getnode(int _data){  
          Node* current = head;
          if(current==NULL){ 
            return NULL;
          }
          while(current != NULL){  
                    if(current->data ==_data ){ 
                              return current;
                    }
                    current = current->next;
          }
          cout<<"data<t found"<<endl;
          return NULL;
    }
    void removenode( Node* resulte){  
          if(resulte == head){ 
                    if(resulte == tail){ 
                              head=tail=NULL;
                    }else{ 
                              head=head->next;
                              head->prev=NULL;
                    }
          }else if(resulte == tail ){ 
                    tail = tail->prev;
                    tail->next=NULL;
          }else{ 
                    Node* N;
                    Node* P;
                    N=resulte->next;
                    P=resulte->prev;

                    N->prev=P;
                    P->next=N;
          }
          delete resulte;
    }  
public:
  Node *head ;
  Node *tail ;
  int counter =0;


  Linked(){ 
          head=tail=NULL;
    }

    void addnode( int data ){  
          Node* newnode = new Node(data);

          if( head == NULL){ 
                    head=tail=newnode;
          }
          tail->next=newnode;
          newnode->prev=tail;
          tail=newnode;
          counter++;
    }
    void addnodeAfter( int olddata , int newdata ){ 
      Node* current = getnode(olddata);
       Node* newnode = new Node(newdata);
      
      if(current == NULL){ 
            delete newnode;
            return;
      }
       if( current->next != NULL  ){ 
           Node* temp = current->next;
            
            temp->prev=newnode;
            newnode->next=temp;

            current->next=newnode;
            newnode->prev=current;

      }else {  
            current->next=newnode;
            newnode->prev=current;
            newnode->next=NULL;
            tail=newnode;
      }
      counter++;
    }

      void addNodeBefore(int olddata , int newdata){  
            Node* newnode = new Node(newdata);
            Node* current = getnode(olddata);
            
            if(current == NULL){ 
                  delete newnode;
                  return;
            }
             if(current->prev != NULL ){ 
                  Node* temp =current->prev;
                 

                  temp->next=newnode;
                  newnode->prev=temp;

                  newnode->next=current;
                  current->prev=newnode;
            }else{ 
                  newnode->next=current;
                  newnode->prev=NULL;
                  current->prev=newnode;                 
                  head=newnode;
            }
            counter++;

    }

    int founddata(int data){  
          Node *resulte= getnode(data);
          int node;
          if( resulte==NULL ){ 
                    return 0 ;
          }
            node = resulte->data;
            cout<<"node you need :"<<node<<endl;
          return node;
    }
    
    void remove(int _data){ 
          Node* resulte = getnode(_data);
          if(resulte != NULL && resulte->data == _data){ 
            removenode(resulte);
             cout << "Node with data " << _data << " removed successfully." << endl;
                    return ;
          }
          cout<<"data N"<<endl;
          counter--;
    }
    void removeAll(int _data){  
          Node* current=head;
          Node* temp;
          if(current == NULL){ 
                    cout<<"Linked empty"<<endl;
                    return ;
          }
          
          while(current != NULL){ 
                  temp = current;
                  current=current->next;

             if(temp->data == _data){
            
                  removenode(temp);
                  counter--;
             }
            
          }
          
          return ;
    }
    void display(){ 
          Node* current = head;
          int data;
          if(current == NULL){ 
                    cout<<"linked empty"<<endl;
                    return;
          }
          while( current != NULL){ 
                    data = current->data;

                    cout<<data<<endl;
                    current=current->next;
          }
    }
    int getcounter(){
      cout<<"num of nodes\n"<<counter<<endl;
      return counter;
    }

    

};