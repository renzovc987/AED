#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//238
class Polinomio{
private:
    int grado;
    vector<int> pol;
public:
    Polinomio(int grad=0){
        grado=grad;
        pol.assign(grad,0);
    }
    Polinomio(int lis[],int n){
        grado=n;
        //copy(lis,lis+grado,pol.begin());
        for(int i=0;i<n;i++){
            pol.push_back(lis[i]);
        }
    }
    void a_coeficiente(int grado,int valor){
        if(this->grado<grado)pol.resize(grado);
        pol[grado]=valor;
    }
    void mostrar(){
        for(int i=0;i<grado;i++){
            if(pol[i]==0)continue;
            if(i==0)cout<<pol[i];
            else if(i==1)cout<<pol[i]<<"x";
            else cout<<pol[i]<<"x^"<<i;
            if(i!=grado-1)cout<<" + ";
        }
        cout<<endl;
    }
    int get_g(){
        return grado;
    }
    int get_i(int i){
        return pol[i];
    }
    Polinomio operator + (Polinomio&p){
        int ma=max(grado,p.get_g());
        Polinomio aux(ma);
        for(int i=0;i<ma;i++){
            aux.a_coeficiente(i,pol[i]+p.get_i(i));
        }
        return aux;
    }
    Polinomio operator - (Polinomio&p){
        int ma=max(grado,p.get_g());
        Polinomio aux(ma);
        for(int i=0;i<ma;i++){
            aux.a_coeficiente(i,pol[i]-p.get_i(i));
        }
        return aux;
    }
};


int main(){
    int lista[] ={2,1,3,0,1};
    int lista2[] ={1,0,3,4,5};
    Polinomio p1(lista,5);
    Polinomio p2(lista2,5);
    p1.mostrar();
    p2.mostrar();
    Polinomio p3 =p1+p2;
    //Polinomio p3 =p1-p2;
    p3.mostrar();

}
