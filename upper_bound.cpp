//upper_bound: 找出非递减序列第一个大于val的位置
#include <iostream>
#include <cstring>
using namespace std;

int upper_bound(int arr[], int first, int size, int key) {
	int len = size;
	int middle, half;
	while(len > 0) {
		half = len >> 1;
		middle = first + half;
		if(arr[middle] > key) {  //中位数大于key，在左半边查找
			len = half;
		}
		else {			//中位数小于等key，在右半边查找
			first = middle + 1;		
			len = len - half - 1;
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
	cout << "\n找出非递减序列第一个大于7的位置: " << upper_bound(arr, 0, size, 7) + 1 << endl;
	return 0;
}