public class Heapsort
{
    public void sort(int a[])
    {
        int n = a.length;
        for(int k = n/2-1; k>=0; k--)
        {
            heapify(a,n,k);
        }
        for(int i=n-1; i>=0; i--)
        {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            heapify(a,i,0);
        }
    }

    void heapify(int a[],int n, int k)
    {
        int l = 2*k+1;
        int r = 2*k+2;
        int max = k;
        if(l<n && a[l] > a[max])
            max = l;
        if(r<n && a[r] > a[max])
            max = r;
        if(max != k)
        {
            int temp = a[k];
            a[k] = a[max];
            a[max] = temp;
            heapify(a,n,max);
        }        
    }
    
    static void print(int a[])
    {
        int n = a.length;
        for(int i=0; i<n; ++i)
        {
            System.out.println(a[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[])
    {
        int arr[] = {24, 25, 18, 27, 22};
        Heapsort obj = new Heapsort();

        System.out.println(" Given Data : ");
        print(arr);

        obj.sort(arr);

        System.out.println("Sorted Data : ");
        print(arr);
    }
}
