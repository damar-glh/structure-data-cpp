#include <iostream>
using namespace std;

struct node {
	char data;
	node *left;
	node *right;
}Node;
node *root = NULL;
void addNode(node **root, char isi){
	if ((*root) == NULL){
		node *baru;
		baru = new node;
		baru->data = isi;
		baru->left = NULL;
		baru->right = NULL;
		(*root) = baru;
	}
}

void preorder(node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


int main(){
	char isinya;
	printf("\n         Posisi awal binary tree :   \n\n");
	printf("--------------- A M I K Z J ---------------"); 
	// level 0
	addNode(&root, isinya = 'A'); 
	// level 1
	addNode(&root->left, isinya = 'M');
	addNode(&root->right, isinya = 'I');
	// level 2 
	addNode(&root->left->left, isinya = 'K'); 
	addNode(&root->right->right, isinya = 'Z'); 
	addNode(&root->right->right->left, isinya = 'J');
	
	printf("\n Preorder  : "); preorder(root);
	printf("\n Inorder   : "); inorder(root);
	printf("\n Postorder : "); postorder(root);
}
