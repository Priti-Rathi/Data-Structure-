
/*Expression conversion: Write a menu driven C++ program for expression 
conversion and evaluation 
1. infix to prefix
2. prefix to postfix
3. prefix to infix
4. postfix to infix 
5. postfix to prefix*/
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPrefix(stack<char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((s.top() != '(') && (!s.empty())) {
                prefix += s.top();
                s.pop();
            }

            if (s.top() == '(') {
                s.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (s.empty()) {
                s.push(infix[i]);
            }
            else {
                if (precedence(infix[i]) > precedence(s.top())) {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top()))
                    && (infix[i] == '^')) {
                    while ((precedence(infix[i]) == precedence(s.top()))
                        && (infix[i] == '^')) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.top())) {
                    s.push(infix[i]);
                }
                else {
                    while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top()))) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}	
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}


string PrefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            string op(1, prefix[i]);
            //string op = prefix[i];
            s.push(op);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}

string PostfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isOperand(postfix[i])) {
            string op(1, postfix[i]);
            //string op=postfix[i];
            s.push(op);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    return s.top();
}

string PostfixToPrefix(string postfix) {
  stack < string > s;
  for (int i = 0; i < postfix.length(); i++) {
    if (isOperand(postfix[i])) {
      string op(1, postfix[i]);
      s.push(op);
    } else {
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      s.push(postfix[i] + op2 + op1);
    }
  }
  return s.top();
}

string PrefixToPostfix(string prefix) {
  stack < string > s;
  for (int i = prefix.length() - 1; i >= 0; i--) {
    if (isOperand(prefix[i])) {
      string op(1, prefix[i]);
      s.push(op);
    } else {
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      s.push(op1 + op2 + prefix[i]);
    }
  }

  return s.top();
}
int main()
{
    int ch;
    do{
    cout<<"\nEnter the correct choice"<<endl;
    cout<<"1.infix to prefix\n2Infix to Postfix\n3.prefix to infix\n4.postfix to infix\n5.postfix to prefix\n6.prefix to postfix\n7.Exit"<<endl;
    cin>>ch;
    stack<char> stack;
    switch(ch)
{
    case 1: {
        string infix, prefix;
        cout << "\nEnter an Infix Expression: " << endl;
        cin >> infix;
        cout << "INFIX EXPRESSION: " << infix << endl;
        prefix = InfixToPrefix(stack, infix);
        cout << endl << "PREFIX EXPRESSION: " << prefix;
        break;
    }

    case 2: {
        string infix_exp, postfix_exp;
        cout << "\nEnter an Infix Expression: " << endl;
        cin >> infix_exp;
        cout << "INFIX EXPRESSION: " << infix_exp << endl;
        postfix_exp = InfixToPostfix(stack, infix_exp);
        cout << endl << "POSTFIX EXPRESSION: " << postfix_exp;
        break;
    }

    case 3: {
        string infix, prefix;
        cout << "Enter a PREFIX Expression: " << endl;
        cin >> prefix;
        cout << "PREFIX EXPRESSION: " << prefix << endl;
        infix = PrefixToInfix(prefix);
        cout << endl << "INFIX EXPRESSION: " << infix;
        break;
    }

    case 4: {
        string postfix, infix;
        cout << "Enter a POSTFIX Expression: " << endl;
        cin >> postfix;
        cout << "POSTFIX EXPRESSION: " << postfix << endl;
        infix = PostfixToInfix(postfix);
        cout << endl << "INFIX EXPRESSION: " << infix;
        break;
    }

    case 5:
    {
    string prefix, postfix;
    cout << "Enter a POSTFIX Expression :" << endl;
    cin >> postfix;
    cout << "POSTFIX EXPRESSION: " << postfix << endl;
    prefix = PostfixToPrefix(postfix);
    cout << endl << "PREFIX EXPRESSION: " << prefix;
    break;
    }

    case 6:
    {
        string prefix, postfix;
    cout << "Enter a PREFIX Expression :" << endl;
    cin >> prefix;
    cout << "PREFIX EXPRESSION: " << prefix << endl;
    postfix = PrefixToPostfix(prefix);
    cout << endl << "POSTFIX EXPRESSION: " << postfix;
    break;
    }
    case 7:
    {
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
    }
    }while(ch!=7);

    return 0;
}