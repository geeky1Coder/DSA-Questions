#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
Node* merge(Node* l, Node* r) {
	Node* head = new Node(1);
	Node* end = head;
	while (l != nullptr && r != nullptr) {
		if (l->data <= r->data) {
			end->next = new Node(l->data);
			l = l->next;
			end = end->next;
		}
		else {
			end->next = new Node(r->data);
			r = r->next;
			end = end->next;
		}
	}
	while (l != nullptr) {
		end->next = new Node(l->data);
		l = l->next;
		end = end->next;
	}
	while (r != nullptr) {
		end->next = new Node(r->data);
		r = r->next;
		end = end->next;
	}
	return head->next;
}
Node* mergeSort(Node* head)
{

	/* terminating condition */

	if (head == NULL || head->next == NULL)
		return head;


	Node* slowPtr = head, *fastPtr = head, *prev = NULL;


	while (fastPtr != NULL && fastPtr->next != NULL)
	{
		prev = slowPtr;
		slowPtr = slowPtr->next;
		fastPtr  = fastPtr->next->next;
	}

	/* split the list int two half */
	prev->next = NULL;

	Node* l1 = mergeSort(head);
	Node* l2 = mergeSort(slowPtr);

	return merge(l1, l2);
}


void printList(Node* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;

	head = new Node(5);
	head->next = new Node(4);
	head->next->next = new Node( 8);
	head->next->next->next = new Node( 6);
	head->next->next->next->next = new Node( 2);

	printList(head);

	head = mergeSort(head);

	printList(head);

	return 0;
}
// void merge(int arr[], int l, int m, int r)
// {
// 	int n1 = m - l + 1;
// 	int n2 = r - m;
// 	int L[n1], R[n2];

// 	for (int i = 0; i < n1; i++)
// 		L[i] = arr[l + i];
// 	for (int j = 0; j < n2; j++)
// 		R[j] = arr[m + 1 + j];

// 	int i = 0;
// 	int j = 0;
// 	int k = l;
// 	while (i < n1 && j < n2) {
// 		if (L[i] <= R[j]) {
// 			arr[k] = L[i];
// 			i++;
// 		}
// 		else {
// 			arr[k] = R[j];
// 			j++;
// 		}
// 		k++;
// 	}
// 	while (i < n1) {
// 		arr[k] = L[i];
// 		i++;
// 		k++;
// 	}
// 	while (j < n2) {
// 		arr[k] = R[j];
// 		j++;
// 		k++;
// 	}
// }

// void mergeSort(int arr[], int l, int r) {
// 	if (l >= r) {
// 		return;
// 	}
// 	int mid = l + (r - l) / 2;
// 	mergeSort(arr, l, mid);
// 	mergeSort(arr, mid + 1, r);
// 	merge(arr, l, mid, r);
// }
// void printArr(int arr[], int n) {
// 	for (int i = 0; i < n; ++i) {
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }
