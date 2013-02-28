%{ 
int qtdAlgarismos=0;
int qtdCaracteres=0;
int qtdLinhas=0;
int qtdEspaços=0;
int qtdOutos=0; 
%} 

// Macros
ALGARISMOS [0-9]
CARACTERES [a-zA-Z]
LINHAS \n
ESPAÇOS \t
OUTOS .

%% 

{ALGARISMOS} qtdAlgarismos++;
{CARACTERES} qtdCaracteres++;
{LINHAS} qtdLinhas++;
{ESPAÇOS} qtdEspaços++;
{OUTOS} qtdOutos++;

%% 
int main ( void ) {
	yylex();
	
	printf("Numero de algarismos: %d\n", qtdAlgarismos);
	printf("Numero de caracteres: %d\n", qtdCaracteres);
	printf("Numero de linhas: %d\n", qtdLinhas);
	printf("Numero de espaços: %d\n", qtdEspaços);
	printf("Outros caracteres: %d\n", qtdOutos);
	
	return 0;
} //end main