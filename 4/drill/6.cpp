#include "../../std_lib_fac.h"
int main() 
{
	vector<string> values { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	cout << "Введите цифру для преобразование в строкое представление\n";
	int number { 0 };
	cin >> number;
	cout << number << " равно " << values[number] << '\n';
	cout << "Введи строкое представление числа для преобразование в цифру\n";
	string string_value { "" };
	cin >> string_value;
	for (int i = 0; i < values.size(); ++i)
		if (string_value == values[i])
			cout << string_value << " равно " << i << '\n';
}
