#include<stdio.h>
#include<stdlib.h>

typedef struct AvlNode {
	int data;
	struct AvlNode* left_child, * right_child;
}AvlNode;
AvlNode* root;

void preorder(AvlNode* root) {
	if (root == NULL) return;
	printf("%3d ", root->data);
	preorder(root->left_child);
	preorder(root->right_child);

}

AvlNode* rotate_LL(AvlNode* parent) {
	AvlNode* child = parent->left_child;
	parent->left_child = child->right_child;
	child->right_child = parent;
	return child;
}
AvlNode* rotate_RR(AvlNode* parent) {
	AvlNode* child = parent->right_child;
	parent->right_child = child->left_child;
	child->left_child = parent;
	return child;
}
AvlNode* rotate_RL(AvlNode* parent) {
	AvlNode* child = parent->right_child;
	parent->right_child = rotate_LL(child);
	return rotate_RR(parent);
}
AvlNode* rotate_LR(AvlNode* parent) {
	AvlNode* child = parent->left_child;
	parent->left_child = rotate_RR(child);
	return rotate_LL(parent);
}
AvlNode* avl_search(AvlNode* node, int key) {
	if (node == NULL) return NULL;
	printf("%d ", node->data);
	if (key == node->data) return node;
	else if (key < node->data)
		return avl_search(node->left_child, key);
	else
		return avl_search(node->right_child, key);
}
int get_height(AvlNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left_child), get_height(node->right_child));
	return height;
}
int get_height_diff(AvlNode* node) {
	if (node == NULL) return 0;
	return get_height(node->left_child) - get_height(node->right_child);
}
AvlNode* rebalance(AvlNode** node) {
	int height_diff = get_height_diff(*node);
	if (height_diff > 1) {
		if (get_height_diff((*node)->left_child) > 0)
			* node = rotate_LL(*node);
		else
			*node = rotate_LR(*node);
	}
	else if (height_diff < -1) {
		if (get_height_diff((*node)->right_child) < 0)
			* node = rotate_RR(*node);
		else
			*node = rotate_RL(*node);
	}
	return *node;
}
AvlNode* insert(AvlNode** root, int new_key) {
	if (*root == NULL) {
		*root = (AvlNode*)malloc(sizeof(AvlNode));
		if (*root == NULL) {
			fprintf(stderr, "error\n");
			exit(1);
		}
		(*root)->data = new_key;
		(*root)->left_child = (*root)->right_child = NULL;
	}
	else if (new_key < (*root)->data) {
		(*root)->left_child = insert(&((*root)->left_child), new_key);
		*root = rebalance(root);
	}
	else if (new_key > (*root)->data) {
		(*root)->right_child = insert(&((*root)->right_child), new_key);
		(*root) = rebalance(root);
	}
	else {
		fprintf(stderr, "error\n");
		exit(1);
	}
	return *root;
}
void main() {
	root = insert(&root, 10);
	root = insert(&root, 20);
	root = insert(&root, 30);
	root = insert(&root, 40);
	root = insert(&root, 50);
	preorder(root, 5);
}
