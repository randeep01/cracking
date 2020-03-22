#include<iostream>
#include<unordered_set>

using namespace std;

class LinkedList {
	class Node {
	public:
		int data;
		Node* next;
		Node(int data);
	};
public:
	void add(int data);
	void deleteList(Node* head);
	void insertAtEnd(int data);
	Node* head;
	void print();
	LinkedList();
	void removeDups();
	void removeDups_space();

};

LinkedList::Node::Node(int data):next(nullptr) {
	std::cout << "const\n";
	this->data = data;
}

int main()
{
	LinkedList list;
	//list.add(1);
	//list.add(3);
	list.insertAtEnd(3333);
	list.insertAtEnd(3334);
	list.insertAtEnd(3334);

	list.print();
	list.removeDups();
	list.print();
	return 0;
}
LinkedList::LinkedList():head{nullptr}
{
	cout << "linked list cons\n";
}
void LinkedList::removeDups()
{
	unordered_set<int> os;

	Node* ptr = head;
	Node* prev = nullptr;
	while (ptr != nullptr) {
		
		if (os.find(ptr->data) == os.end())
		{
			os.insert(ptr->data);
			prev = ptr;
		}
		else {
			prev->next = ptr->next;
		}
		ptr = ptr->next;
	}

}
void LinkedList::removeDups_space()
{
}
void LinkedList::add(int data)
{
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}
void LinkedList::insertAtEnd(int data)
{
	Node* temp = new Node(data);

	if (head == nullptr) {
		head = temp;
		return;
	}

	Node* curr = head;
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	curr->next = temp;
	return;

}
void LinkedList::deleteList(Node* head)
{
	if (head == nullptr) {
		return;
	}
	deleteList(head->next);
	delete head;
}
void LinkedList::print() {

	Node* ptr = head;

	while (ptr != nullptr) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}


