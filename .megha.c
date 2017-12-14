#include <stdio.h>

int main() {

	int a,b,c,i,n,d,k,j;
	scanf("%d",&k);
	for(j=0;j<k;j++)
	{
	scanf("%d",&n);
	

a=1;
b=1;
c=1;

for(i=3;i<=n;i++)
{
	d=a+b;

	a=b;
	b=c;
//	c=d;
	
}	printf("%d",d);
printf("\n");
}

	//code
	return 0;
}
