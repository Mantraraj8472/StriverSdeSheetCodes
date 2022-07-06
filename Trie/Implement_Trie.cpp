// problem link:
// https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=striver-sde-sheet-problems

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
#define ALPHABET_SIZE 26

struct TrieNode
{
    TrieNode *links[ALPHABET_SIZE];
    bool isEndOfWord = false;

    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }

    void put(char c, TrieNode *node)
    {
        links[c - 'a'] = node;
    }

    TrieNode *get(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        isEndOfWord = true;
    }

    bool isEnd()
    {
        return isEndOfWord;
    }
};

class Trie
{

private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    // Time complexity is O(length of word)
    void insert(string word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!cur->containsKey(word[i]))
                cur->put(word[i], new TrieNode());
            cur = cur->get(word[i]);
        }
        cur->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.size() and cur; i++)
        {
            if (!cur->containsKey(word[i]))
                return false;
            cur = cur->get(word[i]);
        }
        return cur and cur->isEnd() == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.size() and cur; i++)
        {
            if (!cur->containsKey(prefix[i]))
                return false;
            cur = cur->get(prefix[i]);
        }
        return cur != NULL;
    }
};
