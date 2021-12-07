
 #include<iostream>

 using namespace std;

 typedef struct node
 {
    int data;
    struct node *lchild;
    struct node *rchild;
 }NODE, *PNODE, **PPNODE;

 void Insert(PPNODE Head, int no)
 {
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> lchild = NULL;
    newn -> rchild = NULL;

    if(*Head == NULL)
    {
       *Head = newn;
    }
    else
    {  
       PNODE temp = *Head;

       while(1) // unconditional loop  for( ; ; )
       {
          if(temp -> data == no)
          {
             cout<<"Duplicate node\n";

             delete newn;
             break;
          }
          else if(temp -> data > no) // Smallest data
          {
            if(temp -> lchild == NULL)
            {
               temp -> lchild = newn;
               break;
            }
               temp = temp -> lchild;
          }
          else if(temp -> data < no) // Largest data
          { 
             if(temp -> rchild == NULL)
            {
               temp -> rchild = newn;
               break;
            }
               temp = temp -> rchild;

          }
       }
    }

 }

 bool Search(PNODE Head, int no)
 {

    if(Head == NULL)  // tree is empty
    {
        return false;
    }
    else              // tree contains atleast one node
    {
       while(Head != NULL)
       {
          if(Head -> data == no)
          {
             break;
          }
          else if(Head -> data < no)
          {
             Head = Head -> rchild;
          }
          else if(Head -> data > no)
          {
             Head = Head -> lchild;
          }
       }
       if(Head == NULL)
       {
          return false;
       }
       else
       {
          return true;
       }
    }

 }
 
 int Count(PNODE Head)
  {
     static int iCnt = 0;

     if(Head != NULL)
     {
        iCnt++;
        
        Count(Head -> lchild);
        Count(Head -> rchild);
     }
     return iCnt;
  }
 
 int CountLeaf(PNODE Head)
  {
     static int iCnt = 0;
     

     if(Head != NULL)
     {
      if((Head -> lchild == NULL)&&(Head -> rchild == NULL))
       {
        iCnt++;
       }

        CountLeaf(Head -> lchild);
        CountLeaf(Head -> rchild);
    }
     return iCnt;
  }

  int CountParent(PNODE Head)
  {
     static int iCnt = 0;
     

     if(Head != NULL)
     {
      if((Head -> lchild != NULL)||(Head -> rchild != NULL))
       {
        iCnt++;
       }

      CountParent(Head -> lchild);
      CountParent(Head -> rchild);
    }
     return iCnt;
  }

 int main()
 {
    int no = 0, iRet = 0;
    bool bret = false;

    PNODE first = NULL;

    Insert(&first, 51);
    Insert(&first, 21);
    Insert(&first, 101);

    cout<<"Enter number to search\n";
    cin>>no;

    bret = Search(first, no);

    if(bret == true)
    {
       cout<<"Number is there\n";
    }
    else
    {
       cout<<"Number is not there\n";
    }
    
    iRet = Count(first);

    cout<<"Number of nodes are : "<<iRet<<"\n";
 
    iRet = CountLeaf(first);

    cout<<"Number of leaf nodes are : "<<iRet<<"\n";
    
    iRet = CountParent(first);

    cout<<"Number of parent nodes are : "<<iRet<<"\n";

    return 0;
 } 

 // Data to be inserted : 51   21   101   55  75   20   105  16