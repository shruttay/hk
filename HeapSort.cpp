#include <iostream>
using namespace std;

class heap
{
    public:
    void accept()
    {
        int n;
        cout<<"\nEnter the number of Students : ";
        cin>>n;
        int a[n];
        cout<<"\nEnter the Marks of Students : "<<endl;
        for (int i = 0; i < n  ; i++)
        {
            cin>>a[i];
        }
        heapsort(a,n);
        display(a,n);
    }

    void heapsort(int a[], int n)
    {
        maxheap(a,n);
        int temp;
        for(int i=n-1; i>=0; i--)
        {
            temp = a[i];
            a[i] = a[0];
            a[0] = temp;
            heapify(a,0,i);
        }
    }

    void maxheap(int a[], int n)
    {
        for(int k=(n/2)-1; k>=0; k--)
        {
            heapify(a,k,n);
        }
    }

    void heapify(int a[], int k, int n)
    {
        int l,r, max, temp;
        l = 2*k + 1;
        r = 2*k + 2;
        max = k;
        if(l<n && a[l] > a[max])
            max = l;
        if(r<n && a[r] > a[max])
            max = r;
        if(max!=k)
        {
            temp = a[k];
            a[k] = a[max];
            a[max] = temp;
            heapify(a, max, n);
        }
    }

    void display(int a[], int n)
    {
        cout<<"\n\nSorted Marks : "<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<endl;
        }
        cout<<"\n\nMinimum Marks : "<<a[0];
        cout<<"\nMaxmimum Marks : "<<a[n-1];
    }
};

int main()
{
    heap obj;
    obj.accept();
    return 0;
}
