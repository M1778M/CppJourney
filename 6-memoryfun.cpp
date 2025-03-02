#include <iostream>


template <typename T>
void drop(T *&ptr){
	delete[] ptr;
	ptr = nullptr;
}

template <typename T>
T *sizedArray(size_t size){
	return new T[size];
}

int main(){
	int *arr = sizedArray<int>(10);

	std::fill(arr, arr+10, 4);

	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << ' ';
	
	drop(arr);
	if (arr){
		std::cout << "exists";
	} else {
		std::cout << "dont exists";
	}
	return 0;
}
