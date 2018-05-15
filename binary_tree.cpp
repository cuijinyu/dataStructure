#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

//The Bi_Node data structure
class Bi_Node{
public:
    char data;
    Bi_Node *lchild,
            *rchild;
};

class Bi_Tree{
private:
    Bi_Node * root;//the binary's root element
    int height;//the hight of the binary tree
    void pre_order(Bi_Node * t);
    void in_order(Bi_Node *t);
    void post_order(Bi_Node *t);
    Bi_Node * create(string &s,int &pos);
    void get_height(Bi_Node *t,int h);
public:
    Bi_Tree() {
        root = nullptr;
        height = 0;
    }
    void create_bi_tree(string s);//to build the binary tree by preorder traversal
    void preOrder();
    void inOrder();
    void postOrder();
    void levelOrder();
    int getHeight();
};

Bi_Node * Bi_Tree::create(string &s,int &pos) {
    ++pos;
    Bi_Node * t;
    if(static_cast<unsigned>(pos) >= s.size()){
        return nullptr;
    }else{
        if(s[pos] == '#'){
            t = nullptr;
        }else{
            t = new Bi_Node;
            t->data = s[pos];
            t->lchild = create(s,pos);
            t->rchild = create(s,pos);
        }
    }
    return t;
};

void Bi_Tree::create_bi_tree(string s) {
    int pos = -1;
    root = create(s,pos);
};

void Bi_Tree::preOrder() {
    pre_order(root);
    cout << endl;
};

void Bi_Tree::pre_order(Bi_Node * t){
    if(t != nullptr){
        cout << t->data << ' ';
        pre_order(t->lchild);
        pre_order(t->rchild);
    }
};

void Bi_Tree::inOrder() {
    in_order(root);
    cout<<endl;
};

void Bi_Tree::in_order(Bi_Node *t) {
    if(t != nullptr){
        in_order(t->lchild);
        cout<<t->data<<' ';
        in_order(t->rchild);
    }
};

void Bi_Tree::postOrder() {
    post_order(root);
    cout << endl;
};

void Bi_Tree::post_order(Bi_Node * t) {
    if(t!=nullptr){
        post_order(t->lchild);
        post_order(t->rchild);
        cout<<t->data<<' ';
    }
};

void Bi_Tree::levelOrder() {
    if(root == nullptr){
        return;
    }
    queue<Bi_Node *> q;
    q.push(root);
    while(!q.empty()){
        Bi_Node *t;
        t = q.front();
        q.pop();
        cout<<t->data<<' ';
        if(t->lchild!=nullptr){
            q.push(t->lchild);
        }
        if(t->rchild!=nullptr){
            q.push(t->rchild);
        }
    }
    cout<<endl;
};

//get the tree's height
int Bi_Tree::getHeight() {
    get_height(root,0);
    return height;
};

void Bi_Tree::get_height(Bi_Node *t,int h) {
    if(t != nullptr){
        ++h;
        if(h > height){
            height = h;
        }
        get_height(t->lchild,h);
        get_height(t->rchild,h);
    }
};

int main()
{
    Bi_Tree a;
    string s;
    s="ABD##E#F##C##";
    a.create_bi_tree(s);
    cout<<"前序遍历："<<endl;
    a.preOrder();
    cout<<"中序遍历："<<endl;
    a.inOrder();
    cout<<"后序遍历："<<endl;
    a.postOrder();
    cout<<"层序遍历："<<endl;
    a.levelOrder();
    cout<<"树高："<<endl;
    cout<<a.getHeight()<<endl;
    return 0;
}
