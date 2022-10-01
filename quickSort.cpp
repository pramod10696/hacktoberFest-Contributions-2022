#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int s, int e){
	int pivot = a[s];
	int count = 0;
	for(int i = s+1; i <= e; i++){
		if(a[i] <= pivot) count++;
	}

	int pivotIndex = s + count;
	swap(a[pivotIndex], a[s]);

	int i = s, j = e;
	while(i < pivotIndex && j > pivotIndex){
		while(a[i] < pivot){
			i++;
		}
		while(a[j] > pivot){
			j--;
		}
		if(i < pivotIndex && j > pivotIndex){
			swap(a[i++], a[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int a[], int s, int e){
	if(s >= e) return;

	int p = partition(a, s, e);

	quickSort(a, s, p-1);
	quickSort(a, p+1, e);
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	quickSort(a, 0, n-1);
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
