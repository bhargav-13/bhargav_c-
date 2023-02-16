#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
}; 

void display(node* &head)
{
   if(head == NULL){
    cout << "list is empty" << endl;
    return ;
   }
   node* temp = head;
   cout << "[ ";
   while(temp != NULL){
    cout << temp -> data << " -> " << flush;
    this_thread::sleep_for(chrono::milliseconds(500));
    temp = temp -> next;
   }
   cout << "NULL ]" << endl;
}

void insertbyTail(node* &tail, int data){
    node *temp = new node(data);
    tail -> next = temp;
    tail = temp;
}

void insert(node* &head,node* &tail, int pos, int data){
    node* temp = head;
    int count = 1;
    if(pos == 0){
        node* nodetoins = new node(data);
        nodetoins -> next = head;
        head = nodetoins;
    }

        while(count<pos-1)
        {
          temp = temp -> next;
          count++;
        }

     if(temp -> next == NULL)
    {
        //cout << "inside tail" << endl;
        insertbyTail(tail,data);
        }
    else
    {
        node* nodetoins = new node(data);
        nodetoins -> next = temp -> next;
        temp -> next = nodetoins;
    }

}

void deletebyIndex(node* &head, int index){
       node* temp = head;
       node* q = NULL;
       int count = 1;
       if(index == 0){
          head = head -> next;
          temp -> next = NULL;
          delete temp;
       }
       while(count<index)
        {
          q = temp;
          temp = temp -> next;
          count++;
        }
        q -> next = temp -> next; 
        temp -> next = NULL;
        delete temp;        
}
int isSorted(node *p)
{
int x=-65536;

while(p!=NULL)
{
if(p->data < x)
return 0;
x=p->data;
p=p->next;
}
return 1;
}



int main(int argc, char const *argv[])
{
        node* n = new node(10);
        node* head  = n;
        node* tail  = n;

        insertbyTail(tail, 20);
        insertbyTail(tail, 30);
        insertbyTail(tail, 40);
        insertbyTail(tail, 50);
        insertbyTail(tail, 60);

        insert(head, tail, 5, 45);
        
        deletebyIndex(head, 4);

        isSorted(head)?(cout << "sorted" << endl) : (cout << "not sorted" << endl);
        display(head);
}
