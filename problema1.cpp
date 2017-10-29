#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

int main()
{
    vector<pair<int,int> > lista,fin;
    int n,a,b,k = 0;

    cout << "Nr intervale:";
    cin >> n;
    for(int i = 0; i < n;i++)
     {
        cout << "Intervale:";
        cin >> a >> b;
        lista.push_back(make_pair(a,b));
     }
    sort(lista.begin(),lista.end(),compare);

    fin.push_back(lista[0]);
    for(int i = 1;i < n;i++)
     {
        if(fin[k].second < lista[i].first)
        {
            fin.push_back(lista[i]);
        }
        k++;
     }

     cout << "===================================" << endl;
     cout << "Lista finala:" << endl;
     for(int i = 0;i < fin.size();i++)
     {
         cout << fin[i].first <<"-"<< fin[i].second << " ";
     }

    return 0;
}
