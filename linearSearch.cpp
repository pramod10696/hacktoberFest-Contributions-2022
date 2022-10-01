#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n,int key){
	for(int i=0;i<n;i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}

int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int key;
	cin>>key;
	int ans=0;

	cout<<linearSearch(a,n,key)<<endl;

	return 0;
}