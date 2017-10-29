#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

struct activitate
{
    int t,p,ind;
}a,b;

/*
sortam descrescator vectorul de activitati in functie de profit
parcugem vectorul, si incercam sa asezam activitatea de profit maxim
de la pasul curent cat mai tarziu posibil.
cand avem un numar de activitati egal cu cel mai mare timp
de finalizare al activitatilor algoritmul se opreste
(nu putem sa avem mai mult de 4 activitati daca nu exista
 o activitate care sa se termine la 5);
*/

bool compare(activitate a, activitate b) {return a.p > b.p;}

using namespace std;

int main()
{
    int n,timp_max = 0, k = 0;
    vector<activitate> activitati;
    activitate solutie[100];
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        solutie[i].t = 0;
        cin >> a.p;
        cin >> a.t;
        a.ind = i;
        activitati.push_back(a);
        if(timp_max < a.t) timp_max = a.t;
    }
    sort(activitati.begin(),activitati.end(),compare);
 //   for(int i = 0;i < n;i++) cout << activitati[i].p << endl;
    for(int i = 0;i < n;i++)
    {
        if(k == timp_max) break;
        int j = activitati[i].t-1;
        while(j > -1)
        {
            if(solutie[j].t == 0)
            {
                solutie[j] = activitati[i];
                j = -1;
                k++;
            }
            else j--;

        }

    }
    int prof = 0;
    for(int i = 0;i < timp_max;i++)
    {
        cout << solutie[i].ind + 1 << " ";
        prof += solutie[i].p;
    }
    cout << "\nPROFIT:" << prof;
    cout << endl;
    return 0;
}
