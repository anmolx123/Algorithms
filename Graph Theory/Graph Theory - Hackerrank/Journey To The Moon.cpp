#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100001];
int f;
bool vis[100001];
void dfs(int node){
	vis[node]=true;
	
	for(int i=0;i<adj[node].size();i++){
		int d = adj[node][i];
		
		if(vis[d]==false){
			f++;
			dfs(d);
		}
	}
}

int main(){
	int n,m,a,b,k,l,ar[100005],sum1;
	long long int sum=0;
	
	cin >> n >> m;
	
	memset(vis,false,sizeof(vis));
	
	for(int i=0;i<m;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	l=0;
	for(int i=0;i<n;i++){
		
		if(vis[i]==false){
			f=1;
			dfs(i);
			ar[l++]=f;
		}
	}
	
	sum1=0;
	for(int i=n-1;i>0;i--){
        sum1 += ar[i];
        sum += ar[i-1]*sum1;
    }
	cout << sum ;
}
