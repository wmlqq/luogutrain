#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>W11;
    vector<int>W21;
    vector<int>L11;
    vector<int>L21;
    int index11=0;
    int index21=0;
    W11.push_back(0);
    W21.push_back(0);
    L11.push_back(0);
    L21.push_back(0);
    while(1){
        char c;
        cin>>c;
        if(c=='E')break;

        if(c=='W'){
            if(++W11[index11]>=11&&W11[index11]-L11[index11]>=2){index11++;W11.push_back(0);L11.push_back(0);}
            if(++W21[index21]>=21&&W21[index21]-L21[index21]>=2){index21++;W21.push_back(0);L21.push_back(0);}
        }
        if(c=='L'){
            if(++L11[index11]>=11&&L11[index11]-W11[index11]>=2){index11++;W11.push_back(0);L11.push_back(0);}
            if(++L21[index21]>=21&&L21[index21]-W21[index21]>=2){index21++;W21.push_back(0);L21.push_back(0);}
        }
        
    }

    for(int i=0;i<W11.size();i++)cout<<W11[i]<<':'<<L11[i]<<endl;
    cout<<endl;
    for(int i=0;i<W21.size();i++)cout<<W21[i]<<':'<<L21[i]<<endl;
    return 0;
}