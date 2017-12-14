//W.A.P to find first and follow of the grammar 


#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
	printf("please how many productions in your grammar\n");
	int n;
	scanf("%d",&n);
	printf("please enter the set of terminals in your grammar\n");
	printf("please enter the terminal no:\n");
	   int terminalno;
		scanf("%d",&terminalno);
	printf("please enter the non terminal no:\n");	
	
   int nonterminalno;
	scanf("%d",&nonterminalno);

	char terminal[terminalno];
	printf("please enter the terminals\n");
	scanf("%s",&terminal);
		char nonterminal[nonterminalno];
	printf("please enter the non terminals in your grammar\n");
	scanf("%s",&nonterminal);
	printf("please enter the productions of your grammar\n");
	char a[n][100];
	for(int r=0;r<n;r++){
		scanf("%s",a[r]);
	}
	char ans[nonterminalno][10];
	//now all my productions have been taken from the user
	//now to compute the first of every non terminal we had to search the terminal in 0 location and then go after the arrow then see whther there is a :-
	//terminal or non terminal
	//if there is a terminal -:::::then include in the first and that is the answer
	//if there is a non terminal -:::::::then take that non terminal and then search for the process again.
	for(int i=0;i<nonterminalno;i++){
		int flag=0;
	    char skip=nonterminal[i];
	  
	    ans[i][0]=nonterminal[i];
	   
	    int at;
		while(flag!=1){
		
			//now to  search for the production rule that correspnding to the particular variable
              int j=0;
		for(;j<n;j++){
		
		
			if(a[j][0]==skip){
			//now i have got the production  rule 	
			//so got the other side of the production rule

	          int at=strlen(ans[i]);
			int k=1;
			while(a[j][k]!='>'){
				k++;
			}
			k=k+1;
		    //now checking for the first symbol is the terminal or non terminal
              int got=0;
              int u=0;
			for(;u<terminalno;u++){
				if(a[j][k]==terminal[u]){
				
					
					got=1;
					break;
				}
			}
			if(got==1){
			
		ans[i][1]=terminal[u];
			ans[i][2]='\0';
		
			flag=1;
			at++;
			break;
			}else{
				skip=a[j][k];
			}
			 
			
			}
			
		}
		if(flag==1){
			break;
		}	
		}
	}
	//now printing the results
	printf("the first of the corresponding grammar is:\n");
	for(int i=0;i<nonterminalno;i++){
		printf("%s\n",ans[i]);
	}
	//computing the follow of the grammar\n
	char follow[nonterminalno][3];
	for(int i=0;i<nonterminalno;i++){
		int flag=0;int che=0;
		char skip=nonterminal[i];
		
		if(i==0){
			follow[i][0]=nonterminal[i];
			follow[i][1]='$';
		}
	while(flag!=1){
		  int j=0;
		  for(;j<n;j++){
		  	int c=3;int ter=0;
		  	while(c<strlen(a[j])){
		  		if(a[j][c]==skip){
		  			
		  			ter=1;
		  			break;
				  }
		  		c++;
			  }
			  c++;
			  if(ter==1){
			  
		          if(a[j][c]!='\0'){
		          	follow[i][0]=nonterminal[i];
		          	int f;
		          	if(i==0){
		          		f=2;
					  }else{
					  	f=1;
					  }
					  //searching for the a[j][c]
					  int l=0;
					  for(;l<nonterminalno;l++){
					  	if(a[j][c]==nonterminal[l]){
					  		break;
						  }
					  }
		          	for(;f<strlen(ans[l]);f++){
					  
		          	follow[i][f]=ans[l][f];
				  }	  
		              flag=1;
		  }
		  else{
		  	//you had to check first whether the follow exits or not na!!!!!!
		  	//checking for the follow.
		  	skip=a[j][0];
		  	
		  	for(int q=0;q<i;q++){
		  		if(follow[q][0]==a[j][0]){
		  			
		  			che=1;
		  		for(int f=0;f<strlen(ans[i]);f++){
					  if(i!=0&&f==0){
					  
				         follow[i][0]=nonterminal[i];
				         
				}else{
				
				
		          	follow[i][f]=follow[q][f];}
				  }	
				  }
				  if(che==1){
				  	flag=1;
				  	break;
				  }
			  }
		  }
		}
	if(j+1==n){
		flag=1;
	}
		}
		
	if(flag==1){
		break;
	}	
		
	}
}
	printf("the follow of the corresponding grammar is:\n");
	for(int i=0;i<nonterminalno;i++){
		printf("%s\n",follow[i]);
	}

return 0;}
