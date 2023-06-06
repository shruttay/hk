#include <iostream>
#define max 10
using namespace std;

class node
{
    node *next;
    string city;
    int time;
    public:
    friend class graph;
    node()
    {
        next = NULL;
        city = " ";
        time = 0;
    }
    node(string city, int weight)
    {
        next = NULL;
        this->city = city;
        time = weight;
    }
};

class graph
{
    node *start[max];
    int n;
    public:
    friend class que;
    static int cnt;
    string vis[max];
    graph(int num)
    {
        n = num;
        for(int i=0; i<n; i++)
            start[i] = NULL;
    }
    void getdata();
    void insert(string city1, string city2, int time);
    int index(string city);
    void display();
    void bfs(string sc);
    int visited(string city);
};

int graph::cnt = 0;
class que
{
    int f,r;
    public:
    string q[max];
    que()
    {
        f = r = -1;
    }
    int isQFull()
    {
        if(r == max -1)
            return 1;
        else
            return 0;
    }
    int isQEmpty()
    {
        if(f==-1 && r==-1)
            return 1;
        else
            return 0;
    }
    void add(string s);
    string del();
    int search(string city);
};

void que::add(string s)
{
    if(isQFull())
        cout<<"\nQueue is Full";
    else
    {
        if(f==-1)
        {
            f = r = 0;
            q[r] = s;
        }
        else
        {
            r++;
            q[r] = s;
        }
    }
}

string que::del()
{
    string city;
    if(isQEmpty())
        cout<<"\nQueue is Empty";
    else
    {
        if(f == r)
        {
            city = q[f];
            f = r = -1;
        }
        else
        {
            city = q[f];
            f++;
        }
        return city;
    }
}

int que::search(string city)
{
    if(f==-1 && r ==-1)
        return 0;
    else
    {
        for(int i=f; i<=r; i++)
        {
            if(q[i] == city)
                return 1;
        }
        return 0;
    }
}

void graph::getdata()
{
    string city1, city2;
    int flight, time;
    cout<<"\nEnter City Details";
    for(int i=0; i<n; i++)
    {
        start[i] = new node;
        cout<<"\nEnter name of city "<<i+1<<" : ";
        cin>>start[i]->city;
    }
    cout<<"\nEnter flight Details";
    cout<<"\nEnter number of flights : ";
    cin>>flight;
    for(int i=0; i<flight; i++)
    {
        cout<<"\nEnter Source : ";
        cin>>city1;
        cout<<"\nEnter Destination : ";
        cin>>city2;
        cout<<"\nEnter Flight Time : ";
        cin>>time;
        insert(city1, city2, time);
        insert(city2, city1, time);
    }
}

void graph::insert(string city1, string city2, int time)
{
    node *source;
    node *dest = new node(city2, time);
    int ind = index(city1);
    source = start[ind];
    while(source->next != NULL)
        source = source->next;
    source->next = dest;
}

int graph::index(string city)
{
    for(int i=0; i<n; i++)
    {
        if(start[i]->city == city)
            return i;
    }
    return -1;
}

void graph::display()
{
    node *source;
    for(int i=0; i<n; i++)
    {
        source = start[i];
        while(source != NULL)
        {
            cout<<source->city<<"("<<source->time<<")"<<" --> ";
            source = source->next;
        }
        cout<<"NULL"<<endl;
    }
}

void graph::bfs(string sc)
{
    que q;
    node *head;
    string str;
    q.add(sc);
    while(q.isQEmpty() == 0)
    {
        str = q.del();
        cout<<"\t"<<str;
        vis[cnt] = str;
        cnt++;
        int ind = index(str);
        head = start[ind];
        while(head->next!= NULL)
        {
            head = head->next;
            if((!q.search(head->city)) && (!visited(head->city)))
                q.add(head->city);
        }
    }
}

int graph::visited(string city)
{
    for(int i=0; i<cnt; i++)
    {
        if(vis[i] == city)
            return 1;
    }
    return 0;
}

int main()
{
    int num,ch;
    cout<<"\nEnter the number of Cities : ";
    cin>>num;
    graph g(num);
    string cs;
    do
    {
        cout<<"\n\n******MENU******";
        cout<<"\n1 : Insert";
        cout<<"\n2 : Display";
        cout<<"\n3 : BFS";
        cout<<"\n4 : Exit";
        cout<<"\nEnter choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                g.getdata();
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout<<"\nEnter the Starting city : ";
                cin>>cs;
                g.bfs(cs);
                break;
            case 4:
                cout<<"\nEnd of Program";
                break;
        }
    } while (ch != 4);
    return 0;
}
