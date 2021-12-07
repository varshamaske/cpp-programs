
#include<iostream>

using namespace std;

typedef unsigned int UINT;

UINT ToggleBits(UINT iNo, int iPos1, int iPos2)
{
  int iCnt = 0, i = 0;

  int iMask = 0;
  UINT iMask1 = 0X00000001;
  UINT iMask2 = 0X00000001;
  int iResult = 0;

  iMask1 = iMask1 << (iPos1 - 1);
  iMask2 = iMask2 << (iPos2 - 1);

  iMask = iMask1 | iMask2;
  
  iResult = iNo ^ iMask;

  return iResult;
  
}

int main()
{
  int iValue = 0, iRet = 0, i = 0, j = 0;

  cout<<"Enter number\n";
  cin>>iValue;

  cout<<"Enter first position\n";
  cin>>i;

  cout<<"Enter second position\n";
  cin>>j;

  iRet = ToggleBits(iValue, i, j);

  cout<<"Updated Number is : "<<iRet<<"\n";

  return 0;
}