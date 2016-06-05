#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
using namespace std;
vector<int> graph[1000];
vector<int> v[1001];
bool visit[1000]={0};
int parent[1000];
int dp[501][20001];
int m;

void dfs(int v,int parent)
	{
		int j,k;
		visit[v] = true;
		bool isleaf = true;
		for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
			{
				if(visit[*i]==0)
					{
						dfs(*i,v);
					}
				if((*i)!=parent)
					isleaf = false;
			}
		if(isleaf==true)
			{
				for(j=1;j<=m;++j)
					dp[v][j] = 1;
			}
		else
			{
				LL total=0,result;
				for(j=1;j<=m;++j)
					{
						result = 1;
						for(vector<int>::iterator i = graph[v].begin();i!=graph[v].end();i++)
							{
								if(*i!=parent)
									{
										total = 0;
										for(k=j;k<=m;k+=j)
											{
												total = total + dp[*i][k];
												if(total>=M)
													total%=M;
											}
										result = result*total;
									}
								if(result>=M)
									result%=M;
							}
						dp[v][j] = result;
					}
			}
	}


int main()
	{
		
		LL ans = 0;
		int t,u,v,n,m,i;
	
				ans = 0;
				memset(visit,0,sizeof(visit));
				memset(dp,0,sizeof(dp));
				scanf("%d%d",&n,&m);
				::m = m;
				for(i=1;i<=n-1;++i)
					{
						scanf("%d%d",&u,&v);
						graph[u].push_back(v);
						graph[v].push_back(u);
					}
				dfs(1,-1);
				for(i=1;i<=n;++i) 
					{
						graph[i].clear();
						::v[i].clear();
					}
				for(i=1;i<=m;++i)
					{
						ans = ans + dp[1][i];
						if(ans>=M)
							ans%=M;
					}
				printf("%lld\n",ans);
			
	}
