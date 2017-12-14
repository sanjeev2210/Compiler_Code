#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	string str,s;
	cin>>str;
		int x=str[a-1];
		int y=str[b-1];
		if(x==y)
		{
			cout<<"0"<<endl;
		}
		else
		{
			cout<<"1"<<endl;
	}
	return 0;
}
