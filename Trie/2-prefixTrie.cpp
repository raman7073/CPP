#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool end;
    unordered_map<char, TrieNode *> keys;
    TrieNode()
    {
        this->end = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        this->root = new TrieNode();
    }
    void insert(string &word)
    {
        insert(0, word, root);
    }
    bool search(string &word)
    {
        return search(0, word, root);
    }
    bool startsWith(string &word)
    {
        return startsWith(0, word, root);
    }

private:
    void insert(int curIdx, string &word, TrieNode *temp)
    {
        if (curIdx == word.length())
        {
            temp->end = true;
            return;
        }
        if (!temp->keys[word[curIdx]])
        {
            temp->keys[word[curIdx]] = new TrieNode();
        }
        this->insert(curIdx + 1, word, temp->keys[word[curIdx]]);
    }
    bool search(int curIdx, string &word, TrieNode *temp)
    {
        if (curIdx == word.length() && temp->end)
        {
            return true;
        }
        else if (curIdx == word.length())
        {
            return false;
        }
        else if (!temp->keys[word[curIdx]])
        {
            return false;
        }
        else
            return this->search(curIdx + 1, word, temp->keys[word[curIdx]]);
    }
    bool startsWith(int curIdx, string &word, TrieNode *temp)
    {
        if (curIdx == word.length())
        {
            return true;
        }
        else if (!temp->keys[word[curIdx]])
        {
            return false;
        }
        else
            return this->startsWith(curIdx + 1, word, temp->keys[word[curIdx]]);
    }
};

int main()
{
    Trie tr;
    string word = "Apple";
    tr.insert(word);
    string w = "App";
    cout << (tr.startsWith(w));
    return 0;
}
