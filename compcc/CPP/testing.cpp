#include <bits/stdc++.h>

using namespace std;

class LinkedListNode 
{  
public:

    int data;
    LinkedListNode *next;


    LinkedListNode() {
        this->data = 0;
        this->next = nullptr;
    }

    LinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }

    LinkedListNode(LinkedListNode *node) {
        this->data = node->data;
        this->next = node->next;
    }

};

class LinkedList
{
public:
    LinkedListNode *head;

    LinkedList() {
        this->head = nullptr;
    }

    void addNode(int value) {
        LinkedListNode *curr = head;
        LinkedListNode *node = new LinkedListNode(value);
        LinkedListNode node = 5;

        cout << "node :: " << node->data << endl;
        if (curr == nullptr) {
            head = node;
            cout << "nullptr\n";
            return;
        }
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;

    }

    void printList() {
        LinkedListNode *curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main() {

    LinkedList *llist = new LinkedList();

    llist->addNode(1);
    llist->printList();
    llist->addNode(2);
    llist->printList();
    llist->addNode(3);
    llist->printList();
    llist->addNode(4);
    llist->addNode(5);

    llist->printList();
        

        LinkedListNode *ptr = new LinkedListNode();

    string str = "java php java cpp";
    vector<string> vstr = { "java", "php", "java", "cpp" };
    map<string,int> hash;


    return 0;

}