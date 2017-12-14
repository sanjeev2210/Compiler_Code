#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,k,l,p=1;
	cin>>n>>k;
	string str,s,s1;
	str='1';
	cout<<str<<endl;
	for(ll i=2;i<=n;i++)
	{
		s1=int(i);
		str=str+s1;
		cout<<str<<endl;
		l=str.length();
		s=str.substr(0,l-2);
		str=str+s;
		p=p+l;
		cout<<str<<endl;
	}
	cout<<str[k-1]<<endl;
	return 0;
}
