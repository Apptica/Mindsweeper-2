#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int main()
	{
		long long int m,n,i,o,p;
		long long int ans=0;
		cin>>m>>n>>o>>p;
		long long int a,b,c,d;
		for(i=1;i<=MAX;++i)
			{
				a = i*m*n;
				b = n*p;
				c = o*p;
				d = m*o;
				if(a%b==0&&a%c==0&&a%d==0)
					{
						b = a/b;
						c = a/c;
						d = a/d;
						if(b<=1000000&&c<=1000000&&d<=1000000)
							++ans;
					}
			}
		cout<<ans*MAX;
	}
