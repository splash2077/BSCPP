#include "../../std_lib_fac.h"
int main()
{
	vector<double> set_positive;//read data
	for (double temp; cin >> temp; ) 
		set_positive.push_back(temp);
	sort(set_positive);

	int max_series { 0 };//initi values
	int current_series { 0 };
	double mode { set_positive[0] };
	double previous { set_positive[0] };

	if (set_positive.size() > 0) {//find mode
		for (int i = 1; i < set_positive.size(); ++i) {
			if (previous == set_positive[i]) {
				++current_series;
				if (current_series > max_series) {
					mode = previous;
					max_series = current_series;
				}
			}
			else {
				current_series = 0;
				previous = set_positive[i];
			}
		}
	}

	else 
		cout << "Пустое множество\n";
	//cout values
	cout << "Мода: " << mode << " длинна серии равна " << max_series + 1 << '\n';
}

