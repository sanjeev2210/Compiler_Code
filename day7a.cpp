#include<stdio.h>
#include<conio.h>
#include<string.h>
//@ denotes the epsilon
int main(){
	
	printf("Enter the regular grammer\n");
	int n=0;
	printf("enter how many production rules in the grammar\n");
	scanf("%d",&n);
	char a[100][100];
	printf("enter the production rules\n");
	for(int i=0;i<n;i++){
		scanf("%s",a+i);
	}

	//scanning the part for left recursion
	int next=n+1;
	for(int i=0;i<n;i++){
		int len1=strlen(a[i]);
		//checking the regular expression for left factoring
		//assuming that the user enters the the context free of the form S->A|B
	if(a[i][0]==a[i][3]){
		//it is guarentee that there is a left factoring 
		//now we had to travers untill there is a beta or not A->A.alpha|Beta
	//	printf("%c%c",a[i][0],a[i][3]);
		char alpha[40];
		int j=4;
		for(int u=0;j<strlen(a[i])&&a[i][j]!='|';u++,j++){
			        alpha[u]=a[i][j];
		}
		//printing the alpha
	//	printf("%s\n",alpha);
		// now we had got the alpha and we had to check whether there is a beta if there is a beta then we had to collect beta
		char beta[40];
		if(j!=len1){
			j++;
			for(int u=0;j<len1&&a[i][j];u++,j++){
				beta[u]=a[i][j];
				//testing the beta
			//	printf("%cbeta",a[i][j]);
			}
		}
		//printintf the beta
	//	printf("%s\n",beta);
		// now to replace the original string with the relaxed one
		int len=strlen(a[i]);
		int u=3;
		for(int y=0;u<len&&y<strlen(beta);u++,y++){
			a[i][u]=beta[y];
		}
		a[i][u]=a[i][0];
		u++;
		a[i][u]='^';
		u++;
		a[i][u]='\0';
	 //now replace the new production rules
	 a[next][0]=a[i][0];
	 a[next][1]='^';
	 a[next][2]='-';
	 a[next][3]='>';
	 int t=4;
	 for(int u=0;(u<strlen(alpha))&&(alpha[u]!='\0');u++,t++){
	 	a[next][t]=alpha[u];
	 	}
	    
	 a[next][t]=a[i][0];
	 t++;
	 a[next][t]='^';
	 t++;
	 a[next][t]='|';
	 printf("%c",a[next][t]);
	 t++;
	 a[next][t]='@';
	//printf("%c",a[next][t]);	
		
	}
	next++;
	
	}	
	printf("printing the produciton rules\n"); 
		for(int i=0;i<next;i++){
		printf("%s\n",a[i]);
	}
return 0;}
