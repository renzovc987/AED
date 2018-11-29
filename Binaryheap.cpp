#include <bits/stdc++.h>
using namespace std;

template <typename Comparable>
class BinaryHeap{
public:
    //Constructor con capacidad de 100 para el binary heap y en la posicion actual cero
	explicit BinaryHeap( int capacity = 0):currentSize(capacity=0){
	    array.resize(10);
		//vector<Comparable> array;
	}
    //Constructor que inicaliza el array que utilizara el binary heap con 10 elementos
	explicit BinaryHeap( const vector<Comparable> & items ): array( items.size( ) + 10 ), currentSize{ items.size( )}{
		for( int i = 0; i < items.size( ); ++i )
			array[ i+1]= items[ i ];
		buildHeap( );
	}
    //Retorna si el binaryheap esta vacio
	bool isEmpty( ) const{
        return currentSize==0;
	}
	//Encuentra el minimo elemneto en el montivulo binario
	const Comparable & findMin( ) const;
	void insert( const Comparable & x ){
	    //si la posicion actual del array es igual al ultimo se duplica el tamaño del array
        if( currentSize == array.size( )-1)
            array.resize( array.size( ) * 2 );
        //El agujero estara una posicion mas de la poscion actual
        int hole = ++currentSize;
        //Definimos un elemnto del tipo comparable;
        Comparable copy = x;
        // Si el array esta vacio entonces agregamos memoria para insertar el elmento
        if(array.size()==0)array.push_back(move( copy ));
        //de lo contrario se agrega el ememento
        else array[ 0 ] = std::move( copy );
        //si el elemento es mayor al padre entonces el agujero pasa a la posicion del padre
        for( ; x < array[ hole / 2 ]; hole /= 2 ){
            array[ hole ] = std::move( array[ hole / 2 ] );
           // cout<<"2"<<endl;
        }
        //Luego dicho elemento es añadido al array
        array[ hole ] = std::move( array[ 0 ] );
		//cout<<currentSize<<endl;

	}
	//void insert( Comparable && x );
	//Definicion de delete min(eliminar el minimo)
	void deleteMin( ){
	    // Si el arbol esta vacio no se hace nada solo se indica que esta vacio
        if( isEmpty( ) )
            cout<<"Empty Tree"<<endl;
        // De lo contrario el elemento uno del array es reemplazado por el elemnto de la poscion actual menos 1
        array[ 1 ] = std::move( array[ currentSize-- ] );
        // Posteriormente se hace el percolado para que se cumpla la propiedad de orden
        percolateDown( 1 );
    }

	void deleteMin( Comparable & minItem );
	//Vacia el array
	void makeEmpty( ){
        currentSize=0;
        array.clear();
	}
	//Muestra el array del binary heap
	void print(){
		for (int i = 1; i <= currentSize; ++i)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl<<currentSize<<endl;
	}
private:
    //Definimos las variables miembro de nuestra claase binary heap
    //Posicion actual
    //Y el array
	int currentSize; // Number of elements in heap
	vector<Comparable> array; // The heap array
	//Buildheap balancea el array en la construccion del binary heap
	void buildHeap( ){
		for( int i = currentSize / 2; i > 0; --i )
			percolateDown( i );
	}
	//Percolado
	void percolateDown( int hole ){
		int child;
		// Definimos un auxiliar que empezara en el agujero
		Comparable tmp = std::move( array[ hole ] );
		//Posteriormente en base a la condicion de hijo(2*) definiremos los hijos
		for( ; hole * 2 <= currentSize; hole = child )
		{
			child = hole * 2;
			//Si la posicion del hijo es diferente al maximo y el elemento posterior al indice child
			//es menor a este se aumenta en uno el indice para que las propiedades de que el hijo derecho =2*i+2=hijo derecho
			//y 2*i+1 es hijo izquierdo se cumpla.
			if( child != currentSize && array[ child +1]< array[ child ] )
				++child;
				// ya con eso hacemos las comparacipones en base al uxiliar
			if( array[ child ] < tmp )
                //y el agujero toma el valor del hijo en el array
				array[ hole ] = std::move( array[ child ] );
			else
				break;
		}
		array[ hole ] = std::move( tmp );
	}
};



int main(){
	BinaryHeap<int>H;
	//int x=4;
	H.insert(78);
	H.insert(47);
	H.insert(14);
	H.insert(46);
	H.insert(15);
	H.insert(77);
	H.insert(20);
	H.insert(65);
	H.insert(98);
	H.insert(12);
	H.insert(10);
	H.insert(11);
	H.print();
	H.deleteMin();
	H.print();
}
