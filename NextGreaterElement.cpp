#include<bits/stdc++.h>
using namespace std;

vector <long long> nextLargerElement(long long arr[], int n) {
	std::stack<int> s;
	s.push(arr[0]);
	std::map<int, int> m;
	for (int i = 1; i < n; ++i) {
		while (!s.empty()) {
			int x = s.top();
			if (arr[i] <= x) {
				break;
			}
			m[x] = arr[i];

			s.pop();
		}
		s.push(arr[i]);
	}
	while (!s.empty()) {
		int x = s.top();
		m[x] = -1;
		s.pop();
	}
	vector<long long> ans;
	for (int i = 0; i < n; ++i) {
		ans.push_back(m[arr[i]]);
	}
	return ans;
}

int main() {
	long long arr[] = {1, 3, 2, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<long long> v = nextLargerElement(arr, n);
	for (auto el : v) {
		cout << el << " ";
	}
	return 0;
}
