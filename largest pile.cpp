#include<bits/stdc++.h>
using namespace std;
int H[1005];
int G[1005];
int Height[1005];
int Profit[1005];
int main()
	{
		ios_base::sync_with_stdio(0);
		int N,i,j;
		int a=0,b=0;
		cin>>N;
		for(i=1;i<=N;++i)
			cin>>H[i];
		for(i=1;i<=N;++i)
			cin>>G[i];
		for(i=1;i<=N;++i)
			{
				Profit[i] = G[i];
				Height[i] = H[i];
				for(j=i-1;j>=1;--j)
					{
						if(H[j]>H[i])
							{
								if(Profit[j]+G[i]>Profit[i])
									{
										Profit[i] = Profit[j] + G[i];
										Height[i] = Height[j] + H[i];
									}
								else if(Profit[j]+G[i]==Profit[i])
									{
										if(Height[j] + H[i]>Height[i])
											Height[i] = Height[j] + H[i];
									}
							}
					}
			//	cout<<Profit[i]<<" ";
			}
		//cout<<endl;
		for(i=1;i<=N;++i)
			{
				if(Profit[i]>a)
					{
						a = Profit[i];
						b = Height[i];
					}
				else if(Profit[i]==a)
					{	
						if(Height[i]>b)
							b = Height[i];
					}
			}
		cout<<b<<" "<<a;
	}
