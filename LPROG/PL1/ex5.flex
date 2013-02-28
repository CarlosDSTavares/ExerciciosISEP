%{ 
int qtdN=0; 
%} 

%% 
0
-[1-9]+
[1-9]+ qtdN++;
. 

%% 
int main ( void ) {
	yylex();
	
	printf("#encontrei %d numeros naturais.\n", qtdN); 
	
	return 0;
} //end main