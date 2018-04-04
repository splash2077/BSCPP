/*
	I have inserted 3 logic errors that should cause the program to give wrong results
*/
#include "../../std_lib_fac.h"
int factorial(int x) 
{
	if (x == 0)
		return 1;
	for (int i = x - 1; i > 0; --i) 
		x *= i;
	return x;
}

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
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': case '}' : case '{' : 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
	    char factorial_check;
	    cin >> factorial_check;
	    if (factorial_check == '!')
		    return Token('8', factorial(val));
	    else
		    cin.putback(factorial_check);
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}


Token_stream ts;        // provides get() and putback() 


double expression();    // declaration so that primary() can call expression()
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
		    error("')' expected)");
            return d;
        }
    case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}')
			throw runtime_error("'}' expected)");
		return d;
	}
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
	    break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Добро пожаловать в программу калькулятор! Вводите выражения с числами с плавающей точкой.\n"
	 << "Доступные математические операции: +, -, *, /.\n" 
	 << "Чтобы выйти из программы введите 'x'\n";
    double val {0};
    while (cin) {
        Token t = ts.get();
        if (t.kind == 'x') break; // 'x' for quit
        if (t.kind == '=')        // '=' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
	keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------ 
