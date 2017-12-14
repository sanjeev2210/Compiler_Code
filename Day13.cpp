/*
Develop a program for part of speech tagging(POS) of english words.


*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
//verbs 
//Four suffixes consistently added to a verb’s base create all forms of a verb used in all tenses:

//1. -s          creates 3rd person singular / present tense  (He talks.)

//2. -ing       creates the present participle / used with be  (He is talking.)

//3. -ed        creates the simple past  (He talked.)

//4. -en        creates the past participle / used with have  (He has talked.)
	char verb[][12]={"run","hear","call","know","recognised","believe","am","is","drove","slept","talks","talking","talked","gone","write","wrote","writing","arise","arose"
	
                        "eat","forgive","done" ,"do","happy","chosen","choose","burst ","brought","began" ,"bring", "break", "blow", "begin", "bear" ,"awoke","attack","read"};

	char pronoun[][12]={"he","she","it","I","you","my","herself","who","him","her","someone","whose","everybody"};
	char adj[][12]={"blue","funny","crazy","cold","tall","good","nice","cheaper","fast","beautiful","adorable","big","old","green","orange","yellow","red","brown"};
    //words staring with these and ending with er and est are also adjectives.	
	//adverb 
	//words that end with ly
	
	char conjuction[][12]={"and","that","for","but","although","after","because","if"};
	char articles[][5]={"a","an","the"};
	
	///apart from these are considerd to be nouns
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
	  
	for(int u=0;u<36;u++){
		int j=0;int flag=0;
		for(;j<strlen(verb[u]);j++){
			
			if(token[i][j]!=verb[u][j]){
				//printf("hey\n");
				flag=1;
			break;
			}
			
		}
	
		 int len=strlen(token[u])-1;
	if(token[i][len]=='d'&&token[i][len-1]=='e'){
		flag=1;
		
	}else if(token[i][len]=='n'&&token[i][len-1]=='e'){
		
		flag=1;
	}else  if(token[i][len]=='g'&&token[i][len-1]=='n'&&token[i][len-2]=='i'){
		
		flag=1;
	}else  if(token[i][len]=='s'){
		
		flag=1;
	}else{
	}
		if(flag==0){
			printf("%s    verb\n",token[i]);
	
			state=1;
			break;
		}
		}
}
         if(state==0){
		 
		for(int u=0;u<13;u++){
		int j=0;int flag=0;
		for(;j<strlen(pronoun[u]);j++){
			if(token[i][j]!=pronoun[u][j]){
				flag=1;
				
				break;
			}
			
		}
		if(flag==0){
			printf("%s     pronoun\n",token[i]);
			
			state=1;
			break;
		}
		}}
		if(state==0){
		
			for(int u=0;u<18;u++){
		int j=0;int flag=0;
		for(;j<strlen(adj[u]);j++){
			if(token[i][j]!=adj[u][j]){
				flag=1;
				
				break;
			}
			
		}
		int len=strlen(token[u])-1;
		 if(token[i][len]=='r'&&token[i][len-1]=='e'){
		
		flag=1;
	}else  if(token[i][len]=='t'&&token[i][len-1]=='s'&&token[i][len-1]=='e'){
		
		flag=1;
	}
		if(flag==0){
			printf("%s      adjective\n",token[i]);
			
			state=1;
			break;
		}
		}	
	}
	if(state==0){
		
			for(int u=0;u<8;u++){
		int j=0;int flag=0;
		for(;j<strlen(conjuction[u]);j++){
			if(token[i][j]!=conjuction[u][j]){
				flag=1;
				
				break;
			}
			
		}
		if(flag==0){
			printf("%s     conjunction\n",token[i]);
			
			state=1;
			break;
		}
		}
	}
	if(state==0){

			for(int u=0;u<3;u++){
		int j=0;int flag=0;
		for(;j<strlen(articles[u]);j++){
			if(token[i][j]!=articles[u][j]){
				flag=1;
				
				break;
			}
			
		}
		if(flag==0){
			printf("%s     article\n",token[i]);
			
			state=1;
			break;
		}}
	
		}
if(state==0){
	//cheking for adverb

           int len=strlen(token[i])-1;
	if(token[i][len]=='y'&&token[i][len-1]=='l'){
		printf("%s     adverb\n",token[i]);
		state=1;
	}
	}
	if(state==0){
	
  printf("%s     noun\n",token[i]);
	}}
	
	
	
	
	
	return 0;
}
