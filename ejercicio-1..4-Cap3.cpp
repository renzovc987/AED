#include <iostream>

using namespace std;



/*
int main() {
    int x;
    cin>>x;
    int lista[x];
    for(int i=0;i<x;i++){
        cin>>lista[i];
    }
    int y,i=0;
    cin>>y;
    while(i<x){
        if(y==lista[i]){lista[i]=lista[x-1];x=x-1;}
        else{
            i++;
        }

    }
    for(int i=0;i<x;i++){
        cout<<lista[i]<<endl;
    }

}
*/

class arrayListType
{
private:
    int tamano;
    int lista[3000];
public:
    arrayListType(){
        tamano = 0;
    }
    void llenar(int x){
        tamano = x;
        for(int i=0;i<x;i++){
            cin>>lista[i];
        }
    }
    void setTam(int x){
        tamano = x;
    }
    void elimElem(int y){
        int i=0;
        while(i<tamano){
            if(y==lista[i]){
                lista[i]=lista[tamano-1];
                tamano=tamano-1;
                break;
            }
            else{
                i++;
            }
        }
    }
    void elimElemall(int y){
        int i=0;
        while(i<tamano){
            if(y==lista[i]){
                lista[i]=lista[tamano-1];
                tamano=tamano-1;
                           }
            else{
                i++;
            }
        }
    }
    void mostrar(){
        for(int i=0;i<tamano;i++){
            cout<<lista[i]<<" ";
        }
        cout<<endl;
    }
    int peque(){
        int mini=lista[0];
        for(int i=0;i<tamano;i++){
            if(lista[i]<mini){mini=lista[i];}


        }
        return mini;



    }
    int mayor(){
        int maxi=lista[0];
        for(int i=0;i<tamano;i++){
            if(lista[i]>maxi){maxi=lista[i];}


        }
        return maxi;



    }
    //~arrayListType();

};

int main() {
    arrayListType list;
    list.llenar(6);
    list.mostrar();
    cout<<list.peque()<<endl;
     cout<<list.mayor()<<endl;

    return 0;
}
