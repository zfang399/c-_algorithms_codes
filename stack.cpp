#include<iostream>
#include<cstdio>
using namespace std;

class stack{
	private:
		enum {MAX=10};
		int items[MAX];
		int top;
	public:
		stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const int &item);
		bool pop(int &item);
};
stack::stack()
{
	top=0;
}
bool stack::isempty() const
{
	return top==0;
}
bool stack::isfull() const
{
	return top==MAX;
}
bool stack::push(const int &item)
{
	if (top<MAX)
	{
		top++;
		items[top]=item;
		return true;
	}
	else return false;
}
bool stack::pop(int &item)
{
	if(top!=0)
	{
		item=items[top];
		top--;
		return true;
	}
	else return false;
}

int main()
{
	stack s();
	
	return 0;
}

