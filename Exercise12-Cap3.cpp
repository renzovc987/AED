#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class matrixType
{
private:
	int filas, columnas;
	int m[300][300];
public:
	matrixType(){
		filas=0;
		columnas=0;
	}
	matrixType(int f, int c){
		filas=f;
		columnas=c;
	}
	void llenarMatriz(){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cin>>m[i][j];
			}
		}
	}
	void replaceVal(int f, int c, int val){
		m[f][c]=val;
	}
	int getElement(int f, int c){
		return m[f][c];
	}
	void setFilCol(int f, int c){
		filas=f;
		columnas=c;	
	}
	int getFil(){
		return filas;
	}
	int getCol(){
		return columnas;
	}

	matrixType operator +(matrixType a){
		matrixType res=matrixType(filas, columnas);
		if(a.getCol()!=columnas || a.getFil()!=filas){
			cout<<"No se puede realizar esta operacion"<<endl;
			return res;
		}
		
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < columnas; ++j)
			{
				res.replaceVal(i, j, m[i][j]+a.getElement(i, j));
			}
		}
		return res;
	}
	matrixType operator -(matrixType a){
		matrixType res=matrixType(filas, columnas);
		if(a.getCol()!=columnas || a.getFil()!=filas){
			cout<<"No se puede realizar esta operacion"<<endl;
			return res;
		}
		
		for (int i = 0; i < filas; ++i)
		{
			for (int j = 0; j < columnas; ++j)
			{
				res.replaceVal(i, j, m[i][j]-a.getElement(i, j));
			}
		}
		return res;
	}

	matrixType operator *(matrixType a){ 
    	matrixType res = matrixType(filas,a.getCol());
	    if(columnas==a.getFil()){
	        for(int i=0;i<filas;i++){ 
	            for(int j=0;j<a.getCol();j++){ 
	                res.replaceVal(i,j,0);
	                for(int k=0;k<columnas;k++){ 
	                    //C[i][j]=C[i][j]+A[i][k]*B[k][j];
	                    res.replaceVal(i, j, res.getElement(i, j)+m[i][k]*a.getElement(k,j));
	                }
	            }
	        }
	    }
	    else return res;
    } 
	//~matrixType();
};
ostream& operator << (ostream &o, matrixType &p){
	for(int i=0;i<p.getFil();i++){
		for (int j = 0; j < p.getCol(); ++j)
		{
			o<<p.getElement(i,j)<<" ";
		}
		o<<endl;
	}
	return o;
}

int main(){
	matrixType a=matrixType(3,3);
	matrixType b=matrixType(3,3);
	matrixType c;
	a.llenarMatriz();
	b.llenarMatriz();
	c=a+b;
	cout<<c;
}