#include <iostream>
#include <stdlib.h>

template <typename T> size_t lenof(T arr[]){
	return sizeof(arr)/sizeof(arr[0]);
}
template <typename U> int lenof(U *arr){
	return sizeof(arr)/sizeof(arr[0]);
}

int main(){
	char a[] = {'H','e','l','l','o'};
	int x[] = {1,2,3,4,5};
	std::string s[] = {"Yo bro","Look","at", "me","lol"};
	
	int *ptr = (int*)malloc(1024);
	
	std::cout << "Len of char a -> " << lenof(*ptr) << '\n';
	
	free(ptr);
}
