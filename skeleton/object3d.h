/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D {

    public:
        vector<_vertex3ui> Triangles; // Es un vector en tres ejes: X Y Z
        /*
        For triangles, normals are created from the triangle vertex positions.
        The edge vectors lie in the plane of the triangle face and are
        tangent to the face. So, the cross product of two edge vectors
        results in a vector perpendicular to the tangent: the normal vector.
        */
        vector<_vertex3f> Triangles_normals; // Las normales

        // Requiere de los Triangulos, por eso no se hace en la clase Basic su calculo
        vector<_vertex3f> Vertexes_normals; //Cada vector tiene su normal

        _object3D(){selected_triangle=-1;};
        void draw_line();
        void draw_fill();
        void draw_chess();

        // Practia 04 --> Textura e Iluminacion
        void draw_flat_shaded_lighting();
        void draw_gouraud_shaded_lighting();
        void draw_unlit_texture();
        void draw_texture_flat_shaded_lighting();
        void draw_gouraud_shaded_lighting_texture();

        // Practica 05
        bool is_selected(unsigned int t);
        void draw_scene();
        void selection(float color[]);
        void crearColores();

    protected:
        vector<_vertex3f> colours;      // Practica 05
        unsigned int selected_triangle; // Practica 05
        vector<_vertex3f> colores;      // Practica 05
        vector<unsigned int> triangles_selected; // Practica 05

        void normalize_triangles(); // Práctica 04
        void normalize_vertexes();  // Práctica 04
};

#endif // OBJECT3D_H
