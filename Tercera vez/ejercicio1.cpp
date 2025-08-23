#include <iostream>
using namespace std;

int* crea_array(int tam){
    int* array=new int[tam];
    for(int i=0;i<tam;i++){
        cin>>*(array+i);
    }
    return array;
}

void merge(int* p,int* q){
    while (p != q) {
        if (*p > *q) {
            for (int* ini = p, *fin = q; ini != q; ini++, fin++) {
                if(*ini>*fin){
                    swap(*ini, *fin);
                }
            }
        }
        p++;
    }
}

void mostrar(int* ar, int tam) {
    for (int i = 0; i < tam; i++) {
        cout<<ar[i]<<"  ";
    }
}


int main(){
    int a;
    cout<<"Ingresa tamanho"<<endl;
    cin>>a;

    int *ar=crea_array(a);
    merge(ar,ar+(a/2));
    mostrar(ar,a);

    delete[] ar;

    return 0;
}