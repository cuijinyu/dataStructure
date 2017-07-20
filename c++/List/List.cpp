#include <iostream>
using namespace std;
template <typename T>
class Node{
public:
	Node(){};
	~Node(){};
	T data;
	Node *next;
};
template <class T>
class List{
	public:
		List(){
			node=NULL;
			headNode=NULL;
			lastNode=NULL;
		};
		~List(){};
		bool addNode(T x);
		bool clearList();//清空线性表
		//bool getElem(int i,T *e);//取得某个位置元素的值
		bool locateElem(T e);//在线性表里查找与给定值e相等的元素，如果查找成功，返回true，如果失败，返回false
		bool listInsert(T i,Node *e);//在线性表L中的第i个位置插入新元素e
		bool listDelete(int i,T *e);//删除线性表中第i个位置的元素，并用e返回其值
		bool transval();//遍历并输出链表的内容
		bool isEmpty();
		int listLength();//返回线性表的长度
	private:
		int length;
		Node<T> *node;//临时节点
		Node<T> *headNode;//头结点
		Node<T> *lastNode;//尾节点
};
template <class T>
bool List<T>::transval(){
	node=headNode;
	while(node!=NULL){
		cout<<node->data<<endl;
		node=node->next;
	}
	cout<<"transval successful"<<endl;
	return true;
}	
template <class T>
bool List<T>::addNode(T x){
	node=new Node<T>();
	node->data=x;
	if(lastNode==NULL){//如果尾节点为空则链表为空
		lastNode=node;
		headNode=node;
	}else
	{
		lastNode->next=node;
		lastNode=node;
	}
	length++;
	return true;
}
template <class T>
bool List<T>::isEmpty(){
	if(length==0){
		return true;
	}else{
		return false;
	}
}
template <class T>
bool List<T>::listInsert(T i,Node *e){
	if(e=NULL){
		return false;
	}
	node=new Node<T>();
	node->data=i;
	node->next=e->next;
	if(node->next==NULL){
		lastNode=node;
	}
	return true;
}
template <class T>
bool List<T>::clearList(){
	Node<T>*del=new Node<T>();
	node=headNode;
	del=node;
	if(node->next!=NULL){
		node=node->next;
		headNode=node;
	}else{
		delete node;
		headNode=NULL;
		lastNode=NULL;
	}
	return true;
}


template <class T>
int List<T>::listLength(){
	return length;
}
int main(){
	List<int>test=new List();
	test.addNode(3);
	test.addNode(4);
	test.transval();
	return 0;
}
