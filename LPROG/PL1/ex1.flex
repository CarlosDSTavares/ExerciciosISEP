%{ 
int qtdCadeia=0; 
%} 

%% 

abc qtdCadeia++;
. 

%% 
int main ( void ) {
	yylex();
	
	printf("#encontrei %d vezes a cadeia 'abc'\n", qtdCadeia); 
	
	return 0;
} //end main