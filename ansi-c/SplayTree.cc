
/*
 * ========================================================================
 *
 *       Filename:  SplayTree.cc
 *
 *    Description:  Splay tree implementation.
 *
 *        Created:  10/23/2013 11:18:38 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

// http://problem-solving-notes.blogspot.com/2012/01/needlessly-long-but-correct-splay-tree.html

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

typedef long long LL;
typedef pair < int, int >pii;

#define INF (1<<30)

#define KEY_TYPE int

class Node {
  private:
	KEY_TYPE key;
	int cnt;					// size of the subtree rooted here

	Node *left;
	Node *right;
	Node *parent;

	int calcTreeSize();

  public:
	  bool isLeftChild();
	bool isRightChild();
	bool isRoot();

	KEY_TYPE getKeyVal();
	int getCnt();

	void Rotate();
	void Zig();
	void ZigZig();
	void ZigZag();

	bool NormalBSTInsert(Node * newNode);
	void Splay();
	void SplayUntil(Node * until);

	  Node();
	  Node(const KEY_TYPE _key);

	 ~Node();

	Node *FindNearest(const KEY_TYPE _key);
	bool Exists(const KEY_TYPE _key);
	void Insert(KEY_TYPE _key);
	void Insert(Node * newNode);
	void Delete();
	void Delete(KEY_TYPE _key);

	void PrintInOrder();
	void PrintPreOrder();

	KEY_TYPE findKth(int k);
	int Count(KEY_TYPE _key);
};

Node *ROOT;

bool
Node::isLeftChild()
{
	return (this->parent != NULL && this->parent->left == this);
}

bool
Node::isRightChild()
{
	return (this->parent != NULL && this->parent->right == this);
}

bool
Node::isRoot()
{
	return this->parent == NULL;
}

KEY_TYPE
Node::getKeyVal()
{
	return this->key;
}

int
Node::getCnt()
{
	return this->cnt;
}

int
Node::calcTreeSize()
{
	return 1 + (this->left ? this->left->cnt : 0) +
		(this->right ? this->right->cnt : 0);
}

void
Node::Rotate()
{
	if (isLeftChild()) {
		bool parWasLeftChild =
			this->parent ? this->parent->isLeftChild() : false;

		parent->left = this->right;

		if (this->right)
			this->right->parent = this->parent;

		Node *newParent = this->parent->parent;

		this->right = this->parent;

		if (this->right)
			this->right->parent = this;

		this->parent = newParent;

		if (this->parent != NULL) {
			if (parWasLeftChild)
				this->parent->left = this;
			else
				this->parent->right = this;
		}

		this->right->cnt = this->right->calcTreeSize();
		this->cnt = this->calcTreeSize();
	} else if (isRightChild()) {
		bool parWasLeftChild =
			this->parent ? this->parent->isLeftChild() : false;

		parent->right = this->left;

		if (this->left)
			this->left->parent = parent;

		Node *newParent = this->parent->parent;

		this->left = this->parent;

		if (this->left)
			this->left->parent = this;

		this->parent = newParent;

		if (this->parent != NULL) {
			if (parWasLeftChild)
				this->parent->left = this;
			else
				this->parent->right = this;
		}

		this->left->cnt = this->left->calcTreeSize();
		this->cnt = this->calcTreeSize();
	}
}

void
Node::Zig()
{
	Rotate();
}

void
Node::ZigZig()
{
	this->parent->Rotate();
	this->Rotate();
}

void
Node::ZigZag()
{
	this->Rotate();
	this->Rotate();
}

void
Node::Splay()
{
	while (!this->isRoot()) {
		if (this->parent->isRoot())	// Zig
		{
			this->Zig();
		} else if (this->isLeftChild() == this->parent->isLeftChild())	// ZigZig
		{
			this->ZigZig();
		} else					// ZigZag
		{
			this->ZigZag();
		}
	}

	ROOT = this;
}

Node::Node()
{
	key = 0;
	cnt = 0;
	left = NULL;
	right = NULL;
	parent = NULL;
}

Node::Node(const KEY_TYPE _key)
{
	key = _key;
	cnt = 1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

Node::~Node()
{

}

Node *
Node::FindNearest(const KEY_TYPE _key)
{
	Node *ret = this;

	while (true) {

		if (ret->key < _key) {
			if (ret->right) {
				ret = ret->right;
			} else
				break;
		} else if (ret->key > _key) {
			if (ret->left) {
				ret = ret->left;
			} else
				break;
		} else {
			break;
		}
	}

	return ret;
}

bool
Node::Exists(const KEY_TYPE _key)
{
	Node *temp = this->FindNearest(_key);

	temp->Splay();

	return ROOT->key == _key;
}

// returns false if a node with key = newNode->key already exists in the tree
bool
Node::NormalBSTInsert(Node * newNode)
{
	Node *curNode = this;
	bool alreadyThere = false;

	while (true) {
		if (newNode->key > curNode->key) {
			if (curNode->right) {
				curNode = curNode->right;
			} else {
				curNode->right = newNode;
				newNode->parent = curNode;
				break;
			}
		} else if (newNode->key < curNode->key) {
			if (curNode->left) {
				curNode = curNode->left;
			} else {
				curNode->left = newNode;
				newNode->parent = curNode;
				break;
			}
		} else {
			alreadyThere = true;
			break;
		}
	}

	if (!alreadyThere) {
		Node *temp = newNode->parent;

		while (temp) {
			temp->cnt = temp->calcTreeSize();
			temp = temp->parent;
		}

		return true;
	} else
		return false;
}

void
Node::Insert(KEY_TYPE _key)
{
	this->Insert(new Node(_key));
}

void
Node::Insert(Node * newNode)
{
	if (newNode == NULL)
		return;

	if (this->NormalBSTInsert(newNode))
		newNode->Splay();
}

void
Node::SplayUntil(Node * until)
{
	Node *grandParent = until->parent;

	while (this->parent != grandParent) {
		if (this->parent == until)	// zig
		{
			this->Zig();
		} else if (this->isLeftChild() == this->parent->isLeftChild())	// zigzig
		{
			this->ZigZig();
		} else
			this->ZigZag();
	}
}

void
Node::Delete()
{
	this->Splay();

	if (this->left) {
		Node *maxNode = this->left->FindNearest(INF);

		maxNode->SplayUntil(this->left);

		this->left->right = this->right;

		if (this->right)
			this->right->parent = this->left;

		ROOT = this->left;
		ROOT->parent = NULL;
		ROOT->cnt = ROOT->calcTreeSize();
	} else if (this->right) {
		Node *minNode = this->right->FindNearest(-INF);

		minNode->SplayUntil(this->right);

		this->right->left = this->left;

		if (this->left)
			this->left->parent = this->right;

		ROOT = this->right;
		ROOT->parent = NULL;
		ROOT->cnt = ROOT->calcTreeSize();
	} else {
		ROOT = NULL;
	}
}

void
Node::Delete(KEY_TYPE _key)
{
	if (this->Exists(_key)) {
		Node *forDelete = ROOT;	// the Exists method splays the node to the root

		ROOT->Delete();
		delete forDelete;

		forDelete = NULL;
	}
}

KEY_TYPE
Node::findKth(int k)
{
	if (this->cnt < k)
		return -INF;

	Node *temp = this;

	while (true) {
		int c = (temp->left ? temp->left->cnt : 0) + 1;

		if (c == k)
			break;

		if (c < k) {
			k -= c;
			temp = temp->right;
		} else {
			temp = temp->left;
		}
	}

	temp->Splay();
	return ROOT->key;
}

int
Node::Count(KEY_TYPE _key)
{
	Node *temp = this;

	int ret = 0;

	while (true) {
		if (temp->key < _key) {
			int c = (temp->left ? temp->left->cnt : 0) + 1;

			ret += c;

			if (temp->right) {
				temp = temp->right;
			} else {
				break;
			}
		} else if (temp->key > _key) {
			if (temp->left) {
				temp = temp->left;
			} else
				break;
		} else {
			ret += (temp->left ? temp->left->cnt : 0);
			break;
		}
	}

	temp->Splay();

	return ret;
}

void
Node::PrintInOrder()			// not needed for the problem
{
	if (this->left)
		this->left->PrintInOrder();

	cout << this->getKeyVal() << " ";

	if (this->right)
		this->right->PrintInOrder();
}

void
Node::PrintPreOrder()			// not needed for the problem
{
	cout << "[" << this->getKeyVal() << ":" << this->cnt << "]";

	printf("(");
	if (this->left)
		this->left->PrintPreOrder();
	printf(")");

	printf("(");
	if (this->right)
		this->right->PrintPreOrder();
	printf(")");
}

void
SplayTreeInsert(KEY_TYPE key)
{
	if (ROOT)
		ROOT->Insert(key);
	else
		ROOT = new Node(key);
}

int
main()
{
	int Q;

	scanf("%d", &Q);

	ROOT = NULL;

	while (Q--) {
		char t[5];
		int p;

		scanf("%s%d", t, &p);

		if (t[0] == 'I') {
			SplayTreeInsert(p);
		} else if (t[0] == 'D') {
			if (ROOT)
				ROOT->Delete(p);
		} else if (t[0] == 'K') {
			int v = -INF;

			if (ROOT)
				v = ROOT->findKth(p);

			if (v > -INF) {
				printf("%d\n", v);
			} else
				puts("invalid");
		} else {
			int v = 0;

			if (ROOT)
				v = ROOT->Count(p);

			printf("%d\n", v);
		}

	}

	return 0;
}
