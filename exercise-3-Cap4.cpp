#include <cstdio>
#include <vector>
using namespace std;
int main(){
    vector<int> lista;
    int cas,numero,mayor=-999999,menor=999999,promedio,total=0;
    while(true){
        printf("Que desea realizar?\n");
        printf("(0)Ingresar numero\n");
        printf("(1)Verificar datos\n");
        printf("(2)Salir\n");
        scanf("%d",&cas);
        switch (cas){
            case 0:
                printf("Ingrese numero\n");
                scanf("%d",&numero);
                lista.push_back(numero);
                total+=numero;
                if(numero>mayor)mayor=numero;
                if(numero<menor)menor=numero;
                promedio=total/lista.size();
                break;
            case 1:
                printf("Numero mayor: %d\n",mayor);
                printf("Numero mayor: %d\n",menor);
                printf("Promedio: %d\n",promedio);
                break;
            case 2:
                return 0;
        }


    }



}
