#include "byte.h"
#include "imagen.h"

Imagen::Imagen(){
	nfilas = 0;
	ncolumnas = 0;
}

Imagen::Imagen(int filas, int columnas){
	nfilas = filas;
	ncolumnas = columnas;
	for(int i=0; i<nfilas*ncolumnas; i++){
		datos[i] = 0;
	}
}

void Imagen::crear(int filas, int columnas){
	nfilas = filas;
	ncolumnas = columnas;
	for(int i=0; i<nfilas*ncolumnas; i++){
		datos[i] = 0;
	}
}

int Imagen::filas() const{
	return nfilas;
}

int Imagen::columnas() const{
	return ncolumnas;
}

void Imagen::set(int y, int x, Byte v){
	int i = y*ncolumnas+x;
	datos[i] = v;
}

Byte Imagen::get(int y, int x, Byte v){
	int i = y*ncolumnas+x;
	return datos[i];
}

void Imagen::setPos(int i, Byte v){
	datos[i] = v;
}

Byte Imagen::getPos(int i) const{
	Return datos[i];
}

bool Image::leerImagen(const char nombreFichero[]){
	
}
