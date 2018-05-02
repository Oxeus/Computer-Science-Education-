class queue {
public:
	queue();
	~queue();
	bool isEmpty();
	void enqueue(int newNum);
	int dequeue();
private:
	struct node {
		int num;
		node * next;
	};
	node *front, *rear;
};