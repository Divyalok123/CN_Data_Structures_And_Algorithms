// Givan n number of words and an incomplete word w. You need to auto-complete that word w.
// That means, find and print all the possible words which can be formed using the incomplete word w.

// Sample Input 1 :
// 7
// do dont no not note notes den
// no
// Sample Output 2 :
// no
// not
// note
// notes

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
    void helper(TrieNode* root, string pattern, string temp)
    {
        if(pattern.size() == 0)
        {
            if(root->isTerminal == true)
                cout << temp << endl;
            
            for(int i = 0; i < 26; i++)
            {
                TrieNode* child = root->children[i];
                
                if(child != NULL)
                {
                    string ans = temp;
                    ans += child->data;
                    helper(child, pattern, ans);
                }
            }
        }
        else
        {
            int index = pattern[0] - 'a';
            TrieNode* child = root->children[index];
            if(child != NULL)
            {
                temp += child->data;
                helper(child, pattern.substr(1), temp);
            }
        }
    }
    
    void autoComplete(vector<string> input, string pattern) {
        for(int i = 0; i < input.size(); i++)
        {
            insertWord(input[i]);
        }
        
        string s;
        helper(root, pattern, s); 
    }
};


int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
