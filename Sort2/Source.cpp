#include "Header.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(){
	srand(time(0));
	int size = 100000;
	int* arr = new int[size];
	
	for (int i = 0; i < size; i++){
		arr[i] = rand();
	}
	int time = clock();
	if (!isSorted(arr, size)){
		sortRadix(arr, size);
		//sortCounting(arr, size);
	}
	int time2 = clock();
	cout << isSorted(arr, size) << endl;
	cout << time2-time << endl;
	//for (int i = 0; i < size; i++){
	//	cout << arr[i] << " ";
	//}
		
  	system("pause");
}