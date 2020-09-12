#include <iostream>
using namespace std;


#define SIZE 10


template <class X>
class stack
{
	X *arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);	
	void push(X);
	X pop();
	X peek();

	int size();
	bool empty();
	bool isFull();
};


template <class X>
stack<X>::stack(int size)
{
	arr = new X[size];
	capacity = size;
	top = -1;
}


template <class X>
void stack<X>::push(X x)
{
	if (isFull())
	{
		cout << "Stack overflow!\n";
		
	}

	
	arr[++top] = x;
}


template <class X>
X stack<X>::pop()
{
	
	if (empty())
	{
		cout << "stack underflow!\n\n";
	
	}

	

	return arr[top--];
}

template <class X>
X stack<X>::peek()
{
	if (!empty())
		return arr[top];
	else
		cout<<"Stack is empty!\n";
}

template <class X>
int stack<X>::size()
{
	return top + 1;
}

template <class X>
bool stack<X>::empty()
{
	return top == -1;	
}

template <class X>
bool stack<X>::isFull()
{
	return top == capacity - 1;	
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
bool isOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/'||C== '%')
		return true;

	return false;
}
         
 void avi(string postfix)
 { int may[100];
    stack <int> k;
     for(int i=0;i<postfix.length();i++)
    
    {
         if(isOperand(postfix[i]))
      { 
           cout<<"\nEnter the values of :"<<postfix[i]<<endl;
           cin>>may[i];
           k.push(may[i]);
      }
         else if(isOperator(postfix[i]))
     {   int a,b;
             
            if(postfix[i] == '+') 
        {   a=k.pop();
            b=k.pop();
             k.push(b+a);
        }
	else if(postfix[i] == '-') 
    	{a=k.pop();
         b=k.pop();
        k.push(b-a);
	    }
	else if(postfix[i] == '*')
	    { a=k.pop();
            b=k.pop();
	    k.push(b*a);
    	}
	else if(postfix[i] == '/')
	    { a=k.pop();
            b=k.pop();
	    k.push(b/a);
	    }
	    else if(postfix[i] == '%')
	    { a=k.pop();
            b=k.pop();
	    k.push(b%a);
	    }
    }
 }
   int result=k.peek();
    cout<<"Your result is:\n"<<result<<"\n";
 }
string post_to_in(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isOperand(postfix[i])) {
            string op(1, postfix[i]);
            
            s.push(op);
        }
        else {
            string op1 = s.peek();
            s.pop();
            string op2 = s.peek();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
 
    return s.peek();
}
 
int main()
{
 
    string infix, postfix;
    cout << "Enter a POSTFIX Expression :" << endl;
    cin >> postfix;
    cout << "POSTFIX EXPRESSION: " << postfix << endl;
    infix = post_to_in(postfix);
    cout << "\nINFIX EXPRESSION: " << infix<<endl;
 avi(postfix);
    return 0;
}

