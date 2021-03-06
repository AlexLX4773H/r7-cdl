//Including Libraries 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//Global Variables 
int z = 0, i = 0, j = 0, c = 0; 

char a[16], ac[20], stk[15], act[10]; 

void check() 
{ 
	// Coping string to be printed as action 
	strcpy(ac,"REDUCE TO S -> "); 
	
	// c=length of input string 
	for(z = 0; z < c; z++) 
	{ 
		//checking for producing rule S->4 
		if(stk[z] == '9') 
		{ 
			printf("%s9", ac); 
			stk[z] = 'S'; 
			stk[z + 1] = '\0'; 
			
			//pinting action 
			printf("\n$%s\t%s$\t", stk, a); 
		} 
	} 
		
	for(z = 0; z < c - 2; z++) 
	{ 
		//checking for another production 
		if(stk[z] == '5' && stk[z + 1] == 'S' && 
								stk[z + 2] == '5') 
		{ 
			printf("%s5S5", ac); 
			stk[z] = 'S'; 
			stk[z + 1] = '\0'; 
			stk[z + 2] = '\0'; 
			printf("\n$%s\t%s$\t", stk, a); 
			i = i - 2; 
		} 
		
	} 
		
	for(z=0; z<c-2; z++) 
	{ 
		//checking for S->7S7 
		if(stk[z] == '7' && stk[z + 1] == 'S' && 
								stk[z + 2] == '7') 
		{ 
			printf("%s7S7", ac); 
			stk[z]='S'; 
			stk[z + 1]='\0'; 
			stk[z + 1]='\0'; 
			printf("\n$%s\t%s$\t", stk, a); 
			i = i - 2; 
		} 
	} 
	return ; //return to main 
} 

//Driver Function 
int main() 
{ 
	printf("GRAMMAR is -\n\nS->5S5 \tS->7S7 \tS->9\n\n");	 
	
	// a is input string 
	printf("Enter string: \n");
	scanf("%s",a);
	//strcpy(a,"32423"); 
	
	// strlen(a) will return the length of a to c 
	c=strlen(a); 
	
	// "SHIFT" is copied to act to be printed 
	strcpy(act,"SHIFT"); 
	
	// This will print Lables (column name) 
	printf("\nstack \t input \t action"); 
	
	// This will print the initial 
	// values of stack and input 
	printf("\n$\t%s$\t", a); 
	
	// This will Run upto length of input string 
	for(i = 0; j < c; i++, j++) 
	{ 
		// Printing action 
		printf("%s", act); 
		
		// Pushing into stack 
		stk[i] = a[j];	 
		stk[i + 1] = '\0'; 
		
		// Moving the pointer 
		a[j]=' '; 
		
		// Printing action 
		printf("\n$%s\t%s$\t", stk, a); 
		
		// Call check function ..which will 
		// check the stack whether its contain 
		// any production or not 
		check(); 
	} 
	
	// Rechecking last time if contain 
	// any valid production then it will 
	// replace otherwise invalid 
	check(); 
	
	// if top of the stack is E(starting symbol) 
	// then it will accept the input 
	if(stk[0] == 'S' && stk[1] == '\0') 
		printf("Accept\n"); 
	else //else reject 
		printf("Reject\n"); 
} 
// This code is contributed by Ritesh Aggarwal 
