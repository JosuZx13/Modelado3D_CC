#ifndef OBJREV_H
#define OBJREV_H

#include "object3d.h"
#include <math.h>

class _objrev:public _object3D{

    public:      
        vector<_vertex3f> Perfil; //Contiene los puntos que componen el perfil principal (El cuerpo)
        /*
            Funciones Seno y Coseno para rotar cada punto del perfil; R = radio de la circunferencia
            x = R * cos(alpha)
            z = -R * sin(alpha)
            0 <= alpha <= 2PI

            Transparencias Tema 02 - Rotacion Eje Y
                P' = R(P) con R = alpha
                x' = x * cos(alpha) + z * sin(alpha)
                y' = y // Porque es sobre el Eje Y
                z' = -x * sin(alpha) + z*cos(alpha)
        */
        vector<_vertex3f> Bases; //Se van a guardar las bases Superior e Inferior de la figura, que dependerá de la propia figura

        // Necesita el conjunto de vertices y el angulo por el que va rotando
        // Devuelve un nuevo conjunto de vertices tras rotar
        _vertex3f rotarY(_vertex3f v, double alpha); //El perfil se va a rotar sobre el Eje Y (Y no cambia)

        // Al igual que object3D no hay constructor, es una clase "template"
        void revolucion(unsigned int n); //A la hora de revolucionar el objeto se hacen n cortes (minimo 3)

        // Se crean los triángulos del objeto
        // Es necesario pasar n para poder recorrer los bucles
        void creacionCuerpo(unsigned int n);

        void creacionBases(unsigned int n, bool superior, bool inferior);
};

#endif // OBJREV_H
