#include <iostream>
using namespace std;

struct node
{
    string word, mean;
    node *lc, *rc;
};

class Dict
{
    public:
    node *root;
    Dict()
    {
        root = NULL;
    }
    void insert();
    void display();
    void ascending(node *t);
    void descending(node *t);
    void search();
    void callDel();
    node *del(node *t, string key);
    node *successor(node *t);
    node *predecessor(node *t);
};

void Dict::insert()
{
    node *temp, *curr;
    temp = new node;
    temp->lc = temp->rc = NULL;
    cout<<"\nEnter Word : ";
    cin>>temp->word;
    cout<<"\nEnter Meaning : ";
    cin>>temp->mean;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        curr = root;
        while(true)
        {
            if(temp->word == curr->word)
            {
                cout<<"\nWord already exist";
                break;
            }
            else if(temp->word < curr->word)
            {
                if(curr->lc == NULL)
                {
                    curr->lc = temp;
                    break;
                }
                else
                    curr = curr->lc;
            }
            else
            {
                if(curr->rc == NULL)
                {
                    curr->rc = temp;
                    break;
                }
                else
                    curr = curr->rc;
            }
        }
    }
}

void Dict::display()
{
    cout<<"\nAscending order : ";
    ascending(root);
    cout<<"\nDescending order : ";
    descending(root);
}

void Dict::ascending(node *t)
{
    if(t != NULL)
    {
        ascending(t->lc);
        cout<<"\n"<<t->word<<" : "<<t->mean;
        ascending(t->rc);
    }
}

void Dict::descending(node *t)
{
    if(t != NULL)
    {
        descending(t->rc);
        cout<<"\n"<<t->word<<" : "<<t->mean;
        descending(t->lc);
    }
}

void Dict::search()
{
    node *t = root;
    int cmp = 1;
    string key;
    cout<<"\nEnter word to search : ";
    cin>>key;
    int flag = 0;
    if(t == NULL)
    {
        cout<<"\nNo data";
    }
    else
    {
        while(t != NULL)
        {
            if(key == t->word)
            {
                flag = 1;
                break;
            }
            else if(key < t->word)
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
        if(flag == 0)
            cout<<"\nKey not found";
        else
        {
            cout<<"\n"<<t->word<<" : "<<t->mean;
            cout<<"\nKey found in "<<cmp<<" comparisons";
        }
    }
}
 
node* Dict::del(node *t, string key)
{
    if(t == NULL)
        return NULL;
    if(key < t->word)
        t->lc = del(t->lc, key);
    else if(key > t->word)
        t->rc = del(t->rc, key);
    else
    {
        if (t->lc == NULL)
        {
            node* temp = t->rc;
            delete t;
            return temp;
        }
        else if (t->rc == NULL)
        {
            node* temp = t->lc;
            delete t;
            return temp;
        }
        
        node* succ = successor(t);
        t->word = succ->word;
        t->mean = succ->mean;
        t->rc = del(t->rc, succ->word);
    }
    return t;
}

node* Dict::successor(node *t)
{
    t = t->rc;
    while(t->lc != NULL)
        t = t->lc;
    return t;
}

void Dict::callDel()
{
    string key;
    cout<<"\nEnter Word to delete : ";
    cin>>key;
    root = del(root, key);
}

int main()
{
    Dict obj;
    int ch;
    do
    {
        cout<<"\n******MENU******";
        cout<<"\n1 : Insert";
        cout<<"\n2 : Display";
        cout<<"\n3 : Search";
        cout<<"\n4 : Delete";
        cout<<"\n5 : Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.search();
                break;
            case 4:
                obj.callDel();
                break;
            case 5:
                cout<<"\nEnd of Program";
                break;
        }
    }while(ch != 5);
}
