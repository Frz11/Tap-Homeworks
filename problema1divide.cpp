#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int divide(vector<int> a,int l,int r)
{

    if(r == 0) return -1;

    if(a[(l+r)/2] == (l+r)/2) return (l+r)/2;
    if(a[(l+r)/2] > (l+r)/2) return divide(a,l,(r+l)/2);
    if(a[(l+r)/2] < (l+r)/2) return divide(a,(l+r)/2,r);

}


int main()
{
    int n;
    vector<int> a(100);
    cin >> n;
    for(int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    cout << divide(a,0,n);
    return 0;
}
