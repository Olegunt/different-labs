%START SPACE
MYREG1 (00|11)*((01|10)(00|11)*(01|10)(00|11)*)*
MYREG2 {MYREG1}(101|0){MYREG1}
MYREG3 {MYREG1}(010|1){MYREG1}
MYREG4 {MYREG1}(10|01){MYREG1}

%%
^{MYREG2}/[" "\t\n]				                            {
                                                       ECHO;
                                                       printf(" - дa\n");
                                                      }

^({MYREG1}|{MYREG3}|{MYREG4})/[" "\t\n]               {
	                                                     ECHO;
	                                                     printf(" - нет\n");
                                                      }                                    


[" "\t]/{MYREG2}[" "\t\n]                             BEGIN SPACE;

<SPACE>{MYREG2}		                                    {
	                                                     ECHO;
	                                                     printf(" - да\n");
                                                       BEGIN 0;
                                                      }

[" "\t]/({MYREG1}|{MYREG3}|{MYREG4})[" "\t\n]         BEGIN SPACE;

<SPACE>({MYREG1}|{MYREG3}|{MYREG4})		                {
	                                                     ECHO;
	                                                     printf(" - нет\n");
                                                       BEGIN 0;
                                                      }
  
.|\n                                                  ;
%%
