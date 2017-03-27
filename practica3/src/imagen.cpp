#include "byte.h"
#include "imagen.h"
#include "pgm.h"
#include <string.h>

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

Byte Imagen::get(int y, int x) const{
    int i = y*ncolumnas+x;
    return datos[i];
}

void Imagen::setPos(int i, Byte v){
    datos[i] = v;
}

Byte Imagen::getPos(int i) const{
    return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
    bool exito = false;
    if(infoPGM(nombreFichero, nfilas, ncolumnas) == IMG_PGM_BINARIO){
      if(nfilas*ncolumnas < MAXPIXELS){
        exito = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
      }
    }
    return exito;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario) const{
    bool exito = false;
    if(esBinario){
      exito = escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
    }
    return exito;
}


Imagen Imagen::plano (int k) const{
  Imagen nueva(nfilas, ncolumnas);

  for (int i = 0; i < ncolumnas; i++){
    for(int j = 0; j < nfilas; j++){
      //Cojo cada byte de la imagen
      Byte byte = this->get(j,i);
      //Creo un byte con todo 0s
      Byte nuevo = 0x0;
      //Miro si la posición k del byte de la imagen está encendida
      bool estado = getBit(byte,k);
      //Coloco el bit más significativo a 1 si está encencido
      if (estado == true)
        onBit(nuevo,7);
      //Asigno el nuevo byte a la posición i,j de la imágen
      nueva.set(j,i, nuevo);
    }
  }
  //Devuelvo la imagen
  return nueva;
}


bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong) const{
  bool cabe = false;

  if (nfilas*ncolumnas + nfilas <= maxlong){
    cabe = true;

    for (int i = 0; i < nfilas; i++){
      for(int j = 0; j < ncolumnas; j++){
        //Cojo cada byte de la imagen
        Byte byte = this->get(i,j);
        //Compruebo que simbolo le correspondiente
        char simbolo = grises[byte*strlen(grises)/256];
        arteASCII[i*ncolumnas + j] = simbolo;
      }
      arteASCII[i*ncolumnas] = '\n';
    }
  }

  return cabe;
}
