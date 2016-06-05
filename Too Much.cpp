#include<bits/stdc++.h>
#define LL long long int
using namespace std;
#define M 1000000007
LL a[100001];
int main()
	{
		LL n,i;
		LL ans = 1;
		cin>>n;
		for(i=1;i<=n;++i)
			cin>>a[i];
		for(i=1;i<=n;++i)
			{
				ans = ans * (1 + a[i]);
				if(ans>=M)
					ans%=M;
			}
		cout<<(ans-1+M)%M;

	}
