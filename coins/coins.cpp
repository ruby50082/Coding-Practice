#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMin(vector<int>& base, int m);

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,m;
		cin>>n>>m;	
		vector<int> base;
		for(int j=0; j<n; j++){
			int tmp;
			cin>>tmp;
			base.push_back(tmp);
		}	
		cout<<findMin(base, m)<<endl;
		base.clear();
	}
}


int findMin(vector<int>& base, int m)
{
	vector<int> dp(m+1);
	dp[0]=0;
	int maxi=m+1;
	for(int i=1; i<=m; i++){
		dp[i]=maxi;
	}

	for(int i=1; i<=m; i++){
		for(int j=0; j<base.size(); j++){
			if(base[j] <= i){
				dp[i] = min(dp[i], dp[i-base[j]]+1);
			}
		}
	}
	if(dp[m] == maxi)	return -1;
	else	return dp[m];
}