# include <iostream>
using namespace std;

class TBT
{
    struct node
    {
        int data;
        node *lc, *rc;
        int lflag, rflag;
    }*root, *header;
    int count = 0;

    public:
    TBT()
    {
        root = NULL;
        header = new node;
        header->lc = header->rc = header;
        header->lflag = header->rflag = 0;
    }
    void create();
    void preorder();
    void postorder();
    void inorder();
};

void TBT::create()
{
    char ans = 'y';
    do
    {
        count++;
        node *temp, *curr;
        temp = new node;
        temp->lc = temp->rc = NULL;
        temp->lflag = temp->rflag = 0;
        cout<<"\nEnter data : ";
        cin>>temp->data;
        if(root == NULL)
        {
            root = temp;
            header->lc = root;
            header->lflag = header->rflag = 1;
            root->lc = root->rc = header;
        }
        else
        {
            curr = root;
            while(true)
            {
                if(temp->data < curr->data)
                {
                    if(curr->lflag == 0)
                    {
                        temp->lc = curr->lc;
                        curr->lc = temp;
                        temp->rc = curr;
                        curr->lflag = 1;
                        break;
                    }
                    else
                        curr = curr->lc;
                }
                else if(temp->data > curr->data)
                {
                     if(curr->rflag == 0)
                    {
                        temp->rc = curr->rc;
                        curr->rc = temp;
                        temp->lc = curr;
                        curr->rflag = 1;
                        break;
                    }
                    else
                        curr = curr->rc;
                }
            }
        }
        cout<<"\nInsert more?(y/n) : ";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
}

void TBT::preorder()
{
    if(header->lc == header)
    {
        cout<<"\nTBT is empty";
    }
    else
    {
        node *t = root;
        cout<<t->data<<" ";
        while(true)
        {
            while(t->lflag == 1)
            {
                t = t->lc;
                cout<<t->data<<" ";
            }
            while(t->rflag != 1)
                t = t->rc;
            if(t == header)
                break;
            t = t->rc;
            cout<<t->data<<" ";
        }
    }
}

void TBT::postorder()
{
    if(header->lc == header)
    {
        cout<<"\nTBT is Empty";
    }
    else
    {
        node *t = root;
        int arr[count], i = -1;
        arr[++i] = t->data;
        while(true)
        {
            while (t->rflag == 1)
            {
                t = t->rc;
                arr[++i] = t->data;
            }
            if(t->rflag == 0 && t->rflag == 0)
                while(t->lflag != 1)
                    t = t->lc;
            if(t->lflag == 1)
            {
                if(t == header)
                    break;
                t = t->lc;
                arr[++i] = t->data;
            }
        }
        for(int j = count - 1; j>=0; j--)
            cout<<arr[j]<<" ";
    }
}

void TBT::inorder()
{
    if(header->lc == header)
    {
        cout<<"\nTBT is Empty";
    }
    else
    {
        node *t = root;
        int flag = 0;
        while(true)
        {
            while(t->lflag == 1)
                t = t->lc;
            cout<<t->data<<" ";
            if(t->rflag == 1)
                t = t->rc;
            else
            {
                while(t->rflag != 1)
                {
                    t = t->rc;
                    if(t == header)
                    {
                        flag = 1;
                        break;
                    }
                    cout<<t->data<<" ";
                }
                if(flag == 1)
                    break;
                t = t->rc;
            }
        }
    }
}

int main()
{
    TBT obj;
    int ch;
    do
    {
        cout<<"\n******MENU******";
        cout<<"\n1 : Create";
        cout<<"\n2 : Preorder Traversal";
        cout<<"\n3 : Postorder Traversal";
        cout<<"\n4 : Inorder Traversal";
        cout<<"\n5 : Exit";
        cout<<"\nEnter your Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                obj.create();
                break;
            case 2:
                obj.preorder();
                break;
            case 3:
                obj.postorder();
                break;
            case 4:
                obj.inorder();
                break;
            case 5:
                cout<<"\nEnd of Program";
                break;
        }
    }while(ch != 5);
    return 0;
}
