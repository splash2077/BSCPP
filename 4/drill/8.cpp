#include "../../std_lib_fac.h"
int main() 
{
	int current_cel { 1 }, summ { 1 };
	for (int i = 2; summ < 1'000'000'000; ++i) {
		current_cel *= 2;
		summ += current_cel;
		cout << current_cel << " зерен на " << i << " клетке и общая сумма " << summ << '\n'; 

	}
}


