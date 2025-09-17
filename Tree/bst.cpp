 #include <bits/stdc++.h>
 using namespace std;

struct Node {
	int key;
	Node *left, *right;
	Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int key) {
	if (!node) return new Node(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

bool search(Node* root, int key) {
	if (!root) return false;
	if (root->key == key) return true;
	if (key < root->key) return search(root->left, key);
	else return search(root->right, key);
}

void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

int main() {
	Node* root = nullptr;
	vector<int> keys = {50, 30, 20, 40, 70, 60, 80};
	for (int k : keys) root = insert(root, k);
	cout << "Inorder traversal of BST: ";
	inorder(root);
	cout << endl;
	int val = 40;
	cout << "Search " << val << ": " << (search(root, val) ? "Found" : "Not Found") << endl;
	return 0;
}
