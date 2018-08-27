
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

template<class elemType>
int seqSearch(const vector<elemType> &lista, const elemType& item){
    for(int i=0;i<lista.size();i++){
        if(lista[i]==item)return i;
    }
    return -1;
}

int main(){
    vector <int> l_int;
    vector <char> l_str;
    l_int.push_back(4);
    l_int.push_back(5);
    l_int.push_back(6);

    l_str.push_back('a');
    l_str.push_back('b');
    l_str.push_back('c');

    printf("%d\n",seqSearch(l_int,5));
    printf("%d\n",seqSearch(l_int,8));

    printf("%d\n",seqSearch(l_str,'c'));
    printf("%d\n",seqSearch(l_str,'e'));
}
