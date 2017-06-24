//****** Anmol Agarwal 

#include<bits/stdc++.h>
using namespace std;

bool vis[100005];
vector<long int>adj[100005];
int main(){
	long long int query,n,m,clib,croad,a,b,ans;
	
	cin >> query;
	while(query--){
		ans=0;
		queue <long int> q;
		
		cin >> n >> m >> clib >> croad;
		memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
		adj[i].clear();
		for(int i=0;i<m;i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		if(clib<croad){
			cout << clib * n << endl;
		}
		else{
			for(int j=1;j<=n;j++){
				if(vis[j]==false){
					q.push(j);
					vis[j]=true;
					ans += clib;
					while(!q.empty()){
						int d = q.front();
						q.pop();
						
						for(int i=0;i<adj[d].size();i++){
							int e = adj[d][i];
							if(vis[e]==false){
								ans+=croad;
								vis[e]=true;
								q.push(e);
							}
						}
					}
				
				}
			}
		cout << ans << endl;
		
		}
	}
}
