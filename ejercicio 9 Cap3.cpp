#include <iostream> //Line 1
#include <string>
#include <assert.h>

using namespace std;


class dateType
{
private:
    int ano;
    int mes;
    int dia;
public:
    dateType(){
        ano = 0;
        mes = 0;
        dia = 0;
    }
    dateType(int d, int m, int a){
        ano = a;
        mes = m;
        dia = d;
    }

    void setCum(int d, int m, int a){
        ano = a;
        mes = m;
        dia = d;   
    }
    
    bool isLeapYear(){
        if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
            return true;
        }
        else return false;
    }

    void printf(){
        cout<<dia<<"/"<<mes<<"/"<<ano<<endl;
    }

    int getMes(){
    	return mes;
    }
    
};

///////////////////////////////////////////////////////////////////////
class addressType{
    private:
        string direccion;
        string ciudad;
        string estado;
        int codigopostal;
    public:
        addressType(){
            direccion="Sin Direccion";
            ciudad="Sin Ciudad";
            estado="Sin estado";
            codigopostal=0;
        }
        void setAll(string a, string b, string c, int x){
        	direccion =a;
        	ciudad =b;
        	estado =c;
        	codigopostal =x;
        }

        void addireccion(string direc){
            direccion=direc;

        }
        string verdireccion(){
            return direccion;

        }
        void addciudad(string ciu){
            ciudad=ciu;

        }
        string verciudad(){
            return ciudad;

        }

        void addestado(string estad){
            estado=estad;

        }
        string verestado(){
            return estado;

        }
        void addpostal(int postal){
            codigopostal=postal;

        }
        int verpostal(){
            return codigopostal;

        }
        void printa(){
        	cout<<"direccion: "<<direccion<<"\nciudad: "<<ciudad<<"\nestado: "<<estado<<"\ncodigoPostal: "<<codigopostal<<endl;
    	}
};

////////////////////////////////////////////////////////////////////


class personType
{
    public:
        void print() const;
        void setName(string first, string last);
        virtual string getFirstName() const = 0;
        virtual string getLastName() const = 0;
        personType();
        //personType(string first, string last);
    protected:
        string firstName; //variable to store the first name
        string lastName; //variable to store the last name
};

void personType::print() const
{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

personType::personType()
{
    firstName = "";
    lastName = "";
}

////////////////////////////////////////////////////////////////////////

class extPersonType: personType
{
private:
    string typeP;
    addressType adre;
    dateType fecha;
    int numero;
public:
    extPersonType(){
        firstName = "";
        lastName = "";
        typeP = "";
        numero = 0;
    }
    extPersonType(string first, string last, string ty){
        firstName = first;
        lastName = last;
        typeP = ty;
        numero = 0;
    }

    addressType getAdress(){
        return adre;
    }


    void setAdress(string a,string b,string c,int x){
    	adre.setAll(a,b,c,x);
    }


    dateType getDate(){
        return fecha;
    }

    void setDate(int a,int b,int c){
    	fecha.setCum(a,b,c);
    }

    string verTipoPer(){
        return typeP;
    }

    void setNumber(int a){
        numero = a;
    }

    int getNumber(){
        return numero;
    }

    string getLastName() const
	{
    return lastName;
	}

	string getFirstName() const
	{
    return firstName;
	}

    //~extPersonType();
};

//////////////////////////////////////////////////////////

template <class elemType>
class arrayListType
{
public:
	const arrayListType<elemType>& operator= (const arrayListType<elemType>&);
//Overloads the assignment operator
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print() const;
	bool isItemAtEqual(int location, const elemType& item) const;
	void insertAt(int location, const elemType& insertItem);
	void insertEnd(const elemType& insertItem);
	void removeAt(int location);
	void retrieveAt(int location, elemType& retItem) const;
	void replaceAt(int location, const elemType& repItem);
	void clearList();
	int seqSearch(const elemType& item) const;
	void insert(const elemType& insertItem);
	void remove(const elemType& removeItem);
	arrayListType(int size = 100);
	arrayListType(const arrayListType<elemType>& otherList);
	~arrayListType();
protected:
	elemType *list; //array to hold the list elements
	int length; //to store the length of the list
	int maxSize; //to store the maximum size of the list
};

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}
template <class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
}
template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	
	cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
	return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
	if (location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted "<< "is out of range" << endl;
	else
		if (length >= maxSize) //list is full
			cerr << "Cannot insert in a full list" << endl;
		else
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1]; //move the elements down
			list[location] = insertItem; //insert the item at the
			length++; //increment the length
		}
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if (length >= maxSize) //the list is full
		cerr << "Cannot insert in a full list" << endl;
	else
	{
		list[length] = insertItem; //insert the item at the end
		length++; //increment the length
	}
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed "<< "is out of range" << endl;
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i+1];
		length--;
	}
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is "<< "out of range." << endl;
	else
		retItem = list[location];
} //end retrieveAt

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is "<< "out of range." << endl;
	else
		list[location] = repItem;
} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
} //end clearList

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "<< "an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete [] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize]; //create the array
	assert(list != NULL); //terminate if unable to allocate
	//memory space
	for (int j = 0; j < length; j++) //copy otherList
		list [j] = otherList.list[j];
} //end copy constructor

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList)
{
	if (this != &otherList) //avoid self-assignment
	{
		delete [] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		
		list = new elemType[maxSize]; //create the array
		assert(list != NULL); //if unable to allocate memory
		//space, terminate the program
		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
	int loc;
	if (length == 0) //list is empty
		list[length++] = insertItem; //insert the item and
		//increment the length
	else if (length == maxSize)
		cerr << "Cannot insert in a full list." << endl;
	else
	{
		loc = seqSearch(insertItem);
		if (loc == -1) //the item to be inserted
		//does not exist in the list
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in "<< "the list. No duplicates are allowed." << endl;
	}
} //end insert

template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;
	if (length == 0)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list."<< endl;
	}
} //end remove


class addressBookType
{
private:
	extPersonType *list; //array to hold the list elements
	int length; //to store the length of the list
	int maxSize; //to store the maximum size of the list
public:
	addressBookType(int size){
		if (size < 0)
		{
			cerr << "The array size must be positive. Creating "<< "an array of size 100. " << endl;
			maxSize = 100;
		}
		else
			maxSize = size;
		length = 0;
		list = new extPersonType[maxSize];
		assert(list != NULL);
	}
	int searchByLast(string item){
		int loc;
		bool found = false;
		for (loc = 0; loc < length; loc++)
			if (list[loc].getLastName() == item)
			{
				found = true;
				break;
			}
		if (found)
			return loc;
		else
			return -1;
	}
	void viewDates(string item){
		int loc;
		bool found = false;
		for (loc = 0; loc < length; loc++)
			if (list[loc].getLastName() == item)
			{
				found = true;
				break;
			}
		if (found){
			cout<<list[loc].getFirstName()<<" "<<list[loc].getLastName()<<endl;
			list[loc].getAdress().printa();
			cout<<"cumpleaños: ";
			list[loc].getDate().printf();
		}
		else
			cout<<"No existe"<<endl;
	}

	void viewBirth(int i, int j){
		int loc;
		for (loc = 0; loc < length; loc++)
			if(list[loc].getDate().getMes()>=i && list[loc].getDate().getMes()<=j)
				cout<<list[loc].getFirstName()<<" "<<list[loc].getLastName()<<endl;
	}

	void viewStatus(string status){
		int loc;
		for (loc = 0; loc < length; loc++){
			if(list[loc].verTipoPer()==status)
				cout<<list[loc].getFirstName()<<" "<<list[loc].getLastName()<<endl;
		}
	}

	void betweenLast(string i, string j){
		int loc;
		bool pass=false;
		for (loc = 0; loc < length; loc++){
			if(list[loc].getLastName()==i)
				pass=true;
			if(pass)
				cout<<list[loc].getFirstName()<<" "<<list[loc].getLastName()<<endl;						
			if(list[loc].getLastName()==j){
				pass=false;
				break;
			}
		}
	}

	void mostrar(){
		int loc;
		for (loc = 0; loc < length; loc++)
			cout<<list[loc].getFirstName()<<" "<<list[loc].getLastName()<<endl;
	}


	void insert(const extPersonType& insertItem)
	{
		int loc;
		if (length == 0) //list is empty
			list[length++] = insertItem; //insert the item and
			//increment the length
		else if (length == maxSize)
			cerr << "Cannot insert in a full list." << endl;
		else
		{
			
			list[length++] = insertItem;
		}
	}

	~addressBookType(){
		delete[] list;
	}
};

int main() 
{
	addressBookType libreta=addressBookType(500);
	while(true){
		int op;
		cout<<"**********************************************************************"<<endl;
		cout<<"* 1)Agregar Elementos    2)Ver Elementos     3)Buscar por Apellidos  *"<<endl;
		cout<<"* 4)Ver datos            5)Ver cumpleaños    6)Ver por Status        *"<<endl;
		cout<<"* 7)Ver nombres entre dos Apellidos          8)Salir                 *"<<endl;
		cout<<"**********************************************************************"<<endl;
		cin>>op;
		if(op==1){
			string a,b,c,d,e,f;
			int x,g,h,i;
			cout<<"Nombre: ";
			cin>>a;
			cout<<"Apellido: ";
			cin>>b;
			cout<<"Status: ";
			cin>>c;
			extPersonType nuevo=extPersonType(a,b,c);
			cout<<"Direccion: ";
			cin>>d;
			cout<<"Ciudad: ";
			cin>>e;
			cout<<"Estado: ";
			cin>>f;
			cout<<"CodigoPostal: ";
			cin>>x;
			nuevo.setAdress(d,e,f,x);//.setAll(d,e,f,x);
			cout<<"Nacimiento:"<<endl;
			cout<<" Dia: ";
			cin>>g;
			cout<<" Mes: ";
			cin>>h;
			cout<<" Anio: ";
			cin>>i;
			nuevo.setDate(g,h,i);
			libreta.insert(nuevo);
		}
		else if(op==2){
			cout<<"/////////////////////////////////////////////////////"<<endl;
			libreta.mostrar();
			cout<<"/////////////////////////////////////////////////////"<<endl;
		}
		else if(op==3){
			string last;
			int pos;
			cout<<"Apellido a buscar: ";
			cin>>last;
			pos = libreta.searchByLast(last);
			if(pos>=0) cout<<"Se encuentra en la posicion "<<pos<<endl;
			else cout<<"No esta almacenado"<<endl;
		}
		else if(op==4){
			string last;
			cout<<"Apellido a buscar datos: ";
			cin>>last;
			libreta.viewDates(last);
		}
		else if(op==5){
			int i, j;
			cout<<"Ingrese el mes inicial: ";
			cin>>i;
			cout<<"Buscar hasta el mes: ";
			cin>>j;
			cout<<"/////////////////////////////////////////////////////"<<endl;
			libreta.viewBirth(i,j);
			cout<<"/////////////////////////////////////////////////////"<<endl;
		}
		else if(op==6){
			string sta;
			cout<<"Ingrese el status a buscar: ";
			cin>>sta;
			cout<<"/////////////////////////////////////////////////////"<<endl;
			libreta.viewStatus(sta);
			cout<<"/////////////////////////////////////////////////////"<<endl;
		}
		else if(op==7){
			string last1,last2;
			cout<<"Buscar desde el apellido: ";
			cin>>last1;
			cout<<"Hasta el apellido: ";
			cin>>last2;
			cout<<"/////////////////////////////////////////////////////"<<endl;
			libreta.betweenLast(last1, last2);
			cout<<"/////////////////////////////////////////////////////"<<endl;
		}
		else if(op==8) break;
		else cout<<"Inserte una opcion valida"<<endl;
	}

	return 0;
}