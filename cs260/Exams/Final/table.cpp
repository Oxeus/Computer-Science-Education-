#include "table.h"

//Please put the impelementation of the required functions here

int sumOfNodes(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}
	return (root->data + sumOfNodes(root->left) + sumOfNodes(root->right));
}

void copyLeaf(node * src, node *& dest)
{
	if (!src) return;
	dest = new node;
	dest->data = src->data;
	copyLeaf(src->left, dest->left);
    	copyLeaf(src->right, dest->right);
}

