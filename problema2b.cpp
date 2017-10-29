#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Sortam crescator vectorul de cuvinte Texte dupa lungimile acestora
apoi parcurgem vectorul Texte si adaugam cate un cuvant pe fiecare banda;
EX:
texte(deja sortat) : 1 2 3 4 5 6,7 , nr benzi 3;
banda 1: 1 4 7
banda 2: 2 5
banda 3: 3 6
astfel vom minimiza numarul de aparitii al cuvintelor(mai ales celor de lungime mare)
*/

bool compare(int a,int b){return a < b;}

int main()
{
    int n,x,k;
    vector<int> Texte;
    vector<int> benzi[100];

    cout << "nr cunvite:";
    cin >> n;
    cout << "nr benzi:";
    cin >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> x;
        Texte.push_back(x);
    }
    int j = 0;
    sort(Texte.begin(),Texte.end(),compare);
    for(int i = 0;i < n;i++)
    {
        benzi[j].push_back(Texte[i]);
        j++;
        j = j%k;
    }
    for(int i = 0;i < k;i++)
    {
        cout << i << ":";
        for(int j = 0;j < benzi[i].size();j++)
        {
            cout << benzi[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
