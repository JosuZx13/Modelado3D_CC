/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "sphere.h"

_sphere::_sphere(float Size) {

    int n_verts = 9 ;
    float alpha = 0;

    Perfil.resize(n_verts-1); // Se cargaran mediante push_bach. Se inicializa a 0 para no cargar puntos de más
    // Se empieza en 1 porque no interesa el punto pegado al EjeY
    for(int i = 1; i < n_verts; i++){

        alpha = -(M_PI/2) + (i*M_PI/(n_verts));

        Perfil[i-1] = _vertex3f(0.5*cos(alpha), 0.5*sin(alpha), 0.0);
    }

    Bases.resize(2);

    Bases[0]=_vertex3f(0, -Size/2, 0); // Base Inferior
    Bases[1]=_vertex3f(0, Size/2, 0); // Base Superior


    unsigned int cortes = 30;
    revolucion(cortes);
    creacionCuerpo(cortes);
    creacionBases(cortes, true, true);
}
