#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define Console_width 80

int round_ (float x)
{
	float d;
	x *= 100;
	d = x - (int)x;
	if(d >= 0.5)
		return ((int)(x + 1));
	return((int)x);
}

int main(int argc,char* argv[])
{
	static int cnt_ltrs[26];
    char ch;
    int k,i,letters=0;
    float m;

	if(argc < 2)
	{
		printf("Too few arguments.\n");
		exit(1);
	}

	FILE* fp;
    if((fp=fopen(argv[1], "r"))==NULL)
    {
        printf("Open failed.\n");
        exit(2);
    }

    while((ch=fgetc(fp))!=EOF)
    {
    	if(isalpha(ch))
    	{
    	    letters++;
    		cnt_ltrs[tolower(ch)-'a']++;
    	}
    }

    fclose(fp);

    if(!letters)
    {
    	printf("No letters in file\n");
        exit(3);
    }

    char* width;
    int j;
    width = getenv("COLUMNS");
    Console_width = atoi(width);
    printf("columns:%d\n",Console_width);
    
    for(i=0;i<26;i++)
    {
    	k = round_((float)cnt_ltrs[i]/letters);
        printf("%c:%d%%\t",'a'+i,k);
        k *= (float)Console_width / 100;
    	while(k--)
    		printf("#");
    	printf("\n");
    }
}
