//add two lists, suppose their lengths are same

struct Node *addTwoLists(struct Node *a, struct Node *b) {
	struct Node *head = alloc_node();

	struct Node *cur, *last, *end = head;

	//head->next = alloc_node();

	while (a) {
		int sum = a->value + b->value;

		if (sum >= 10) {
			last->val++;
			sum -= 10;
			last = last->next;
			while (last) {
				last->value = 0;
			}			
		}

		cur->next = alloc_node(sum);
		cur = cur->next;
		if (sum != 9) {
			last = cur;
		}

		a = a->next;
		b = b->next;
	}

	return head->val ? head : head->next;
}