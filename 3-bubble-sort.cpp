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


void print_array(int arr[], size_t size){
	for (int i = 0; i< size; i++){
		std::cout << arr[i] << ' ';
	}
}

int main(){
	srand(time(NULL));
	int ar[10];
	for (int i = 0; i < 10; i++)
		ar[i] = rand();

	for(int e: ar){
		std::cout << e << ' ';
	}
	std::cout << "Is sorted: " << is_sorted(ar, sizeof(ar)/sizeof(ar[0])) <<'\n';

	
	m1sort(ar,sizeof(ar)/sizeof(ar[0]));

	
	for(int e: ar){
		std::cout << e << ' ';
	}
	std::cout << '\n';
}
