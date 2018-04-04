/*
 * podkovyrkin yefim
 * 07.03.2018
 * name saver and check uniq
 */
#include "../../std_lib_fac.h"
class Human {
	public:
	int age;
	string name;
};
int main() 
try
{
	vector<Human> humans;
	int age;
	string name;
	while ((cin >> name >> age) && name != "NoName" && age != 0) {
		humans.push_back(Human{age, name});
	}
	for (int i = 0; i < humans.size(); ++i)
		for (int j = i + 1; j < humans.size(); ++j)
			if (humans[i].name == humans[j].name)
				throw runtime_error("not uniq name");
	for (Human x : humans) 
		cout << x.name << ' ' << x.age << '\n';


}
catch(runtime_error& s) 
{
	cerr << "runtime error: " << s.what() << '\n';
	return 1;
}
catch(...) 
{
	cerr << "unhandled exception\n";
	return 2;
}

