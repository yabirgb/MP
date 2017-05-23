#include "byte.h"
#include "lista.h"
#include <cstring>

Celda::Celda(){
	img = NULL;
	sig = NULL;
}

Celda::~Celda(){
	/*Celda* current = sig;
	Celda* next = sig->sig;
	while (next != NULL){	
		delete current;
		current = next;
	}
	delete current;
	current = 0;*/

	if (img != NULL){
		delete img;
		img = NULL;
	}

	if (sig != NULL){
		delete sig;
		sig = NULL;
	}
}

void Celda::setImagen(const Imagen &img){
	this->img = img;	
}

Imagen* getImagen(){
	Imagen * img = this->img;

	return img;
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
