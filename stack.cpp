#include<iostream>
using namespace std;

template<typename T>
class stack
{
public:
	stack();
	~stack();
	void push(T value);
	void pop();
	T top();
	bool empty();

private:
	T* data;
	unsigned int cap;
	unsigned int idx;
};


template<typename T>
stack<T>::stack()
{
	data = new T[100];
	cap = 100;
	idx = 0;
}

template<typename T>
stack<T>::~stack()
{
	delete []data;
	cap = 0;
	idx = 0;
	data = NULL;
}

template<typename T>
void stack<T>::push(T value)
{
	data[idx] = value;
	idx++;
}

template<typename T>
T stack<T>::top()
{
	return data[idx-1];
}

template<typename T>
void stack<T>::pop()
{
	idx--;
}

template<typename T>
bool stack<T>::empty()
{
	return (idx==0);
}

int main()
{
	stack<int> s;
	s.push(5);
	s.push(7);
	int d1 = s.top();
	cout<<d1<<endl;

	return 0;
}
