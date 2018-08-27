#include <vector>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int main(){
    float total=0,winner=0,indice=0;
    vector<string> l_can(5);
    vector<int> l_vo(5);
    for(int i=0;i<5;i++){
        cout<<"Ingrese Apellido de candidato "<<i+1<<endl;
        cin>>l_can[i];
        cout<<"Ingrese cantidad de votos"<<endl;
        cin>>l_vo[i];
        total+=l_vo[i];
        if(l_vo[i]>winner){indice=i;winner=l_vo[i];}
    }
    cout<<"Candidato   Votos recibidos   %total de votos\t"<<endl;
    for(int i=0;i<5;i++){
        cout<<l_can[i]<<"   \t";
        cout<<l_vo[i]<<"   \t";
        printf("%2.2f   \t\n",l_vo[i]/total*100.0);
    }
    cout<<endl<<"Total\t"<<total<<endl;
    cout<<"El ganador de las elecciones es "<<l_can[indice]<<endl;

}
