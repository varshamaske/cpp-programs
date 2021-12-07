
#include<iostream>

using namespace std;

typedef unsigned int UINT;

UINT CountBit(UINT iNo)
{
  int iCnt = 0, i = 0;

  UINT iMask = 0X00000001;
  
  for(i = 1; i < 32 ; i++,  iMask = iMask << 1)
  {  
    if((iNo & iMask) == iMask)
    {
       iCnt++;
    }
  }
  return iCnt;
}

int main()
{
  int iValue = 0, iRet = 0;

  cout<<"Enter number\n";
  cin>>iValue;

  iRet = CountBit(iValue);

  cout<<"Number of bits which are ON : "<<iRet<<"\n";

  return 0;
}