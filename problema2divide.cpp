#include <iostream>
#include <math.h>

using namespace std;
int m,n,g = 1,n1,k = 1;
struct infoMat{
    int x1,y1,x2,y2;//pozitii pt colturi;
    int pozitie;//ce cadran reprezinta matricea noastra
};

void completeaza(int Tabla[100][100],infoMat info,int x,int y,int k,int& g1,int& g2)
{
           if(!(x >= info.x1 && x <= info.x2 && y >= info.y1 && y <= info.y2)) // daca gaura nu este in matrice -> completam o piesa;
        {

            if(info.pozitie == 0 && Tabla[info.x2][info.y2]== 0) //matricea stanga-sus
            {
                Tabla[info.x2][info.y2] = k;
                g1 = info.x2;
                g2 = info.y2;
            }
            else if(info.pozitie == 1 && Tabla[info.x1][info.y2] == 0) // colt stanga-jos
            {
                Tabla[info.x1][info.y2] = k;
                g1 = info.x1;
                g2 = info.y2;
            }
            else if(info.pozitie == 2 && Tabla[info.x2][info.y1] == 0) // colt dreapta-sus
            {
                Tabla[info.x2][info.y1] = k;
                g1 = info.x2;
                g2 = info.y1;
            }
            else if(info.pozitie == 3 && Tabla[info.x1][info.y1] == 0) // colt dreapta-jos
            {
                Tabla[info.x1][info.y1] = k;
                g1 = info.x1;
                g2 = info.y1;
            }

        }

}

int divide(int Tabla[100][100],infoMat info,int x,int y,int z){

    infoMat b[4];


    if(info.x1 != info.x2 && info.y1 != info.y2)
    {
        int g[8];
        for(int i = 0;i < 7;i++){g[i] = x;g[i+1] = y;}
        b[0].x1 = info.x1;
        b[0].y1 = info.y1;
        b[0].x2 = (info.x1 + info.x2)/2;
        b[0].y2 = (info.y1 + info.y2)/2;
        b[0].pozitie = 0;
        completeaza(Tabla,b[0],x,y,k,g[0],g[1]);


        b[1].x1 = (info.x1 + info.x2)/2+1;
        b[1].y1 = info.y1;
        b[1].x2 = info.x2;
        b[1].y2 = (info.y1 + info.y2)/2;
        b[1].pozitie = 1;
        completeaza(Tabla,b[1],x,y,k,g[2],g[3]);


        b[2].x1 = info.x1;
        b[2].y1 = (info.y1 + info.y2)/2+1;
        b[2].x2 = (info.x1 + info.x2)/2;
        b[2].y2 = info.y2;
        b[2].pozitie = 2;
        completeaza(Tabla,b[2],x,y,k,g[4],g[5]);


        b[3].x1 = (info.x2 + info.x1)/2+1;
        b[3].y1 = (info.y2 + info.y1)/2+1;
        b[3].x2 = info.x2;
        b[3].y2 = info.y2;
        b[3].pozitie = 3;
        completeaza(Tabla,b[3],x,y,k,g[6],g[7]);
        k++;
        divide(Tabla,b[0],g[0],g[1],k);
        divide(Tabla,b[1],g[2],g[3],k);
        divide(Tabla,b[2],g[4],g[5],k);
        divide(Tabla,b[3],g[6],g[7],k);

    }



    }
    //else if(info.x1 != x || info.y1 != y){
           // Tabla[info.x1][info.y1] = k;





int main(){

    int x,y,Tabla[100][100];
    cin >> n >> x >> y;
    n1 = n;
    n = pow(2,n);
    Tabla[x][y] = 0;
    infoMat info;
    info.x1 = 0;
    info.y1 = 0;
    info.y2 = n-1;
    info.x2 = n-1;
    info.pozitie = -1;
    divide(Tabla,info,x,y,1);

    cout << endl;
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << Tabla[i][j] << " ";
            }
            cout << endl;
        }

    return 0;
}
