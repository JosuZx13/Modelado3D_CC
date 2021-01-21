/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "cone.h"

_cone::_cone(float Size) {

    Perfil.resize(1);

    // Perfil[0]=_vertex3f(0, Size/2, 0); //Como la X es 0, no va cambiar, así que no es necesario rotar este punto
    Perfil[0]=_vertex3f(Size/2, -Size/2, 0);

    Bases.resize(2);

    Bases[0] = _vertex3f(0, -Size/2, 0);
    Bases[1] = _vertex3f(0, Size/2, 0);

    unsigned int cortes = 30;

    revolucion(cortes);
    creacionCuerpo(cortes);
    creacionBases(cortes, true, true);
}
