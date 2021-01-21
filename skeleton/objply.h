#ifndef OBJPLY_H
#define OBJPLY_H

//Clase creada para la Practica 01
#include "object3d.h"
#include "file_ply_stl.h"

class _objply:public _object3D {

        public:
            _objply(string fichero="../ply_models/ant.ply");
};

#endif // OBJPLY_H
