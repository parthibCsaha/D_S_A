#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int>& a,int n)
{
    for(int i=0;i<n-1;i++) 
    {
        if(a[i]>a[i+1])
        {
            int j=i+1;
            while(j>0&&a[j-1]>a[j])
            {
                swap(a[j],a[j-1]);
                j--;
            }
        }
    }
}
int main()
{
	vector<int> a{1,5,2,4,3,9};
	insertionsort(a,5);
	for(auto i:a)cout << i << ' ';
}