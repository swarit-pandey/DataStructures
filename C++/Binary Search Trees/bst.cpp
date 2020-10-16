#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    Node* leftChild;
    int data;
    Node* rightChild;
};

class bst{
private:
    Node* root;
public:
    bst() { root = nullptr; }
    Node* getRoot() { return root; }
    void insert(int element);
    Node* search(Node* p, int key);
    Node* iSearch(int key);
    void inorder(Node* p);
    void createFromPreorder(int pre[], int n);
};

void bst::insert(int element){
    Node* t = root;
    Node* r;
    Node* p;
    
    // The very first node will be created here
    if(root == nullptr){
        p = new Node;
        p -> leftChild = nullptr;
        p -> data = element;
        p -> rightChild = nullptr;
        root = p;
        return;
    }
    
    // From this point onwards we will make t traverse to find the target position, r is tailing t
    while(t != nullptr){
        r = t;
        if(element < t -> data){
            t = t -> leftChild;
        } else if(element > t -> data){
            t = t -> rightChild;
        } else{
            return;
        }
    }
    
    // we have found the position and created the new node having the data
    p = new Node;
    p -> leftChild = nullptr;
    p -> data = element;
    p -> rightChild = nullptr;
    
    // this is place where we need to decide where the new node will get connected
    if(element < r -> data){
        r -> leftChild = p;
    } else{
        r -> rightChild = p;
    }
}

Node* bst::search(Node* p, int key){
    if(key == p -> data){
        return p;
    } else if(key < p -> data){
        return search(p -> leftChild, key);
    } else{
        return search(p -> rightChild, key);
    }
}

Node* bst::iSearch(int key){
    Node* p = root;
    while(p != nullptr){
        if(key == p -> data){
            return p;
        } else if(key < p -> data){
            p = p -> leftChild;
        } else{
            p = p -> rightChild;
        }
    }
    return nullptr;
}

void bst::inorder(Node* p){
    if(p){
        inorder(p -> leftChild);
        cout << p -> data << ", " << flush;
        inorder(p -> rightChild);
    }
}

void bst::createFromPreorder(int* pre, int n){
    stack<Node*> stk;
    root = new Node;
    Node* p = root;
    p -> data = pre[0];
    p -> leftChild = nullptr;
    p -> rightChild = nullptr;
    int i;
    stk.push(p);
    Node* temp;
    for(int i = 1; i < n; ++i){
        temp = nullptr;
        while(!stk.empty() and pre[i] > stk.top() -> data){
            temp = stk.top();
            stk.pop();
        } 
        if(temp != nullptr){
            Node* smart = new Node;
            smart -> data = pre[i];
            smart -> leftChild = nullptr;
            smart -> rightChild = nullptr;
            temp -> rightChild = smart;
            stk.push(smart);
        } else{
            Node* pointTo = stk.top();
            Node* creator = new Node;
            pointTo -> leftChild = creator;
            creator -> data = pre[i];
            creator -> leftChild = nullptr;
            creator -> rightChild = nullptr;
            stk.push(creator);
        }
    }
}

int main(){
    bst tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(16);
    tree.insert(14);
    tree.insert(25);
    tree.insert(7);
    
    tree.inorder(tree.getRoot());
    cout << endl;
    
    // Recursive search
    Node* temp = tree.search(tree.getRoot(), 7);
    if(temp != nullptr){
        cout << temp -> data << endl;
    } else{
    // this is condition is not working as expected.
        cout << "Not found.";
    }
    
    // Iterative search 
    temp = tree.iSearch(8);
    if(temp != nullptr){
        cout << temp -> data << endl;
    } else{
        cout << "Not found." << endl;
    }
    
    int pre[] = {25, 20, 10, 5, 12, 22, 28, 30, 38, 48, 40};
    int n = sizeof(pre)/sizeof(pre[0]);
    
    bst NewTree;
    
    NewTree.createFromPreorder(pre, n);
    NewTree.inorder(NewTree.getRoot());
    cout << endl;
}
