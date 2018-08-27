#include <iostream>
#include <vector>
#include <string>

using namespace std;
//158
//296
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


int main(){
    vector<bookType> libros;
    bookType l1(12345,50,3,"Holitas","Coquito");
    l1.aumentar_a("Andy");
    l1.aumentar_a("Geanpiero");
    libros.push_back(l1);

    bookType l2(11111,29,1,"Chaufitas","Esopo");
    l2.aumentar_a("Pepa");
    l2.aumentar_a("Pedro");
    l2.aumentar_a("Pepito");
    libros.push_back(l2);

    bookType l3(22222,10,2,"Condorito","Velazco");
    l3.aumentar_a("Coco");
    l3.aumentar_a("Perico");
    libros.push_back(l3);

    for(int i=0;i<libros.size();i++)libros[i].show_all();
    cout<<endl;
    for(int i=0;i<libros.size();i++){
        if(libros[i].check_t("Chaufitas"))cout<<"libro encontrado por titulo"<<endl;
    }
    cout<<endl;
    for(int i=0;i<libros.size();i++){
        if(libros[i].check_c(11111))cout<<"libro encontrado por codigo"<<endl;
    }
    cout<<endl;
    for(int i=0;i<libros.size();i++){
        libros[i].set_stock(i+200);
    }
    cout<<endl;
    cout<<"Actualizacion de stock"<<endl;
    for(int i=0;i<libros.size();i++)libros[i].show_all();
}
