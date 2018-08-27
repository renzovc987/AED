#include <iostream>
#include <vector>
#include <string>
using namespace std;
class bookType{
private:
    int codigo,precio,stock;
    string titulo,editorial;
    vector <string> autores;
public:
    bookType(int cod=0,int pre=0,int sto=0,string ti="",string ed=""):codigo(cod),precio(pre),stock(sto),titulo(ti),editorial(ed){};
    void show_all(){
          cout<<"________________________________________________________________"<<endl;
        bookType::show_t();
        bookType::show_a();
        bookType::show_e();
        bookType::show_c();
        bookType::show_p();
        bookType::show_s();
        cout<<"________________________________________________________________"<<endl;

    }
    void set_titulo(string titulo){
        this->titulo=titulo;
    }
    bool check_t(string titulo){
        if(this->titulo==titulo)return true;
        return false;
    }
    void show_t(){
        cout<<"El titulo es :"<<titulo<<endl;
    }
    string get_t(){
        return this->titulo;
    }
    void set_editorial(string editorial){
        this->editorial=editorial;
    }
    string get_editorial(){
        return this->editorial;
    }
    void show_e(){
        cout<<"La editorial es: "<<editorial<<endl;
    }

    void update_a(string autor,string autor2){
        for(int i=0;i<autores.size();i++){
            if(autores[i]==autor){
                autores[i]=autor2;
                return;
            }
        }
        cout<<"No se encuentra el autor en la lista"<<endl;
    }
    void aumentar_a(string autor){
        autores.push_back(autor);
    }
    vector<string> get_autores(){
        return this->autores;
    }
    void show_a(){
        for(int i=0;i<autores.size();i++){
            cout<<"Autor N° "<<i+1<<" : "<<autores[i]<<endl;
        }
    }

    void set_codigo(int codigo){
        this->codigo=codigo;
    }
    int get_codigo(){
        return this->codigo;
    }
    void show_c(){
        cout<<"El codigo es : "<<codigo<<endl;
    }
    bool check_c(int codigo){
        if(this->codigo==codigo)return true;
        return false;
    }

    void set_precio(int precio){
        this->precio=precio;
    }
    int get_precio(){
        return this->precio;
    }
    void show_p(){
        cout<<"El precio es : "<<precio<<endl;
    }

    void set_stock(int stock){
        this->stock=stock;
    }
    int get_stock(){
        return this->stock;
    }
    void update(string op){
        if(op=="+")this->stock++;
        else if(op=="-")this->stock--;
        else cout<<"Operacion incorrecta"<<endl;
    }
    void show_s(){
        cout<<"Se encuentran "<<stock<<" libro(s) disponibles "<<endl;
    }
};

class memberType{
private:
    string nombre;
    int ID,n_l,total;
    vector<bookType> libros;
    bool miembro;

public:
    static int can;
    memberType(string nombre){
        total=0;
        n_l=0;
        can++;
        this->ID=can;
        this->nombre=nombre;
        miembro=false;
    }
    void update_m(){
        if(n_l>=10)miembro=true;
        else cout<<"Usted no es usuario recurrente"<<endl;
    }
    void show_m(){
        if(miembro)cout<<"Usted es miembro"<<endl;
        else cout<<"Usted aun no es miembro"<<endl;
    }
    void show_id(){
        cout<<"EL ID es : " <<ID<<endl;
    }
    void set_n(string nombre){
        this->nombre=nombre;
    }
    void show_n(){
        cout<<"El nombre de la persona es : "<<nombre<<endl;
    }

    void add_l(bookType &libro){
        n_l++;
        if(n_l==11){
            cout<<"Se le aplicara un descuento especial"<<endl;
            total=total/n_l;
        }
        libros.push_back(libro);

        total+=libro.get_precio();
        if(miembro){total-=(libro.get_precio()*5/100);}
        libro.update("-");
    }
    void set_n(int n_l){
        this->n_l=n_l;
    }
    int get_n(){
        return this->n_l;
    }
    void show_l(){
        if(n_l==0){
            cout<<"No tiene libros"<<endl;
            return;
        }
        cout<<"Posee los "<<n_l<<" siguientes libros :"<<endl;
        for(int i=0;i<n_l;i++){
            cout<<"* "<<libros[i].get_t()<<endl;
        }
    }
    void devolver_l(bookType &libro){
        for(int i=0;i<n_l;i++){
            if(libros[i].check_t(libro.get_t())){
                libro.update("+");
                libros.erase(libros.begin()+i);
                n_l--;
                return;
            }
        }
        cout<<"Usted no alquilo este libro"<<endl;
    }
    void pago(int monto){
        this->total-=monto;
    }
    int get_t(){
        return this->total;
    }
    void show_t(){
        cout<<"La deuda total es : "<<total<<endl;
    }

    void show_all(){
        memberType::show_id();
        memberType::show_n();
        memberType::show_l();
        memberType::show_t();
        memberType::show_m();

    }

};

int memberType::can =11111;
int main(){
    vector<bookType> libros;
    bookType l1(12345,50,3,"Holitas","Coquito");
    l1.aumentar_a("Andy");
    l1.aumentar_a("Geanpiero");
    libros.push_back(l1);

    bookType l2(11111,100,1,"Chaufitas","Esopo");
    l2.aumentar_a("Pepa");
    l2.aumentar_a("Pedro");
    l2.aumentar_a("Pepito");
    libros.push_back(l2);

    bookType l3(22222,10,2,"Condorito","Velazco");
    l3.aumentar_a("Coco");
    l3.aumentar_a("Perico");
    libros.push_back(l3);

    memberType p1("Roberto");
/*
    p1.add_l(l2);
    p1.show_l();
    p1.show_t();
    p1.update_m();
    p1.set_n(20);
    p1.update_m();
    p1.add_l(l2);
    p1.show_t();

*/


    int op,can;
    string librop;
    while(true){
        cout<<endl;
        cout<<"Ingrese opcion"<<endl;
        cout<<"(0)Listar libros"<<endl;
        cout<<"(1)Pedir libro"<<endl;
        cout<<"(2)Devolver libro"<<endl;
        cout<<"(3) Efetuar pago"<<endl;
        cout<<"(4) Verificar datos"<<endl;
        cin>>op;
        switch(op){
            case 0:
                for(int i=0;i<libros.size();i++)libros[i].show_t();
                break;
            case 1:
                cout<<"Que libro desea pedir?"<<endl;
                cin>>librop;
                for(int i=0;i<libros.size();i++){
                    if(libros[i].check_t(librop)){
                       p1.add_l(libros[i]);
                       break;
                    }
                }
                break;
            case 2:
                cout<<"Que libro desea devolver?"<<endl;
                cin>>librop;
                for(int i=0;i<libros.size();i++){
                    if(libros[i].check_t(librop)){
                       p1.devolver_l(libros[i]);
                       break;
                    }
                }
                break;
            case 3:
                cout<<"Ingrese cantidad a pagar"<<endl;
                cin>>can;
                p1.pago(can);
                break;
            case 4:
                p1.show_all();
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                break;


        }
    }


}
