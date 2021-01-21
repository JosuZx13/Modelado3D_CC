/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}

//Metodo auxiliar para no repetir codigo
bool _gl_widget::EnableMode(int em){

    if(em == Qt::Checked){
        return true;
    }
    return false;
}

//Implementacion de los Slots para la funcionalidad del Widget en Window
void _gl_widget::modoPuntos(int p){
    Draw_point = EnableMode(p);
    update(); //Lo redibuja todo
}

void _gl_widget::modoLineas(int l){
    Draw_line = EnableMode(l);
    update();
}
/*
void _gl_widget::modoRelleno(int r){
    Draw_fill = EnableMode(r);
    update();
}

void _gl_widget::modoAjedrez(int a){
    Draw_chess = EnableMode(a);
    update();
}*/

void _gl_widget::obj_tetrahedron(){
    Object=OBJECT_TETRAHEDRON;
    update();
}

void _gl_widget::obj_cube(){
    Object=OBJECT_CUBE;
    update();
}

void _gl_widget::obj_cone(){
    Object=OBJECT_CONE;
    update();
}

void _gl_widget::obj_cylinder(){
    Object=OBJECT_CYLINDER;
    update();
}

void _gl_widget::obj_sphere(){
    Object=OBJECT_SPHERE;
    update();
}

void _gl_widget::obj_ply(){
    Object=OBJECT_PLY;
    update();
}

void _gl_widget::obj_hierarchical(){
    Object=OBJECT_HIERARCHICAL;
    update();
}

void _gl_widget::obj_dashboard(){
    Object=OBJECT_DASHBOARD;
    update();
}

void _gl_widget::First_Increase(){
    First_Degree_Increase();
    update();
}
void _gl_widget::First_Decrease(){
    First_Degree_Decrease();
    update();
}
void _gl_widget::First_Rate_Increase(){
    First_Rate_Modification_Increase();
    update();
}
void _gl_widget::First_Rate_Decrease(){
    First_Rate_Modification_Decrease();
    update();
}
void _gl_widget::Second_Increase(){
    Second_Degree_Increase();
    update();
}
void _gl_widget::Second_Decrease(){
    Second_Degree_Decrease();
    update();
}
void _gl_widget::Second_Rate_Increase(){
    Second_Rate_Modification_Increase();
    update();
}

void _gl_widget::Second_Rate_Decrease(){
    Second_Rate_Modification_Decrease();
    update();
}
void _gl_widget::Third_Increase(){
    Third_Degree_Increase();
    update();
}
void _gl_widget::Third_Decrease(){
    Third_Degree_Decrease();
    update();
}
void _gl_widget::Third_Rate_Increase(){
    Third_Rate_Modification_Increase();
    update();
}

void _gl_widget::Third_Rate_Decrease(){
    Third_Rate_Modification_Decrease();
    update();
}

void _gl_widget::AnimarDigidel(){
    Animation();
}

void _gl_widget::Agitar(){
    if(increase){
        turno++;
        First_Degree_Increase();
        Second_Degree_Increase();
        Third_Degree_Increase();
        update();

        if(turno == REPETICIONES){
            increase = false;
        }
    }else{
        turno--;
        First_Degree_Decrease();
        Second_Degree_Decrease();
        Third_Degree_Decrease();
        update();

        if(turno == 0){
            increase = true;
        }
    }

    // Rota 360 grados alrededor del objeto
    if (Second_Light) {
        Angle_Light_Magenta = (Angle_Light_Magenta < 360 ) ? Angle_Light_Magenta += 5 : Angle_Light_Magenta = 0;
        //cout << angle_light_magenta << endl;
    }
}

void _gl_widget::ChangePerspective(){
    Projection_Type=PERSPECTIVE_PROJECTION;
    update();
}

void _gl_widget::ChangeParallel(){
    Projection_Type=PARALLEL_PROJECTION;
    update();
}

void _gl_widget::modoLight1(int l1){
    First_Light = EnableMode(l1);
    update();
}

void _gl_widget::modoLight2(int l2){
    Second_Light = EnableMode(l2);
    update();
}

void _gl_widget::no_mode(){
    Draw_fill = false;
    update();
}

void _gl_widget::mode_solid(){
    Draw_fill=true;
    Rendering_Mode=MODE_SOLID;
    update();
}

void _gl_widget::mode_chess(){
    Draw_fill=true;
    Rendering_Mode=MODE_SOLID_CHESS;
    update();
}

void _gl_widget::mode_flat_shaded_lighting(){
    Draw_fill=true;
    Rendering_Mode=MODE_FLAT_SHADED_LIGHTING;
    update();
}

void _gl_widget::mode_gouraud_shaded_lighting(){
    Draw_fill=true;
    Rendering_Mode=MODE_GOURAUD_SHADED_LIGHTING;
    update();
}

void _gl_widget::mode_unlit_texture(){
    Draw_fill=true;
    Rendering_Mode=MODE_UNLIT_TEXTURE;
    update();
}

void _gl_widget::mode_texture_flat_shaded_lighting(){
    Draw_fill=true;
    Rendering_Mode=MODE_TEXTURE_FLAT_SHADED_LIGHTING;
    update();
}

void _gl_widget::mode_gouraud_shaded_lighting_texture(){
    Draw_fill=true;
    Rendering_Mode=MODE_GOURAUD_SHADED_LIGHTING_TEXTURE;
    update();
}

void _gl_widget::obsidian(){
    Material_chosen = 0;
    update();
}

void _gl_widget::turquoise(){
    Material_chosen = 1;
    update();
}

void _gl_widget::redRubber(){
    Material_chosen = 2;
    update();
}

void _gl_widget::AlternarMaterial(){
    Material_chosen=(Material_chosen+1)%NUM_MATERIAL;
    update();
}

/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent) {
    switch(Keyevent->key()){
        case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
        case Qt::Key_2:Object=OBJECT_CUBE;break;            //Practica 01
        case Qt::Key_3:Object=OBJECT_CONE;break;            //Practica 02
        case Qt::Key_4:Object=OBJECT_CYLINDER;break;        //Practica 02
        case Qt::Key_5:Object=OBJECT_SPHERE;break;          //Practica 02
        case Qt::Key_6:Object=OBJECT_PLY;break;             //Practica 02
        case Qt::Key_7:Object=OBJECT_HIERARCHICAL;break;    //Practica 03
        case Qt::Key_8:Object=OBJECT_DASHBOARD;break;      //Practica 04

        case Qt::Key_P:Draw_point=!Draw_point;break;
        case Qt::Key_L:Draw_line=!Draw_line;break;
        case Qt::Key_F:Draw_fill=!Draw_fill;break;
        // Mio Propio
        case Qt::Key_O:Draw_chess=!Draw_chess;break; //Se cambia por F2 en la práctica 04

        case Qt::Key_A:Animation();break;                               //Practica 03

        case Qt::Key_Q:First_Degree_Increase();break;                   //Práctica 03
        case Qt::Key_W:First_Degree_Decrease();break;                   //Práctica 03

        case Qt::Key_S:Second_Degree_Increase();break;                  //Práctica 03
        case Qt::Key_D:Second_Degree_Decrease();break;                  //Práctica 03

        case Qt::Key_Z:Third_Degree_Increase();break;                   //Práctica 03
        case Qt::Key_X:Third_Degree_Decrease();break;                   //Práctica 03

        case Qt::Key_E:First_Rate_Modification_Increase();break;        //Práctica 03
        case Qt::Key_R:First_Rate_Modification_Decrease();break;        //Práctica 03

        case Qt::Key_T:Second_Rate_Modification_Increase();break;       //Práctica 03
        case Qt::Key_Y:Second_Rate_Modification_Decrease();break;       //Práctica 03

        case Qt::Key_U:Third_Rate_Modification_Increase();break;        //Práctica 03
        case Qt::Key_I:Third_Rate_Modification_Decrease();break;        //Práctica 03

        case Qt::Key_F1:
            Draw_fill=true;
            Rendering_Mode=MODE_SOLID;break;                            // Practica 04
        case Qt::Key_F2:
            Draw_fill=true;
            Rendering_Mode=MODE_SOLID_CHESS;break;                      // Practica 04
        case Qt::Key_F3:
            Draw_fill=true;
            Rendering_Mode=MODE_FLAT_SHADED_LIGHTING;break;             // Practica 04
        case Qt::Key_F4:
            Draw_fill=true;
            Rendering_Mode=MODE_GOURAUD_SHADED_LIGHTING;break;          // Practica 04
        case Qt::Key_F5:
            Draw_fill=true;
            Rendering_Mode=MODE_UNLIT_TEXTURE;break;                    // Practica 04
        case Qt::Key_F6:
            Draw_fill=true;
            Rendering_Mode=MODE_TEXTURE_FLAT_SHADED_LIGHTING;break;     // Practica 04
        case Qt::Key_F7:
            Draw_fill=true;
            Rendering_Mode=MODE_GOURAUD_SHADED_LIGHTING_TEXTURE;break;  // Practica 04
        // Mia propia
        case Qt::Key_F8:Draw_fill=false;break;

        case Qt::Key_J:First_Light=!First_Light;break;   // Pratica 04
        case Qt::Key_K:Second_Light=!Second_Light;break;   // Practica 04
        // Cambia entre los tres tipos de materiales que hay
        case Qt::Key_M:Material_chosen=(Material_chosen+1)%NUM_MATERIAL;break;   // Practica 04

        case Qt::Key_C:Projection_Type=PERSPECTIVE_PROJECTION;break; // Practica 05
        case Qt::Key_V:Projection_Type=PARALLEL_PROJECTION;break;   // Practica 05

        case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
        case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
        case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
        case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
        case Qt::Key_PageUp:Observer_distance*=1.2;break;
        case Qt::Key_PageDown:Observer_distance/=1.2;break;

    }

    update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Esto sirve sobre todo para ajustar el zoom en la proyección paralela
    // Para mantener una relación de ASPECTO con el tamaño de la ventana
    float aspecto = w_height/w_width;

    // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
    // Front_plane>0  Back_plane>PlanoDelantero)
    //glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);

    // Practica 05
    if (Projection_Type==PERSPECTIVE_PROJECTION){
            glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
            //glFrustum(-Camera_width,Camera_width,-Camera_width*Aspect, Camera_width*Aspect,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);

    }else if (Projection_Type==PARALLEL_PROJECTION){
        //Camara ortogonal
        glOrtho(X_MIN*Scale_factor , X_MAX*Scale_factor , Y_MIN*aspecto*Scale_factor , Y_MAX*aspecto*Scale_factor, FRONT_PLANE_PARALLEL , BACK_PLANE_PARALLEL );
        //glOrtho(-Camera_width*Scale_factor , Camera_width*Scale_factor , -Camera_width*Aspect*Scale_factor , Camera_width*Aspect*Scale_factor , FRONT_PLANE_PARALLEL , BACK_PLANE_PARALLEL );
    }
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer() {
    // posicion del observador
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-Observer_distance);
    glRotatef(Observer_angle_x,1,0,0);
    glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects() {
    Axis.draw_line();

    if (Draw_point){
        glPointSize(5);
        glColor3fv((GLfloat *) &BLACK);
        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
            case OBJECT_CUBE:Cube.draw_point();break;           //Cube es un objeto creado en el Header de GLWIDGET del tipo _cube
            case OBJECT_CONE:Cone.draw_point();break;           //Práctica 02
            case OBJECT_CYLINDER:Cylinder.draw_point();break;   //Práctica 02
            case OBJECT_SPHERE:Sphere.draw_point();break;       //Práctica 02
            case OBJECT_PLY:ObjPly.draw_point();break;          //Práctica 02
            case OBJECT_HIERARCHICAL:ObjHierar.draw_point();break;  // Practica 03
            case OBJECT_DASHBOARD:Dashboard.draw_point();break;  // Practica 04
            default:break;
        }

        //Las matrices de rotacion se crean antes de la rotacion

        //glRotatef(90, 0, 0 1); //Grados, Eje X, eje Y, Eje Z
        //glPushMatrix(); //Para que solo rote respecto la base)
            //Todo lo que se ejecute aquí se aplica a lo que esté dentro
        //glPopMatrix();

        //EJemplo: S(R(O)) El orden de las funciones tengo del glMatrix se aplican como una pila, la ultima que entra la primera que se ejecuta
        /*
        Orden correcto:
        Translate
        Rotate
        Scale
        */
        //glScalef(); //Se le pasa el valor por el que se multiplicaria en el EjeX, Eje Y, Eje Z

        //La ejecucion se hace primero escalar y luego se rota. El orden se hace de arriba abajo

        //glTranslatef(); //Translada en cada eje (X, Y, Z)


        //Para cada parte del cuerpo, cabeza, brazo, base, se crearía un push y pop matrix y entre ambos métodos se realizan las transformaciones pertinentes

        // En matrix se puede meter también un color personalizado. usando glColor3f(r, g, b) sin embargo no tiene en cuenta el push matrix o pop, aplica a todo
        // "Todo lo que venga después es de color A"

        /*
        Para rotar desde otro punto que no sea el centro, primero hay que volverlo al centro, luego rotar y volver a dejarlo donde estaba al principio
        */

        /*
        Si se inserta un pushMAtrix dentro de otro, se aplica lo anterior y ademas lo nuevo
        */

        /*
        Lo más recomendable es hacer una clase con el objeto, para luego poder aplicar operaciones al objeto completo en un pushMatrix
        */
    }

    if (Draw_line){
        glLineWidth(3);
        glColor3fv((GLfloat *) &BLUE);
        switch (Object){
            case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
            case OBJECT_CUBE:Cube.draw_line();break;
            case OBJECT_CONE:Cone.draw_line();break;                //Práctica 02
            case OBJECT_CYLINDER:Cylinder.draw_line();break;        //Práctica 02
            case OBJECT_SPHERE:Sphere.draw_line();break;            //Práctica 02
            case OBJECT_PLY:ObjPly.draw_line();break;               //Práctica 02
            case OBJECT_HIERARCHICAL:ObjHierar.draw_line();break;   //Práctica 03
            case OBJECT_DASHBOARD:Dashboard.draw_line();break;
            default:break;
        }
    }

    if (Draw_fill){ // Practica 04 --> Se controla que modo de render hay activo ya que esto solo se aplica si el modo de dibujo es Relleno

        switch(Rendering_Mode){
            case MODE_SOLID:
                glColor3fv((GLfloat *) &MAGENTA);
                switch (Object){
                    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
                    case OBJECT_CUBE:Cube.draw_fill();break;
                    case OBJECT_CONE:Cone.draw_fill();break;                //Práctica 02
                    case OBJECT_CYLINDER:Cylinder.draw_fill();break;        //Práctica 02
                    case OBJECT_SPHERE:Sphere.draw_fill();break;            //Práctica 02
                    case OBJECT_PLY:ObjPly.draw_fill();break;               //Práctica 02
                    case OBJECT_HIERARCHICAL:ObjHierar.draw_fill();break;   //Práctica 03
                    case OBJECT_DASHBOARD:Dashboard.draw_fill();break;
                    default:break;
                }
            break;

            case MODE_SOLID_CHESS:
                switch (Object){
                    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
                    case OBJECT_CUBE:Cube.draw_chess();break;
                    case OBJECT_CONE:Cone.draw_chess();break;
                    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
                    case OBJECT_SPHERE:Sphere.draw_chess();break;
                    case OBJECT_PLY:ObjPly.draw_chess();break;
                    case OBJECT_HIERARCHICAL:ObjHierar.draw_chess();break;
                    case OBJECT_DASHBOARD:Dashboard.draw_chess();break;
                    default:break;
                }
            break;

            case MODE_FLAT_SHADED_LIGHTING:
                Ambient(0.1, 0.1, 0.1, 1);

                glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

                Lights();
                Materials();

                glEnable(GL_LIGHTING);

                switch (Object){
                    case OBJECT_TETRAHEDRON:Tetrahedron.draw_flat_shaded_lighting();break;
                    case OBJECT_CUBE:Cube.draw_flat_shaded_lighting();break;
                    case OBJECT_CONE:Cone.draw_flat_shaded_lighting();break;
                    case OBJECT_CYLINDER:Cylinder.draw_flat_shaded_lighting();break;
                    case OBJECT_SPHERE:Sphere.draw_flat_shaded_lighting();break;
                    case OBJECT_PLY:ObjPly.draw_flat_shaded_lighting();break;
                    case OBJECT_HIERARCHICAL:ObjHierar.draw_flat_shaded_lighting();break;
                    case OBJECT_DASHBOARD:Dashboard.draw_flat_shaded_lighting();break;
                    default:break;
                }

                glDisable(GL_LIGHTING);

            break;

            case MODE_GOURAUD_SHADED_LIGHTING:
                Ambient(0.1, 0.1, 0.1, 1);

                glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

                Lights();
                Materials();

                glEnable(GL_LIGHTING);

                switch (Object){
                    case OBJECT_TETRAHEDRON:Tetrahedron.draw_gouraud_shaded_lighting();break;
                    case OBJECT_CUBE:Cube.draw_gouraud_shaded_lighting();break;
                    case OBJECT_CONE:Cone.draw_gouraud_shaded_lighting();break;
                    case OBJECT_CYLINDER:Cylinder.draw_gouraud_shaded_lighting();break;
                    case OBJECT_SPHERE:Sphere.draw_gouraud_shaded_lighting();break;
                    case OBJECT_PLY:ObjPly.draw_gouraud_shaded_lighting();break;
                    case OBJECT_HIERARCHICAL:ObjHierar.draw_gouraud_shaded_lighting();break;
                    case OBJECT_DASHBOARD:Dashboard.draw_gouraud_shaded_lighting();break;
                    default:break;
                }

                glDisable(GL_LIGHTING);

            break;

            case MODE_UNLIT_TEXTURE:
                switch (Object){
                    case OBJECT_TETRAHEDRON:Tetrahedron.draw_unlit_texture();break;
                    case OBJECT_CUBE:Cube.draw_unlit_texture();break;
                    case OBJECT_CONE:Cone.draw_unlit_texture();break;
                    case OBJECT_CYLINDER:Cylinder.draw_unlit_texture();break;
                    case OBJECT_SPHERE:Sphere.draw_unlit_texture();break;
                    case OBJECT_PLY:ObjPly.draw_unlit_texture();break;
                    case OBJECT_HIERARCHICAL:ObjHierar.draw_unlit_texture();break;
                    case OBJECT_DASHBOARD:Dashboard.draw_unlit_texture();break;
                    default:break;
                }
            break;

            case MODE_TEXTURE_FLAT_SHADED_LIGHTING:
                Ambient(0.1, 0.1, 0.1, 1);

                glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

                Lights();
                Materials();

                glEnable(GL_LIGHTING);
                // Aplicar la Textura
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
                switch (Object){
                    case OBJECT_TETRAHEDRON:Tetrahedron.draw_texture_flat_shaded_lighting();break;
                    case OBJECT_CUBE:Cube.draw_texture_flat_shaded_lighting();break;
                    case OBJECT_CONE:Cone.draw_texture_flat_shaded_lighting();break;
                    case OBJECT_CYLINDER:Cylinder.draw_texture_flat_shaded_lighting();break;
                    case OBJECT_SPHERE:Sphere.draw_texture_flat_shaded_lighting();break;
                    case OBJECT_PLY:ObjPly.draw_texture_flat_shaded_lighting();break;
                    case OBJECT_HIERARCHICAL:ObjHierar.draw_texture_flat_shaded_lighting();break;
                    case OBJECT_DASHBOARD:Dashboard.draw_texture_flat_shaded_lighting();break;
                    default:break;
                }
                glDisable(GL_LIGHTING);

            break;

            case MODE_GOURAUD_SHADED_LIGHTING_TEXTURE:
                Ambient(0.1, 0.1, 0.1, 1);

                glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

                Lights();
                Materials();

                glEnable(GL_LIGHTING);
                // Aplicar la Textura
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
                switch (Object){
                    case OBJECT_TETRAHEDRON:Tetrahedron.draw_gouraud_shaded_lighting_texture();break;
                    case OBJECT_CUBE:Cube.draw_gouraud_shaded_lighting_texture();break;
                    case OBJECT_CONE:Cone.draw_gouraud_shaded_lighting_texture();break;
                    case OBJECT_CYLINDER:Cylinder.draw_gouraud_shaded_lighting_texture();break;
                    case OBJECT_SPHERE:Sphere.draw_gouraud_shaded_lighting_texture();break;
                    case OBJECT_PLY:ObjPly.draw_gouraud_shaded_lighting_texture();break;
                    case OBJECT_HIERARCHICAL:ObjHierar.draw_gouraud_shaded_lighting_texture();break;
                    case OBJECT_DASHBOARD:Dashboard.draw_gouraud_shaded_lighting_texture();break;
                    default:break;
                }
                glDisable(GL_LIGHTING);
            break;
        }
    }
}

/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL() {
    clear_window();
    change_projection();
    change_observer();
    draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1) {
    w_width = Width1;
    w_height = Height1;
    glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL() {

    const GLubyte* strm;

    strm = glGetString(GL_VENDOR);
    std::cerr << "Vendor: " << strm << "\n";
    strm = glGetString(GL_RENDERER);
    std::cerr << "Renderer: " << strm << "\n";
    strm = glGetString(GL_VERSION);
    std::cerr << "OpenGL Version: " << strm << "\n";

    if (strm[0] == '1'){
        std::cerr << "Only OpenGL 1.X supported!\n";
        exit(-1);
    }

    strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
    std::cerr << "GLSL Version: " << strm << "\n";

    int Max_texture_size=0;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
    std::cerr << "Max texture size: " << Max_texture_size << "\n";

    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);;

    // Inicializacion de los primeros valores que debe tomar el primer dibujo

    Object=OBJECT_TETRAHEDRON; // Para que a veces no se vea en lienzo en blanco

    Observer_angle_x=0;
    Observer_angle_y=0;
    Observer_distance=DEFAULT_DISTANCE;

    Draw_point=false;
    Draw_line=true;
    Draw_fill=false;
    Draw_chess=false;

    Activate_Animation=false;
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this , SLOT(Agitar()));
    turno = 0;
    increase = true;

    First_Light = true;
    Second_Light = false;
    Angle_Light_Magenta = 0; // Empieza en cero y comienza a moverse

    Rendering_Mode=MODE_SOLID;
    Material_chosen = 0;

    Scale_factor=10;
    Projection_Type=PERSPECTIVE_PROJECTION;

    // CODIGO PROFESOR

    // Code for reading an image

    QString File_name(TEXTURA_DIA);
    QImage Image;
    QImageReader Reader(File_name);
    Reader.setAutoTransform(true);
    Image = Reader.read();
    if (Image.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
        exit(-1);
    }

    Image=Image.mirrored();
    Image=Image.convertToFormat(QImage::Format_RGB888);

    // Code to control the application of the texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // Code to pass the image to OpenGL to form a texture 2D
    glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());

    //FIN CODIGO DADO POR EL PROFESOR
}

/*****************************************************************************//**
* EVENTOS DE GRADOS DE LIBERTAD (Práctica 03)
*
*
********************************************************************************/

void _gl_widget::First_Degree_Increase() {
    First_Degree = true;
    ObjHierar.first_cascabeles(First_Degree);
}

void _gl_widget::First_Degree_Decrease() {
    First_Degree = false;
    ObjHierar.first_cascabeles(First_Degree);
}

void _gl_widget::Second_Degree_Increase() {
    Second_Degree = true;
    ObjHierar.second_corona(Second_Degree);

}

void _gl_widget::Second_Degree_Decrease() {
    Second_Degree = false;
    ObjHierar.second_corona(Second_Degree);
}

void _gl_widget::Third_Degree_Increase() {
    Third_Degree = true;
    ObjHierar.third_cola(Third_Degree);

}

void _gl_widget::Third_Degree_Decrease() {
    Third_Degree = false;
    ObjHierar.third_cola(Third_Degree);
}

void _gl_widget::First_Rate_Modification_Increase() {
    First_Rate_Modification = true;
    ObjHierar.first_rate(First_Rate_Modification);
}

void _gl_widget::First_Rate_Modification_Decrease() {
    First_Rate_Modification = false;
    ObjHierar.first_rate(First_Rate_Modification);
}

void _gl_widget::Second_Rate_Modification_Increase() {
    Second_Rate_Modification = true;
    ObjHierar.second_rate(Second_Rate_Modification);
}

void _gl_widget::Second_Rate_Modification_Decrease() {
    Second_Rate_Modification = false;
    ObjHierar.second_rate(Second_Rate_Modification);
}

void _gl_widget::Third_Rate_Modification_Increase() {
    Third_Rate_Modification = true;
    ObjHierar.third_rate(Third_Rate_Modification);
}

void _gl_widget::Third_Rate_Modification_Decrease() {
    Third_Rate_Modification = false;
    ObjHierar.third_rate(Third_Rate_Modification);
}

void _gl_widget::Animation(){
    Activate_Animation=!Activate_Animation;
    if(Activate_Animation){
        Timer->start(VELOCIDAD_ANIMACION);
    }else{
        Timer->stop();
    }
}

/*****************************************************************************//**
 * ILUMINACION Y TEXTURA (Práctica 04)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::Lights(){

    if(First_Light){
        _vertex4f Position(0,0,1,0);
        glEnable(GL_LIGHT0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glLightfv(GL_LIGHT0,GL_POSITION,(GLfloat *)&Position);
        glPopMatrix();
    }else{
        glDisable(GL_LIGHT0); // Se mantiene desactivada la primera luz (Macro 0)
    }

    if(Second_Light){
        GLfloat light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f};
        GLfloat light_magenta[] = {1.0f, 0.0f, 1.0f, 1.0f};

        _vertex4f light1_position(12.0, 10.0, 20.0, 1.0);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_magenta);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_magenta);
        glEnable(GL_LIGHT1);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glRotatef(Angle_Light_Magenta,0,1,0);
        glLightfv(GL_LIGHT1,GL_POSITION, (GLfloat *)&light1_position);
        glPopMatrix();
    }else{
        glDisable(GL_LIGHT1); // Segunda luz, Macro 1
    }

}

// http://www.it.hiof.no/~borres/j3d/explain/light/p-materials.html
// Se han elegido tres materiales de esta pagina
void _gl_widget::Materials(){
    switch (Material_chosen){
        case 0:{ //Obsidian
            GLfloat mat_ambient[] = {0.05375f, 0.05f, 0.06625f, 0.82f};
            GLfloat mat_diffuse[] = {0.18275f, 0.17f, 0.22525f, 0.82f};
            GLfloat mat_specular[] = {0.332741f, 0.328634f, 0.346435f, 0.82f};
            float shine = 0.2f ;

            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
            glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS, shine);
        }
        break;

        case 1: {//Turquoise
            GLfloat mat_ambient[] = {0.1f, 0.18725f, 0.1745f};
            GLfloat mat_diffuse[] = {0.396f, 0.74151f, 0.69102f};
            GLfloat mat_specular[] = {0.297254f, 0.30829f, 0.306678f};
            float shine=0.2f;

            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT, mat_ambient);
            glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
        }
        break;
        case 2: { //Red rubber
            GLfloat mat_ambient[] = {0.05f,0.0f,0.0f};
            GLfloat mat_diffuse[] = {0.4f,0.5f,0.4f};
            GLfloat mat_specular[] = {0.7f,0.04f,0.04f};
            float shine=0.2f;

            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT, mat_ambient);
            glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
        }
        break;
    }
}


/*****************************************************************************//**
 * EVENTOS DEL RATÓN (Práctica 05)
 *
 *
 *
 *****************************************************************************/

//La camara solo se puede mover si esta el boton izquierdo pulsado
//La distancia se divide /3 para que al mover la camara se vea centrado (las 3 dimensiones)
void _gl_widget::mouseMoveEvent(QMouseEvent *Event) {

    int x = Event->x(), y = Event->y();

    if ( Event->buttons() & Qt::LeftButton ) {
        if ( last_x < x )   Observer_angle_y+=ANGLE_STEP/3;
        else if (last_x > x )   Observer_angle_y-=ANGLE_STEP/3;

        if ( last_y < y )   Observer_angle_x+=ANGLE_STEP/3;
        else if (last_y > y )   Observer_angle_x-=ANGLE_STEP/3;

        last_x = x;
        last_y = y;
    }
    update();
}

void _gl_widget::wheelEvent(QWheelEvent *Event) {

    // Desviacion por defecto de 15 grados
    //delta() indica el numero de lineas que debde desplazarse
    //la visualizacion por cada vuelta de rueda del raton.
    //Un valor positivo indica un desplazamiento hacia arriba,
    //y un valor negativo un desplazamiento hacia abajo

    // Typical Calculations (Ref Qt Doc)
    //Most mouse types work in steps of 15 degrees,
    //in which case the delta value is a multiple of 120; i.e., 120 units * 1/8 = 15 degrees.
    const int degrees = Event->delta()  / 8;
    int steps = degrees / 15;

    switch(Projection_Type){

        case PERSPECTIVE_PROJECTION:
            if (degrees > 0){

                Observer_distance /= steps*DISTANCE_FACTOR;

            }else if (degrees < 0){

                Observer_distance *= abs(steps*DISTANCE_FACTOR);
            }
        break;

        case PARALLEL_PROJECTION:
            if (degrees > 0){
                Scale_factor /= steps*DISTANCE_FACTOR;

            }else if (degrees < 0){
                Scale_factor *= abs(steps*DISTANCE_FACTOR);
            }

        break;
    }

    Event->accept();
    update();
}

// Al hacer click derecho al objeto selecciona el triangulo
void _gl_widget::mousePressEvent(QMouseEvent *Event) {

    if(Draw_fill){
        if (Event->buttons() & Qt::RightButton) {
            Selection_position_x = Event->x();
            Selection_position_y = height() - Event->y();

        }
    }

}

// Al despulsar el click derecho del ratón
void _gl_widget::mouseReleaseEvent(QMouseEvent *Event) {
    if (Draw_fill) {
        if ( Event->button() & Qt::RightButton ) {
            pick();
            update();
        }
    }
}


// Skeleton for pick fuction using glDeleteFramebuffers
//
// Domingo Martín Perandrés
// GPL
//
// Window_width and Window_height are the widht and height of the device window
// Selection_position_x and Selection_position_y are the coordinates of the mouse

void _gl_widget::pick() {
    //Para hacer el pick sobre la ventana actual
    makeCurrent();

    // dibujar con colores de seleccion
    glClearColor(0, 0, 0, 1);
    clear_window();
    change_projection();
    change_observer();

    switch (Object){
      case OBJECT_TETRAHEDRON:Tetrahedron.draw_scene();break;
       case OBJECT_PLY:ObjPly.draw_scene();break;
    default:break;}

    std::vector<float> Color(3);
    glPixelStorei(GL_PACK_ALIGNMENT,1);
    glReadBuffer(GL_BACK); // seleccionamos el buffer trasero

    /*************************/
    // captura el pixel
    glReadPixels(Selection_position_x, Selection_position_y,1,1,GL_RGB,GL_FLOAT, &Color[0]);

    // convertir de RGB a identificador
    // actualizar el identificador en el objeto
    /*************************/
    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.selection(&Color[0]);break;
        case OBJECT_PLY:ObjPly.selection(&Color[0]);break;
    default:break;
    }
    // Dibuja normal la segunda pasada
    glClearColor(1, 1, 1, 1);
    clear_window();
    change_projection();
    change_observer();
}
