#include "../../std_lib_fac.h"
int main() 
{
	char test { 'a' };
	constexpr int number_of_values_c { 256 };
	int i { 0 };
	while (i < number_of_values_c)
	{
		cout << char{ test + i } << ' ' << int{ char{ test + i } } << '\n';
		++i;
	}


}
