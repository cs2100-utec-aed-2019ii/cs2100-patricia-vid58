
#include <iostream>
#include <map>
using namespace std;

struct Trie {

    map<string, Trie*> children;
    bool is_node;

};

Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->is_node = false;
    return node;

}

void insert(Trie*& root, const string str)
{
    if (root == nullptr) {
        root = getNewTrieNode();
    }
    Trie* temp = root;
    string x;
    for (int i = 0; i < str.length(); i++) {
        x = str[i];

        if (temp->children.find(x) == temp->children.end())
            temp->children[x] = getNewTrieNode();

        temp = temp->children[x];
    }

    temp->is_node = true;
}

void convertToPatricia(Trie* root, const string& str){

    char aux[str.length()];

    string aux2;
    string aux3;

    Trie* temp=root;

    for(int i=0;i<str.length();i++){
        aux[i]=str[i+1];
    }
    for(int i=0;i<str.length();i++){
        aux2[i]=aux[i];
    }
    aux3=str[0];

    temp->children[aux3]=getNewTrieNode();
    temp=temp->children[aux3];
    temp->children[aux2]=getNewTrieNode();

    temp->is_node = true;
}

bool search(Trie* root, const string& str)
{
    if (root == nullptr)
        return false;

    Trie* temp = root;
    string n;

    for (int i = 0; i < str.length(); i++) {
        n=str[i];

        temp = temp->children[n];

        if (temp == nullptr)
            return false;
    }

    return temp->is_node;
}

void eliminar(Trie* root, const string& str){
    Trie* temp = root;
    string x;
    for (int i = 0; i < str.length(); i++) {

        x = str[i];

        if (temp->children.find(x) == temp->children.end())
            return;

        temp = temp->children[x];
    }

    temp->is_node = false;
}

void imprimir(Trie* root, const string str)
{
    Trie* temp=root;
    if(temp->is_node)
        cout << str<< endl;
    for(auto &i:temp->children)
        imprimir(i.second, str+i.first);
}
int main()
{
    Trie* root = nullptr;

    insert(root, "llama");
    cout << search(root, "llama") << " ";

    insert(root, "llame");
    cout << search(root, "llame") << " ";

    insert(root, "llami");
    cout << search(root, "llami") << " ";

    cout << search(root, "llamo") << " ";

    insert(root, "llamu");
    cout << search(root, "llamu") << " ";

    eliminar(root,"llamu");
    cout << search(root, "llamu") << endl;

    imprimir(root," ");
    return 0;
}
