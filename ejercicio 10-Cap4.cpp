#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Stock_Object
{
public:
    char* simbolo;
    float precio_apertura;
    float precio_cierre;
    float precio_alto_hoy;
    float precio_bajo_hoy;
    float precio_cierre_anterior;
    float porcentaje;
    int volumen,pos;
public:
    Stock_Object()
    {
        simbolo=new char[0];
        precio_apertura=0.0;
        precio_cierre=0.0;
        precio_alto_hoy=0.0;
        precio_bajo_hoy=0.0;
        precio_cierre_anterior=0.0;
        volumen=0;
        porcentaje=0.0;
        pos=0;
    }
    void set_simbolo(char*simbol)
    {
        simbolo=simbol;
    }
    void setp_apertura(float pa)
    {
        precio_apertura=pa;
    }
    void setp_cierre(float pc)
    {
        precio_cierre=pc;
    }
    void setp_altohoy(float pah)
    {
        precio_alto_hoy=pah;
    }
    void setp_bajohoy(float pbh)
    {
        precio_bajo_hoy=pbh;
    }
        void setp_cierrea(float pca)
    {
        precio_cierre_anterior=pca;
    }
    void set_volumen(int v)
    {
        volumen=v;
    }
    void set_porcentaje()
    {
        porcentaje=(precio_cierre-precio_cierre_anterior)/(precio_cierre_anterior/100);

    }

    void mostrar_precios()
    {
        cout<<"precio_apertura"<<" "<<"precio_cierre"<<" "<<"precio_alto_hoy"<<" "<<"precio_bajo_hoy"<<" "<<"precio_cierre_anterior"<<endl;
        cout<<precio_apertura<<" "<<precio_cierre<<" "<<precio_alto_hoy<<" "<<precio_bajo_hoy<<" "<<precio_cierre_anterior<<endl;
    }
    void mostrar_n_acciones()
    {
        cout<<"El numero de acciones es:"<<endl;
        cout<<volumen<<endl;
    }
    void mostrar_stock()
    {
        cout<<setfill(' ');
        cout<<setw(10)<<simbolo<<setw(10)<<precio_apertura<<setw(10)<<precio_cierre<<setw(10)<<precio_alto_hoy<<setw(10)<<precio_bajo_hoy<<setw(10)<<precio_cierre_anterior<<setw(10)<<porcentaje<<setw(10)<<volumen<<endl;
    }
    char* get_t(){
        return simbolo;
    }
    int get_p(){
        return porcentaje;
    }
    void update_p(int p){
        pos=p;
    }
    int get_pos(){
        return pos;
    }


};
ostream&operator<<(ostream &salida, const Stock_Object &stock1)
{
    salida<<"Simbolo: "<<stock1.simbolo<<'\n'<<"Precio de apertura: "<<stock1.precio_apertura<<'\n'<<"Precio de cierre: "<<stock1.precio_cierre<<'\n'<<"Precio alto de hoy: "<<stock1.precio_alto_hoy<<'\n'<<"Precio bajo de hoy: "<<stock1.precio_bajo_hoy<<'\n'<<"Precio de cierre de ayer: "<<stock1.precio_cierre_anterior<<'\n'<<"Porcentaje de ganancia/perdida: "<<stock1.porcentaje<<'\n'<<"N° de acciones: "<<stock1.volumen<<endl;
    return salida;
}
istream&operator>>(istream &entrada, const Stock_Object &stock1)
{
    entrada>>stock1;
    return entrada;
}


class Stock_Type_List
{
private:
    vector <Stock_Object> lista;
    vector <int> indexByGain;
    int tam;
public:
    Stock_Type_List():tam(0){}
    void insertar(Stock_Object item){
        bool est=false;
        int ma=0;
        //mostrar_lista();
        if(tam==0){
           lista.push_back(item);
           est=true;
        }
        else {
            for(int i=0;i<tam;i++){
                if(strcmp(item.get_t(),lista[i].get_t())<0){
                    lista.insert(lista.begin()+i,item);
                    est=true;
                    break;
                }
            }
        }
        if(!est)lista.push_back(item);
        tam++;


        /*
        vector <Stock_Object> aux;
        aux=lista;
        sort(aux.begin(),aux.begin()+tam);
        for(int i=0;i<tam;i++){
            cout<<aux[i].get_t()<<endl;
        }
        cout<<endl;
*/
    }

    void mostrar_lista(){
        int total=0;
        cout<<"Lista de inversiones"<<endl;
        cout<<"Reporte financiero"<<endl;
        cout<<"| Stock"<<setw(8)<<"| Hoy"<<setw(26)<<"| Anterior"<<setw(26)<<"| Porcentaje"<<endl;
        cout<<setw(88)<<setfill('-')<<" "<<endl;
        cout<<"| simbolo | "<<setw(8)<<"apertura | "<<setw(10)<<"cierre | "<<setw(10)<<"pre. alto | "<<setw(10)<<"pre. bajo | "<<setw(10)<<"pre. cierre | "<<setw(10)<<"ganancia | "<<setw(10)<<"volumen | "<<endl;
        cout<<setw(88)<<setfill('-')<<" "<<endl;

        for(int it=0;it<tam;it++){
            //cout<<lista[it]<<endl;
            lista[it].mostrar_stock();
        }
        cout<<"Activos de cierre:"<<total<<endl;
        cout<<setw(88)<<setfill('_')<<""<<endl;
    }
};

int main()
{
    Stock_Object s1,s2,s3;

    s1.set_simbolo("B");
    s2.set_simbolo("C");
    s3.set_simbolo("D");
    s1.setp_cierre(75);
    s1.setp_cierrea(83);
    s1.set_porcentaje();
    s2.setp_cierre(100);
    s2.setp_cierrea(10);
    s2.set_porcentaje();
    s3.setp_cierre(90);
    s3.setp_cierrea(98);
    s3.set_porcentaje();
    Stock_Type_List lista_stock;
    lista_stock.insertar(s1);
    lista_stock.insertar(s2);
    lista_stock.insertar(s3);
    lista_stock.mostrar_lista();

}
