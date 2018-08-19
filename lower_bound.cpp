//upper_bound: 找出非递减序列第一个大于等于key的位置
#include <iostream>
using namespace std;

int lower_bound(int arr[], int first, int size, int key) {
	int len = size, middle, half;
	while(len > 0) {
		half = len >> 1;
		middle = half + first;
		if(arr[middle] >= key) {	//在左半边序列中查找
			len = half;
		}
		else {		               //在右半边序列中查找
			len = len - half - 1;
			first = middle + 1;
		}
	}
	return first;
}

int main(int argc, char const *argv[]) {
	int arr[] = {1, 3, 3, 5, 6, 7, 7, 7, 9, 10};
	int size = sizeof(arr)/sizeof(int);
	for(int i = 0; i < size; ++ i) {
		cout << arr[i] << " ";
	}
	cout << "\n找出非递减序列第一个大于等于3的位置: " << lower_bound(arr, 0, size, 3) + 1 << endl;
	return 0;
}