#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	int profit = 0;
	int min = prices[0];
	int maxProfit = 0;
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] < min) {
			min = prices[i];
		}
		else {
			int temp = prices[i] - min;
			if (temp > profit) {
				profit = temp;
			}
		}
	}
	return profit;
}

int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr + n);
	sort(dep, dep + n);
	int i = 0;
	int j = 0;
	int platforms = 1;
	int maxPlatforms = 1;
	while (i != n && j != n) {
		if (arr[i + 1] > dep[j]) {
			j++;
			platforms--;
		}
		else {
			i++;
			platforms++;
		}
		if (platforms > maxPlatforms) {
			maxPlatforms = platforms;
		}
	}
	return maxPlatforms;
}

int main() {
	int arr[] = {};
	cout << maxProfit(prices);
	return 0;
}