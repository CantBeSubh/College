#include <iostream>
using namespace std;

class BST
{
	int data;
	BST *left, *right;

public:
	BST();

	BST(int);

	BST* Insert(BST*, int);

	int Least(BST*);

	int Most(BST*);

    int Median(BST*);

    void Inorder(BST*);
};

BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST* BST ::Insert(BST* root, int value)
{
	if (!root)
	{
		return new BST(value);
	}

	if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}
	else
	{
		root->left = Insert(root->left, value);
	}

	return root;
}


int BST ::Least(BST* root){
    while(root->left!=NULL){root=root->left;}
	return root->data;
}
int BST ::Most(BST* root){
    while(root->right!=NULL){root=root->right;}
	return root->data;
}

int BST::Median(BST* root){
return root->data;
}

void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

// Driver code
int main(){;
	BST a, *root1 = NULL;
	BST b, *root2 = NULL;
	root1 = a.Insert(root1, 5);
	a.Insert(root1, 3);
	a.Insert(root1, 2);
	a.Insert(root1, 4);
	a.Insert(root1, 7);
	a.Insert(root1, 6);
	a.Insert(root1, 8);
    int least=a.Least(root1);
    int max=a.Most(root1);
    int med=a.Median(root1);
    root2=b.Insert(root2,med);
    b.Insert(root2,max);
    b.Insert(root2,least);
    b.Inorder(root2);
	return 0;
}
