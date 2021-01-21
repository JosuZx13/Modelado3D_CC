#ifndef DIGIDEL_CABEZA_H
#define DIGIDEL_CABEZA_H

/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "object3d.h"
#include "sphere.h"
#include "cone.h"

//Clase creada para la Práctica 03
class _digidel_cabeza:public _object3D {
    private:
        _sphere cara;
        _cone oreja_izq;
        _cone oreja_der;
        _cone oreja_trasera;

    public:
        _digidel_cabeza();
        void draw_point();
        void draw_line();
        void draw_fill();
        void draw_chess();

        // Practia 04 --> Textura e Iluminacion
        void draw_flat_shaded_lighting();
        void draw_gouraud_shaded_lighting();
        void draw_unlit_texture();
        void draw_texture_flat_shaded_lighting();
        void draw_gouraud_shaded_lighting_texture();
};

#endif // DIGIDEL_CABEZA_H
