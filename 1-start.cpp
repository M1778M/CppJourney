#include <cstring>
#include <iostream>
#include <stdlib.h>

class PyInt{
	private:
		long long int val = 0;
	public:
		PyInt(long long ival){
			val = ival;
		}
		long long get_val(){
			return val;
		}
		bool set_val(long long int nval){
			val = nval;
			return true;
		}
};

class PyStr{
	private:
		char *str = (char*)malloc(1);
	public:
		PyStr(const char* initial_string){
			str = (char*)realloc(str, sizeof(char) * strlen(initial_string));
			memcpy(str,initial_string,sizeof(char) * strlen(initial_string));
		}
		PyStr(){}
		char *get_val(){
			return str;
		}

		bool set_val(const char* nstr){
			str = (char*)realloc(str, sizeof(char) * strlen(nstr));
			memcpy(str, nstr, sizeof(char) * strlen(nstr));
			return true;
		}
		std::string operator+(const char* other){
			str = (char*)realloc(str, sizeof(char) * strlen(other)+strlen(str));
			std::string temp;
			temp.append(str);
			temp.append(other);
			// memcpy(str,temp.data(),temp.length() * sizeof(char));
			return temp;
		}
		void operator+=(const char* other){
			str = (char*)realloc(str, sizeof(char) * strlen(other)+strlen(str));
			std::string temp;
			temp.append(str);
			temp.append(other);
			memcpy(str,temp.data(),temp.length() * sizeof(char));
		}
};


int main(){
	// PyInt x(100);
	// // x.set_val(100);
	// std::cout << x.get_val() << '\n';
	PyStr mystr("Hello");
	std::string result = mystr+" World";
	mystr+=" Yooo";
	std::cout << result << '\n';
	std::cout << mystr.get_val() << '\n';
	

	return 0;
}	
