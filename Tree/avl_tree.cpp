 #include <bits/stdc++.h>
 using namespace std;

struct Node {
	int key, height;
	Node *left, *right;
	Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int height(Node *N) {
	return N ? N->height : 0;
}

int getBalance(Node *N) {
	return N ? height(N->left) - height(N->right) : 0;
}

Node* rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

Node* leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

Node* insert(Node* node, int key) {
	if (!node) return new Node(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else return node;
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

void inorder(Node *root) {
	if (root) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

int main() {
	Node *root = nullptr;
	vector<int> keys = {10, 20, 30, 40, 50, 25};
	for (int k : keys) root = insert(root, k);
	cout << "Inorder traversal of AVL tree: ";
	inorder(root);
	cout << endl;
	return 0;
}
