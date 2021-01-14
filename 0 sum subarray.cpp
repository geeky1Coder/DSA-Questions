#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
	std::set<int> prefixSums;
	int s = 0;
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (s == 0) {
			flag = true;
			break;
		}
		s += arr[i];
		if (prefixSums.count(s) != 0) {
			flag = true;
			break;
		}
		prefixSums.insert(s);
	}
	return flag;
}

int main() {
	int arr[] = {4, 2, -3, 1, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << subArrayExists(arr, n);
	return 0;
}