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
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK
using namespace std;

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