#include "lista.h"
#include <cstring>

Lista::Lista(){
	lista = NULL;
}

Lista::~Lista(){
	destruir();
}

void Lista::destruir(){
	if (lista != NULL){
		delete lista;
		lista = NULL;
	}
}

void Lista::insertarPrincipio(const Imagen &img){
	Celda * nueva = new Celda;
	nueva->sig = lista;
	nueva->img = img;	
}

void Lista:: insertarFinal(const Imagen &img){
	Celda * nueva = new Celda;
	nueva->img = img;
	
	Celda* aux = lista.getSiguiente();
	while(aux->sig != NULL)
		aux = aux.getSiguiente();

	aux = nueva;
}
void setSiguiente(Celda* next){
	if(sig != NULL){
		delete sig;	
	}
	sig = next;
}

Celda* getSiguiente() const{
	Celda* sigue = sig;
	return sigue;
}
