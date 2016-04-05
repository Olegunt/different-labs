#include <stdlib.h>
#include <iostream>
using namespace std;

class Alpha
{
 private:
 	unsigned bin;
 public:
 	Alpha() {bin=0;}
 	Alpha (char *);
 	Alpha operator= (const Alpha &y) {bin=y.bin; return *this;};
 	int operator , (Alpha &);
 	int operator()(Alpha &, Alpha &);
 	int pop(unsigned);
 	friend ostream&operator <<(ostream&, Alpha&);
 	operator char*();
 };
 
Alpha::Alpha(char* s)
{  
  bin=0; 
  while(*s)
  { 
    bin |= (1 << (tolower(*s)-'a')); s++;
  }
} 

ostream& operator << (ostream& out,Alpha& z)
{  
  unsigned bit=1; 
  int i; 
 for(i=0; i <26; i++)
 { 
   if((z.bin & bit)>0) 
    out<<(char)('a'+i); 
   bit=bit<<1; 
} 
  return out;
} 

Alpha::operator char*()
{  
  static  char s[32]; 
  unsigned  b=bin; 
  int i=0; 
  int j=0; 
  while(b>0)
  { 
    if(b & 1) 
      s[j++]='a'+i; 
    i++; 
    b>>=1; 
  } 
  s[j]=0; 
  return (s); 
}

int Alpha::operator,(Alpha &y)
{
  return (pop(bin & y.bin));
}

int Alpha::operator()(Alpha &x, Alpha &y)
{
  return (pop(x.bin ^ y.bin));
}

int Alpha::pop(unsigned b)
{
 int i=0;
 while(b!=0)
  { 
    b=b&(b-1);
    i++;
   }
   return(i);
}

int main (int argc,char* argv[])
{  
  Alpha A(argv[1]); 
  Alpha B(argv[2]);
  Alpha H; 
  int d=H(A,B);
  int s=(A,B);
  cout<<"H("<<argv[1]<<","<<argv[2]<<")="<<d<<"\n"; 
  cout<<"("<<argv[1]<<","<<argv[2];
  cout<<")="<<s<<"\n";
 return (0); 
}
