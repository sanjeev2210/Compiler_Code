#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
   ll g,n,m,k,res;
    cin>>g;
    while(g--)
        {
        cin>>n;
        res=0;
        while(n--)
            {
            cin>>m>>k;
            if(m>2){
                if(m%2==0)
                 res=res^2;
                else
                    res=res^1;
                        
            }
            else if(m==1)
                res=res^1;  
        }
        if(res!=0)
            cout<<"BOB"<<endl;
        else
            cout<<"BEN"<<endl;
    }
    return 0;
}

