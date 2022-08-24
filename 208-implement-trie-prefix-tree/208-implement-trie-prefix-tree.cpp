class TrieNode {
  public:
    bool endofWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(){
        endofWord = false;
    }
};

class Trie {
public:
    TrieNode* root = nullptr;
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        destruct(root);
    }
    void destruct(TrieNode* node){
        if (node->children.size()==0){return;}
        for (auto child : node->children){
            destruct(child.second);
        }
        delete node;
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto letter : word){
            if (cur->children.find(letter)==cur->children.end()){
                cur->children[letter] = new TrieNode();
                cur = cur->children[letter];
            } else {
                cur = cur->children[letter];
            }
        }
        cur->endofWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto letter : word){
            if (cur->children.find(letter)==cur->children.end()){
                return false;
            }
            cur = cur->children[letter];
        }
        return cur->endofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto letter : prefix){
            if (cur->children.find(letter)==cur->children.end()){
                return false;
            }
            cur = cur->children[letter];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */