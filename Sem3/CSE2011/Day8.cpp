#include <iostream>
using namespace std;

class BST{
	int data;
	BST *left, *right;

public:
	BST(){
        data=0;
        left=NULL;
        right=NULL;
    }

	BST(int value){
        data = value;
        left = right = NULL;
    }

	BST* Insert(BST* root, int value){
        if (!root){
            return new BST(value);
        }

        if (value > root->data){
            root->right = Insert(root->right, value);
        }
        else{
            root->left = Insert(root->left, value);
        }
        return root;
    }   
	void Inorder(BST* root){
        if (!root){
            return;
        }
        Inorder(root->left);
        cout << root->data <<"\t";
        Inorder(root->right);
    }
    void Preorder(BST* root){
        if(!root){
            return;
        }
        cout<<root->data<<"\t";
        Preorder(root->left);
        Preorder(root->right);

    }
    void Postorder(BST* root){
        if(!root){
            return;
        }
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<"\t";
    }
};

int main(){
     cout<<R"(                                                       
BBBBBBBBBBBBBBBBB      SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTT
B::::::::::::::::B   SS:::::::::::::::ST:::::::::::::::::::::T
B::::::BBBBBB:::::B S:::::SSSSSS::::::ST:::::::::::::::::::::T
BB:::::B     B:::::BS:::::S     SSSSSSST:::::TT:::::::TT:::::T
  B::::B     B:::::BS:::::S            TTTTTT  T:::::T  TTTTTT
  B::::B     B:::::BS:::::S                    T:::::T        
  B::::BBBBBB:::::B  S::::SSSS                 T:::::T        
  B:::::::::::::BB    SS::::::SSSSS            T:::::T        
  B::::BBBBBB:::::B     SSS::::::::SS          T:::::T        
  B::::B     B:::::B       SSSSSS::::S         T:::::T        
  B::::B     B:::::B            S:::::S        T:::::T        
  B::::B     B:::::B            S:::::S        T:::::T        
BB:::::BBBBBB::::::BSSSSSSS     S:::::S      TT:::::::TT      
B:::::::::::::::::B S::::::SSSSSS:::::S      T:::::::::T      
B::::::::::::::::B  S:::::::::::::::SS       T:::::::::T      
BBBBBBBBBBBBBBBBB    SSSSSSSSSSSSSSS         TTTTTTTTTTT
)";
	BST a;
    BST *root = NULL;
    int b,value;
mm:
    cout<<R"(
Choose:
    1. Insert
    2. Inorder
    3. Preorder
    4. Postorder
    5. Exit
    )"<<endl;
    cin>>b;
    switch(b){
        case 1:
            cout<<"Enter Value: ";
            cin>>value;
            if(!root){
                root = a.Insert(root, value);
                goto mm;
            }
            a.Insert(root,value);
            goto mm;
        case 2:
            a.Inorder(root);
            goto mm;
        case 3:
            a.Preorder(root);
            goto mm;
        case 4:
            a.Postorder(root);
            goto mm;
        case 5:
            cout<<"Goodbye!";
            return 0;
        default:
            cout<<"Enter Valid option!";
            goto mm;
    }
}