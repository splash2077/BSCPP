#include "../../std_lib_fac.h"
/*
 * Podkovyrkin E. programmer
 * 08.03.2018
 * english grammer checker
*/
/*
sentence
	complex_noun verb .
	sentence conjunction sentece .
complex_noun
	noun
	the noun
noun
	birds
	fish
	c++
verb
	fly
	rules
	swim
conjunction
	and
	or 
	but
*/
class Token {
	public:
		string val;
};
class Token_stream {
	private:
		bool full {false};
		Token buffer;
	public:
		Token get_token();
		void putback(Token);
};
Token Token_stream::get_token()
{
	if (full) {
		full = false;
		return buffer;
	}
	string s;
	cin >> s;
	return Token{s};
}
void Token_stream::putback(Token t)
{
	if (!full) {
		buffer = t;
		full = true;
	}
	else
		throw runtime_error("full buffer");
}
Token_stream ts;
vector<string> nouns {"birds", "fish", "c++"};
vector<string> verbs {"fly", "rules", "swim"};
vector<string> conjunctions {"and", "or", "but"};
bool sentence();
bool complex_noun();
bool noun();
bool verb();
bool conjunction();
bool sentence() 
{
	if (!complex_noun())
		return false;
	if (!verb())
		return false;
	Token t;
	t = ts.get_token();
	if (t.val == ".") 
		return true;
	ts.putback(t);
	if (!conjunction())
		return false;
	return sentence();
}
bool complex_noun()
{
	Token t;
	t = ts.get_token();
	if (t.val == "the")
		return noun();
	ts.putback(t);
	return noun();
}
bool noun() 
{
	Token t;
	t = ts.get_token();
	for (string x : nouns)
		if (t.val == x)
			return true;
	return false;
}
bool verb()
{
	Token t;
	t = ts.get_token();
	for (string x : verbs)
		if (t.val == x)
			return true;
	return false;
}
bool conjunction()
{
	Token t;
	t = ts.get_token();
	for (string x : conjunctions)
		if (t.val == x)
			return true;
	ts.putback(t);
	return false;
}

int main()
try
{
	while (cin) {

		if (sentence())
			cout << "Valid english sentence\n";
		else
			cout << "Invalid english sentence\n";
	}
}
catch(exception& s)
{
	cerr << "runtime exception" << s.what() << '\n';
	return 1;
}
catch(...)
{
	cerr << "Unhandled exception\n";
	return 2;
}

