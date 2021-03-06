#include <iostream>
using namespace std;
int main() 
{
	constexpr double inch { 2.54 };
	constexpr double ft { 12 * inch };
	constexpr double meter { 100 };
	double min = { 0 };
	double max = { min };
	double temp = { 0 };
	int count { 0 };
	double sum { 0 }; //should show in meters;
	string measurement { "???" };
	std::cout << "Введите значение в сантиметрах, метрах, футах, дюймах\n";
	while (cin >> temp >> measurement) {
		if (measurement == "cm");
		else if (measurement == "m")
			temp *= meter;
		else if (measurement == "ft")
			temp *= ft;
		else if (measurement == "in")
			temp *= inch;
		else {
			std::cout << "Значение не считанно\n";
			continue;
		}
		if (temp < min) {
			min = temp;
			std::cout << temp << " Наименьшее среди введенных\n";
		}
		else if (temp > max) {
			max = temp;
			std::cout << temp << " Наибольшее среди введенных\n";
		}	
		else 
			std::cout << temp << '\n';
		sum += temp;
		++count;
	}
	std::cout << "Number of elements: " << count
	     << "\nSum of elements in meters: " << sum / meter
	     << "\nMax element: " << max
	     << "\nMin element: " << min << '\n';
	
}
