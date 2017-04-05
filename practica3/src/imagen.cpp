#include "byte.h"
#include "imagen.h"
#include "pgm.h"
#include <cstring>

Imagen::Imagen(){
    nfilas = 0;
    ncolumnas = 0;
}

Imagen::Imagen(int filas, int columnas){

    if (nfilas >= 0 && ncolumnas >= 0 && filas*columnas < MAXPIXELS){
      nfilas = filas;
      ncolumnas = columnas;
      for(int i=0; i<nfilas*ncolumnas; i++){
        datos[i] = 0;
      }
    }
}

void Imagen::crear(int filas, int columnas){

    if (nfilas >= 0 && ncolumnas >= 0 && filas*columnas < MAXPIXELS){
      nfilas = filas;
      ncolumnas = columnas;
      for(int i=0; i<nfilas*ncolumnas; i++){
        datos[i] = 0;
      }
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
    if (i < MAXPIXELS && i >= 0)
      datos[i] = v;
}

Byte Imagen::get(int y, int x) const{
    Byte byte = 0x0;
    int i = y*ncolumnas+x;
    if (i < MAXPIXELS && i >= 0)
      byte = datos[i];

    return byte;
}

void Imagen::setPos(int i, Byte v){
    if (i < MAXPIXELS && i >= 0)
      datos[i] = v;
}

Byte Imagen::getPos(int i) const{
    Byte byte = 0x0;
    if (i < MAXPIXELS && i >= 0)
      byte = datos[i];

    return byte;
}

bool Imagen::leerImagen(const char nombreFichero[]){
    bool exito = false;
    // Comprobamos que sea PGM BINARIO
    if(infoPGM(nombreFichero, nfilas, ncolumnas) == IMG_PGM_BINARIO){
      // Comprobamos que no supere el tamaño máximo
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

  if (k < 7 && k >= 0){


    for (int i = 0; i < ncolumnas; i++){
      for(int j = 0; j < nfilas; j++){
        //Cojo cada byte de la imagen
        Byte byte = this->get(j,i);
        //Creo un byte con todo 0s
        Byte nuevo = 0x0;
        //Miro si la posición k del byte de la imagen está encendida
        bool estado = getBit(byte,k);
        //Coloco el bit más significativo a 1 si está encencido
        if (estado)
          onByte(nuevo);
        //Asigno el nuevo byte a la posición i,j de la imágen
        nueva.set(j,i, nuevo);
      }
    }
  }
  //Devuelvo la imagen
  return nueva;

}


bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong) const{
  bool tamanio_correcto = false;

  if (maxlong < MAXPIXELS  && nfilas*(ncolumnas+1) <= maxlong){
    tamanio_correcto = true;

    for (int i = 0; i < nfilas; i++){
      for(int j = 0; j < ncolumnas; j++){
        //Cojo cada byte de la imagen
        Byte byte = this->get(i,j);
        //Compruebo que símbolo le corresponde
        char simbolo = grises[byte*strlen(grises)/256];
        arteASCII[i*ncolumnas + j] = simbolo;
      }
      //añado el salto de carro al final de cada línea
      arteASCII[i*ncolumnas] = '\n';
    }

    //Agrego al final de la cadena el salto de línea y el caracter
    arteASCII[(nfilas-1)*ncolumnas+ncolumnas] = '\n';
    arteASCII[(nfilas-1)*ncolumnas+ncolumnas+1] = '\0';
  }

  return tamanio_correcto;
}
