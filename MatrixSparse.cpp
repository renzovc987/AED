#include<bits/stdc++.h>

using namespace std;

struct Nodo
{
    int valor;
    int fila;
    int columna;
    struct Nodo *next;
};

void NuevoNodo(Nodo** cabeza, int elemento_no_zero,
                     int indice_fila, int indice_col )
{
    Nodo *temp, *r;
    temp = *cabeza;
    if (temp == NULL)
    {
        temp = new Nodo;
        temp->valor = elemento_no_zero;
        temp->fila = indice_fila;
        temp->columna = indice_col;
        temp->next = NULL;
        *cabeza = temp;

    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        r = new Nodo;
        r->valor = elemento_no_zero;
        r->fila = indice_fila;
        r->columna = indice_col;
        r->next = NULL;
        temp->next = r;

    }
}


void Mostrar(struct Nodo* cabeza)
{
    Nodo *temp, *r, *s;
    temp = r = s = cabeza;

    cout<<"Indice Fila: "<<endl;
    while(temp != NULL)
    {

        cout<<temp->fila<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Indice Columna: "<<endl;
    while(r != NULL)
    {
        cout<<r->columna<<" ";
        r = r->next;
    }
    cout<<endl;
    cout<<"Valor: "<<endl;
    while(s != NULL)
    {
        cout<< s->valor<<" ";
        s = s->next;
    }
    cout<<endl;
}
/*void Sumar(Nodo*head1,Nodo*head2)
{
    Nodo *temp= head1;
    Nodo *temp1= head2;

    while(temp!= NULL && temp1!= NULL)
    {
        temp=temp->next;
        temp1=temp1->next;
        cout<<temp1->valor+temp->valor<<" ";

    }
    cout<<endl;
}*/
int main()
{
    int f,c;
    cout<<"filas"<<endl;
    cin>>f;
    cout<<"columnas"<<endl;
    cin>>c;
    int Matriz[f][c];
    int Matriz1[f][c];
    cout<<"Ingrese elementos para Matriz"<<endl;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>Matriz[i][j];
        }
    }
    cout<<"Ingrese elementos para Matriz1"<<endl;

       for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>Matriz1[i][j];
        }
    }
    cout<<"Matriz"<<endl;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<Matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matriz1"<<endl;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<Matriz1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    Nodo* cabeza = NULL;
    Nodo* cabeza1 = NULL;
    Nodo* cabeza2 = NULL;
    cout<<"MATRIZ"<<endl;
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            if (Matriz[i][j] != 0)
                NuevoNodo(&cabeza, Matriz[i][j], i, j);
    Mostrar(cabeza);
    cout<<"MATRIZ1"<<endl;
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            if (Matriz1[i][j] != 0)
                NuevoNodo(&cabeza1, Matriz1[i][j], i, j);
    Mostrar(cabeza1);
    cout<<"SUMA"<<endl;
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            if (Matriz1[i][j] != 0 && Matriz[i][j] != 0)
                NuevoNodo(&cabeza2, Matriz1[i][j]+Matriz[i][j], i, j);
    Mostrar(cabeza2);



    return 0;
}
