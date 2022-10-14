/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Daniel Tolsky
 * Date: 14/10/2022
 */

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

///////////////
// TokenType //
//           //////////////////
//  symbols:  +, -, *, /, (, )
// literals:  integer
//  special:  eof, err
///////////////////////////////
typedef enum { pltok, mitok, asttok, slashtok, lptok, rptok, integer, errtok, eof }
TokenType ;


//---------//
//  Token  //
//---------//
class Token 
{
    public:
        TokenType tt;
        string text;
        int val;
};


// Description: Display a Token
ostream &operator<<(ostream &lhs, Token &rhs);


// Description: Token scanner.  Given an input stream, will return a sequence
//       of Tokens via successive calls to .getnext();
class Scanner 
{
    private:
        int line;
        istream *str;
        char buf[2];
    public:
        Scanner(istream &str);
        Token getnext();
};

template <class T>
class Stack 
{
    class Node 
    {
        public: 
            T data;
            Node *next;
    };

    private:
        Node* head;

    public:
        Stack();
        ~Stack();
        void push(T x);
        T pop();
        T peek();
        bool isEmpty();
};



////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


template <class T> 
Stack<T>::Stack() 
{
    head = NULL;
}


template <class T> 
void Stack<T>::push(T x) 
{
    Node *newhead = new Node;
    newhead->data = x;
    newhead->next = head;
    head = newhead;
}


template <class T> 
T Stack<T>::pop() 
{
    T ret = head->data;
    Node *old_head = head;
    head = head->next;
    delete old_head;
    return ret;
}


template <class T> 
T Stack<T>::peek() 
{
    return head->data;
}


template <class T> 
bool Stack<T>::isEmpty() 
{
    return (head == NULL);
}


template <class T> 
Stack<T>::~Stack() 
{
    Node *p = head;
    while (p != NULL) 
    {
        head = head->next;
        delete p;
        p = head;
    }
}


// Description:  Util:  string + char
string operator+(string &lhs, char &rhs) 
{
    char c[2]; c[0] = rhs; c[1] = 0;
    return lhs+c;
}


// Description:  Display a Token
ostream &operator<<(ostream &os, Token &rhs) 
{
    if (rhs.tt == eof) os << "eof";
    else if (rhs.tt == errtok) os << "err";
    else if (rhs.tt == integer) os << rhs.val;
    else os << rhs.text;

    return os;
} 


// Description:  Constructor
Scanner::Scanner(istream &str) 
{
    this->str = &str;
    buf[0] = buf[1] = 0;
}


// Description:  Util:  Test for newline
int newl(char c) { return (c == '\n'); }


// Description:  Return the next token
Token Scanner::getnext() 
{
    Token ret; ret.text = "";
    if (buf[0] == 0) { buf[0] = str->get(); }


    // collapse whitespace
    while (isspace(buf[0]) || (buf[0] == 13) || (buf[0] == '\n')) 
    {
        buf[0] = str->get(); 
        if (str->eof()) break;
    }


    // case 1: eof    
    if (str->eof()) { ret.tt = eof; ret.text = ""; return ret; }


    // case 2: numerical-   [0-9]+
    if (isdigit(buf[0])) 
    {
        ret.tt = integer; ret.text = buf;
        buf[0] = str->get();
        while (isdigit(buf[0])) 
        {
            ret.text += buf;
            buf[0] = str->get();
        }
        ret.val = stod(ret.text, NULL);
        if (isspace(buf[0]) || (buf[0] == 13) || (buf[0] == '\n')) buf[0] = 0;
        return ret;
    }


    // case 3: symbol
    ret.text = buf; 
    if (buf[0] == '+') { ret.tt = pltok; buf[0] = 0; }
    else if (buf[0] == '-') { ret.tt = mitok; buf[0] = 0; }
    else if (buf[0] == '*') { ret.tt = asttok; buf[0] = 0; }
    else if (buf[0] == '/') { ret.tt = slashtok; buf[0] = 0; }
    else if (buf[0] == '(') { ret.tt = lptok; buf[0] = 0; }
    else if (buf[0] == ')') { ret.tt = rptok; buf[0] = 0; }
    else { ret.tt = errtok; buf[0] = 0; }
    return ret;
}


int operate(Token, int, int);
void performOp(Stack <Token>&, Stack <Token>&, Token&);

int main ()
{
    Scanner S(cin);
    Token t;

    Stack <Token> numstack, opstack;  // 2x Stacks of type Token
    
    t = S.getnext();

    while (t.tt != eof || !opstack.isEmpty())
    {
        if (t.tt == integer)
        {
            numstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == lptok)
        {
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok)
            {
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                performOp(numstack, opstack, t);
            }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            if (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok 
            || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                performOp(numstack, opstack, t);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if (t.tt == asttok || t.tt == slashtok)
        {
            if (!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                performOp(numstack, opstack, t);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }

    cout << '\n' << numstack.peek().val << endl;

    system("pause");
}

void performOp(Stack <Token>& nums, Stack <Token>& ops, Token& t) //function which completes the operation of two integers and does stack manipulation
{
    int num1 = nums.pop().val;
    int num2 = nums.pop().val;
    Token op = ops.pop();

    t.val = operate(op, num2, num1);
    nums.push(t);
}

int operate(Token op, int a, int b) //function which returns result of various operations
{
    if (op.tt == pltok)
    {
        return (a + b);
    }
    else if (op.tt == mitok)
    {
        return (a - b);
    }
    else if (op.tt == asttok)
    {
        return (a * b);
    }
    else if (op.tt == slashtok)
    {
        return (a / b);
    }
    else
    {
        logic_error("ERROR: operate(), operator token invlaid");
    }
    return -1; // to get rid of compilation warning
}