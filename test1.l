%START SPACE
MYREG1 (00|11)*((01|10)(00|11)*(01|10)(00|11)*)*(101|0)(00|11)*((01|10)(00|11)*(01|10)(00|11)*)*

%%
^{MYREG1}/[" "\t\n]				    {
                                     ECHO ;
                                     printf(" - дa\n");
                                    }

[" "\t]/{MYREG1}[" "\t\n]            BEGIN SPACE;

<SPACE>{MYREG1}		                {
	                                 ECHO;
	                                 printf(" - да\n");
                                     BEGIN 0;
                                    }
  
.|\n                                ;
%%
