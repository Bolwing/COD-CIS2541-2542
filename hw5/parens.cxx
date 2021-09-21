// FILE: parens.cxx
// A small demonstration program for a stack.
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <iostream>    // Provides cin, cout
#include <stack>       // Provides stack
#include <string>      // Provides string
using namespace std;

// PROTOTYPE for a function used by this demonstration program
bool is_balanced(const string& expression);
bool isNested(const string& expression);
// Postcondition: A true return value indicates that the parentheses in the
// given expression are balanced. Otherwise, the return value is false.

int main()
{

    string user_input;
    ifstream myfile("hw5test.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, user_input))
        {
            cout << user_input << '\n' << endl;
            if (is_balanced(user_input))
                cout << "Those parentheses are balanced.\n";
            else
                cout << "Those parentheses are not balanced.\n";

            cout << "That ends this balancing act.\n";

            if (isNested(user_input)) {
                cout << "Those Parentheses are nested properly\n";
            }
            else
            {
                cout << "Those parentheses are nested improperly\n";
            }
            cout << "That ends this nesting act.\n";

            //return EXIT_SUCCESS;
        }
        myfile.close();
    }


    return EXIT_SUCCESS;
}

bool is_balanced(const string& expression)
// Library facilities used: stack, string
{
    // Meaningful names for constants
    const char LEFT_PARENTHESIS = '(';
    const char RIGHT_PARENTHESIS = ')';
    const char LEFT_BRACKET = '[';
    const char RIGHT_BRACKET = ']';
    const char LEFT_SQUIGGLY = '{';
    const char RIGHT_SQUIGGLY = '}';

    int failcount = 0;

    stack<char> store;    // Stack to store the left parentheses as they occur
    string::size_type i;  // An index into the string
    char next;            // The next character from the string
    bool afailed = false;  // Becomes true if a needed parenthesis is not found
    bool bfailed = false;
    bool cfailed = false;

    for (i = 0; !afailed  &&  (i < expression.length( )); ++i)
    {
        next = expression[i];
        if (next == LEFT_PARENTHESIS)
            store.push(next);
        else if ((next == RIGHT_PARENTHESIS) && (!store.empty( )))
            store.pop( ); // Pops the corresponding left parenthesis.
        else if ((next == RIGHT_PARENTHESIS) && (store.empty( )))
            afailed = true;
        //cout << "Parens Balanced ?      " << afailed << endl;
    }

    //return (store.empty( ) && !afailed);
    if (!(store.empty() && !afailed)) {
        failcount++;
    }

    for (i = 0; !bfailed && (i < expression.length()); ++i)
    {
        next = expression[i];
        if (next == LEFT_BRACKET)
            store.push(next);
        else if ((next == RIGHT_BRACKET) && (!store.empty()))
            store.pop(); // Pops the corresponding left parenthesis.
        else if ((next == RIGHT_BRACKET) && (store.empty()))
            bfailed = true;
        //cout << "Brackets Balanced ?      " << bfailed << endl;
    }

    //return (store.empty() && !bfailed);
    if (!(store.empty() && !bfailed)) {
        failcount++;
    }

    for (i = 0; !cfailed && (i < expression.length()); ++i)
    {
        next = expression[i];
        if (next == LEFT_SQUIGGLY)
            store.push(next);
        else if ((next == RIGHT_SQUIGGLY) && (!store.empty()))
            store.pop(); // Pops the corresponding left parenthesis.
        else if ((next == RIGHT_SQUIGGLY) && (store.empty()))
            cfailed = true;
        //cout << "Squiggly Balanced ?    " << cfailed << endl;
    }

    //return (store.empty() && !cfailed);
    if (!(store.empty() && !cfailed)) {
        failcount++;
    }

    if (failcount != 0) {
        return false;
    }
    else {
        return true;
    }


}
bool isNested(const string& expression)
{
    stack<char> store;
    char next;
    
    for (int i = 0; i < expression.length(); i++)
    {

        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            store.push(expression[i]);
            continue;
        }

        if (store.empty())
            return false;

        switch (expression[i])

        {

        case ')':

            next = store.top();
            store.pop();
            if (next == '{' || next == '[')
                return false;
            break;

        case '}':

            next = store.top();
            store.pop();
            if (next == '(' || next == '[')
                return false;
            break;

        case ']':

            next = store.top();
            store.pop();
            if (next == '(' || next == '{')
                return false;
            break;
        }
    }
    return (store.empty());
}
