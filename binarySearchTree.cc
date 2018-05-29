// search.cpp : 定义控制台应用程序的入口点。
//
	}

	pnode = new BSNode<T>(key); // 以元素的值构建新的节点

	if (pparent == nullptr) {
		root = pnode;//以新节点为根
	}
	else {
		if (key > pparent->value) {
			pparent->rchild = pnode;
		}
		else {
			pparent->lchild = pnode;
		}
	}
	pnode->parent = pparent;
}

template<typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
}

template<typename T>
void BSTree<T>::inOrder(BSNode<T>* p)
{
	if (p != nullptr) {
		inOrder(p->lchild);
		cout << p->value;
		inOrder(p->rchild);
	}
}

template<typename T>
void BSTree<T>::create(T * Tarray,int length)
{
	for (int i = 0; i < length; i++) {
		insert(Tarray[i]);
	}
}

template<typename T>
void BSTree<T>::remove(const T & data)
{
	remove(root, data);
}

template<typename T>
void BSTree<T>::remove(BSNode<T>*& p, T key)
{
	if (p != nullptr) {
		if (p->value == key) {
			BSNode<T> * pdel = nullptr; // 记录要删除的节点

			if (p->lchild == nullptr || p->rchild == nullptr) {
				//删除节点只有左子树或者右子树或者都没有
				pdel = p;
			}
			else {
				//被删节点左右子树都有
				pdel = predecessor(p);
			}

			BSNode<T> * pchild = nullptr;
			if (pdel->lchild != nullptr) {
				pchild = pdel->lchild;
			}
			else {
				pchild = pdel->rchild;
			}

			if (pchild != nullptr) {
				pchild->parent = pdel->parent;
			}
			if (pdel->parent == nullptr) {
				root = pchild;
			}
			else if (pdel->parent->lchild == pdel) {
				pdel->parent->lchild = pchild;
			}
			else {
				pdel->parent->rchild = pchild;
			}

			if (p->value != pdel->value) {
				p->value = pdel->value;
			}

			delete pdel;
			
		}
		else if (p->value > key) {
			remove(p->lchild, key);
		}
		else {
			remove(p->rchild, key);
		}
	}
}

template<typename T>
BSNode<T>* BSTree<T>::search(T key)
{
	return search(root, key);
}

template<typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>*& p, T key)
{
	if (p == nullptr) {
		return nullptr;
	}
	if (p->value == key) {
		return p;
	}
	if (p->value > key) {
		return search(p->lchild, key);
	}
	else {
		return search(p->rchild, key);
	}
}

template<typename T>
BSNode<T>* BSTree<T>::predecessor(BSNode<T>*& p)
{
	if (p->lchild != nullptr) {
		p = p->lchild;
		while(p->rchild != nullptr) {
			p = p->rchild;
		}
		return p;
	}

	BSNode<T> *pparent = p-> parent;
	while (pparent != nullptr && pparent->lchild == p) {
		p = pparent;
		pparent = pparent-> parent;
	}
	return pparent;
}

int main()
{
	BSTree<int> test;
	int array[5] = { 1,2,3,4,5 };
	int length = sizeof(array) / sizeof(array[0]);
	test.create(array,length);
  //There still have some problems
	test.remove(4); 
	cout << test.search(3)->value;
	test.inOrder();
	return 0;
}

