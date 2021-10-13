#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node (int x){
        val = x;
        left=0;
        right=0;
    }

    Node (int x, Node *l, Node *r){
        val=x;
        l=left;
        r=right;
    }
};

int findClosest(Node *root, int x){
    if (!root) return 0;
    if (root->val==x) return x;

    if (root->left && x<root->val){
        int left=findClosest(root->left,x);
        if (abs(x-root->val)<abs(x-left)) return root->val;
        else return left;
    }
    else if (root->right && root->val<x){
        int right=findClosest(root->right,x);
        if (abs(x-root->val)<abs(x-right)) return root->val;
        else return right;
    }

    return root->val;
}

Node* createTree(vector<int> tree){
    if (!tree.size()) return 0;
    int k=0;
    Node *root=new Node(tree[k++]);
    queue<Node *> q;
    q.push(root);

    while (!q.empty() && k<tree.size()){
        Node *cur=q.front();
        q.pop();
        if (tree[k]!=-1){
            cur->left=new Node(tree[k]);
            q.push(cur->left);
        }
        ++k;
        if (tree[k]!=-1){
            cur->right = new Node (tree[k]);
            q.push(cur->right);
        }
        ++k;
    }

    return root;
}

void deleteTree(Node *root){
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> tree={50,30,100,10,40,150,-1,-1,-1,35,45,10,200,31,37,-1,-1,-1,121,-1,-1,-1,-1,-1,-1,120,149};
    int x=34;

    Node *root=createTree(tree);

    cout << findClosest(root,x);

    deleteTree(root);
int left=findClosest(root->left,x);
        if (abs(x-root->val)<abs(x-left)) return root->val;
        else return left;
    return 0;
}