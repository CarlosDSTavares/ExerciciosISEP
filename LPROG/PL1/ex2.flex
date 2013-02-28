%{ 
int qtdCadeia=0; 
%} 

%% 

FEUP printf("ISEP");
2007 printf("2008");
. printf("%s", yytext);

%% 
int main ( void ) {
	yylex();
	
	return 0;
} //end main