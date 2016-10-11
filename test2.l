%START SPACE
MYREG [01]*

%%
^{MYREG}/[" "\t\n]				    {
                                     int count_1 = 0;
                                     int count_0 = 0;
                                     int ost_1;
                                     int ost_0;
                                     int i;
                                     for(i=0;i<yyleng;i++)
                                     {
                                     	if(yytext[i] == 1)
                                     	  count_1++;
                                     	else
                                     	  count_0++;
                                     }
                                     ost_1 = count_1%2;
                                     ost_0 = count_0%2;
                                     if((ost_1 == 0)&&(ost_0 == 1))
                                       printf("%s - да\n",yytext);
                                     else
                                       printf("%s - нет\n",yytext);
                                    }

[" "\t]/{MYREG}[" "\t\n]            BEGIN SPACE;

<SPACE>{MYREG}		                {
                                     int count_1 = 0;
                                     int count_0 = 0;
                                     int ost_1;
                                     int ost_0;
                                     int i;
                                     for(i=0;i<yyleng;i++)
                                     {
                                     	if(yytext[i] == 1)
                                     	  count_1++;
                                     	else
                                     	  count_0++;
                                     }
                                     ost_1 = count_1%2;
                                     ost_0 = count_0%2;
                                     if((ost_1 == 0)&&(ost_0 == 1))
                                       printf("%s - да\n",yytext);
                                     else
                                       printf("%s - нет\n",yytext);
                                    }
  
.|\n ;
%%
