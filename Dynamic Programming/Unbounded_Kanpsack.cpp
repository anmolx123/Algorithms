#include<bits/stdc++.h>
#define m 100005
using namespace std;

int main(){
	
	int t,c,n,k;
	cin >> t;
	while(t--){
		
		int a[100005];
		cin >> n >> k;
		
		int dp[k+1];
		
		for(int i=1;i<=k;i++){
			cin >> a[i];
			dp[i]=a[i];
		}
		dp[0]=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=i;j++){
				if(a[j]!=-1 && dp[i-j]!=-1){
					dp[i] = min(dp[i],dp[i-j]+a[j]);
				}						
			}
		}
		cout << dp[k] << endl;
		
	}
	return 0;
}
