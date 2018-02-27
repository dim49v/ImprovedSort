#include <iostream>
using namespace std;
void sortRadix(int* &arr, int size){
	int const N10 = 10;
	int max = arr[0];
	int	length = 1;
	for (int i = 1; i < size; i++){
		if (arr[i] > max)
			max = arr[i];
	}
	for (int d = 1; max / d > 0; length++, d *= 10)
		;
	int* arr1 = new int[N10];
	int* arr2 = new int[size];
	int* temp;
	
	for (int i = 0, d = 1; i <= length; i++, d *= 10){
		for (int j = 0; j < N10; j++){
			arr1[j] = 0;
		}
		for (int j = 0; j < size; j++){
 			arr1[arr[j] / d % 10]++;
		}
		for (int j = 1; j < N10; j++){
			arr1[j] += arr1[j - 1];
		}
		for (int j = size - 1; j >= 0; j--){
			arr2[arr1[arr[j] / d % 10] - 1] = arr[j];
			arr1[arr[j] / d % 10]--;
		}
		temp = arr;
		arr = arr2;
		arr2 = temp;
	}
	delete[] arr2;
	delete[] arr1;
}