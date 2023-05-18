#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>& a,int l,int h,int e)
{
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(a[mid]==e)return mid;
        if(a[mid]>e) {
            binarysearch(a,l,mid-1,e);
        }
        else {
            binarysearch(a,mid+1,h,e);
        }
    }
    else return -1;
}
int main()
{
	vector<int> a{1,2,3,4,5,6};
	cout << binarysearch(a,0,5,6);
}