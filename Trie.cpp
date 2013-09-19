#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
#include <boost/container/vector.hpp>
 
struct TrieNode {
    boost::container::vector<TrieNode> children;
    std::vector<std::vector<std::string>::const_iterator> head;
 
    TrieNode()
        : children()
        , head()
    { }
 
    TrieNode& child(char c) {
        std::size_t i = c - 'a';
        if (children.size() <= i)
            children.resize(i + 1);
        return children[i];
    }
};
 
class Trie {
public:
    Trie(int n = 26)
        : root()
    { (void) n; /* we don't actually use it any more */ }
 
    void insert_trie_node(const std::string& w, std::vector<std::string>::const_iterator ind);
 
    TrieNode& get_root_node() {
        return root;
    }
 
private:
    TrieNode root;
};
 
void Trie::insert_trie_node(const std::string& w, std::vector<std::string>::const_iterator ind) {
    TrieNode* r = &root;
 
    for (auto it = w.begin(); it != w.end(); ++it)
        r = &r->child(*it);
 
    r->head.push_back(ind);
}
 
void traversal_trie(std::ostream& out, TrieNode const& r) {
    for (auto it = r.head.begin(); it != r.head.end(); ++it)
        out << **it << "\n";
 
    for (auto it = r.children.begin(); it != r.children.end(); ++it)
        traversal_trie(out, *it);
}
 
void cluster_anagrams(const std::vector<std::string>& word_arr, std::size_t size) {
    Trie trie(26);
 
    for (auto it = word_arr.begin(); it != word_arr.end(); ++it) {
        std::string str = *it;
        sort(str.begin(), str.end());
        trie.insert_trie_node(str, it);
    }
 
    traversal_trie(std::cout, trie.get_root_node());
}
 
int main() {
    const char* word_arr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    std::size_t size = sizeof(word_arr) / sizeof(word_arr[0]);
    std::vector<std::string> word_arr1(word_arr, word_arr + size);
 
    cluster_anagrams(word_arr1, size);
}