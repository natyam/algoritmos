//============================================================================
// Name        : 64.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstring>
#include <iostream>
using namespace std;
struct nodo{
	int info;
	nodo * sgte;
};
int pop(nodo *&pila );
void push(nodo *&pila, int valor);
void ej80(nodo *&pila, int valor);
int main() {
	cout<<"Ej 80- Segundo Cuatrimestre";
	nodo * pila= NULL;
	for (int i=0;i<5;i++)
	{
		push(pila, i);
		}
	//comienzo del ej 80
	int valorn;
	cout<<"\n Ingrese nuevo valor: ";

	cin>>valorn;
	//cout<<valorn;
	ej80(pila,valorn);
	while(pila!=NULL){
		cout<<"\n "<<pop(pila);
	}

	return 0;
}
int pop(nodo *&pila ){

	nodo * p2=pila;
	int x=p2->info;
	pila=p2->sgte;
	delete p2;
	return x;

}
void push(nodo *&pila, int valor){
	nodo* aux= new nodo();
	aux->info= valor;
	aux->sgte= pila;
	pila= aux;
	return;
}
void ej80(nodo *&pila, int valor)
{
	nodo * pcopia=NULL;
	nodo *poriginal= pila;
	//poriginal= pila;
	int v;
	while(poriginal!=NULL && poriginal->sgte!=NULL)
	{
		v=pop(poriginal);
		push(pcopia, v);
	}
	cout<<"\n pila 2";

	/*while(pcopia!=NULL){
		   // MUESTRO LA SEGUNDA PILA POR LAS DUDAS
			cout<<"\n "<<pop(pcopia);
		}*/
	//cout<<"\n pila 1";

	if(poriginal!=NULL){
		poriginal->info=valor;
	}
	//MUESTRO LA PILA 1 Q SOLO TIENE Q TENER UN VALOR
/*
		while(poriginal!=NULL){

				cout<<"\n "<<pop(poriginal);
			}
*/



	 //cambiar el 1 por otro numero si quiero eliminar mas cosas
	for(int i=0;i<1 && pcopia!=NULL;i++)
	{
		pop(pcopia);
	}

	while(pcopia!=NULL)
	{
		push(poriginal,pop(pcopia));
	}

return;
}
