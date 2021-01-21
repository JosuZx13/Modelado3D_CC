/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_GLEXT_PROTOTYPES
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QImage>
#include <QImageReader>
#include <QTimer>
#include <iostream>
#include <stdlib.h>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "objply.h"
#include "objhierar.h"
#include "dashboard.h"

namespace _gl_widget_ne {

    const float X_MIN=-.1;
    const float X_MAX=.1;
    const float Y_MIN=-.1;
    const float Y_MAX=.1;
    const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
    const float BACK_PLANE_PERSPECTIVE=1000;
    const float DEFAULT_DISTANCE=2;
    const int NUM_MATERIAL=3;
    const float FRONT_PLANE_PARALLEL=-1000; // Practica 05
    const float BACK_PLANE_PARALLEL=1000;   // Practica 05
    const float DISTANCE_FACTOR=0.55; // Aplicado al zoom de la camara
    const float ANGLE_STEP=1;
    const unsigned int REPETICIONES = 5; // Numero de movimientos de la animacion
    const unsigned int VELOCIDAD_ANIMACION = 200; // Velocidad con la que se ejecuta la animacion

    typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
    typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_CONE, OBJECT_CYLINDER,
                OBJECT_SPHERE, OBJECT_PLY, OBJECT_HIERARCHICAL, OBJECT_DASHBOARD} _object;

    // Tipo de iluminacion o textura (Practica 05)
    typedef enum {MODE_SOLID,MODE_SOLID_CHESS, MODE_FLAT_SHADED_LIGHTING,
                MODE_GOURAUD_SHADED_LIGHTING, MODE_UNLIT_TEXTURE,
                MODE_TEXTURE_FLAT_SHADED_LIGHTING,
                MODE_GOURAUD_SHADED_LIGHTING_TEXTURE} _rendering;

    typedef enum {PERSPECTIVE_PROJECTION, PARALLEL_PROJECTION} _projection;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget {
Q_OBJECT
public:
    _gl_widget(_window *Window1);

    void clear_window();
    void change_projection();
    void change_observer();

    void draw_axis();
    void draw_objects();

// Es necesario crear los slots para poder dotar de funcionalidad el menu creado en Windows
public slots:
    void modoPuntos(int p);
    void modoLineas(int l);
    //void modoRelleno(int r);
    //void modoAjedrez(int a);
    void obj_tetrahedron();
    void obj_cube();
    void obj_cone();
    void obj_cylinder();
    void obj_sphere();
    void obj_ply();
    void obj_hierarchical();
    void obj_dashboard();
    // Controla el movimiento mediante botones del objeto jerarquico
    void First_Increase();
    void First_Rate_Increase();
    void First_Decrease();
    void First_Rate_Decrease();
    void Second_Increase();
    void Second_Rate_Increase();
    void Second_Decrease();
    void Second_Rate_Decrease();
    void Third_Increase();
    void Third_Rate_Increase();
    void Third_Decrease();
    void Third_Rate_Decrease();
    // Fin de los métodos que controlan el movimiento del objeto jerarquico
    void AnimarDigidel(); // Este lo ejecuta el botón de Windows.h
    void Agitar(); // Realiza la animacion de la cola
    void ChangePerspective();   // Cambia el tipo de camara a Perspective
    void ChangeParallel();      // Cambia el tipo de camara a Parallel
    void modoLight1(int l1);
    void modoLight2(int l2);
    // Control de las texturas
    void no_mode();
    void mode_solid();
    void mode_chess();
    void mode_flat_shaded_lighting();
    void mode_gouraud_shaded_lighting();
    void mode_unlit_texture();
    void mode_texture_flat_shaded_lighting();
    void mode_gouraud_shaded_lighting_texture();
    // Control de los Materiales
    void obsidian();
    void turquoise();
    void redRubber();
    void AlternarMaterial(); // Cambia los materiales como si se pulsase la M

protected:
    void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void initializeGL() Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;

    // Practica 05
    // Mover camara con el ratón
    void mouseMoveEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
    // Zoom de la camara mediante la rueda del raton
    void wheelEvent(QWheelEvent *Event) Q_DECL_OVERRIDE;
    // Al hacer click
    void mousePressEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
    // Al levantar el click del raton
    void mouseReleaseEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
    // Seleccionar un triangulo y cambiar el color
    void pick(); // La estructura es código del profesor Domingo


private:
    _window *Window;

    _axis Axis;
    _tetrahedron Tetrahedron;
    _cube Cube; //Se añade el cubo (Práctica 01)
    _cone Cone; //Se añade el cono (Práctica 02)
    _cylinder Cylinder; //Se añade el cilindro (Práctica 02)
    _sphere Sphere; //Se añade la esfera (Práctica 02)
    _objply ObjPly; //Se añade el objeto PLY (Práctica 02)
    _objhierar ObjHierar; //Objeto Jerárquico (Práctica 03)
    _dashboard Dashboard;
    _gl_widget_ne::_object Object;

    bool Draw_point;
    bool Draw_line;
    bool Draw_fill;
    bool Draw_chess;

    float Observer_angle_x;
    float Observer_angle_y;
    float Observer_distance;

    bool Activate_Animation;    //Practica 03
    QTimer * Timer;             // Practica 03
    unsigned int turno; // Controla el proceso de la animacion
    bool increase;

    // Practica 03
    // Con estas variables se controla si debe hacer "Increase" o "Decrease"
    // TRUE => Increase; FALSE => Decrease
    bool First_Degree;
    bool Second_Degree;
    bool Third_Degree;
    bool First_Rate_Modification;
    bool Second_Rate_Modification;
    bool Third_Rate_Modification;

    // Practica 04 -- Texturas e Iluminacion
    bool First_Light;
    bool Second_Light;
    float Angle_Light_Magenta;
    _vertex4f Ambient; // Luz Ambiente

    // Numeraliza el material que esta activo. Ser un entero, permite que sea más fácil cambiarlo pulsando una letra (M)
    // Ya que puedes hacer % (módulo) sobre él
    int Material_chosen;

    const char* TEXTURA_DIA = "../texturas/dia_8192.jpg";
    const char* TEXTURA_ESTRELLAS = "../texturas/estrellas_8192.png";
    const char* TEXTURA_NUBES = "../texturas/nubes_8192.jpg";

    //Practica 05 -- Opciones para mover la camar con el raton
    int last_x, last_y; //Referencia a la posicion antes de mover la camara con el ratón
    int w_width; // Ancho de la pantalla indicado en Window.h
    int w_height; // Alto de la pantalla indicado en Window.h
    _gl_widget_ne::_projection Projection_Type;
    _gl_widget_ne::_rendering Rendering_Mode;

    // Para el pick
    int Selection_position_x;
    int Selection_position_y;
    unsigned int Selection_Triangle;

    float Scale_factor; // Practica 05

    bool EnableMode(int em);

    void First_Degree_Increase();               // Práctica 03
    void First_Degree_Decrease();               // Práctica 03

    void Second_Degree_Increase();              // Práctica 03
    void Second_Degree_Decrease();              // Práctica 03

    void Third_Degree_Increase();               // Práctica 03
    void Third_Degree_Decrease();               // Práctica 03

    void First_Rate_Modification_Increase();    // Práctica 03
    void First_Rate_Modification_Decrease();    // Práctica 03

    void Second_Rate_Modification_Increase();   // Práctica 03
    void Second_Rate_Modification_Decrease();   // Práctica 03

    void Third_Rate_Modification_Increase();    // Práctica 03
    void Third_Rate_Modification_Decrease();    // Práctica 03

    void Animation();                           // Practica 03

    void Lights();                              // Practica 04
    void Materials();

};

#endif
