#include<bits/stdc++.h>
using namespace std;
int parent[100001];
bool visit[100001]={0};
queue<int>q;
vector<int>graph[100001];
bool check[100001]={0};
void bfs(int v)
	{
		q.pop();//pops out the current vertex as front from the queue initially the pushed vertex is the starting one
		visit[v] = true;//mark the current vertex as the visited one for first time
		//iterator works on address basis
		//depth[depths[parent[v]]+1].push_back(v);
		//depths[v] = depths[parent[v]] + 1;
		//maxdepth = max(maxdepth,depths[v]);
		for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)//i made a variable i to be the iterator of the current row in the adjacency list
			{
				if(visit[*i]==false)
					{
						q.push(*i);
						//printf("%d %d",*i,v);
						parent[*i] = v;
					}
			}
		if(!q.empty())
			{
				bfs(q.front());
			}
	}

int main()
	{
		int i,n,u,v,q;
		ios_base::sync_with_stdio(0);
		cin>>n;
		for(i=1;i<=n-1;++i)
			{
				cin>>u>>v;
				//cout<<u<<" "<<v<<endl;
				check[u] = 1;
				check[v] = 1;
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		cin>>q;
		parent[1] = 1;
		::q.push(1);
		bfs(1);
		while(q--)
			{
				cin>>u>>v;
				if(parent[u]==v)
					{
						cout<<v<<" parent of "<<u<<endl;
					}
				else if(parent[v]==u)
						cout<<u<<" parent of "<<v<<endl;
			}
	}
