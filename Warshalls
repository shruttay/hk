#include <iostream>
using namespace std;
#define INF 999

class Graph
{
    int graph[5][5], n, v1, v2, cost;
    public:
    Graph()
    {
        cout<<"\nEnter Number of Vertices : ";
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = INF;
            }
        }
    }
    void create();
    void display();
    void FloydWarshall();
};

void Graph::create()
{
    int ans = 1;
    do
    {
        cout<<"\nEnter the Vertices between 0 and "<<n-1<<" : ";
        cin>>v1>>v2;
        cout<<"\nEnter cost : ";
        cin>>cost;
        graph[v1][v2] = cost;
        cout<<"\nContinue?(1/0) : ";
        cin>>ans;
    }while(ans == 1);
}

void Graph::display()
{
    for(int i=0; i<n; i++)
    {
        cout<<endl;
        for (int j=0; j<n; j++)
        {
            if(graph[i][j] == INF)
                cout<<"INF\t";
            else
                cout<<graph[i][j]<<"\t";
        }
    }
}

void Graph::FloydWarshall()
{
    cout<<"\nAdjacency Matrix : ";
    display();
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
        if(k != n-1)
        {
            cout<<"\n\nMatrix "<<k+1<<" : ";
            display();
        }
    }
    cout<<"\n\nFinal Matrix : ";
    display();
}

int main()
{
    Graph obj;
    cout<<"\n\nWarshall's Algorithm";
    obj.create();
    obj.FloydWarshall();
    cout<<"\n\nEnd of Program";
    return 0;
}
