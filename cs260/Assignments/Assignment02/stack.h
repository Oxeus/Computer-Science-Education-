#pragma once

class stack {
private:
	struct stackElement {
		int x;
		int y;
		stackElement* prev;
	};
	stackElement * top;

public:
	stack();
	stack(int count);
	~stack();
	void push(int newx ,int newy);
	void pop();
	int topX();
	int topY();
	bool isEmpty();
};