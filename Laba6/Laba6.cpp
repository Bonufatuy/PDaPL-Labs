#include <iostream>
#include <array>

template<typename T, int number>
class Node;

template<typename T, int number>
class List {
public:
	List();
	~List();

	void deleteElem(int);
	void addElem(T*, int);
	void printList();
	void printElem(int);
	void exchange(int, int);

	Node<T, number>* peek(int index) {
		int i = 0;
		Node<T, number>* current = head;
		while (current->pNext && i < index) {
			current = current->pNext;
			i++;
		}
		if (i == index) {
			return current;
		}
		else return nullptr;
	}

	template<typename T, int number>
	friend class Node;

private:
	Node<T, number>* head;
};

template<typename T, int number>
class Node {
private:
	Node<T, number>* pNext;
	T data[number];

public:
	template<typename T, int number>
	friend class List;

	template<typename T, int number>
	friend Node<T, number> operator+(Node<T, number> other_1, Node<T, number> other_2);

	Node<T, number>(T* data) {
		for (int i = 0; i < number; i++) {
			this->data[i] = data[i];
		}
		this->pNext = nullptr;
	}
};

template<typename T, int number>
List<T, number>::List() {
	head = nullptr;
}

template<typename T, int number>
List<T, number>::~List() {}

template<typename T, int number>
void List<T, number>::deleteElem(int index) {

	Node<T, number>* current = head;
	Node<T, number>* Delete = peek(index);
	if (Delete) {
		while (current->pNext != Delete) {
			current = current->pNext;
		}
		if (Delete->pNext) {
			current->pNext = Delete->pNext;
		}
		else {
			current->pNext = nullptr;
		}
	}
	else {
		std::cout << std::endl << "Not found this element: " << index << std::endl;
	}
}

template<typename T, int number>
void List<T, number>::printList() {
	Node<T, number>* current = head;
	while (current) {
		for (int i = 0; i < number; i++) {
			std::cout << current->data[i] << " ";
		}
		std::cout << std::endl;
		if (current->pNext) {
			current = current->pNext;
		}
		else {
			break;
		}
	}
}

template<typename T, int number>
void List<T, number>::exchange(int index_1, int index_2) {

	Node<T, number>* ptr;
	Node<T, number>* elem_1 = peek(index_1);
	Node<T, number>* elem_2 = peek(index_2);
	Node<T, number>* pre_elem_1 = peek(index_1 - 1);
	Node<T, number>* pre_elem_2 = peek(index_2 - 1);

	if (index_1 == 0) {
		pre_elem_2->pNext = elem_1;

		ptr = elem_2->pNext;
		elem_2->pNext = head->pNext;
		head->pNext = ptr;

		head = elem_2;
	}
	else if (index_2 == 0) {
		pre_elem_1->pNext = elem_2;

		ptr = elem_1->pNext;
		elem_1->pNext = head->pNext;
		head->pNext = ptr;

		head = elem_1;
	}
	else {
		pre_elem_1->pNext = elem_2;
		pre_elem_2->pNext = elem_1;

		ptr = elem_1->pNext;
		elem_1->pNext = elem_2->pNext;
		elem_2->pNext = ptr;
	}
}

template<typename T, int number>
void List<T, number>::printElem(int index) {
	Node<T, number>* current = peek(index);
	std::cout << std::endl;
	for (int i = 0; i < number; i++) {
		std::cout << current->data[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T, int number>
void List<T, number>::addElem(T* data, int index) {
	Node<T, number>* node = new Node<T, number>(data);
	if (head == nullptr) {
		head = node;
	}
	else if (index == 0) {
		node->pNext = head;
		head = node;
	}
	else if (index > 0) {
		Node<T, number>* current = head;
		current = peek(index - 1);
		if (current) {
			node->pNext = current->pNext;
			current->pNext = node;
		}
		else {
			std::cout << std::endl << "Impossible add this element: " << index << std::endl;
		}
	}
}

template<typename T, int number>
Node<T, number> operator+(Node<T, number> other_1, Node<T, number> other_2) {
	for (int i = 0; i < number; i++) {
		other_1.data[i] = other_1.data[i] + other_2.data[i];
	}
	return other_1;
}

static const int amount_array = 2;

int main() {
	List<float, amount_array> list;

	float* Array = new float(amount_array);
	int amount_elements;

	std::cout << "Print amount_elements: ";
	std::cin >> amount_elements;

	for (int j = 0; j < amount_elements; j++) {
		for (int i = 0; i < amount_array; i++) {
			std::cin >> Array[i];
		}
		list.addElem(Array, j);
	}

	std::cout << std::endl;
	list.printList();
	std::cout << std::endl;
	*list.peek(1)=*list.peek(1)+*list.peek(2);
	std::cout << std::endl;
	list.printList();
	std::cout << std::endl;
	list.exchange(1, 2);
	std::cout << std::endl;
	list.printList();
	std::cout << std::endl;
	list.deleteElem(3);
	std::cout << std::endl;
	list.printList();
	std::cout << std::endl;
	list.printElem(1);

	return 0;
}
