#include "../../std_lib_fac.h"
int main()
try {
	cout << "1Success!\n";
	cout << "2Success!\n";
	cout << "3Success" << "!\n";
	cout << "4Success!" << '\n';
	//5
	string res5 = "7";
	vector<string> v5(10);
	v5[5] = res5;
	cout << "5Success!\n";
	//6
	vector<int> v6(10);
	v6[5] = 7;
	if (v6[5] == 7)
		cout << "6Success!\n";
	//7
	if (true)
		cout << "7Success!\n";
	else
		cout << "Fail!\n";
	//8
	bool c8 = false;
	if (!c8)
		cout << "8Success!\n";
	else
		cout << "Fail!\n";
	//9
	string s9 = "ape";
	bool c = "fool" > s9;
	if (c) 
		cout << "9Success!\n";
	//10
	string s10 = "ape";
	if (s10 != "fool")
		cout << "10Success!\n";
	//11
	string s11 = "ape";
	if (s11 != "fool")
		cout << "11Success!\n";
	//12
	string s12 = "ape";
	if (s12 != "fool")
		cout << "12Success!\n";
	//13
	vector<char> v13(5);
	for (int i = 0; i < v13.size(); ++i);
		cout << "13Success!\n";
	//14
	vector<char> v14(5);
	for (int i = 0; i <= v14.size(); ++i);
		cout << "14Success!\n";
	//15
	string s15 = "15Success!\n";
	for (int i = 0; i < 11; ++i)
		cout << s15[i];
	//16
	if (true)
		cout << "16Success!\n";
	else 
		cout << "Fail!\n";
	//17
	int x17 = 2000;
	int c17 = x17;
	if (c17 == 2000)
		cout << "17Success!\n";
	//18
	string s18 = "18Success!\n";
	for (int i = 0; i < 11; ++i)
		cout << s18[i];
	//19
	vector<int> v19(5);
	for (int i = 0; i < v19.size(); ++i);
		cout << "19Success!\n";
	//20
	int i20 = 0;
	int j20 = 9;
	while (i20 < 10)
		++i20;
	if (j20 < i20)
		cout << "20Success!\n";
	//21
	int x21 = 2;
	double d21 = 5 / (x21 - 2.0);
	if (d21 != 2 * x21 + 0.5)
		cout << "21Success!\n";
	//22
	string s22 = "22Success!\n";
	for (int i = 0; i <= 10; ++i)
		cout << s22[i];
	//23
	int i23 = 0;
	int j23 = 0;
	while (i23 < 10)
		++i23;
	if (j23 < i23)
		cout << "23Success!\n";
	//24
	int x = 4;
	double d = 5.0 / (x - 2);
	if (d != 2 + x * 0.5)
		cout << "24Success!\n";
	//25
	cout << "25Success!\n";		
}
catch (exception& e) {
	cerr << "Ошибка: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Неизвестное исключение!\n";
	keep_window_open();
	return 2;
}
