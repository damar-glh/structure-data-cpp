#include <iostream>
using namespace std;

struct node {
	char data;
	node *left;
	node *right;
};
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
	addNode(&root->right->right, isinya = 'J');
	
	printf("\n Preorder  : ");
	printf("\n Inorder   : ");
	printf("\n Postorder : "); 
}
