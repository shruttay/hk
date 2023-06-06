#include <iostream>
using namespace std;

class Graph
{
    int n,graph[10][10], visited[10], v1, v2;
    public:
    int cost;
    Graph()
    {
        cout<<"\nEnter the Number of nodes : ";
        cin>>n;
        for(int i=0; i<n; i++)
        {
            graph[i][i] = 0;
            visited[i] = 0;
        }
    }
    void create();
    void display();
    void prims();
};

void Graph::create()
{
    int ans = 1, c;
    do
    {
        cout<<"\nEnter Vertices between 0 and "<<n-1<<" : ";
        cin>>v1>>v2;
        cout<<"\nEnter distance : ";
        cin>>c;
        graph[v1][v2] = graph[v2][v1] = c;
        cout<<"\nContinue?(1/0) : ";
        cin>>ans;
    }while(ans == 1);
}

void Graph::display()
{
    cout<<"\nAdjacency matrix : ";
    for(int i=0; i<n; i++)
    {
        cout<<endl;
        for(int j=0; j<n; j++)
        {
            cout<<graph[i][j]<<"\t";
        }
    }
}

void Graph::prims()
{
    int sn;
    cout<<"\nEnter starting node : ";
    cin>>sn;
    visited[sn] = 1;
    int min = 9999;
    for (int e=0; e<n-1; e++)
    {
        min = 9999;
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 1)
            {
                for(int j=0; j<n; j++)
                {
                    if(visited[j] == 0 && i != j)
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            v1 = i;
                            v2 = j;
                        }
                    }
                }
            }
        }
        cout<<v1<<"-"<<v2<<"   ------>   "<<graph[v1][v2]<<endl;
        visited[v2] = 1;
        cost += graph[v1][v2];
    }
    cout<<"\nTotal cost : "<<cost;
}

int main()
{
    int ch;
    Graph obj;
    do
    {
        cout<<"\n\n******MENU******";
        cout<<"\n1 : Create";
        cout<<"\n2 : Display";
        cout<<"\n3 : Minimum Cost";
        cout<<"\n4 : Exit";
        cout<<"\nEnter your choice : ";
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
                obj.prims();
                break;
            case 4:
                cout<<"\nEnd of Program";
                break;
        }
    }while(ch != 4);
}
