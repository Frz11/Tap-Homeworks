#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>

using namespace std;



typedef pair<int,float> iPair;

float a1,a2;
struct sume{
float suma_inf,suma_superioara;
} ;
int partitie_random(vector<iPair>,int,int,sume&);
int partitie(vector<iPair>,int,int,sume&);
void sw(iPair&,iPair&);






int Al_K_lea(vector<iPair> lista,int r, int l,int k,sume& a)
{

        //cout << endl << k << endl;
       if (k >= 0 && k <= r - l + 1)
       {

        int pos = partitie_random(lista, l, r,a);
          //  cout << lista[pos].first << endl;

        if (pos-l == k-1)
            return pos;
        if (pos-l > k-1){



            return Al_K_lea(lista, pos-1, l, k,a);

        }
        if (pos-l < k-1){

            return Al_K_lea(lista, r, pos+1, k-pos+l-1,a);
        }
       }


    return -1;

}

int partitie_random(vector<iPair> lista,int l,int r,sume& a){
    int n = r-l+1;
    int pivot = rand() % n;
    //cout << endl << pivot << endl;
    sw(lista[l + pivot], lista[r]);
    return partitie(lista, l, r,a);
}

void sw(iPair& a, iPair& b)
{
    iPair temp = a;
    a = b;
    b = temp;
}


int partitie(vector<iPair> lista, int l, int r,sume& a)
{
    iPair x = lista[r];
    int i = l;

    //cout << x.first << endl;
    for (int j = l; j <= r - 1; j++)
    {
        if (lista[j].first < x.first)
        {
            //cout << lista[j].second;
            //cout << a.suma_inf + lista[j].second;
            //a.suma_inf = a.suma_inf + lista[j].second;
            sw(lista[i], lista[j]);
            i++;
        }
        else if(lista[j].first > x.first) a.suma_superioara += lista[j].second;

}
    sw(lista[i], lista[r]);
    return i;
}

iPair mediana_ponderata(vector<iPair> lista,int l,int r,sume& b) {


    int piv,z;

    if(r == 0) return lista[piv];
    if(r%2 == 0) piv = Al_K_lea(lista,r-1,l,(r+l)/2,b);
    else piv = Al_K_lea(lista,r-1,l,(r+l)/2 + 1,b);


    b.suma_inf = 0;
    b.suma_superioara =0;
    for(int i = 0;i < lista.size(); i++)
    {
        if(lista[i].first < lista[piv].first) b.suma_inf += lista[i].second;
        else if(lista[i].first > lista[piv].first) b.suma_superioara += lista[i].second;
    }
        //cout << "piv:" << piv <<" "<< b.suma_inf << endl;
    if(b.suma_inf >= 0.5){

         return mediana_ponderata(lista,l,piv,b);
    }
    else if (b.suma_superioara > 0.5){

            return mediana_ponderata(lista,piv,r,b);
    }

    else if(b.suma_inf < 0.5 && b.suma_superioara <= 0.5)
            return lista[ piv];

     return make_pair(-1,-1);
}


int main(){

vector<iPair> lista(50);
int n;
cin >> n;
for(int i = 0 ;i < n;i++){
    cin >> lista[i].first >> lista[i].second;
}
sume b;
b.suma_inf = 0;
b.suma_superioara =0;


cout << "Pivot :" << mediana_ponderata(lista,0,n,b).first << endl;
cout << "Suma inferioara:" << b.suma_inf << "Suma superioara:" << b.suma_superioara;


return 0;

}
