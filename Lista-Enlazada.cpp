#include <iostream>

using namespace std;
template <class R>
class nodo{

R dato;
nodo<R> *siguiente;
public:
    nodo(R d)
    {
        dato=d;
        this->siguiente=NULL;
    }
    void nextnodo(nodo<R> *next)
    {
        siguiente=next;
    }
    R getdato()
    {
        return dato;
    }
    nodo<R>*getsiguiente()
    {
        return siguiente;
    }
};
template<class X>
class lista_en
{
    nodo<X> *inicio;

public:
    //1.Inicializar la Lista
    lista_en()
    {
        this->inicio=NULL;
    }
    int tam()
    {
        nodo<X>*aux;
        aux=inicio;
        int c=0;
        while(aux!=NULL)
        {
             c++;
            aux=aux->getsiguiente();
        }
        return c;
    }

    void insert_inicio(X dat)
    {
        nodo<X>*nuevo;
        nuevo=new nodo<X>(dat);
		nuevo->nextnodo(inicio);
		inicio=nuevo;
    }
    int buscar_xpos(int p)
    {
        nodo<X>*temp;
        temp=inicio;
        for(int i=0;i<p;++i)
        {
            temp=temp->getsiguiente();
        }
        return temp->getdato();
    }
    void eliminar_xpos(int p)
    {
        nodo<X>*temp;
        temp=inicio;
        nodo<X>*temp1;
        if(p==0)
        {
            temp=temp->getsiguiente();
        }
        else
        {
            for(int j=0;j<p-1;j++)
            {
                temp=temp->getsiguiente();
            }
            temp1=temp->getsiguiente();
            temp->nextnodo(temp1->getsiguiente());
        }
    }
    //10.Delete an item from the list.
   void eliminar_xvalor(X v)
   {
       nodo<X>*temp;
       temp=inicio;
       nodo<X>*temp1=inicio->getsiguiente();
       if(v==inicio->getdato())
       {
           inicio=inicio->getsiguiente();
       }
       else
       {
           while(temp1!=NULL)
           {
               if(v==temp1->getdato())
               {
                   temp->nextnodo(temp1->getsiguiente());
                   return;
               }
               temp=temp->getsiguiente();
               temp1=temp1->getsiguiente();
           }
       }

   }
   void insertar_xpos(int p,X v)
   {
       nodo<X>*nuevo_nodo;
       nuevo_nodo=new nodo<X>(v);
       nodo<X>*temp;
       temp=inicio;
       if(p==0)
       {
           nuevo_nodo->nextnodo(inicio);
           inicio=nuevo_nodo;
       }
       else
       {
           for(int i=0;i<p-1;i++)
           {
               temp=temp->getsiguiente();
           }
           nuevo_nodo->nextnodo(temp->getsiguiente());
           temp->nextnodo(nuevo_nodo);
       }

   }


    //9. Insert an item in the list.
    void insert_final(X dat)
    {
        nodo<X>*nuevonodo;
        nuevonodo=new nodo<X>(dat);
        nodo<X>*auxiliar;
        if(inicio==NULL)
        {
            inicio=nuevonodo;
        }
        else{
                auxiliar=inicio;
                while((auxiliar->getsiguiente())!=NULL)
                {
                    auxiliar=auxiliar->getsiguiente();
                }
            auxiliar->nextnodo(nuevonodo);
        }
    }
    //8. Search the list for a given item.
    int buscar_xvalor(X v)
    {
        nodo<X>*temp=inicio;
        int p=0;
        while(temp!=NULL)
        {
            if(v==temp->getdato())
            {
                return p;
            }
              p++;
            temp=temp->getsiguiente();
        }
        return -8;

    }
    void mostrar()
    {
        nodo<X>*temp;
        temp=inicio;
        while(temp!=NULL)
        {
            cout<<temp->getdato()<<" ";
            temp=temp->getsiguiente();
        }
        cout<<endl;

    }
    //6. Retrieve the info contained in the first node.
    X retrieve_info_start()
    {
        return inicio->getdato();
    }
    //7. Retrieve the info contained in the last node.
    X retrieve_info_last()
    {
        nodo<X> *aux;
        nodo<X> *aux2;
        int c=0;
        aux=inicio;
        aux2=inicio;
        while(aux!=NULL)
        {
            aux=aux->getsiguiente();
            c++;
        }
        for(int i=0;i<c-1;i++)
        {
            aux2=aux2->getsiguiente();
        }
        return aux2->getdato();

    }
    //11. Make a copy of the linked list.
    void copiar(lista_en l2)
    {

      nodo<X>*aux2;
      aux2=l2.inicio;
      int c=0;
      while(aux2!=NULL)
      {
          aux2=aux2->getsiguiente();
         c++;
      }
      aux2=l2.inicio;
      for(int i=0;i<c;i++)
      {

          if(aux2!=NULL)
           {
               this->insert_final(aux2->getdato());
               aux2=aux2->getsiguiente();
           }
      }



    }
    //5. Destroy the list.
    ~lista_en()
    {

       while(inicio!=NULL)
       {
           inicio=inicio->getsiguiente();
           delete inicio;
       }
    }
};
int main()
{
    lista_en<char> l;
    lista_en<char> lista2;
    l.insert_final('a');
    l.insert_inicio('b');
    l.insert_inicio('c');
    l.insert_inicio('f');
    l.insert_final('g');
    l.insert_inicio('h');
    l.insert_inicio('n');
    l.insert_inicio('m');
    l.insert_final('z');
    l.insertar_xpos(2,'s');
    //2.Determine whether the list is empty.
    if(l.tam()==0)
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        //3.Print the list.
        cout<<"Elementos Insertados"<<endl;
        l.mostrar();
        cout<<"El primer elemento de la lista es: "<<l.retrieve_info_start()<<endl;
        cout<<"El ultimo elemento de la lista es: "<<l.retrieve_info_last()<<endl;


         //4. Find the length of the list.
        cout<<"Tamaño de la lista enlazada"<<endl;
        cout<<l.tam()<<endl;



        int x,valor,eli,eliv,nuevo,pnuevo;
        cout<<"Introduzca posicion"<<endl;
        cin>>x;
        cout<<"El valor del elemento de la posicion "<<x<<" es "<<l.buscar_xpos(x)<<endl;
        cout<<"Introduzca elemento a buscar"<<endl;
        cin>>valor;
        if(l.buscar_xvalor(valor)==-8)
        {
            cout<<"El elemento no existe "<<endl;
        }
        else
        {
            cout<<"La posicion del elemento del valor "<<valor<<" es "<<l.buscar_xvalor(valor)<<endl;
        }
        cout<<"Introduzca posicion del elemento a eliminar "<<endl;
        cin>>eli;
        l.eliminar_xpos(eli);
        l.mostrar();
        cout<<"Introduzca valor a eliminar "<<endl;
        cin>>eliv;
        l.eliminar_xvalor(eliv);
        l.mostrar();
        cout<<"Ingrese la posicion del nuevo elemento y el nuevo elemento "<<endl;
        cin>>pnuevo>>nuevo;
        l.insertar_xpos(pnuevo,nuevo);
        l.mostrar();
        lista2.copiar(l);
        cout<<"Contenido de la Lista 2 despues de realizada la copia"<<endl;
        lista2.mostrar();
        l.~lista_en();
        cout<<"Lista 1 despues de ser destruida"<<endl;
        l.mostrar();
    }




}
