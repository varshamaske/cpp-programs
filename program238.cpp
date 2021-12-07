
 #include<iostream>
 
 using namespace std;
 
  int AdditionI(int Arr[], int iSize)
 {
   int iSum = 0, i = 0;

   while(i < iSize)
   {
     iSum = iSum + Arr[i];
     i++;
   }

   return iSum;
 }
 int AdditionR(int Arr[], int iSize)
 {
   static int iSum = 0, i = 0;

   if(i < iSize)
   {
     iSum = iSum + Arr[i];
     i++;
     AdditionR(Arr, iSize);
   }

   return iSum;
 }

 
 int main()
 {
 	
  int iLength = 0, iRet = 0;
  int *p = NULL;
  
  cout<<"Enter number of elements\n";
  cin>>iLength;
 
  p = new int[iLength];

  cout<<"Enter elements\n";

  for(int i = 0; i < iLength; i++)
  {
    cin>>p[i];
  }

  //iRet = AdditionI(p, iLength);

  iRet = AdditionR(p, iLength);

  cout<<"Addition of elements are : "<<iRet<<"\n";

  delete[]p;
	 
  return 0;
 }