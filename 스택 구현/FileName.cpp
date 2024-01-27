#pragma warning(disable: 4996)
#include <iostream> //  전처리 지시자
#include<string>
#include <cassert>

struct Node {
	struct Node* next;
	int data;
};


class Stack {

private:
	struct List {
		Node* head;
		int count;
	};
	List* list;

public:
	Stack() {
		list = ListInit(); //생성자로 초기화                 아래부터 코드를 보면 암묵적으로 this생략가능
	}

	List* ListInit() {
		List* newlist = new List;
		newlist->head = nullptr;
		newlist->count = 0;
		return newlist;
	}

	bool ListisEmpty() {
		if (this->list->head == nullptr) {
			return true;
		}
		else
			return false;
	}
	void ListPush(int data, int* fingercount) {
		Node* newNode = new Node;
		newNode->data = data;
		if (this->list->head == nullptr) {
			this->list->head = newNode;
			this->list->head->next = nullptr;
		}
		else {
			newNode->next = this->list->head;
			this->list->head = newNode;
		}
		(this->list->count)++;
		(*fingercount)++;

	}
	int ListPop(int *fingercount) {
		assert(this->ListisEmpty() == false);

		Node* delnode = this->list->head;
		int deldata = delnode->data;
		this->list->head = this->list->head->next;
		delete delnode;
		(this->list->count)--;
		(*fingercount)++;
		return deldata;

	}

	int Listpeek() {
		/*assert(this->ListisEmpty() == false);*/
		if (this->ListisEmpty()) {
			return 0;
		}
		else
		    return this->list->head->data;

	}

	/*void LClear() {
		while (this->ListisEmpty() == false) {
			this->ListPop();
		}
	}*/
	~Stack() {
		delete this->list->head;
		delete this->list;
	}
};



int main() {
	using namespace std;
	Stack* listpret = new Stack[500010];
	int N, K, i, sound, pret;
	int fingercount = 0;

	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &sound, &pret);
		if (listpret[sound].ListisEmpty()) {
			listpret[sound].ListPush(pret, &fingercount);

		}
		else {
			if (listpret[sound].Listpeek() < pret) {
				listpret[sound].ListPush(pret, &fingercount);
			}
			else if (listpret[sound].Listpeek() == pret) {
				;
			}
			else {
				while (listpret[sound].ListisEmpty() == false) {
					listpret[sound].ListPop(&fingercount);
					if (listpret[sound].Listpeek() == pret) {
						break;
					}
					if (listpret[sound].Listpeek() < pret) {
						listpret[sound].ListPush(pret, &fingercount);
						break;
					}
				}
			}
		}
	}

	cout << fingercount << endl;

}