#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct {
	TreeNode *head;
} BinarySearchTree;

BinarySearchTree *create_binary_search_tree(void)
{
	BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));
	if (bst == NULL) {
		fprintf(stderr, "***Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	bst->head = NULL;
	return bst;
}

TreeNode *create_node(int value, TreeNode *l,TreeNode *r)
{
	TreeNode *node = malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "***Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->data = value;
	node->left = l;
	node->right = r;

	return node;
}

// TreeNode *find_min(BinarySearchTree *bst)
// {}

// TreeNode *find_max(BinarySearchTree *bst)
// {}

void preorder_traversal(TreeNode *node)
{
	if (node == NULL) return;
	printf("%d\n", node->data);
	preorder_traversal(node->left);
	preorder_traversal(node->right);

	return;
}

void postorder_traversal(TreeNode *node)
{
	if (node == NULL) return;
	postorder_traversal(node->left);
	postorder_traversal(node->right);
	printf("%d\n", node->data);

	return;
}

void inorder_traversal(TreeNode *node)
{
	if (node == NULL) return;
	inorder_traversal(node->left);
	printf("%d\n", node->data);
	inorder_traversal(node->right);

	return;
}

TreeNode *find_inorder_successor(TreeNode *node)
{
	if (node->left != NULL) {
		return find_inorder_successor(node->left);
	}
	return node;
}

void *deleteNode(TreeNode *node, int del)
{
	if (node == NULL) return;

	if (del < node->data) {
		node->left = deleteNode(node->left, del);
	} else if (del > node->data) {
		node->right = deleteNode(node->right, del):
	} else {
		if (node->left == NULL) {
			TempNode *temp = node->right;
			free(node);
			return temp;
		} else if (node->right == NULL) {
			TempNode *temp = node->left;
			free(node);
			return temp;
		}

		TreeNode *successor = find_inorder_successor(node->right);
		node->data = successor->data;
		node->right = deleteNode(node->right, successor->data);
	}

	return node;
}

bool insert(TreeNode *node, TreeNode *newNode)
{
	if (node == NULL || newNode == NULL) return false;

	if (node->data > newNode->data) {
		if (node->left == NULL) {
			node->left = newNode;
			return true;
		}
		insert(node->left, newNode);
	}
	if (node->data < newNode->data) {
		if (node->right == NULL) {
			node->right = newNode;
			return true;
		}
		insert(node->right, newNode);
	}

	return false;
}

TreeNode *search(TreeNode *node, int target)
{
	if (node == NULL) return NULL;
	if (target < node->data) {
		return search(node->left, target);
	}

	if (target > node->data) {
		return search(node->right, target);
	}

	if (target == node->data) {
		return node;
	}
	
	return NULL;
}

void testTraversalPatterns(TreeNode *node)
{
	printf("---INORDER TRAVERSAL BEGIN---\n");
	inorder_traversal(node);
	printf("---INORDER TRAVERSAL END---\n");

	printf("---POSTORDER TRAVERSAL BEGIN---\n");
	postorder_traversal(node);
	printf("---POSTORDER TRAVERSAL END---\n");

	printf("---PREORDER TRAVERSAL BEGIN---\n");
	preorder_traversal(node);
	printf("---PREORDER TRAVERSAL END---\n");
}

void free_tree(BinarySearchTree *bst)
{
	free(bst);
}

void free_node(TreeNode *head)
{
	if (head == NULL) return;
	free_node(head->left);
	free_node(head->right);
	free(head);
}

int main(void)
{
	printf("---BINARY SEARCH TREE---\n");

	BinarySearchTree *bst = create_binary_search_tree();
	TreeNode *node0 = create_node(0, NULL, NULL);
	TreeNode *node7 = create_node(7, NULL, NULL);
	TreeNode *node25 = create_node(25, NULL, NULL);
	TreeNode *node15 = create_node(15, NULL, NULL);
	TreeNode *node5 = create_node(5, node0, node7);
	TreeNode *node20 = create_node(20, node15, node25);
	TreeNode *node10 = create_node(10, node5, node20);
	bst->head = node10;

	TreeNode *node3 = create_node(3, NULL, NULL);

	insert(bst->head, node3);
	printf("This should be 3: %d\n", node3->data);

	deleteNode(bst->head, NULL, 3, 'n');

	free_node(bst->head);
	free_tree(bst);

	printf("---END BINARY SEARCH TREE---\n");
	return 0;
}
