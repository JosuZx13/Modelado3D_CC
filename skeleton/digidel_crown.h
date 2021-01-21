#ifndef DIGIDEL_CROWN_H
#define DIGIDEL_CROWN_H

/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "object3d.h"
#include "cone.h"
#include "sphere.h"

//Clase creada para la Práctica 03
class _digidel_crown:public _object3D {
    private:
        _cone cola1;
        _sphere punta1;
        _cone cola2;
        _sphere punta2;
        _cone cola3;
        _sphere punta3;

        // First
        float altura;
        float speed_altura_first;
        float rate_altura;

        // Second
        double angulo;
        double speed_angulo;
        double rate_angulo;
        float speed_altura_second;



    public:
        _digidel_crown();
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

        // Liberty
        void first_cascabeles(bool degree); // First
        void second_corona(bool degree);    // Second

        // Ratio de Modificacion
        void first_rate(bool rate);
        void second_rate(bool rate);
        void third_rate(bool rate);
};

#endif // DIGIDEL_CROWN_H
