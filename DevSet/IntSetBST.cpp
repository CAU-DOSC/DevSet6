#include "IntSet.cpp"

/*
	Implementation using binary search tree
	time complexity: 
		worst O(n^2)
		best O(nlog(n))
	space complexity: O(n)
*/

class IntSetBST : IntSet {
private:
	struct node
	{
		int key;
		struct node *left, *right;
	};
	struct node *root;
	int n;
	struct node *newNode(int item)
	{
		struct node *temp = new struct node;
		temp->key = item;
		temp->left = temp->right = NULL;
		return temp;
	}
	void bst_inorder(struct node *root, int *v, int *i)
	{
		if (root != NULL)
		{
			bst_inorder(root->left, v, i);
			v[(*i)++] = root->key;
			bst_inorder(root->right, v, i);
		}
	}
	struct node* bst_insert(struct node* node, int key)
	{
		/* If the tree is empty, return a new node */
		if (node == NULL) return newNode(key);

		/* Otherwise, recur down the tree */
		if (key <= node->key)
			node->left = bst_insert(node->left, key);
		else if (key > node->key)
			node->right = bst_insert(node->right, key);
		else
			// key is already in bst
			n--;

		/* return the (unchanged) node pointer */
		return node;
	}
public:
	IntSetBST(int max_elements, int max_value) {
		set_maxelems(max_elements);
		set_maxval(max_value);
		root = NULL;
		n = 0;
	}
	int size() { return n; }
	void insert(int num) {
		root = bst_insert(root, num);
		n++;
	}
	void report(int *v) {
		int *i = new int;
		*i = 0;
		bst_inorder(root, v, i);
	}
};