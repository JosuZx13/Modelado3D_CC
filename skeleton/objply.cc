/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "objply.h"

_objply::_objply(string fichero){

    //Objeto de la clase File_PLY entregada para poder leer los ficheros PLY
    _file_ply lectorPLY;

    //Vectores para guardar las coordenadas y posiciones del ficherp PLY
    vector<float> coordinates;
    vector<unsigned int> positions;


    lectorPLY.open(fichero); //Se abre el fichero

    lectorPLY.read(coordinates, positions);

    Vertices.resize(coordinates.size()/3); //Consta de size/3 vertices
    Triangles.resize(positions.size()/3); // Consta de size/3 triangulos

    unsigned int vert = 0; //Será el indice para controlar la insercción de los datos en los vertices
    unsigned int trian = 0; //Será el indice para controlar el triangulos que se añade


    //Como cada vertice coordenadas X, Y, Z, cada trío de puntos es un vértice
    //Además se divide entre 3 el FOR (o sea, v avanza de 3 en 3)
    for(unsigned int v=0; v < coordinates.size(); v=v+3){
        Vertices[vert]=_vertex3f(coordinates[v], coordinates[v+1], coordinates[v+2]);
        vert++; //Se aumenta en uno para guardar el siguiente XYZ vertice
    }

    // Con los triangulos ocurre lo mismo que con los vértices a la hora de recogerlos
    for(unsigned int t=0; t < positions.size(); t=t+3){
        Triangles[trian]=_vertex3ui(positions[t], positions[t+1], positions[t+2]);
        trian++;
    }

    lectorPLY.close();


}
