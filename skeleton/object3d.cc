/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line(){
    //Hay que dibujar cada triangulo
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //Se usa GL_TRIANGLES porque se quieren formar triangulos con cada vertice
    glBegin(GL_TRIANGLES);
        //La clase object3D tiene un conjunto vertex3ui Triangles
        for (unsigned int i=0;i<Triangles.size();i++){
            //Un triangulo estará formado por un conjunto de tres vertices
            //glVertex3fv((GLfloat *) &Vertices[i]);
            //No basta solo indicar uno, formaria solo la base
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].x]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].y]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].z]);
        }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
        for (unsigned int i=0;i<Triangles.size();i++){
            if(is_selected(i)){
                glColor3fv((GLfloat *) &BLUE);
            }else{
                glColor3fv((GLfloat *) &MAGENTA);
            }

            glVertex3fv((GLfloat *) &Vertices[Triangles[i].x]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].y]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].z]);       
        }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
        for (unsigned int i=0;i<Triangles.size();i++){
            // Solo va a indicarse una condición para que según si el triangulo tiene una posición par, use un color u otro
            if(i%2 == 0){
                glColor3fv((GLfloat *) &BLACK);
            }else{
                glColor3fv((GLfloat *) &RED);
            }
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].x]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].y]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].z]);
        }
    glEnd();
}

// TEXTURA E ILUMINACION --> PRACTICA 04
/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


void _object3D::draw_flat_shaded_lighting(){

    normalize_triangles();
    normalize_vertexes();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);

        for (unsigned int i = 0; i<Triangles.size(); i++){
            glNormal3f(Triangles_normals[i].x, Triangles_normals[i].y, Triangles_normals[i].z);

            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    glEnd();
}

void _object3D::draw_gouraud_shaded_lighting(){

    normalize_triangles();
    normalize_vertexes();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLES);

        for (unsigned int i = 0; i<Triangles.size(); i++){
            glNormal3f(Triangles_normals[i].x, Triangles_normals[i].y, Triangles_normals[i].z);

            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glNormal3f(Vertexes_normals[Triangles[i]._0].x, Vertexes_normals[Triangles[i]._0].y, Vertexes_normals[Triangles[i]._0].z);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glNormal3f(Vertexes_normals[Triangles[i]._1].x, Vertexes_normals[Triangles[i]._1].y, Vertexes_normals[Triangles[i]._1].z);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
            glNormal3f(Vertexes_normals[Triangles[i]._2].x, Vertexes_normals[Triangles[i]._2].y, Vertexes_normals[Triangles[i]._2].z);


        }
    glEnd();
}

void _object3D::draw_unlit_texture(){

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
        for (unsigned int i=0;i<Triangles.size();i++){
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].x]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].y]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i].z]);
        }
    glEnd();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}

void _object3D::draw_texture_flat_shaded_lighting(){
    normalize_triangles();
    normalize_vertexes();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_FLAT);

    glBegin(GL_TRIANGLES);

        for (unsigned int i = 0; i<Triangles.size(); i++){
            glNormal3f(Triangles_normals[i].x, Triangles_normals[i].y, Triangles_normals[i].z);

            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    glEnd();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}

void _object3D::draw_gouraud_shaded_lighting_texture(){
    normalize_triangles();
    normalize_vertexes();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLES);

        for (unsigned int i = 0; i<Triangles.size(); i++){
            glNormal3f(Triangles_normals[i].x, Triangles_normals[i].y, Triangles_normals[i].z);

            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glNormal3f(Vertexes_normals[Triangles[i]._0].x, Vertexes_normals[Triangles[i]._0].y, Vertexes_normals[Triangles[i]._0].z);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glNormal3f(Vertexes_normals[Triangles[i]._1].x, Vertexes_normals[Triangles[i]._1].y, Vertexes_normals[Triangles[i]._1].z);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
            glNormal3f(Vertexes_normals[Triangles[i]._2].x, Vertexes_normals[Triangles[i]._2].y, Vertexes_normals[Triangles[i]._2].z);


        }
    glEnd();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);

}

// CALCULO DE NORMALES
/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::normalize_triangles(){
    _vertex3f n;
    _vertex3f p0, p1, p2;
    float px, py, pz;
    float qx, qy, qz;
    float nx, ny, nz;

    float m;

    for(unsigned int i=0; i < Triangles.size(); ++i) {
        /*
         * Dados los puntos p0, p1 y p2, se calculan los vectores
         *
         * A = p1 - p0 y B = p2 - 0
         *
         * donde
         *      p0 = (x0, y0, z0)
         *      p1 = (x1, y1, z1)
         *      p2 = (x2, y2, z2)
         *
         * A = (px, py, pz)
         * donde
         *      px = (x1 - x0)
         *      py = (y1 - y0)
         *      pz = (z1 - z0)
         *
         * y B = (qx, qy, qz)
         * donde
         *      qx = (x2 - x0)
         *      qy = (y2 - y0)
         *      qz = (z2 - z0)
         *
         * Como el vector normalizado N = A (PRODCUTO VECTORIAL) B
         * Entonces N = (nx, ny, nz)
         * donde
         *      nx = ( (py * qz) - (pz * qy) )
         *      ny = ( (pz * qx) - (px * qz) )
         *      nz = ( (px * qy) - (py * qx) )
         *
         * El vector normalizado para el triangulo X, Triangles[i]
         * N = A (Producto Vectorial) B
         *
         * Por último, faltaria dividir cada componente de N
         * Por un modulo calculado de la forma
         *
         * m = SQRT( (nx² + ny² + nz²)
         *
         * nx = nx / m
         * ny = ny / m
         * nz = nz / m
         *
         * Y finalmente, N = (nx, ny, nz)

        */

        //Elige el punto (vertice) correspondiente al triangulo
        p0 = Vertices[Triangles[i]._0];
        p1 = Vertices[Triangles[i]._1];
        p2 = Vertices[Triangles[i]._2];

        // Vector A = (px, py, pz)
        px = (p1.x - p0.x);
        py = (p1.y - p0.y);
        pz = (p1.z - p0.z);

        // Vector B = (qx, qy, qz)
        qx = (p2.x - p0.x);
        qy = (p2.y - p0.y);
        qz = (p2.z - p0.z);

        // Vector N = (nx, ny, nz)
        nx = (py * qz) - (pz * qy);
        ny = (pz * qx) - (px * qz);
        nz = (px * qy) - (py * qx);

        m = pow(nx, 2) + pow(ny, 2) + pow(nz, 2);
        m = sqrt(m);

        nx = nx / m;
        ny = ny / m;
        nz = nz / m;

        n(nx, ny, nz);

        Triangles_normals.push_back(n);

        /*
        a(Vertices[Triangles[i]._1].x - Vertices[Triangles[i]._0].x,
          Vertices[Triangles[i]._1].y - Vertices[Triangles[i]._0].y,
          Vertices[Triangles[i]._1].z - Vertices[Triangles[i]._0].z);

        b(Vertices[Triangles[i]._2].x - Vertices[Triangles[i]._0].x,
          Vertices[Triangles[i]._2].y - Vertices[Triangles[i]._0].y,
          Vertices[Triangles[i]._2].z - Vertices[Triangles[i]._0].z);


        Para el triangulo p1, p2, p3, si el vector A= p2 - p1
        y el Vector B = p3 - p1
        Entonces la normal N = A x B
        siendo calculada de la forma:

        Nx = Ay * Bz - Az * By
        Ny = Az * Bx - Ax * Bz
        Nz = Ax * By - Ay * Bx


        n((a.y * b.z) - (a.z * b.y),
         -((a.x * b.z) - (a.z * b.x)),
          (a.x * b.y) - (a.y * b.x));


        //Normalizacion de la normal
        module = sqrt( pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2) );
        n/=module;
        */


    }
}

void _object3D::normalize_vertexes(){

    Vertexes_normals.resize(Vertices.size());   //Cada vector tiene su normal

    _vertex3f normal;

    for(unsigned int i = 0; i < Vertices.size(); ++i)
        Vertexes_normals[i] = _vertex3f(0.0,0.0,0.0);

    for(unsigned int i = 0; i < Triangles.size(); ++i){
        Vertexes_normals[Triangles[i]._0] += Triangles_normals[i];
        Vertexes_normals[Triangles[i]._1] += Triangles_normals[i];
        Vertexes_normals[Triangles[i]._2] += Triangles_normals[i];
    }

    for(unsigned int i = 0; i < Vertices.size(); ++i){
        Vertexes_normals[i].normalize();
    }
}

// Practica 05

bool _object3D::is_selected(unsigned int t){
    bool esta=false;
    for(unsigned int j=0; j<triangles_selected.size(); j++){
        if(triangles_selected[j]==t){
            esta=true;
        }
    }

    return esta;
}

void _object3D::selection(float color[]){

    unsigned int num=0;
    float diferencia=20;

    for(unsigned int i=0; i<colores.size(); i++){
        if( (abs(colores[i].x-color[0]) + abs(colores[i].y-color[1])  + abs(colores[i].z-color[2])) < diferencia  ){
            num=i;
            diferencia= (abs(colores[i].x-color[0]) + abs(colores[i].y-color[1])  + abs(colores[i].z-color[2]));
        }
        //cout << colores[i].x << " " <<  color[0] << endl << colores[i].y << " " << color[1]  << endl << colores[i].z <<" " <<  color[2] << endl;
    }

    bool esta= false;
    int pos=0;

    if(diferencia < 0.000001){
        for(unsigned int j=0; j<this->triangles_selected.size(); j++){
            if(triangles_selected[j]==num){ pos=j; esta=true;}
        }

        if(esta){
            triangles_selected.erase(triangles_selected.begin()+pos);
        }else{
            triangles_selected.push_back(num);
        }
    }
}

void _object3D::crearColores(){
    colores.resize(Triangles.size());

    for(unsigned int i=0; i<Triangles.size(); i++){

        float red = ((i+1) & 0x00FF0000) >>16;
        red /= 255.0;

        float green = ((i+1) & 0x0000FF00) >> 8;
        green /= 255.0;

        float blue=((i+1) & 0x000000FF);
        blue /= 255.0;

        colores[i]= _vertex3f(red,green,blue);
    }
}

// Se dibuja una escena para hacer la seleccion
void _object3D::draw_scene() {
    glPolygonMode(GL_FRONT,GL_FILL);

    crearColores();

    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){

        glColor3f(colores[i].x,colores[i].y,colores[i].z);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}
