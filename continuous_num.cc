#include"stdio.h"
#include"stdlib.h"
#include<iostream>

using namespace std;

int GetSubString(char *strSource, char *strResult) {
  int iTmp=0, iHead=0, iMax=0;
  for(int Index=0, iLen=0; strSource[Index]; Index++) {
    if(strSource[Index] >= '0' && strSource[Index] <= '9' &&
        strSource[Index-1] > '0' && strSource[Index] == strSource[Index-1]+1) {
      iLen++;                       // 连续数字的长度增1
    } else {                          // 出现字符或不连续数字
      if(iLen > iMax) {
        iMax = iLen;  
        iHead = iTmp;
      }       
      //该字符是数字，但数字不连续
      if(strSource[Index] >= '0' && strSource[Index] <= '9') {
        iTmp = Index;
        iLen = 1;
      }
    }   
  }
  for(int i=0 ; i< iMax; i++) // 将原字符串中最长的连续数字串赋值给结果串
    strResult[i] = strSource[iHead++];
  strResult[iMax]='\0';
  return iMax;     // 返回连续数字的最大长度
}
int main() {
  char strSource[]="ads3sl456789DF3456ld345AA";
  char strResult[sizeof(strSource)];
  printf("Len=%d, strResult=%s \nstrSource=%s\n",GetSubString(strSource, strResult), strResult, strSource);
}


