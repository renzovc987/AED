#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Complejo
{
    public:
    int parte_real;
    int parte_compleja;
public:
    Complejo(int real=0,int com=0){
        this->parte_real=real;
        this->parte_compleja=com;
    }
    int comprobar(){
        if(parte_compleja==0&&parte_real==0)return 0;
        else if(parte_real>0||parte_compleja>0) return 1;
        else return -1;
    }
};
 Complejo operator+(Complejo o,Complejo u)
    {
        Complejo res;
        res.parte_real=o.parte_real+u.parte_real;
        res.parte_compleja=o.parte_compleja+u.parte_compleja;
        return res;
    }
 Complejo operator-(Complejo a,Complejo b)
    {
        Complejo res1;
        res1.parte_real=a.parte_real-b.parte_real;
        res1.parte_compleja=a.parte_compleja-b.parte_compleja;
        return res1;
    }
 Complejo operator*(Complejo a,Complejo b){
        Complejo res1;
        res1.parte_real=a.parte_real*b.parte_compleja-(a.parte_compleja*b.parte_compleja);
        res1.parte_compleja=a.parte_real*b.parte_compleja+a.parte_compleja*b.parte_real;
        return res1;
    }
ostream&operator <<(ostream&salida, Complejo c){
    if(c.parte_compleja<0){
        salida<<c.parte_real<<c.parte_compleja<<"i";
    }
    else{
         salida<<c.parte_real<<"+"<<c.parte_compleja<<"i";
    }
    return salida;
}



class Polynomial_type{
public:
    int grado;
    Complejo *pol;

    Polynomial_type(int grad=0){
        grado=grad;
        pol=new Complejo[grad+1];
    }
    void a_coeficiente(int grado,Complejo valor){
        pol[grado]=valor;
    }
    void s_coeficiente(int grado,Complejo valor){
        pol[grado]=pol[grado]+valor;
    }
    void mostrar(){
        bool inicio=false;
        for(int i=grado;i>=0;i--){
            if(pol[i].comprobar()==0)continue;
            if(pol[i].comprobar()>0){
                if(inicio)cout<<" + ";
            }
            inicio=true;
            if(i==0)cout<<pol[i];
            else if(i==1)cout<<pol[i]<<"x";
            else cout<<pol[i]<<"x^"<<i;
        }
        cout<<endl;
    }
    int get_g(){
        return grado;
    }
    Complejo get_i(int i){
        return pol[i];
    }
    void insertar(){
        for(int i=0;i<=grado;i++){
            cout<<"termino "<<i<<":"<<endl;
            cout<<"p_real:";cin>>pol[i].parte_real;
            cout<<"p_com:";cin>>pol[i].parte_compleja;
        }
    }
    ~Polynomial_type(){
        delete[] pol;
    }

};
Polynomial_type operator +(Polynomial_type &pol1, Polynomial_type &pol2){

    int tam1,tam2,tam3;
    tam1=pol1.grado;
    tam2=pol2.grado;
    Polynomial_type p3(max(tam1,tam2));
    tam3=p3.grado;
    for(int i=0;i<=tam3;i++){
        if(tam1<0)p3.pol[i]=pol2.pol[i];
        else if(tam2<0)p3.pol[i]=pol1.pol[i];
        else p3.pol[i]=pol1.pol[i]+pol2.pol[i];
        tam1--;tam2--;
        //cout<<p3.pol[i]<<endl;
    }
    return p3;
}
Polynomial_type operator -(Polynomial_type &pol1, Polynomial_type &pol2){
    int tam1,tam2,tam3;
    tam1=pol1.grado;
    tam2=pol2.grado;
    Polynomial_type p3(max(tam1,tam2));
    tam3=p3.grado;
    for(int i=0;i<=tam3;i++){
        if(tam1<0)p3.pol[i]=pol2.pol[i];
        else if(tam2<0)p3.pol[i]=pol1.pol[i];
        else p3.pol[i]=pol1.pol[i]-pol2.pol[i];
        tam1--;tam2--;
        //cout<<p3.pol[i]<<endl;
    }
    return p3;
}
Polynomial_type operator *(Polynomial_type &pol1, Polynomial_type &pol2){
    Polynomial_type aux(pol2.grado+pol1.grado);
    int tam1,tam2;
    tam1=pol1.grado;
    tam2=pol2.grado;
    for(int i=0;i<=tam1;i++){
        for(int j=0;j<=tam2;j++){
            aux.s_coeficiente(i+j,pol1.pol[i]*pol2.get_i(j));
        }
        aux.mostrar();
    }
    return aux;

}
int main(){
    int grado;
    cout<<"Ingrese grado de p1"<<endl,
    cin>>grado;
    Polynomial_type P1(grado);
    cout<<"Ingrese grado de p2"<<endl,
    cin>>grado;
    Polynomial_type P2(grado);
    cout<<"Inserta elementos p1"<<endl;
    P1.insertar();
    cout<<"polinomio p1"<<endl;
    P1.mostrar();
    cout<<"Inserta elementos p2"<<endl;
    P2.insertar();
    cout<<"polinomio p2"<<endl;
    P2.mostrar();

    Polynomial_type P4=P1+P2;
    Polynomial_type P5=P1-P2;
    Polynomial_type P6=P1*P2;

    cout<<"polinomio suma"<<endl;
    P4.mostrar();
    cout<<"polinomio resta"<<endl;
    P5.mostrar();
    cout<<"polinomio multiplicacion"<<endl;
    /*
    Complejo c1(2,3),c2(1,2);
    cout<<c1*c2<<endl;
    */
    P6.mostrar();
}

