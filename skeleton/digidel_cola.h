#ifndef DIGIDEL_COLA_H
#define DIGIDEL_COLA_H

/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "object3d.h"
#include "cylinder.h"
#include "cone.h"
#include "sphere.h"
#include "digidel_crown.h"

//Clase creada para la Práctica 03
class _digidel_cola:public _object3D {
    private:
        _cylinder cuerpo;
        _digidel_crown corona;

        // Atributos globales para posicionar el objeto jerarquico
        // Al tenerlos como variables es más fácil modificar el movimento
        double angulo;
        double speed;
        double rate_speed;

    public:
        _digidel_cola();
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

        // Movmimientos de Digidel de la cola
        void first_cascabeles(bool degree); // First
        void second_corona(bool degree);     // Second
        void third_cola(bool degree);       // Third

        // Ratio de la modificacion
        void first_rate(bool rate);
        void second_rate(bool rate);
        void third_rate(bool rate);
};


#endif // DIGIDEL_COLA_H
