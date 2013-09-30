//input: 1->2->3->4->5->6->7
//output: 1->7->2->6->3->5->4
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(NULL) {}
	ListNode(int v) : val(v), next(NULL) {}
};

ListNode *reverseList(ListNode *head) {
	if (!head) return NULL;

	ListNode extra;
	ListNode *next;
	while (head) {
		next = head->next;
		head->next = extra.next;
		extra.next = head;
		head = next;
	}
	return extra.next;
}

ListNode *twistList(ListNode *head) {
	if (!head) return NULL;

	//find the middle node
	ListNode *slow = head;
	ListNode *fast = head->next;

	while (fast) {
		cout << fast->val << endl;
		fast = fast->next;
		if (!fast) break;
		slow = slow->next;
		fast = fast->next;
	}

	ListNode *lastHalf = slow->next;
	slow->next = NULL;
	ListNode *reverse = reverseList(lastHalf);

	//insert
	ListNode *next;
	while (head && reverse) {
		next = reverse->next;
		reverse->next = head->next;
		head->next = reverse;
		reverse = next;
		head = head->next->next;
	}

	return head;
}


int main() {
	ListNode head;
	head.val = 1;
	ListNode *cur = &head;

	int i = 2;
	while (i < 8) {
		ListNode *n = new ListNode();
		n->val = i++;
		cur->next = n;
		cur = n;
		cur->next = NULL;
	}

	cout << "begin twist" << endl;
	twistList(&head);

	cur = &head;
	while (cur) {
		cout << "cur->val: " << cur->val << endl;
		cur = cur->next;
	}

	return 0;
}
