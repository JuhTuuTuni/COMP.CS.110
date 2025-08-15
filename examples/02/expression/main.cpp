#include <iostream>

// Parse expressions following the grammar:
// <Expr> ::= <Term> + <Expr> | <Term> - <Expr> | <Term>
// <Term> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | ( <Expr> )

using namespace std;

// Forward declaration needed due to indirect recursion
bool parse_expr(int& value, unsigned int& index, const string& expr);

// Parse term:
// <Term> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | ( <Expr> )
bool parse_term(int& value, unsigned int& index, const string& expr)
{
    if(index >= expr.size())
    {
        cout << "Unexpected end of expression" << endl;
        return false;
    }

    // The rule choices: <Term> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
    if(isdigit(expr.at(index)))
    {
        value = expr.at(index) - '0';
        ++index; // skip digit
    }

    // The rule choice <Term> ::= ( <Expr> )
    else if(expr.at(index) == '(')
    {
        ++index; // skip left parenthesis
        bool ok = parse_expr(value, index, expr);
        if(not ok)
        {
            cout << "Syntax error from parse_expr" << endl;
            return false;
        }
        if(index >= expr.size() or expr.at(index) != ')')
        {
            cout << "Right parenthesis missing" << endl;
            return false;
        }
        ++index; // skip right parenthesis
    }

    else
    {
        cout << "Syntax error: A digit or parenthesis expected" << endl;
        return false;
    }

    return true;
}

// Parse expression:
// <Expr> ::= <Term> + <Expr> | <Term> - <Expr> | <Term>
bool parse_expr(int& value, unsigned int& index, const string& expr)
{
    bool ok = parse_term(value, index, expr);
    if(not ok)
    {
        return false; // Error message already given
    }

    while(index < expr.size())
    {
        char oper = expr.at(index);

        // The rule choice: <Expr> ::= <Term>
        if(oper != '+' and oper != '-')
        {
            return true;
        }

        // The rule choices: <Expr> ::= <Term> +/- <Expr>
        ++index; // skip operator (plus or minus)
        int value2 = 0;
        ok = parse_term(value2, index, expr);
        if(not ok)
        {
            return false; // Error message already given
        }
        if(oper == '+') // The rule choice: <Expr> ::= <Term> + <Expr>
        {
            value += value2;
        }
        else // if(oper == '-') // The rule choice: <Expr> ::= <Term> - <Expr>
        {
            value -= value2;
        }
    }

    return true;
}

int main()
{
    int value = 0;
    unsigned int index = 0;
    string expr = "";
    cout << "Enter an expression: ";
    getline(cin, expr);
    while(expr != "quit" and expr != "q")
    {
        bool ok = parse_expr(value, index, expr);
        if(ok and index < expr.size())
        {
            cout << "Extra characters after the end of expression" << endl;
        }
        else if(ok)
        {
            cout << "The value of expression " << expr << " is " << value
                 << endl;
        }
        cout << "Enter an expression: ";
        getline(cin, expr);
        index = 0;
    }
    return EXIT_SUCCESS;
}
