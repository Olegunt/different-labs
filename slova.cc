#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;
const int N = 20;
int S = 5;

istream& skip_not_alnum (istream& stream)
{
	char c;
	while((stream >> ws >> c) && !isalnum(c))
		;
	stream.unget();
	return stream;
}

void clear(char* w)
{
	for(int i = 0;i < N;i++)
		w[i] = '\0';
}

char** getmem(char** str_wrd)
{
	char** temp = (char**)realloc(str_wrd,sizeof(char*)*(S+5));
    str_wrd = temp;
    S = S + 5;
    return str_wrd;
}

void cleanmem(char** str_wrd,int n)
{
	for (int i = 0; i != n; ++i)
       delete [] str_wrd[i];
    delete [] str_wrd; 
}

int main(int argc,char** argv)
{
	char ch;
	char word[N];
	char** wrds;
	int i = 0;
	int n = 0;
	int max,p = 0;

	wrds = new char*[S];

	if(argc < 2)
	{
		cerr << "Too few arguments" << endl;
		return 0;
	}

	ifstream input(argv[1]);
	if(!input)
	{
		cerr << argv[1] << ":Can't open to read" << endl;
		return -1;
	}

	if(argv[2])
		max = atoi(argv[2]);
	else
		max = 5;

  input.unsetf(ios::skipws);
  cout << setfill('-') << setw(20) << '\n';
	while(input)
	{
	    input >> ch;
		if(isalnum(ch))
        {
	       word[i] = ch;
	       i++;
        }
        else
        {
	       input >> skip_not_alnum;
	       if((i-1) >= max)
	       {
               if(n == S)
			       wrds = getmem(wrds);
		       wrds[n] = new char(strlen(word)+1);
		       strcpy(wrds[n],word);
               for(int k = 0;k < n;k++)
                   if(strcmp(wrds[k],word) == 0)
                       p++;
               if(!p)
                   cout << word << endl;
               n++;
	       }
	       if(i)
	       {
	           clear(word);
	           i = 0;
	       }
        }
	}
	cout << setfill('-') << setw(20) << '\n';
	input.close();
	cleanmem(wrds,n);
}
