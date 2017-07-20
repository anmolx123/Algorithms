#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[100002];
	int r,u;
	cin >> s;
	while(s[0]!='0'){
		
		long long int dp[100001];
		int d = strlen(s);
		
		for(int i=0;i<d;i++)
		dp[i]=0;
		
		dp[-1]=1;
		dp[0]=1;
		
		for(int i=1;i<d;i++){
			
			//if (i-1)th element has x ways to be decrypted then ith element also has x ways if its a valid digit
			if(s[i]-'0'<10 && s[i]-'0'>0)  
			dp[i]=dp[i-1];
			
			r = s[i-1]-'0';
			u = s[i] - '0';
			r = r*10+u;
			// if (i-1)th and ith are forming a no less than 26 then it would be decrypted in same ways
			//  that (i-2)th element is decrypted so add dp[i] ways and dp[i-2] ways for dp[i]
			if(r>9 && r<27){
				dp[i] += dp[i-2];
			}
		}
		cout << dp[d-1] << endl;
		cin >> s;
	}
}
