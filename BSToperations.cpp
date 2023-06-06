#include <iostream>
using namespace std;

class BST
{
    struct node
    {
        int data;
        node *lc, *rc;
    }*root;

    public:
    BST()
    {
        root = NULL;
    }
    void create();
    void display();
    void preorder(node *t);
    void inorder(node *t);
    void postorder(node *t);
    int height(node *t);
    void callheight();
    void min();
    void mirror();
    void swapn(node *t);
    void search();
};

void BST::create()
{
    char ans = 'y';
    do
    {
        node *temp, *curr;
        temp = new node;
        cout<<"\nEnter Data : ";
        cin>>temp->data;
        temp->lc = NULL;
        temp->rc = NULL;
        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            curr = root;
            while(curr!=NULL)
            {
                if(temp->data < curr->data)
                {
                    if(curr->lc == NULL)
                    {
                        curr->lc = temp;
                        break;
                    }
                    else
                    {
                        curr = curr->lc;
                    }
                }
                if(temp->data > curr->data)
                {
                    if(curr->rc == NULL)
                    {
                        curr->rc = temp;
                        break;
                    }
                    else
                    {
                        curr = curr->rc;
                    }
                }
            }
        }
        cout<<"\nInsert more?(y/n) : ";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
}

void BST::display()
{
    cout<<"\nPreorder Traversal : ";
    preorder(root);
    cout<<"\nInorder Traversal : ";
    inorder(root);
    cout<<"\nPostorder Traversal : ";
    postorder(root);
}

void BST::preorder(node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->lc);
        preorder(t->rc);
    }
}

void BST::inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->lc);
        cout<<t->data<<" ";
        inorder(t->rc);
    }
}

void BST::postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->lc);
        postorder(t->rc);
        cout<<t->data<<" ";
    }
}

int BST::height(node *t)
{
    int lheight, rheight;
    if(t == NULL)
    {
        return 0;
    }
    else
    {
        lheight = height(t->lc);
        rheight = height(t->rc);
        if(lheight > rheight)
        {
            return(lheight + 1);
        }
        else
        {
            return(rheight + 1);
        }
    }
}

void BST::callheight()
{
    cout<<"\nHeight of BST : "<<height(root);
}

void BST::min()
{
    node *t = root;
    while(t->lc != NULL)
    {
        t = t->lc;
    }
    cout<<"\nMinimum Element : "<<t->data;
}

void BST::mirror()
{
    if(root == NULL)
    {
        cout<<"\nBST is empty";
    }
    else
    {
        swapn(root);
    }
}

void BST::swapn(node *t)
{
    node *temp = NULL;
    if(t->lc != NULL)
        swapn(t->lc);
    if(t->rc != NULL)
        swapn(t->rc);
    temp = t->lc;
    t->lc = t->rc;
    t->rc = temp;
}

void BST::search()
{
    int key, cmp = 1, flag = 0 ;
    cout<<"\nEnter key to search : ";
    cin>>key;
    node *t = root;
    if(t == NULL)
    {
        cout<<"\nBST is empty";
    }
    else
    {
        while(t != NULL)
        {
            if(key == t->data)
            {
                flag = 1;
                break;
            }
            else if(key < t->data)
            {
                t = t->lc;
                cmp++;
            }
            else
            {
                t = t->rc;
                cmp++;
            }
        }
    }
    if(flag == 0)
    {
        cout<<"\nKey not found";
    }
    else
    {
        cout<<"\nKey found in "<<cmp<<" comparisons";
    }
}

int main()
{
    BST obj;
    int ch;
    do
    {
        cout<<"\n******MENU******";
        cout<<"\n1 : Create";
        cout<<"\n2 : Display";
        cout<<"\n3 : Height";
        cout<<"\n4 : Minimum Element";
        cout<<"\n5 : Search";
        cout<<"\n6 : Exit";
        cout<<"\nEnter yor Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                obj.create();
                break;
            case 2: 
                obj.display();
                break;
            case 3: 
                obj.callheight();
                break;
            case 4: 
                obj.min();
                break;
            case 5: 
                obj.search();
                break;
            case 6: 
                cout<<"\nEnd of Program";
                break;
        }
    }while(ch != 6);
    return 0;   
}
