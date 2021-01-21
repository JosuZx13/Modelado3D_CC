#ifndef DIGIDEL_PATA_H
#define DIGIDEL_PATA_H

/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "object3d.h"
#include "sphere.h"
#include "cylinder.h"
#include "cone.h"

//Clase creada para la Práctica 03
class _digidel_pata:public _object3D {
    private:
        _cylinder pata;
        _sphere rodilla;
        _cone garra;

    public:
        _digidel_pata();
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

#endif // DIGIDEL_PATA_H
