#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Queue     // Singly Linear Linked List(LIFO)
{
private:
    PNODE first;
    int size;
    
public:
    Queue()
    {
        first = NULL;
        size = 0;
    }
    
    void Enqueue(int no)   // InsertLast()
    {
       PNODE newn = new NODE;

       newn -> data = no;
       newn -> next = NULL;

       if(first == NULL)
       {
         first = newn;
       }
       else
       {
         PNODE temp = first;

         while(temp -> next != NULL)
         {
            temp = temp -> next; 
         }
           temp -> next = newn;
       }
       size++;
    }
    
    int Dequeue()   // DeleteFirst()
    {
       PNODE temp = first;

       if(first != NULL)
       {
         first = first -> next;
         delete temp;

         size--;
       }
       
    }
    
    void Display()
    {
       PNODE temp = first;

       while(temp != NULL)
       {
          cout<<"|"<<temp -> data<<"|->";
          temp = temp -> next;
       }
       cout<<"\n";
    }
    
    int Count()
    {
        return size;
    }
};

int main()
{
    Queue obj;
    
    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
    
    int iret = obj.Dequeue();     // 11
    cout<<iret;                   // 11
    
    obj.Display();                // 21     51     101   
    iret = obj.Count();           // 3
    
    cout<<"Size of queue is : "<<iret<<"\n";        // 3
    
    return 0;
}
