//Find if all the leaf nodes are at same level in binary tree. Recursive and non-recursive approach?

struct node {
	int val;
	node *left;
	node *right;
};

int heightOfTree(node *root, bool &result) {
	if (!root) {
		result = true;
		return 0;
	}
	bool res;
	int left = heightOfTree(root->left, res);

	if (!res) {
		result = false;
		return 0;
	}

	int right = heightOfTree(root->right, res);
	if (!res) {
		result = false; return 0;
	}

	if (left && right && left != right) { //false
		result = false;
		return 0;
	}
	result = true;
	return max(left, right) + 1;
}

bool checkLeaf(node *root) {
	bool result;
	heightOfTree(root, result);
	return result;
}

int main() {
	
}