%{ 
%} 

ALG [0-9]
CAR [A-Z]

%% 
({ALG}{2}-{CAR}{2}-{ALG}{2} | {ALG}{2}-{ALG}{2}-{CAR}{2}) printf("PT\n");
. 

%% 
int main ( void ) {
	yylex();
	
	return 0;
} //end main