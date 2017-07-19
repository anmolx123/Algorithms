#include<bits/stdc++.h>
using namespace std;

int main(){
	int p[101],s[101],m[101],l,h,lo,i,n,a[101],mid,k;
		 
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		l=0;
		for(int i=0;i<n;i++){
			
			lo = 1;				
			h = l;
			
			while(lo<=h){                //binary search
				mid = ceil((lo+h)/2);
				
				if(a[m[mid]] < a[i])
					lo = mid+1;
				else
					h = mid-1;
			}
			
			p[i] = m[lo-1];			// p[k] is used to store the index of the predecessor of last element of current lis so that we can retrieve the previous element of lis during print operation.
			m[lo] = i;				// m[j] is used to store the index(k) of last element a[k] of current lis with length j
			
			if(lo>l)
			l = lo;
		}
		
		k = m[l];
		for(int j=l-1;j>=0;j--){
			s[j] = a[k];
			k = p[k];
		}
		
		for(int j=0;j<l;j++){
			cout << s[j] << " ";
		}
		cout << endl;
}


//Time Cmplexity :- O(nlog(n))
