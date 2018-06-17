#include "IntSet.cpp"

/*
	Implementation using list
	time complexity: O(n^2)
	space complexity: O(n)
*/

class IntSetList : IntSet {
private:
	struct node {
		int key;
		struct node *next;
	};

	struct node *root;

	int n;

	void list_insert(int num) {
		for (struct node *iter = root; iter; iter = iter->next) {
			struct node *next_node = iter->next;
			// find its position to add
			if (!next_node || num < next_node->key) {
				struct node *new_node = new struct node;
				new_node->key = num;
				iter->next = new_node;
				new_node->next = next_node;
				return;
			}
			// if num is in list
			else if (next_node->key == num) {
				n--;
				return;
			}
		}
	}

public:
	IntSetList(int max_elements, int max_value) {
		set_maxelems(max_elements);
		set_maxval(max_value);
		n = 0;
		root = new struct node;
		root->key = -1;
		root->next = NULL;
	}

	int size() { return n; }

	void insert(int num) {
		list_insert(num);
		n++;
	}
	void report(int *v) {
		int j = 0;
		for (struct node *iter = root->next; iter; iter = iter->next)
			v[j++] = iter->key;
	}
};