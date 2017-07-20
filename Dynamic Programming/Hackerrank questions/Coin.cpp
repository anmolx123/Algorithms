#include<bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long int n,m,a[100001],dp[100001];
	cin >> n >> m;
	for(int i=0;i<m;i++)
		cin >> a[i];
		
	dp[0]=1;	
	
	for(int i=0;i<m;i++){
		for(int j=a[i];j<=n;j++){	
			dp[j] += dp[j-a[i]];
		}
	}
	cout << dp[n];
}
