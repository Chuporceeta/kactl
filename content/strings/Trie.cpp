/**
* Author: Matthew Schrank
* Description: Builds a prefix tree of all words in a dictionary.
* Each edge represents a character in the prefix of a word. After
* constructing the trie, it can be used to search for matching 
* words from a set, find maximum or minimum XOR, or find longest
* common prefix of two strings. 
*/

struct node {
    vector<node*> child;
    bool leaf = false;
    int freq = 0;
    node() {
        child.assign(26, nullptr);
    }
};
 
node* root = new node();
void add(string s) {
    node* cur = root;
    for(char c : s) {
        if(cur->child[c-'a'] == nullptr) cur->child[c-'a'] = new node();
        cur = cur->child[c-'a'];
    }
    cur->leaf = true;
    cur->freq++;
}
 
bool contains(string s) {
    node* cur = root;
    for(char c : s) {
        if(cur->child[c-'a'] == nullptr) return false;
        cur = cur->child[c-'a'];
    }
    return true;
}