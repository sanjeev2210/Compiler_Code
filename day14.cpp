/*
Develop a program for part of speech (POS) of hindi words.
*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
	char verb[][13]={"daura","suna","bulaya","janta","pehchanliya","khata","hai","kha","rha"};
	char pronoun[][7]={"wah","wah","yah","mai","tum","mera"};
	char adj[][13]={"nila","thanda","achchha","lamba","sasta"};
	char conjuction[][12]={"aur","wah","liye","lekin"};
	//apart from these are considerd to be sangya
int main(){
printf("enter the text to be pos tagged\n");
char str[40];
gets(str);
char token[40][20];
int j=0;
int k=0;
//categorising differnt tokens
for(int i=0;i<strlen(str);i++){
	if(str[i]==' '){
		token[k][j]='\0';
		j=0;
		k++;
	}else{
		token[k][j]=str[i];
		j++;
	}

}
printf("the different tokens are\n");
for(int i=0;i<=k;i++){
	printf("%s\n",token[i]);
}
//logic for categorising the tokens
printf("the pos tags of the tokens are as follows\n");
int state=0;
for(int i=0;i<=k;i++){
	//searching for verb
	state=0;
	  if(state==0){

	for(int u=0;u<9;u++){
		int j=0;int flag=0;
		for(;j<strlen(verb[u]);j++){
			if(token[i][j]!=verb[u][j]){
				//printf("hey\n");
				flag=1;
			break;
			}

		}

/*		 int len=strlen(token[u])-1;
	if(token[i][len]==''&&token[i][len-1]=='e'){
		flag=1;

	}else if(token[i][len]=='n'&&token[i][len-1]=='e'){

		flag=1;
	}else  if(token[i][len]=='g'&&token[i][len-1]=='n'&&token[i][len-2]=='i'){

		flag=1;
	}else  if(token[i][len]=='s'){

		flag=1;
	}else{
	}*/
		if(flag==0){
			printf("%s    kriya\n",token[i]);

			state=1;
			break;
		}
		}
}
         if(state==0){

		for(int u=0;u<6;u++){
		int j=0;int flag=0;
		for(;j<strlen(pronoun[u]);j++){
			if(token[i][j]!=pronoun[u][j]){
				flag=1;

				break;
			}

		}
		if(flag==0){
			printf("%s     sarvanam\n",token[i]);

			state=1;
			break;
		}
		}}
		if(state==0){

			for(int u=0;u<5;u++){
		int j=0;int flag=0;
		for(;j<strlen(adj[u]);j++){
			if(token[i][j]!=adj[u][j]){
				flag=1;

				break;
			}

		}
if(flag==0){
			printf("%s      visheshan\n",token[i]);

			state=1;
			break;
		}
		}
	}
	if(state==0){

			for(int u=0;u<4;u++){
		int j=0;int flag=0;
		for(;j<strlen(conjuction[u]);j++){
			if(token[i][j]!=conjuction[u][j]){
				flag=1;

				break;
			}

		}
		if(flag==0){
			printf("%s    samuchaya bodhak  \n",token[i]);

			state=1;
			break;
		}
		}
	}
	if(state==0){

  printf("%s     sangya\n",token[i]);
	}}





	return 0;
}
