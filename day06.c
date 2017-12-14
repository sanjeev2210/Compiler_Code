#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree
{
    char ch;
    
    int nullable;
    struct tree * lc;
    struct tree * rc;
}node;
char regular[26][100];
char nonterminal[12]={"SABCDEFGH"};
int k=0;int n1=0;
int assign(){
	n1++;
	return n1;
}
node* alloc(char ch)
{
    node * temp;
    temp=(node *)malloc(sizeof(node));
    temp->nullable=1;
    temp->lc=NULL;
    temp->rc=NULL;
    temp->ch=ch;
   // temp->fpos[0]=-1;
    //temp->lpos[0]=-1;
    return temp;
}

node * create(char str[],int *l)
{

    node * nw;
    nw=alloc(str[*l]);

    nw->lc=NULL;
    nw->rc=NULL;
    if(str[*l]=='*'||str[*l]=='|'||str[*l]=='.')
    {
        if(str[*l]!='*')
        {
            (*l)--;
            nw->nullable=0;
            nw->rc=create(str,l);
        }
        (*l)--;
        nw->lc=create(str,l);
    }
    else
        nw->nullable=0;
    return nw;
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->lc);
        printf("%c",root->ch);
        inorder(root->rc);
    }
}
char cregular(node* root,int n){
	if(root->ch=='*'){
		if(root->lc==NULL){
			int u=n;
			regular[u][0]=nonterminal[k];
			k++;
			regular[u][1]=cregular(root->lc,assign());
			regular[u][2]=regular[u][0];
			regular[u][3]='|';
			regular[u][4]='@';
		}else{
				int u=n;
			regular[u][0]=nonterminal[k];
			k++;
			regular[u][1]=cregular(root->lc,assign());
			regular[u][2]=regular[u][0];
			regular[u][3]='|';
			regular[u][3]='@';
		}
	}
	else if(root->ch=='.'){
		
    regular[n][0]=nonterminal[k];
    k++;
	regular[n][1]=cregular(root->lc,assign());
	
	regular[n][2]='.';
	regular[n][3]=cregular(root->rc,assign());  
	
	//regular[n][3]='\0';
	}
	else if(root->ch=='|'){
    regular[n][0]=nonterminal[k];
    k++;
	regular[n][1]=cregular(root->lc,assign());
	
	printf("%d the number\n",n);
	regular[n][2]='|';
	regular[n][3]=cregular(root->rc,assign());   

	}
	else if(root->ch=='1'){
		regular[n][0]=nonterminal[k];
		k++;
		regular[n][1]='1';
		

			
	}
	else{
		regular[n][0]=nonterminal[k];
		k++;
		regular[n][1]='0';		
	}
	return regular[n][0];
}
int main(){
	char a[1000];int i=0;
	printf("please enter the regular expression to be parsed\n");
	scanf("%s",a);
	printf("creating the parse tree\n");
	 node * root;  
    int l;
   // strcat(a,"#.\0");
    l=strlen(a);
    l--;
    root=create(a,&l);
    inorder(root);
    printf("\n");
    char ch=cregular(root,0);
    for( i=0;i<10;i++){
    	printf("%s\n",regular[i]);
	}
	return 0;
}
