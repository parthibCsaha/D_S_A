#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>& a,int l,int h,int mid)
{
    int lz=mid-l+1;
    int rz=h-mid;
    int L[lz+1],R[rz+1];
    for(int i=0;i<lz;i++)
    {
    	L[i]=a[i+l];
    }
    for(int i=0;i<rz;i++)
    {
    	R[i]=a[i+mid+1];
    }
    L[lz]=R[rz]=1000000;
    int li=0,ri=0; 
    for(int i=l;i<=h;i++)
    {
    	if(L[li]<=R[ri])
    	{
    		a[i]=L[li];
    		li++;
    	}
    	else
    	{
    		a[i]=R[ri];
    		ri++;
    	}
    }
}
void mergesort(vector<int>& a,int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,h,mid);
	}
}
int main()
{
	vector<int> a{1,5,2,4,3,9};
	mergesort(a,0,5);
	for(auto i:a)cout << i << ' ';
}