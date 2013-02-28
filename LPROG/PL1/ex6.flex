%{ 
%} 

%% 

\. //retira os pontos finais
\, //retira as virgulas
-[1-9][0-9]+ printf("%s ",yytext); //retira numeros negativos
-[1-9] printf("%s ",yytext); //retira numeros negativos
[1-9]+ printf("%s ",yytext); //retira numeros positivos
0  //retira o 0
. //apanha o restante

%% 
int main ( void ) {
	yylex();
	
	return 0;
} //end main