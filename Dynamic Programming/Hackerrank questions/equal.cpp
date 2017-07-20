#include<bits/stdc++.h>
#define INT_MAX 1000000007
#define ll long long
using namespace std;

ll int tmp(ll int d){
	ll int x=0;
	while(d>=5){
		x = d/5;
		d = d%5;
	}
	
	while(d>=2){
		x += d/2;
		d = d%2;
	}
	x=d+x;
	return x;
}


ll int picksmall(ll int s[],ll int mi){
	int mini = INT_MAX;
	for(int i=0;i<mi;i++){
		if(s[i] < mini)
		mini = s[i];
	}
	return mini;
}

int main(){
	
	ll int t,n,a[100001],mi,s[10],temp;
	cin >> t;
	while(t--){
		memset(s,0,sizeof(s));
		mi = INT_MAX;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i];
			
			if(a[i]<mi)
				mi = a[i];
		}
		//
		for(int i=0;i<=2;i++){	
			s[i]=0;
			for(int j=0;j<n;j++){
				temp = abs(a[j] - (mi - i));
				s[i] += tmp(temp);
			}
		}
		cout << picksmall(s,3) << endl;
	}
}
