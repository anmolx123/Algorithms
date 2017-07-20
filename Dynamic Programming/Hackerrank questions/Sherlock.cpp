#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll int t,n,a[101010],dp[100001][2];
	cin >> t;
	while(t--){
		dp[0][0] = dp[0][1] = 0;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		
		for(int i=0;i<n;i++){
			dp[i+1][0] = max(dp[i][0],dp[i][1] + abs(a[i]-1));
			dp[i+1][1] = max(dp[i][1] + abs(a[i+1]-a[i]),dp[i][0] + abs(a[i+1]-1));
		}
		
		cout << max(dp[n-1][0],dp[n-1][1]) << endl;
	}
	return 0;
}
