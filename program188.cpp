
#include<iostream>

using namespace std;

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo, int iPos)
{
  UINT iMask = 0X00000001;
  UINT iResult = 0;

  if((iPos < 1)||(iPos > 32))
  {
    return 0;
  }
  iMask = iMask << (iPos - 1);

  iResult = iNo ^ iMask;

  return iResult;

}

int main()
{
  int iValue = 0, iRet = 0, i = 0;

  cout<<"Enter number\n";
  cin>>iValue;

  cout<<"Enter the position of bit\n";
  cin>>i;

  iRet = ToggleBit(iValue, i);

  cout<<"Updated number is : "<<iRet<<"\n";

  return 0;
}