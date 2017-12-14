/*Question
Design a parser which accepts a mathematical expression(containing integers only).If the expression is valid ,then evaluated the expression else report that 
the expression is invalid
Grammar for mathematical expression:-
E->E+T|E-T|T
T->T*F|T/F|F
F->(1|2|3|4|5|6|7|8|9)|(E)
grammar after eleminating left factoring
E->EK|T
K->+T|-T
T->TJ|F
J->*F|/F
F->id|(E)
grammar after eleminating left recursion
E->TX
X->KX|@
T->FZ
Z->JZ|@
K->+T|-T
J->*F|/F
F->id|(E)
*/
#include<stdio.h>
#include<string.h>
char *LA;
int T();
int F();
int X(int n);
int J(int n);
int Z(int n);

struct node* root;
int match(char ptr){
       char d=*LA;
     //  printf("%c %c\n",*LA,ptr);
	if(*LA==ptr){
		LA++;
		return 1;
	}else{
		printf("there is an error here\n");
		return 0;
	}
	
}
int E(){
	
	       int in=T();
	if(in!=0){
            int syn=X(in);
		if(syn!=0){
			return syn;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int K(int in){
	
	if(*LA=='+'){
		if(match('+')==1){
			int syn=T();
			if(syn!=0){
				return in+syn;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else if(*LA=='-'){
		if(match('-')==1){
			int syn2=T();
			if(syn2!=0){
				return in-syn2;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
		
	}else{
		return 0;
	}
}
int J(int in){
	
	if(*LA=='*')
	{ if(match('*')==1){
		int syn1=F();
		if(syn1!=0){
			return in*syn1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
		
	}else if(*LA=='/'){
		if(match('/')==1){
			int syn2=F();
			if(syn2!=0){
				return in/syn2;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}
int F(){
	
	if(*LA=='('){
		if(match('(')==1){
			int syn2=E();
		if(syn2!=0){
		if(match(')')==1){
			return syn2;
		}	
		}else{
			return 0;
		}
		
		}else {
			return 0;
		}
	}else if(*LA=='0'){
		if(match('0')==1){
		
		return 0;}else{
			return 0;
		}
	}else if(*LA=='1'){
		if(match('1')==1){
		
		return 1;}else{
			return 0;
		}
	}else if(*LA=='2'){
			if(match('2')==1){
		
		return 2;}else{
			return 0;
		}
	}else if(*LA=='3'){
	   	if(match('3')==1){
		
		return 3;}else{
			return 0;
		}
	}else if(*LA=='4'){
			if(match('4')==1){
		
		return 4;}else{
			return 0;
		}
	}else if(*LA=='5'){
			if(match('5')==1){
		
		return 5;}else{
			return 0;
		}
	}else if(*LA=='6'){
		if(match('6')==1){
		
		return 6;}else{
			return 0;
		}
	}else if(*LA=='7'){
		if(match('7')==1){
		
		return 7;}else{
			return 0;
		}
	}else if(*LA=='8'){
		if(match('8')==1){
		
		return 8;}else{
			return 0;
		}
	}else if(*LA=='9'){
		if(match('9')==1){
		
		return 9;}else{
			return 0;
		}
	}else {
		return 0;
	}
}
int T(){
	
	int syn1=F();
	if(syn1!=0){
		int syn2=Z(syn1);
		if(syn2!=0){
			return syn2;
		}else{
			return 0;
		}
	}else {
		return 0;
	}
}
int Z(int in){

	if(*LA==')'||*LA=='$'||*LA=='+'||*LA=='-'){
		return in;
	}else{
		int syn1=J(in);
		if(syn1!=0){
			int syn2=Z(syn1);
	        if(syn2!=0){
	        	return syn2;
			}else{
				return 0;
			}		
		}else{
			return 0;
		}
	}
	
}
int X(int in){
	
	if(*LA==')'||*LA=='$'||*LA=='*'||*LA=='/'){
		return in;
	}else{
		int syn1=K(in);
		if(syn1!=0){
			int syn2=X(syn1);
	        if(syn2!=0){
	        	return syn2;
			}else{
				return 0;
			}		
		}else{
			return 0;
		}
	}
	
}
int main(){
		char str[100];
	printf("please enter the arithmetic expression\n");
	scanf("%s",str);
	LA=str;
	root=NULL;
	int k=E();
	if(k!=0){
       printf("the following string is accepted by the grammar\n");
       printf("the value is %d",k);
	}else{
		printf("the following string does not belong to this grammar\n");
	}
return 0;}

