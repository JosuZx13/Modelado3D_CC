#ifndef OBJHIERAR_H
#define OBJHIERAR_H

#endif // OBJHIERAR_H

#include "object3d.h"
#include "digidel_pata.h"
#include "digidel_cola.h"
#include "digidel_cabeza.h"

class _objhierar:public _object3D{
    private:
        _sphere cuerpo;
        _digidel_pata pata1, pata2, pata3, pata4;
        _digidel_cola cola;
        _digidel_cabeza cabeza;
        _digidel_crown corona;


    public:
        _objhierar();
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

        // Movimiento de Digidel
        void first_cascabeles(bool degree); // First
        void second_corona(bool degree);     // Second
        void third_cola(bool degree);       // Third

        // Ratio de modificacion
        void first_rate(bool rate);
        void second_rate(bool rate);
        void third_rate(bool rate);

};
