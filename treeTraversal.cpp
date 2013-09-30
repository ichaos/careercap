//tree traversal: inorder, preorder, postorder

struct TNode {
	int val;
	Tnode *left, *right;
};

//iterative
void iterativeInorder(TNode *root) {
	stack<TNode *> s;
	while (!root || !s.empty()) {
		if (!root) {
			s.push(root);
			root = root->left;
		} else {
			root = s.top();
			s.pop();
			visit(root);
			root = root->right;
		}
	}
}