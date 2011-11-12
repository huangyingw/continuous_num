// continuous_num.cpp : Defines the entry point for the console application.
//

#include"stdio.h"
#include"stdlib.h"
#include<iostream>

using namespace std;

char* GetSubString(char *strSource, int len) 
{
  char * strResult=new char[len];
  int iHead=0, iMax=0;
  int Index=0, iLen=0,nav=0; 
  while(strSource[Index])
  {
    nav=Index;
    while(strSource[nav] >= '0' && strSource[nav] <= '9' &&
        strSource[nav-1] > '0' && strSource[nav] == strSource[nav-1]+1) 
    {
      iLen++;                       // 连续数字的长度增1
      nav++;
    } 
    if ( iMax< iLen)
    {
      iMax=iLen+1;
      iHead=Index-1;
    }
    Index++;
    iLen=0;
  }
  for(int i=0 ; i< iMax; i++) // 将原字符串中最长的连续数字串赋值给结果串
    strResult[i] = strSource[iHead++];
  strResult[iMax]='\0';
  return strResult;     // 返回连续数字的最大长度
}

int main() 
{
  char strSource[]="ads3sl456789DF3456ld345AA";
  char * result=GetSubString(strSource,sizeof(strSource)/sizeof(char));
  cout<<result<<endl;
}
