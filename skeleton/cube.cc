/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "cube.h"

_cube::_cube(float Size) {

    Vertices.resize(8); //Consta de ocho vertices
    // Eje X, Y, Z Size == 1.0
    // Cuatro puntos frontales
    // XY = Size/2 porque salia muy grande
    // Z = Size/2 para traerlo al frente
    Vertices[0]=_vertex3f(-Size/2, Size/2, Size/2); //Arriba Izquierda
    Vertices[1]=_vertex3f(Size/2, Size/2, Size/2); //Arriba Derecha
    Vertices[2]=_vertex3f(-Size/2, -Size/2, Size/2); //Abajo Izquierda
    Vertices[3]=_vertex3f(Size/2, -Size/2, Size/2); //Abajo Derecha

    //Cuatro vertices de profundidad
    // Z = -Size/2 => Se llevan "hacia atrás" los puntos pero en la misma posición que los del frente
    // Se colocan en la profundidad opuesta para formar un cubo que se aprecie como tal en cualquier posicion
    Vertices[4]=_vertex3f(-Size/2, Size/2, -Size/2); //Arriba Izquierda Profunda
    Vertices[5]=_vertex3f(Size/2, Size/2, -Size/2); //Arriba Derecha Profunda
    Vertices[6]=_vertex3f(-Size/2, -Size/2, -Size/2); //Abajo Izquierda Profunda
    Vertices[7]=_vertex3f(Size/2, -Size/2, -Size/2); //Abajo Derecha Profunda

    // Cada cara está formada por dos triangulos
    // El cubo tiene 6 caras, 6*2 = 12
    Triangles.resize(12);

    // Se unen los puntos para formar un triangulo
    // Frontal
    Triangles[0]=_vertex3ui(0, 1, 3); // Cara Frontal, Mitad Superior
    Triangles[1]=_vertex3ui(0, 2, 3); // Cara Frontal, Mitad Inferior

    // Lateral Izquierdo
    Triangles[2]=_vertex3ui(0, 2, 4); // Mitad Superior
    Triangles[3]=_vertex3ui(2, 4, 6); // Mitad Inferior

    // Lateral Derecho
    Triangles[4]=_vertex3ui(1, 3, 5); // Mitad Superior
    Triangles[5]=_vertex3ui(3, 5, 7); // Mitad Inferior

    // Base
    Triangles[6]=_vertex3ui(3, 6, 7); // Mitad Superior
    Triangles[7]=_vertex3ui(2, 3, 6); // Mitad Inferior

    // Techo
    Triangles[8]=_vertex3ui(1, 4, 5); // Mitad Superior
    Triangles[9]=_vertex3ui(0, 1, 4); // Mitad Inferior

    // Cara Trasera
    Triangles[10]=_vertex3ui(4, 5, 7); // Mitad Superior
    Triangles[11]=_vertex3ui(4, 6, 7); // Mitad Inferior
}
