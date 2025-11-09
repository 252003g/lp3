#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node* left, *right;
    Node(char c, int f) : ch(c),freq(f),left(NULL),right(NULL){}
};

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code)
{
    if(!root) return;
    if(root->ch != '$')
    {
        cout<<root->ch << ":"<<code<<"\n";
    }
    printCodes(root->left, code+"0");
    printCodes(root->right,code+"1");
}

int main()
{
    string text;
    cout<<"Enter string : ";
    cin>>text;

    unordered_map<char,int> freq;
    for(char ch : text) freq[ch]++;

    priority_queue<Node*,vector<Node*>,Compare> pq;
    for(auto p : freq)
    {
        pq.push(new Node(p.first,p.second));
    }

    while(pq.size() > 1)
    {
        Node *l = pq.top();
        pq.pop();
        Node* r = pq.top();
        pq.pop();
        Node *merged = new Node('$',l->freq+r->freq);
        merged->left = l;
        merged->right = r;
        pq.push(merged);
    }

    cout<<"\nHuffman Codes:\n";
    printCodes(pq.top(),"");

    return 0;
}