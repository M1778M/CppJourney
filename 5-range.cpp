#include <iostream>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <optional>

class From {
public:
    static const char CHAR_A = 'A'; static const char CHAR_B = 'B'; static const char CHAR_C = 'C'; static const char CHAR_D = 'D'; static const char CHAR_E = 'E'; static const char CHAR_F = 'F'; static const char CHAR_G = 'G'; static const char CHAR_H = 'H'; static const char CHAR_I = 'I'; static const char CHAR_J = 'J'; static const char CHAR_K = 'K'; static const char CHAR_L = 'L'; static const char CHAR_M = 'M'; static const char CHAR_N = 'N'; static const char CHAR_O = 'O'; static const char CHAR_P = 'P'; static const char CHAR_Q = 'Q'; static const char CHAR_R = 'R'; static const char CHAR_S = 'S'; static const char CHAR_T = 'T'; static const char CHAR_U = 'U'; static const char CHAR_V = 'V'; static const char CHAR_W = 'W'; static const char CHAR_X = 'X'; static const char CHAR_Y = 'Y'; static const char CHAR_Z = 'Z'; static const char CHAR_a = 'a'; static const char CHAR_b = 'b'; static const char CHAR_c = 'c'; static const char CHAR_d = 'd'; static const char CHAR_e = 'e'; static const char CHAR_f = 'f'; static const char CHAR_g = 'g'; static const char CHAR_h = 'h'; static const char CHAR_i = 'i'; static const char CHAR_j = 'j'; static const char CHAR_k = 'k'; static const char CHAR_l = 'l'; static const char CHAR_m = 'm'; static const char CHAR_n = 'n'; static const char CHAR_o = 'o'; static const char CHAR_p = 'p'; static const char CHAR_q = 'q'; static const char CHAR_r = 'r'; static const char CHAR_s = 's'; static const char CHAR_t = 't'; static const char CHAR_u = 'u'; static const char CHAR_v = 'v'; static const char CHAR_w = 'w'; static const char CHAR_x = 'x'; static const char CHAR_y = 'y'; static const char CHAR_z = 'z';
};
class To{
public:
    static const char CHAR_A = 'A'; static const char CHAR_B = 'B'; static const char CHAR_C = 'C'; static const char CHAR_D = 'D'; static const char CHAR_E = 'E'; static const char CHAR_F = 'F'; static const char CHAR_G = 'G'; static const char CHAR_H = 'H'; static const char CHAR_I = 'I'; static const char CHAR_J = 'J'; static const char CHAR_K = 'K'; static const char CHAR_L = 'L'; static const char CHAR_M = 'M'; static const char CHAR_N = 'N'; static const char CHAR_O = 'O'; static const char CHAR_P = 'P'; static const char CHAR_Q = 'Q'; static const char CHAR_R = 'R'; static const char CHAR_S = 'S'; static const char CHAR_T = 'T'; static const char CHAR_U = 'U'; static const char CHAR_V = 'V'; static const char CHAR_W = 'W'; static const char CHAR_X = 'X'; static const char CHAR_Y = 'Y'; static const char CHAR_Z = 'Z'; static const char CHAR_a = 'a'; static const char CHAR_b = 'b'; static const char CHAR_c = 'c'; static const char CHAR_d = 'd'; static const char CHAR_e = 'e'; static const char CHAR_f = 'f'; static const char CHAR_g = 'g'; static const char CHAR_h = 'h'; static const char CHAR_i = 'i'; static const char CHAR_j = 'j'; static const char CHAR_k = 'k'; static const char CHAR_l = 'l'; static const char CHAR_m = 'm'; static const char CHAR_n = 'n'; static const char CHAR_o = 'o'; static const char CHAR_p = 'p'; static const char CHAR_q = 'q'; static const char CHAR_r = 'r'; static const char CHAR_s = 's'; static const char CHAR_t = 't'; static const char CHAR_u = 'u'; static const char CHAR_v = 'v'; static const char CHAR_w = 'w'; static const char CHAR_x = 'x'; static const char CHAR_y = 'y'; static const char CHAR_z = 'z';
};


template <typename T>
class Range{
	private:
		unsigned long int current_index = 0;
		unsigned long int last_index;
		bool iterated=false;
		T *range;
		T rng_st;
		T rng_end;
		T rng_step;
	public:
		Range(T range_start, T range_end, T range_step){
			range = (T*)malloc((range_end/range_step)*sizeof(T));
			this->rng_st = range_start;
			for (int i = (int)range_start; i < (int)range_end; i+=(int)range_step)
			{
				*(this->range+i) = i;
			}
			this->last_index = (unsigned long int)range_end/range_step;
			this->rng_end = range_end;
			this->rng_step = range_step;
		}
		Range(T range_start, T range_end){
			range = (T*)malloc(range_end*sizeof(T));
			this->rng_st = range_start;
			for (int i = (int)range_start; i < (int)range_end; i++)
			{
				*(this->range+i) = i;
			}
			this->last_index = (unsigned long int)range_end;
			this->rng_end = range_end;
			this->rng_step = (T)1;
		}
		Range(T range_end){
			range = (T*)malloc(range_end*sizeof(T));
			this->rng_st = 0;
			for (int i = 0; i < (int)range_end; i++)
			{
				*(this->range+i) = i;
			}
			this->last_index = (unsigned long int)range_end;
			this->rng_end = range_end;
			this->rng_step = (T)1;
		}

		void call(std::function<void(T)> callback){
			for (auto i: this->resort()){
				callback(i);
			}
		}


		T *begin(){
			return this->range+this->rng_st;
		}

		T *end(){
			return this->range+this->last_index;
		}

		std::vector<T> resort(){
			std::vector<T> _temp;
			for (T i = (int)this->rng_st;i < (int)this->rng_end;i+=(int)this->rng_step)
				_temp.push_back(i);
			return _temp;
		}

		static std::vector<T> create(T range_start, T range_end, T range_step){
			std::vector<T> _temp;
			for (auto i = range_start; i < range_end; i+=range_step)
				_temp.push_back(i);
			return _temp;
			
		}

		static std::vector<T> create(T range_start, T range_end){
			std::vector<T> _temp;
			for (auto i = range_start; i < range_end; i++)
				_temp.push_back(i);
			return _temp;
			
		}
		static std::vector<T> create(T range_end){
			std::vector<T> _temp;
			for (auto i = 0; i < range_end; i++)
				_temp.push_back(i);
			return _temp;
			
		}

		std::optional<T> next(){
			if (this->iterated){
				if (current_index+1 > last_index){
					this->iterated = false;
					this->current_index = 0;
					return std::nullopt;
					}
				return *(range+ ++current_index);
			} else {
				this->iterated = true;
				return *range;
			}
		}
		~Range(){
			free(this->range);
		}
};

int main(){

	//for (auto i : Range(2, 10)){
	//	std::cout << i;
	//}
	
	// Range(0, 10).call(
	// [](int i){
	// 	std::cout << i;
	// });
	// for(auto i: Range<char>::create(From::CHAR_A,To::CHAR_Z))
	// 	std::cout << i << '\n';
	

	return 0;
}
