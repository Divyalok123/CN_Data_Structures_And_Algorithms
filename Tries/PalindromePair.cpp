// Givan n number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
// Return true or false.

#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}
	
    bool search(TrieNode * root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }
        int index = word[0] - 'a';
        TrieNode *child = root->children[index];
        if (child != NULL)
            return search(child, word.substr(1));
        else
            return false;
    }
	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	

	bool findIfPalindromePair(vector<string> arr)
    {
        for(int i=0; i< arr.size(); i++)
        {
            string str = arr[i];
            reverse(str.begin(), str.end());
            while(str.size() != 0)
            {
                insertWord(str);
                str = str.substr(1);
            }
        }
        bool flag = false;
        for(int i=0; i< arr.size(); i++)
        {
            flag = search(root, arr[i]);
            if (flag == true)
                return true;
        }
        return false;	        
	}
};


int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    
    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}