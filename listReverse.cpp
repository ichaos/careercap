//list reverse: recursive and loop

ListNode *reverse(ListNode *list) {
	if (!list || !list->next) return list;

	ListNode *reverseList = reverse(list->next);

	list->next->next = list;

	list->next = null;

	return reverseList;
}

ListNode *reverse(ListNode *list) {
	ListNode *reverseList = NULL;
	ListNode *prev = NULL;

	while (list) {
		ListNode *next = list->next;

		if (!next) {
			reverseList = list;
		}

		list->next = prev;
		prev = list;
		list = next;
	}

	return reverseList;
}