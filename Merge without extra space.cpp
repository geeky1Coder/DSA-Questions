//Merge without extra space
#include <bits/stdc++.h>
using namespace std;
//Efficient approach using shell sort
void merge(int arr1[], int arr2[], int n, int m) {
    int j = m - 1;
    int i = n - 1;
    while (j >= 0) {
        if (arr2[j] < arr1[i]) {
            //Perform proper swap
            int temp = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = temp;

            int k = n - 2;
            while (k >= 0) {
                if (arr1[k] > arr1[k + 1]) {
                    int temp = arr1[k];
                    arr1[k] = arr1[k + 1];
                    arr1[k + 1] = temp;
                }
                else {
                    break;
                }
                k--;
            }
        }
        j--;
    }
}
int main() {

    int arr1[] =  {1, 5, 9, 10, 15, 20};
    int arr2[] =  {2, 3, 8, 13};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, arr2, n, m);

    for (int i = 0; i < n; ++i) {
        cout << arr1[i] << " ";
    }
    for (int j = 0; j < m; ++j) {
        cout << arr2[j] << " ";
    }
    cout << endl;
    return 0;
}
