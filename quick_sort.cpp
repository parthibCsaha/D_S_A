#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& a,int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    while(i<j)
    {
    	do
    	{
    		i++;
    	}while(a[i]<=pivot);
    	do
    	{
    		j--;
    	}while(a[j]>pivot);
    	if(i<j)swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}
void quicksort(vector<int>& a,int l,int h)
{
	if(l<h)
	{
		int j=partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1,h);
	}
}
int main()
{
	vector<int> a{1,5,2,4,3,1000000};
	quicksort(a,0,5);
	a.pop_back();
	for(auto i:a)cout << i << ' ';
}