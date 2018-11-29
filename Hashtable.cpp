#include <bits/stdc++.h>

using namespace std;
int nextPrime(int x){
    int i, j, c;
    for (i = x + 1; 1; i++){
        for (j = 2, c = 0; j <= i; j++){
            if (i%j == 0){
                c++;
            }
        }
        if (c == 1){
            return i;
            break;
        }
    }
}

int DOUBLE(int a,int tam){
        return tam-(a%tam);
}

template <typename HashedObj>
class HashTable
{
public:
	explicit HashTable( int size = 101 ): array(nextPrime(size))
	{ makeEmpty( ); }
	bool contains( const HashedObj & x ) const;
	void makeEmpty( );
	bool insert( const HashedObj & x );
	//bool insert( HashedObj && x );
	bool remove( const HashedObj & x );
	enum EntryType { ACTIVE, EMPTY, DELETED };
	void print(){
        for(int i=0;i<array.size();i++){
            cout<<array[i].element<<" ";
        }
        cout<<endl;

	}

private:
struct HashEntry
	{
	HashedObj element;
	EntryType info;
	HashEntry( const HashedObj & e = HashedObj{ }, EntryType i = EMPTY )
	: element{ e }, info{ i } { }
	HashEntry( HashedObj && e, EntryType i = EMPTY )
	: element{ std::move( e ) }, info{ i } { }
	};
	vector<HashEntry> array;
	int currentSize;
	bool isActive( int currentPos ) const;
	int findPos( const HashedObj & x ) const;
	void rehash(){
        vector<HashEntry> oldArray = array;
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( auto & entry : array )
            entry.info = EMPTY;
        currentSize = 0;
        for( auto & entry : oldArray )
            if( entry.info == ACTIVE )
                insert( std::move( entry.element ) );
    }
	size_t myhash( const HashedObj & x ) const{
        static hash<HashedObj> hf;
        return hf( x ) % array.size( );
    }
    int findPos3( const HashedObj & x ) const;
    int findPos2( const HashedObj & x ) const;



};

template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty( )
{
	currentSize = 0;
	for( auto & entry : array )
		entry.info = EMPTY;
}
template<typename HashedObj>
bool HashTable<HashedObj>::contains( const HashedObj & x ) const{
	return isActive( findPos( x ) );

}
//double hashing
template<typename HashedObj>
int HashTable<HashedObj>::findPos3( const HashedObj & x ) const{
	int currentPos = myhash( x );
	int offset = DOUBLE(currentPos,array.size());
	if(array[currentPos].element==x)return -1;
	while(array[currentPos].info!=EMPTY&&array[currentPos].element!=x){
            currentPos+=offset;
            cout<<"valor: "<<x<<"  hash: "<<currentPos<<endl;
		if( currentPos >= array.size( ) )
			currentPos -= array.size( );
	}
	return currentPos;
}


//linear probing
template<typename HashedObj>
int HashTable<HashedObj>::findPos( const HashedObj & x ) const{
	int currentPos = myhash( x );
	if(array[currentPos].element==x)return -1;
	while(array[currentPos].info!=EMPTY&&array[currentPos].element!=x){
        currentPos++;
		if( currentPos >= array.size( ) )
			currentPos -= array.size( );
	}
	return currentPos;
}

//cuadratic probing
template<typename HashedObj>
int HashTable<HashedObj>::findPos2( const HashedObj & x ) const{
    int offset =1;
	int currentPos = myhash( x );
	if(array[currentPos].element==x)return -1;
	while(array[currentPos].info!=EMPTY&&array[currentPos].element!=x){
        currentPos += offset;
		offset += 2;
		if( currentPos >= array.size( ) )
			currentPos -= array.size( );
	}
	return currentPos;
}


template<typename HashedObj>
bool HashTable<HashedObj>::isActive( int currentPos ) const{
	return array[ currentPos ].info == ACTIVE;
}
template<typename HashedObj>
bool HashTable<HashedObj>::insert( const HashedObj & x )
{
// Insert x as active
    int currentPos = findPos( x );
    if(currentPos<0)return false;
    if( isActive( currentPos ) )
        return false;

    array[ currentPos ].element = x;
    array[ currentPos ].info = ACTIVE;
    // Rehash; see Section 5.5
    if( ++currentSize > array.size( ) / 2 )
        rehash( );
    return true;
}

template<typename HashedObj>
bool HashTable<HashedObj>::remove( const HashedObj & x )
{
int currentPos = findPos( x );
if( !isActive( currentPos ) )
return false;
array[ currentPos ].info = DELETED;
return true;
}

int main()
{
   HashTable<int> ht;
	ht.insert(417);//residuo 5
	ht.insert(930);//residuo 3
	ht.insert(314);//residuo 5->colision
	ht.insert(105);//residuo 2
	ht.insert(103);//residuo 0
	ht.insert(722);//residuo 1
	ht.insert(828);//residuo 4
	ht.insert(522);//residuo 7
	ht.print();
}
