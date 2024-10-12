#include <iostream>
using namespace std;

void mostrar(int *p,int *q){

    for(int *a = p ; a<=q ; a++){
        cout<< *a <<" ";
    }
}

int contar_impares(int *p, int *q) {

    int contador = 0;
    for (int *a = p; a <= q; a++) {
			if (*a % 2 != 0) {
				contador++;
			}
		}
    return contador;

}

void ordenar_pares_impares(int *ini,int *fin){

    int cont_0 = contar_impares(ini,fin);
	int cont = 0;

    while(ini < fin ){

        if(*ini % 2 == 0 ){
            ini++;
        }
        else{
            int temp = *ini ;
            if( cont == cont_0 ){
				break;
			}
            for(int *p = ini ; p < fin ; p++){
                *p = *(p+1);
            } 
            *fin = temp;
            cont++;
        }

    }

}

int main(){

    int tam=8;

    int M[tam]={1,2,3,4,5,6,7,8};

    cout<<"Array inicial "<<endl;
    mostrar(M,M+7);

    cout<<endl;
    ordenar_pares_impares(M,M+7);
    
    cout<<"Array final "<<endl;
    mostrar(M,M+7);

    




    return 0;
}
