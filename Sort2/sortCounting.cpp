void sortCounting(int* &arr, int size){
	int min=arr[0],
		max=arr[0],
		length;
	for (int i = 1; i < size; i++){
		if (arr[i] < min){
			min = arr[i];
		}
		else{
			if (arr[i] > max)
				max = arr[i];
		}
	}
	length = max - min + 1;
	int* arr1 = new int[length];
	int* arr2 = new int[size];
	for (int i = 0; i < length; i++){
		arr1[i] = 0;
	}
	for (int i = 0; i < size; i++){
		arr1[arr[i] - min]++;
	}
	for (int i = 1; i < length; i++){
		arr1[i] += arr1[i-1];
	}
	for (int i = size - 1; i >= 0; i--){
		arr2[--arr1[arr[i] - min] - 1] = arr[i];
	}
	delete[] arr;
	delete[] arr1;
	arr = arr2;
}
