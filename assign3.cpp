#include<bits/stdc++.h>
using namespace std;


class solution{
    private:
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    public:

    void selectionsort(vector<int>&vect,int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int min=i;
            for(int j=i+1;j<n;j++)
            {
                if(vect[j]<vect[min])
                {
                    min=j;
                }
            }
            swap(vect[i],vect[min]);
        }
    }
    
};
int main()
{
    solution s;
    int n;
    cout<<"Enter the size of Array :";
    cin>>n;
    vector<int>data(n);
    for (int i = 0; i < n; i++)
    {
        cin>>data[i];
    }
    s.selectionsort(data,n);
    cout << "\n\n Sorted array in Acsending Order:";
    for (int i = 0; i < n; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;    
    return 0;
}