#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

/*
Sortam cuburile descrescator in functie de latura si adaugam la vectorul tower cuburile din cubs de la 1 la n
cu conditia: cub[i] sa aiba culoare diferita de cubs[i-1]
*/
bool compare(pair<int,int> a, pair<int,int > b){ return a.first > b.first;}

int main()
{
    vector<pair<int,int> > cubs,tower;
    int i,n,x,y,k = 0;

    cout << "NR CUBURI:";
    cin >> n;
    cout << "CUB SI CULOARE:";
    for(i = 0;i < n;i++)
    {
        cin >> x ;
        cin >> y ;
        cubs.push_back(make_pair(x,y));
    }
    sort(cubs.begin(),cubs.end(),compare);
    tower.push_back(cubs[0]);
    for(i = 1;i < n;i++)
    {
        if(cubs[i].second != tower[k].second)
        {
            tower.push_back(cubs[i]);
            k++;
        }
    }

    cout << "H MAX = " << k + 1 << endl;
    for(int i = 0;i <= k;i++)
    {
        cout << tower[i].first << " " << tower[i].second << endl;
    }
    return 0;
}
