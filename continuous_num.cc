#include"stdio.h"
#include"stdlib.h"
#include<iostream>

using namespace std;

int palindrome_num(int num)
{
  int new_num=0;
  int temp=num;
  while ( temp )
  {
    new_num=new_num*10+temp%10;
    temp/=10;
  }
  return new_num == num;
}

int palindrome_str(char str[], int len)
{
  if (1==len)
    return 1;
  else if (str[len-1]!=str[0])
    return 0;
  else
    return  palindrome_str(str+1,len-2);
}

int main() 
{
  cout<<palindrome_num(12321)<<endl;
  cout<<palindrome_num(22321)<<endl;
  cout<<palindrome_num(123454321)<<endl;
  cout<<palindrome_str("1234321",7)<<endl;
  cout<<palindrome_str("1334321",7)<<endl;
  return 0;
}
