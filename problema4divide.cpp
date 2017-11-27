#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef pair<float,float> iPair;
vector<iPair> X,Y;

bool sort_y(iPair a, iPair b);
float distanta(iPair a,iPair b){
    float dist;
    dist = sqrt(pow(b.first-a.first,2) + pow(b.second-a.second,2));
    return dist;
}


float DivImp(vector<iPair> Y,int l,int r){
    if(r-l < 4){
        float mi = distanta(X[l],X[l+1]);
        for(int i = l;i < r;i++){

            for(int j = i+1;j < r;j++){
                if(mi > distanta(X[i],X[j])){
                    mi = distanta(X[i],X[j]);
                }
            }
        }

        return mi;
    }
    else{
        int mij = (r+l)/2;
        vector<iPair> SY,DY,LY;
        float d,d1,d2;
        cout << "ok!" << endl;
        for(int i = l;i < r;i++){
                if(Y[i].first <= X[mij].first)
                    SY.push_back(Y[i]);
                else
                    DY.push_back(Y[i]);
        }
        //for(int i = mij+1;i < r;i++) DY.push_back(X[i]);
        //sort(X.begin(),X.begin()+mij+1,sort_y);
        //sort(X.begin()+mij+1,X.begin()+r,sort_y);
        d1 = DivImp(SY,l,mij+1);
        d2 = DivImp(DY,mij+1,r);
        d = min(d1,d2);
        for(int i = 0;i < Y.size();i++)
        {
            if(fabs(fabs(Y[i].first)-fabs(mij)) <= d){
                LY.push_back(Y[i]);
            }
        }
        float d3 = INT_MAX - 1;
        for(int i = 0;i < LY.size();i++){
            for(int j = i+1;j < LY.size();j++){
                if(d3 > distanta(LY[i],LY[j])){
                    d3 = distanta(LY[i],LY[j]);
                }
            }
        }
        d = min(d,d3);
        return d;

    }

}




bool sort_x(iPair a,iPair b){

    return a.first < b.first;

}

bool sort_y(iPair a, iPair b){

    return a.second < b.second;
}


int main()
{
    int n;
    ifstream in("puncte.in");
    in >> n;
    vector<iPair> plan(n);
    for(int i = 0;i < n;i++){
        in >> plan[i].first >> plan[i].second;
    }

    for(int i = 0;i < n;i++){
        X.push_back(plan[i]);
        Y.push_back(plan[i]);
    }
    sort(X.begin(),X.end(),sort_x);
    sort(Y.begin(),Y.end(),sort_y);
    cout << DivImp(Y,0,n);
}
