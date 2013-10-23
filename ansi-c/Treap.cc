
/*
 * ========================================================================
 *
 *       Filename:  Treap.cc
 *
 *    Description:  Treap implementation.
 *
 *        Created:  10/23/2013 11:39:20 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

// http://problem-solving-notes.blogspot.com/2012/01/spoj-orderset-with-treap.html
//
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

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

#define INF (1<<30)

typedef long long LL;
typedef pair < int, int >pii;

struct Node {
	int key;
	int cnt;
	int priority;

	Node *left, *right;

	  Node() {
		cnt = 0;
		priority = 0;
		left = right = NULL;
	} Node(int _key) {
		cnt = 1;
		key = _key;
		priority = rand();
		left = right = NULL;
	}
	Node(int _key, int pr) {
		cnt = 1;
		key = _key;
		priority = pr;
		left = right = NULL;
	}
};

struct Treap {
	Node *root;

	  Treap() {
		root = NULL;
		srand(time(NULL));
	} int TreeSize(Node * T) {
		return T == NULL ? 0 : T->cnt;
	}

	void UpdateCnt(Node * &T) {
		if (T) {
			T->cnt = 1 + TreeSize(T->left) + TreeSize(T->right);
		}
	}

	void LeftRotate(Node * &T) {
		Node *temp = T->left;

		T->left = temp->right;
		temp->right = T;
		T = temp;

		UpdateCnt(T->right);
		UpdateCnt(T);
	}

	void RightRotate(Node * &T) {
		Node *temp = T->right;

		T->right = temp->left;
		temp->left = T;
		T = temp;

		UpdateCnt(T->left);
		UpdateCnt(T);
	}

	void Insert(Node * &T, int _key) {
		if (T == NULL) {
			T = new Node(_key);
			return;
		}

		if (T->key > _key) {
			Insert(T->left, _key);

			if (T->priority < T->left->priority)
				LeftRotate(T);
		} else if (T->key < _key) {
			Insert(T->right, _key);

			if (T->priority < T->right->priority)
				RightRotate(T);
		}

		UpdateCnt(T);
	}

	void Insert(int _key) {
		Insert(root, _key);
	}

	void Delete(Node * &T, int _key) {
		if (T == NULL)
			return;

		if (T->key > _key)
			Delete(T->left, _key);
		else if (T->key < _key)
			Delete(T->right, _key);
		else {
			if (T->left && T->right) {
				if (T->left->priority > T->right->priority)
					LeftRotate(T);
				else
					RightRotate(T);

				Delete(T, _key);
			} else {
				Node *temp = T;

				if (T->left)
					T = T->left;
				else
					T = T->right;

				delete temp;
			}
		}

		UpdateCnt(T);
	}

	void Delete(int _key) {
		Delete(root, _key);
	}

	int Count(Node * T, int bound) {
		if (T == NULL)
			return 0;

		if (T->key < bound)
			return 1 + TreeSize(T->left) + Count(T->right, bound);

		return Count(T->left, bound);
	}

	int Count(int bound) {
		return Count(root, bound);
	}

	int FindKth(Node * T, int k) {
		if (TreeSize(T) < k)
			return -INF;

		int sz = 1 + TreeSize(T->left);

		if (sz == k)
			return T->key;

		if (sz < k)
			return FindKth(T->right, k - sz);

		return FindKth(T->left, k);
	}

	int FindKth(int k) {
		return FindKth(root, k);
	}
};

int
main()
{
	// freopen("in.txt","r",stdin);

	int Q;

	scanf("%d", &Q);

	Treap oTreap;

	while (Q--) {
		char t[5];
		int p;

		scanf("%s%d", t, &p);

		if (t[0] == 'I') {
			oTreap.Insert(p);
		} else if (t[0] == 'D') {
			oTreap.Delete(p);
		} else if (t[0] == 'K') {
			int v = oTreap.FindKth(p);

			if (v > -INF) {
				printf("%d\n", v);
			} else
				puts("invalid");
		} else {
			int v = oTreap.Count(p);

			printf("%d\n", v);
		}

	}

	return 0;
}
