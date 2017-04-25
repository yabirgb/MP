/**
   @file testplano.cpp
   @brief Lee la imagen imagenes/giotexto.pgm y extrae el plano 6 en plano6.pgm y el
   plano 0 en plano0.pgm
   @author MP-DGIM - Grupo A

**/
#include<iostream>
#include<imagen.h>
#include <string>

using namespace std;

int main(){
    Imagen origen, plano;
    char imagen1[]="data/giotexto.pgm", imagen2[] = "data/plano6.pgm", imagen3[] = "data/plano0.pgm";

	// Leer la imagen giotexto.pgm
	if (!origen.leerImagen(imagen1)){
		cerr << "error leyendo " << imagen1 << endl;
        origen.destruir();
	    plano.destruir();
		return 1;
	}

 	plano = origen.plano(6);

	// Guardar la imagen plano en el fichero plano6.pgm
	if (plano.escribirImagen(imagen2, false)){
		// si todo va bien
		cout << imagen2 << " guardado correctamente \n";
		cout << "usa: display " << imagen2 << " para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen " << imagen2;
        origen.destruir();
	    plano.destruir();
		return 1;
    
	}

	plano = origen.plano(0);

	// Guardar la imagen plano en el fichero plano0.pgm
	if (plano.escribirImagen(imagen3, false)){
		// si todo va bien
		cout << imagen3 << " guardado correctamente \n";
		cout << "usa: display " << imagen3 << " para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen " << imagen3;
        origen.destruir();
	    plano.destruir();
		return 1;
	}
       
    origen.destruir();
	plano.destruir();

	return 0;
}
