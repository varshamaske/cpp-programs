
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

  iRet = AdditionI(p, iLength);

  cout<<"Addition of elements are : "<<iRet<<"\n";

  delete[]p;
	 
  return 0;
 }