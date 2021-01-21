/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "cylinder.h"

_cylinder::_cylinder(float Size) {

    // Se rellenan con los puntos del perfil, modificando la variable perfil
    Perfil.resize(2); //Consta de 4 puntos
    // Se eliminan los puntos pegados al Eje Y para evitar la repetición de triangulos a la hora de rotar
    // Perfil.resize(2);

    // Se guardan de abajo a arriba
    Perfil[0]=_vertex3f(Size/2, -Size/2, 0);
    Perfil[1]=_vertex3f(Size/2, Size/2, 0);

    Bases.resize(2);
    // Los puntos que componen las bases superior e inferior. Están pegados al Eje Y, por tanto no se añaden al del cuerpo
    // Se evita la repetición de puntos
    Bases[0] =_vertex3f(0, -Size/2, 0);
    Bases[1] =_vertex3f(0, Size/2, 0);

    unsigned int cortes = 30;

    revolucion(cortes);
    creacionCuerpo(cortes);
    creacionBases(cortes, true, true);

}
