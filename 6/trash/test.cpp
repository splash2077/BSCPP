#include "../std_lib_fac.h"

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

class Token_stream {
	public:
		Token_stream() : full (false), buffer(0) {}
		Token get_token();
		void putback(Token t);
	private:
		bool full {false};
		Token buffer;
};

Token_stream ts;


double expression();  // read and evaluate a Expression
double term();        // read and evaluate a Term
double primary();    // read and evaluate a Primary

int main()
try {
	double val { 0 };
	while (cin) {
		Token t = ts.get_token();
		if (t.kind == 'q')
			break;
		if (t.kind == ';')
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open ("~1");
    return 1;
}
catch (...) {
    cerr << "exception\n";
    keep_window_open ("~2");
    return 2;
}

//------------------------------------------------------------------------------
double primary()     // read and evaluate a Primary
{
    Token t = ts.get_token();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get_token();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get_token();     // get the next token
    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get_token();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get_token();
            break;
        default:
	    ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double term()
{
    double left = primary();
    Token t = ts.get_token();     // get the next token

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get_token();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get_token();
                break;
            }
        default: 
	    ts.putback(t);
            return left;
        }
    }
}
void Token_stream::putback(Token t) 
{
	if (full)
		throw runtime_error("buffer is full");
	buffer = t;
	full = true;
}

Token Token_stream::get_token()
{
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch(ch) {
		case 'q' : case ';' : case '(' : case ')' :
		case '+' : case '-' : case '*' : case '/' :
			return Token{ch};
		case '.':
	        case '0': case '1' : case '2' : case '3' : case '4' : 
		case '5': case '6' : case '7' : case '8' : case '9' :
			{
				cin.putback(ch);
				double val;
				cin >> val;
				return Token {'8', val};
			}
		default:
			throw runtime_error("bad token");
	}
}
//------------------------------------------------------------------------------
