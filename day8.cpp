//Consider the following grammar
//              S->ABc
//              A->abA|ab
//             B->b|cc
//Following any suitable parser technique,desgin a parser which accepts a string and says whehter the string is accepted by the grammar or not 

#include<stdio.h>
#include<string.h>

char *LA;
int A();
int B();


int match(char ptr){
       char d=*LA;
       
	if(*LA==ptr){
		LA++;
		return 1;
	}else{
		printf("there is an error here\n");
		return 0;
	}
	
}
int S(){
	char d=*LA;
//	printf("testing S%c\n",*LA);
	if(*LA=='a'){
	     //  printf("entering S()\n");
          if(A()==1){
              if(B()==1){
           //   	printf("returned to S\n");
              	if(match('c')==1){
				  
              	return 1;
			  }else{
			  	return 0;
			  }	
          	
		  }	else{
		  	return 0;
		  }
}else{
	return 0;
}
	}else{
		printf("the following string does not accept by this grammar\n");
		return 0;
	}
}
int A(){
	if(*LA=='a'){
	//	printf("entered A\n");
		if(match('a')==1){
	        	if(match('b')==1){
	        		if(*LA=='a'){
	        			if(A()==1){
	        				
						}else{
							return 0;
						}
					}else{
						return 1;
					}
				}else{
					return 0;
				}		
		}else{
			return 0;
		}
	
		
	}else{
		return 0;
	}
	return 1;
}
int B(){
//	printf("entered B\n");
	if(*LA=='b'){
		if(match('b')==1){
			
		}else{
			return 0;
		}
	}else {
	if(*LA=='c'){
		if(match('c')&&match('c')){
		}else{
			return 0;
		}
	}}
	return 1;
}
int main(){
	char str[100];
	printf("please enter the string\n");
	scanf("%s",str);
	LA=str;
	if(S()==1){
       printf("the following string is accepted by the grammar\n");
	}else{
		printf("the following string does not belong to this grammar\n");
	}
return 0;}
