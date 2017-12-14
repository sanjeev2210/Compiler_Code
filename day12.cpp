/*
WAP to optimise three address codes

*/
#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct node{
	char op1;
	struct node* left;
	struct node* right;
};


char str[10][10];

int sym=0;
char symbols[]={'A','B','C','D','E','F','G','H','I','J','H'};
char *LA;
struct node* T();
struct node* F();
struct node* X(struct node* n);
struct node* J(struct node* n);
struct node* Z(struct node* n);


void inorder(struct node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%c",root->op1);
		inorder(root->right);
	}
}
int n1=0;
int assign(){
	n1++;
	return n1;
}
char threeaddressopcode(struct node* root,int n){
	if(root->op1=='+'||root->op1=='-'||root->op1=='*'||root->op1=='/'){
		str[n][0]=symbols[sym];
	
		sym++;
        str[n][1]='=';
        str[n][2]=threeaddressopcode(root->left,assign());
    
        str[n][3]=root->op1;
    
        str[n][4]=threeaddressopcode(root->right,assign());
	       return str[n][0];	
	}else {
		return root->op1;
	}
}
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
struct node* E(){
	
	       struct node* in=T();
	if(in!=0){
        struct node* syn=X(in);
		if(syn!=NULL){
	
			return syn;
		}else{
			return NULL;
		}
	}else{
		return NULL;
	}
}

struct node* K(struct node* in){
	struct node* root=(struct node*)malloc(sizeof(struct node));
	if(*LA=='+'){
		if(match('+')==1){
			root->right=T();
			if(root->right!=0){
		         root->op1='+';
		         root->left=in;
		         
				return root;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else if(*LA=='-'){
		if(match('-')==1){
			root->right=T();
			if(root->right!=NULL){
				root->op1='-';
				root->left=in;
				return root;
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
struct node* J(struct node* in){
	struct node* root=(struct node*)malloc(sizeof(struct node));
	if(*LA=='*')
	{ if(match('*')==1){
		 root->right=F();
		if(root->right!=NULL){
			root->op1='*';
			root->left=in;
			return root;
		}else{
			return NULL;
		}
	}else{
		return 0;
	}
		
	}else if(*LA=='/'){
		if(match('/')==1){
			root->right=F();
			if(root->right!=NULL){
				root->op1='/';
				root->left=in;
				return root;
			}else{
				return NULL;
			}
		}else{
			return NULL;
		}
	}else{
		return NULL;
	}
}
struct node* F(){
	struct node* temp;
	if(*LA=='('){
		if(match('(')==1){
               temp=E();
		if(temp!=NULL){
		if(match(')')==1){
			return temp;
		}	
		}else{
			return NULL;
		}
		
		}else {
			return NULL;
		}
	}else if(*LA=='0'){
		if(match('0')==1){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='0';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return NULL;
		}
	}else if(*LA=='1'){
		if(match('1')==1){
			temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='1';
		temp->right=NULL;
		temp->left=NULL;
		return temp;
		
		}else{
			return NULL;
		}
	}else if(*LA=='2'){
			if(match('2')==1){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='2';
		temp->right=NULL;
		temp->left=NULL;
		return temp;
	}else{
			return NULL;
		}
	}else if(*LA=='3'){
	   	if(match('3')==1){
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='3';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return 0;
		}
	}else if(*LA=='4'){
			if(match('4')==1){
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='4';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return NULL;
		}
	}else if(*LA=='5'){
			if(match('5')==1){
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='5';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return NULL;
		}
	}else if(*LA=='6'){
		if(match('6')==1){
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='6';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return NULL;
		}
	}else if(*LA=='7'){
		if(match('7')==1){
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='7';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return NULL;
		}
	}else if(*LA=='8'){
		if(match('8')==1){
		
		temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='8';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return NULL;
		}
	}else if(*LA=='9'){
		if(match('9')==1){
		
	temp=(struct node*)malloc(sizeof(struct node));
		temp->op1='9';
		temp->right=NULL;
		temp->left=NULL;
		return temp;}else{
			return NULL;
		}
	}else {
		return NULL;
	}
}
struct node* T(){
	
struct node* syn1=F();
	if(syn1!=NULL){
		struct node* syn2=Z(syn1);
		if(syn2!=NULL){
			return syn2;
		}else{
			return 0;
		}
	}else {
		return 0;
	}
}
struct node* Z(struct node* in){

	if(*LA==')'||*LA=='$'||*LA=='+'||*LA=='-'){
		return in;
	}else{
		struct node* syn1=J(in);
		if(syn1!=NULL){
			struct node* syn2=Z(syn1);
	        if(syn2!=NULL){
	        	return syn2;
			}else{
				return NULL;
			}		
		}else{
			return NULL;
		}
	}
	
}
struct node* X(struct node* in){
	
	if(*LA==')'||*LA=='$'||*LA=='*'||*LA=='/'){
		return in;
	}else{
		struct node* syn1=K(in);
		if(syn1!=NULL){
			struct node* syn2=X(syn1);
	        if(syn2!=NULL){
	        	return syn2;
			}else{
				return NULL;
			}		
		}else{
			return NULL;
		}
	}
	
}
int main(){
		char stri[100];
	printf("please enter the  expression\n");
	scanf("%s",stri);
	LA=stri;
struct node* root=NULL;
	root=E();
	if(root!=NULL){
       printf("the following string is accepted by the grammar\n");
    
       printf("\nthe address opcodes are as follows\n");
       threeaddressopcode(root,0);
       
       for(int i=0;i<10;i++){
       	if(strlen(str[i])>0){
		   
       	printf("%s\n",str[i]);
	   }}
	   //optimising the codes
	   for(int i=0;i<10;i++){
	   	if(strlen(str[i])!=0){
		   
	   	 int j=i+1;
		   	for(;j<=10;j++){
		   		int flag=0;
		   		for(int k=2;k<=4;k++){
		   			if(str[i][k]!=str[j][k]){
		   				
		   				flag=1;
		   				break;
					   }
					   
				   }
		   		if(flag==0){
		   			 
		   			 
		   			break;
				   }
		}
			   str[j][1]='$';
			   for(int y=0;y<i;y++){
			   	for(int p=2;p<=4;p++){
			   		if(str[j][0]==str[y][p]){
			   			str[y][p]=str[i][0];
		
					   }
				   }
			   }
		   }
}
	   printf("printing the optimising codes\n");
	    for(int i=0;i<10;i++){
         if(str[i][1]!='$'&&strlen(str[i])>0){
		 
       	printf("%s\n",str[i]);
	  } }}
	else{
		printf("the following string does not belong to this grammar\n");
	}
return 0;}

