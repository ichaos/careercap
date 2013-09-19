//anagram clustering using a trie

#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
	vector<TrieNode> children;
	vector<vector<string>::const_iterator> value;
	TrieNode() : children(), value() {}

	TrieNode &child(char c) {
		int i = c - 'a';
		if (children.size() <= i) {
			children.resize(i + 1);
		}
		return children[i];
	}
};

class Trie {
public:
	Trie() : root() {}

	void insert(const string &key, vector<string>::const_iterator index) {
		TrieNode *n = &root;

		for (int i = 0; i < key.size(); i++) {
			n = &n->child(key[i]);
		}
		n->value.push_back(index);
	}

	void traversal(TrieNode &r) {		
		for (int i = 0; i < r.value.size(); i++) {
			cout << *r.value[i] << endl;
		}

		for (int i = 0; i < r.children.size(); i++) {
			traversal(r.children[i]);
		}
	}

//private:
	TrieNode root;
};

void anagram_clustering(std::vector<string> v) {
	Trie t;
	for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++) {
		string s = *it;
		sort(s.begin(), s.end());
		t.insert(s, it);
	}

	t.traversal(t.root);
};

int main() {
	//TrieNode t;
	//t.children.push_back(t);
	//cout << t.children.size() << t.children[0].children.size() << endl;
	const char* word_arr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    std::size_t size = sizeof(word_arr) / sizeof(word_arr[0]);
    std::vector<std::string> word_arr1(word_arr, word_arr + size);
 
    anagram_clustering(word_arr1);
	return 0;
}