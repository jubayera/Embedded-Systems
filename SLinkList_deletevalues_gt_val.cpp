#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
	public:
		int data;
		SinglyLinkedListNode *next;

		SinglyLinkedListNode(int node_data) 
		{
			this->data = node_data;
			this->next = nullptr;
		}
};

class SinglyLinkedList {
	public:
		SinglyLinkedListNode *head;
		SinglyLinkedListNode *tail;

		SinglyLinkedList() {
			this->head = nullptr;
			this->tail = nullptr;
		}

		void insert_node(int node_data)
		{
			SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

			if(!this->head) {
				this->head = node;
			}
			else {
				this->tail->next = node;
			}

			this->tail = node;
		}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep)
{
	while(node)
	{
		cout << node->data;
		node = node->next;
		if(node)
			cout << sep;
	}	
}

/* Complete the 'removeNodes' function below.
	The function is expected to return an INTEGER_SINGLY_LINKED_LIST
	Function accepts following parameters:
		1. INTEGER_SINGLY_LINKED_LIST listHead
		2. INTEGER x
*/
SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* listHead, int x)
{
	if(listHead == NULL)
		return listHead;

	if(listHead->data > x && listHead->next == NULL)
		return NULL;

	SinglyLinkedListNode* cur  = listHead;
	SinglyLinkedListNode* prev = NULL;

	while(cur != NULL && cur->data > x)
	{
		prev = cur;
		cur = cur->next;
	}

	if(prev != NULL)
		prev->next = NULL;

	SinglyLinkedListNode* newHead = cur;

	while(cur->next != NULL)
	{
		if(cur->next->data > x)
			cur->next = cur->next->next;
		else
			cur = cur->next;
	}

	return newHead;
}

int main()
{
	SinglyLinkedList* listHead = new SinglyLinkedList();
	
	string listHead_count_temp;
	getline(cin, listHead_count_temp);

	int listHead_count = stoi(ltrim(rtrim(listHead_count_temp)));

	for(int i = 0; i < listHead_count; i++)
	{
		string listHead_item_temp;
		getline(cin, listHead_item_temp);

		int listHead_item = stoi(ltrim(rtrim(listHead_item_temp)));

		listHead->insert_node(listHead_item);
	}

	string x_temp;
	getline(cin, x_temp);

	int x = stoi(ltrim(rtrim(x_temp)));

	SinglyLinkedListNode* result = removeNodes(listHead->head, x);

	print_singly_linked_list(result, "\n");
	cout << "\n";

	//fout.close();

	return 0;
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}
