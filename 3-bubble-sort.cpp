#include <iostream>
#include <ctime>

bool is_sorted(int arr[], size_t size){
	for (int i = 0; i < size; i++){
		if (!(arr[i] < arr[i+1])){
			return false;
		}
	}
	return true;
}


void m1sort(int arr[], size_t size){
	if (is_sorted(arr, size))
		return;
	int ind = 0;
	int temp;
	while (!is_sorted(arr, size)){
		// print_array(arr,size);
		// std::cout << '\n';
		if (ind > size)
			ind = 0;
		if (arr[ind] > arr[ind+1]){
			temp = arr[ind+1];
			arr[ind+1] = arr[ind];
			arr[ind] = temp;
			ind++;
		} else
			ind++;
	}
}

void bubblesort(int arr[], size_t size){
	int temp;
	for(int i = 0; i < size - 1; i++){
		for (int j = i; j < size - 1; j++)
			if (arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}
}


void print_array(int arr[], size_t size){
	for (int i = 0; i< size; i++){
		std::cout << arr[i] << ' ';
	}
}

int main(){
	srand(time(NULL));
	int ar[10000];// = {3,5,7,2,1,3,7,9};
	for (int i = 0; i < 10000; i++)
		ar[i] = rand();

	// for(int e: ar){
	// 	std::cout << e << ' ';
	// }
	std::cout << '\n';
	
	// m1sort(ar,sizeof(ar)/sizeof(ar[0]));
	bubblesort(ar, sizeof(ar)/sizeof(ar[0]));
 
	// for(int e: ar){
	// 	std::cout << e << ' ';
	// }
	std::cout << '\n';
}
