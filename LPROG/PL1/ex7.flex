%{ 
%} 

NUMERO_DECIMAL_NEGATIVO (-[0-9]+([.]+[0-9]+))
NUMERO_DECIMAL_POSITIVO [0-9]+([.]+[0-9]+)

%%

{NUMERO_DECIMAL_NEGATIVO}+ {printf("%s NUMERO_DECIMAL_NEGATIVO \n",yytext);}
{NUMERO_DECIMAL_POSITIVO}+ {printf("%s NUMERO_DECIMAL_POSITIVO \n",yytext);}
[0-9]+ printf("NUEMRO REAL: %s \n",yytext);
-[0-9]+ printf("NUEMRO REAL: %s \n",yytext);
. 

%% 
int main ( void ) {
	yylex();
	
	return 0;
} //end main