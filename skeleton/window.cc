/*! \file
 * Copyright Domingo Martín Perandres (Modificado por Jose Manuel Osuna Luque)
 */

#include "window.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_window::_window() {

    QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // Este es el contenedor principal que contiene los demas
    QWidget *Central_widget = new QWidget(this);
    setCentralWidget(Central_widget);
    setWindowTitle(tr("JOSE MANUEL OSUNA LUQUE OPENGL"));
    resize(w_window, h_window);

    GL_widget = new _gl_widget(this);
    GL_widget->setSizePolicy(Q);

    // El contendor con las opciones (las pestañas a la derecha)
    QTabWidget *opciones = new QTabWidget;
    opciones->setMaximumWidth(w_opciones);
    opciones->setMaximumHeight(h_opciones);
    QWidget *modos_widget = new QWidget; // Contenedor de una pestaña
    QWidget *objetos_widget = new QWidget;
    QWidget *textura_widget = new QWidget;

    // Se añaden los Widget al Contenedor y se ven como pestañas
    opciones->addTab(modos_widget, pest_modo);
    opciones->addTab(objetos_widget, pest_objeto);
    opciones->addTab(textura_widget, pest_textura);

    QHBoxLayout *horizontal_layout = new QHBoxLayout;
    horizontal_layout->addWidget(GL_widget);
    horizontal_layout->addWidget(opciones);

    Central_widget->setLayout(horizontal_layout);

    // ##################################################################################
    // ##################################################################################
    // MODO de dibujar una figura
    QVBoxLayout *vbox_modos = new QVBoxLayout;
    QGridLayout *modos_layout = new QGridLayout;

    modos_widget->setLayout(vbox_modos); //Se aplica un layout, una apariencia

    // SE AÑADEN LOS COMPONENTES AL COMBOBOX MODO
    // CheckBox para el modo Puntos
    QCheckBox *cb_puntos = new QCheckBox;
    QLabel *label_puntos = new QLabel(modo_puntos);
    modos_layout->addWidget(cb_puntos, 0, 0); //Se añaden pensando en que es un 1x2 el Widget
    modos_layout->addWidget(label_puntos, 0, 1);

    // CheckBox para el modo Lineas
    QCheckBox *cb_lineas = new QCheckBox;
    QLabel *label_lineas = new QLabel(modo_lineas);
    modos_layout->addWidget(cb_lineas, 1, 0);
    modos_layout->addWidget(label_lineas, 1, 1);

    /* En la practica 4 se controla mediante el rendering
    // CheckBox para el modo Relleno
    QCheckBox *cb_relleno = new QCheckBox;
    QLabel *label_relleno = new QLabel(modo_relleno);
    modos_layout->addWidget(cb_relleno, 2, 0);
    modos_layout->addWidget(label_relleno, 2, 1);


    // CheckBox para el modo Ajedrez
    QCheckBox *cb_ajedrez = new QCheckBox;
    QLabel *label_ajedrez = new QLabel(modo_ajedrez);
    modos_layout->addWidget(cb_ajedrez, 3, 0);
    modos_layout->addWidget(label_ajedrez, 3, 1);
    */

    QGroupBox *widget_modos = new QGroupBox(gbox_modo);
    widget_modos->setLayout(modos_layout);
    vbox_modos->addWidget(widget_modos);

    // ##################################################################################
    // FREEDOM
    // Grado de Libertad 1
    QGroupBox *widget_degree1 = new QGroupBox(gbox_degree1);
    QGridLayout *degree1_layout = new QGridLayout;

    QPushButton *increase1 = new QPushButton(increase_char, this);
    degree1_layout->addWidget(increase1, 0, 0);
    QPushButton *decrease1 = new QPushButton(decrease_char, this);
    degree1_layout->addWidget(decrease1, 0, 1);

    widget_degree1->setLayout(degree1_layout);
    vbox_modos->addWidget(widget_degree1);

    QGroupBox *widget_rate1 = new QGroupBox(gbox_rate1);
    QGridLayout *rate1_layout = new QGridLayout;

    QPushButton *increase_r1 = new QPushButton(increase_char, this);
    rate1_layout->addWidget(increase_r1, 0, 0);
    QPushButton *decrease_r1 = new QPushButton(decrease_char, this);
    rate1_layout->addWidget(decrease_r1, 0, 1);

    widget_rate1->setLayout(rate1_layout);
    vbox_modos->addWidget(widget_rate1);

    // Grado de Libertad 2
    QGroupBox *widget_degree2 = new QGroupBox(gbox_degree2);
    QGridLayout *degree2_layout = new QGridLayout;

    QPushButton *increase2 = new QPushButton(increase_char, this);
    degree2_layout->addWidget(increase2, 0, 0);
    QPushButton *decrease2 = new QPushButton(decrease_char, this);
    degree2_layout->addWidget(decrease2, 0, 1);

    widget_degree2->setLayout(degree2_layout);
    vbox_modos->addWidget(widget_degree2);

    QGroupBox *widget_rate2 = new QGroupBox(gbox_rate2);
    QGridLayout *rate2_layout = new QGridLayout;

    QPushButton *increase_r2 = new QPushButton(increase_char, this);
    rate2_layout->addWidget(increase_r2, 0, 0);
    QPushButton *decrease_r2 = new QPushButton(decrease_char, this);
    rate2_layout->addWidget(decrease_r2, 0, 1);

    widget_rate2->setLayout(rate2_layout);
    vbox_modos->addWidget(widget_rate2);

    // Grado de Libertad 3
    QGroupBox *widget_degree3 = new QGroupBox(gbox_degree1);
    QGridLayout *degree3_layout = new QGridLayout;

    QPushButton *increase3 = new QPushButton(increase_char, this);
    degree3_layout->addWidget(increase3, 0, 0);
    QPushButton *decrease3 = new QPushButton(decrease_char, this);
    degree3_layout->addWidget(decrease3, 0, 1);

    widget_degree3->setLayout(degree3_layout);
    vbox_modos->addWidget(widget_degree3);

    QGroupBox *widget_rate3 = new QGroupBox(gbox_rate3);
    QGridLayout *rate3_layout = new QGridLayout;

    QPushButton *increase_r3 = new QPushButton(increase_char, this);
    rate3_layout->addWidget(increase_r3, 0, 0);
    QPushButton *decrease_r3 = new QPushButton(decrease_char, this);
    rate3_layout->addWidget(decrease_r3, 0, 1);

    widget_rate3->setLayout(rate3_layout);
    vbox_modos->addWidget(widget_rate3);

    // ##################################################################################
    // BOTON DE LA ANIMACION
    QPushButton *bt_animacion = new QPushButton(tx_animacion, this);
    vbox_modos->addWidget(bt_animacion);

    // ##################################################################################
    // RADIO GROUP PARA CAMARA
    QGroupBox *widget_camera = new QGroupBox(gbox_camara);
    QGridLayout *camera_layout = new QGridLayout;

    // Perspective
    QRadioButton *rb_perspective = new QRadioButton;
    QLabel *label_perspective = new QLabel(camara_perspective);
    camera_layout->addWidget(rb_perspective, 0, 0); //Se añaden pensando en que es un 1x2 el Widget
    camera_layout->addWidget(label_perspective, 0, 1);

    QRadioButton *rb_parallel = new QRadioButton;
    QLabel *label_parallel = new QLabel(camara_parallel);
    camera_layout->addWidget(rb_parallel, 1, 0); //Se añaden pensando en que es un 1x2 el Widget
    camera_layout->addWidget(label_parallel, 1, 1);

    widget_camera->setLayout(camera_layout);
    vbox_modos->addWidget(widget_camera);

    // ##################################################################################
    // LUCES
    QGridLayout *luces_layout = new QGridLayout;

    // SE AÑADEN LOS COMPONENTES AL COMBOBOX MODO
    // CheckBox para First Light
    QCheckBox *cb_light1 = new QCheckBox;
    QLabel *label_light1 = new QLabel(first_light);
    luces_layout->addWidget(cb_light1, 0, 0); //Se añaden pensando en que es un 1x2 el Widget
    luces_layout->addWidget(label_light1, 0, 1);

    // CheckBox para Second Lgiht
    QCheckBox *cb_light2 = new QCheckBox;
    QLabel *label_light2 = new QLabel(second_light);
    luces_layout->addWidget(cb_light2, 1, 0);
    luces_layout->addWidget(label_light2, 1, 1);

    QGroupBox *widget_luces = new QGroupBox(gbox_luz);
    widget_luces->setLayout(luces_layout);
    vbox_modos->addWidget(widget_luces);

    // ##################################################################################
    // ##################################################################################
    //OBJETOS que se pueden dibujar
    QVBoxLayout *vbox_objetos = new QVBoxLayout;
    QGridLayout *objetos_layout = new QGridLayout;
    objetos_widget->setLayout(vbox_objetos);

    QRadioButton *rb_tetrahedron = new QRadioButton;
    QLabel *label_tetrahedron = new QLabel(obj_tetraedro);
    objetos_layout->addWidget(rb_tetrahedron, 0, 0);
    objetos_layout->addWidget(label_tetrahedron, 0, 1);

    QRadioButton *rb_cubo = new QRadioButton;
    QLabel *label_cubo = new QLabel(obj_cubo);
    objetos_layout->addWidget(rb_cubo, 1, 0);
    objetos_layout->addWidget(label_cubo, 1, 1);

    QRadioButton *rb_cono = new QRadioButton;
    QLabel *label_cono = new QLabel(obj_cono);
    objetos_layout->addWidget(rb_cono, 2, 0);
    objetos_layout->addWidget(label_cono, 2, 1);

    QRadioButton *rb_cilindro = new QRadioButton;
    QLabel *label_cilindro = new QLabel(obj_cilindro);
    objetos_layout->addWidget(rb_cilindro, 3, 0);
    objetos_layout->addWidget(label_cilindro, 3, 1);

    QRadioButton *rb_esfera = new QRadioButton;
    QLabel *label_esfera = new QLabel(obj_esfera);
    objetos_layout->addWidget(rb_esfera, 4, 0);
    objetos_layout->addWidget(label_esfera, 4, 1);

    QRadioButton *rb_ply = new QRadioButton;
    QLabel *label_ply = new QLabel(obj_ply);
    objetos_layout->addWidget(rb_ply, 5, 0);
    objetos_layout->addWidget(label_ply, 5, 1);

    QRadioButton *rb_jerarquico = new QRadioButton;
    QLabel *label_jerarquico = new QLabel(obj_jerarquico);
    objetos_layout->addWidget(rb_jerarquico, 6, 0);
    objetos_layout->addWidget(label_jerarquico, 6, 1);

    QRadioButton *rb_dashboard = new QRadioButton;
    QLabel *label_dashboard = new QLabel(obj_dashboard);
    objetos_layout->addWidget(rb_dashboard, 7, 0);
    objetos_layout->addWidget(label_dashboard, 7, 1);

    QGroupBox *widget_objetos = new QGroupBox(gbox_modo);
    widget_objetos->setLayout(objetos_layout);
    vbox_objetos->addWidget(widget_objetos);

    // ##################################################################################
    // ##################################################################################
    // RENDER E ILUMINACION
    QVBoxLayout *vbox_render = new QVBoxLayout;
    textura_widget->setLayout(vbox_render);

    QGroupBox *group_render = new QGroupBox(gbox_render);
    QGridLayout *grid_render = new QGridLayout;

    // Solid
    QRadioButton *rb_no_mode = new QRadioButton;
    QLabel *label_no_mode = new QLabel(no_mode);
    grid_render->addWidget(rb_no_mode, 0, 0);
    grid_render->addWidget(label_no_mode, 0, 1);

    // Solid
    QRadioButton *rb_solid = new QRadioButton;
    QLabel *label_solid = new QLabel(mode_solid);
    grid_render->addWidget(rb_solid, 1, 0);
    grid_render->addWidget(label_solid, 1, 1);

    // Chess
    QRadioButton *rb_chess = new QRadioButton;
    QLabel *label_chess = new QLabel(mode_chess);
    grid_render->addWidget(rb_chess, 2, 0);
    grid_render->addWidget(label_chess, 2, 1);

    // Flat Shaded Lighting
    QRadioButton *rb_flat_shaded_lighting = new QRadioButton;
    QLabel *label_flat_shaded_lighting = new QLabel(mode_flat_shaded_lighting);
    grid_render->addWidget(rb_flat_shaded_lighting, 3, 0);
    grid_render->addWidget(label_flat_shaded_lighting, 3, 1);

    // rb_gouraud_shaded_lighting
    QRadioButton *rb_gouraud_shaded_lighting = new QRadioButton;
    QLabel *label_gouraud_shaded_lighting = new QLabel(mode_gouraud_shaded_lighting);
    grid_render->addWidget(rb_gouraud_shaded_lighting, 4, 0);
    grid_render->addWidget(label_gouraud_shaded_lighting, 4, 1);

    // unlit_texture
    QRadioButton *rb_unlit_texture = new QRadioButton;
    QLabel *label_unlit_texture = new QLabel(mode_unlit_texture);
    grid_render->addWidget(rb_unlit_texture, 5, 0);
    grid_render->addWidget(label_unlit_texture, 5, 1);

    // texture_flat_shaded_lighting
    QRadioButton *rb_texture_flat_shaded_lighting = new QRadioButton;
    QLabel *label_texture_flat_shaded_lighting = new QLabel(mode_texture_flat_shaded_lighting);
    grid_render->addWidget(rb_texture_flat_shaded_lighting, 6, 0);
    grid_render->addWidget(label_texture_flat_shaded_lighting, 6, 1);

    // gouraud_shaded_lighting_texture
    QRadioButton *rb_gouraud_shaded_lighting_texture = new QRadioButton;
    QLabel *label_gouraud_shaded_lighting_texture = new QLabel(mode_gouraud_shaded_lighting_texture);
    grid_render->addWidget(rb_gouraud_shaded_lighting_texture, 7, 0);
    grid_render->addWidget(label_gouraud_shaded_lighting_texture, 7, 1);

    group_render->setLayout(grid_render);
    vbox_render->addWidget(group_render);

    // ##################################################################################
    // RADIO GROUP PARA MATERIALES
    QGroupBox *widget_materials = new QGroupBox(gbox_materiales);
    QGridLayout *materials_layout = new QGridLayout;

    QRadioButton *rb_obsidian = new QRadioButton;
    QLabel *label_obsidian = new QLabel(material_obsidian);
    materials_layout->addWidget(rb_obsidian, 0, 0); //Se añaden pensando en que es un 1x2 el Widget
    materials_layout->addWidget(label_obsidian, 0, 1);

    QRadioButton *rb_turquoise = new QRadioButton;
    QLabel *label_turquoise = new QLabel(material_turquoise);
    materials_layout->addWidget(rb_turquoise, 1, 0); //Se añaden pensando en que es un 1x2 el Widget
    materials_layout->addWidget(label_turquoise, 1, 1);

    QRadioButton *rb_redRubber = new QRadioButton;
    QLabel *label_redRubber = new QLabel(material_redRubber);
    materials_layout->addWidget(rb_redRubber, 2, 0); //Se añaden pensando en que es un 1x2 el Widget
    materials_layout->addWidget(label_redRubber, 2, 1);

    widget_materials->setLayout(materials_layout);
    vbox_render->addWidget(widget_materials);

    // ##################################################################################
    // BOTON PARA ALTERNAR EL MATERIAL
    QPushButton *bt_material = new QPushButton(tx_materiales, this);
    vbox_render->addWidget(bt_material);

    // ##################################################################################
    // ##################################################################################
    // CONEXIONES

    rb_tetrahedron->setChecked(true);
    cb_lineas->setCheckState(Qt::Checked); //Por defecto pulsado
    cb_light1->setCheckState(Qt::Checked);
    rb_perspective->setChecked(true);
    rb_no_mode->setChecked(true);
    rb_obsidian->setChecked(true);

    //Conecta una señal con una funcion, es necesario crear slots en la clase receptora
    //connect(EMISOR, SEÑAL, RECEPTOR, SLOT(esto es, la funcion que se ejecuta del receptor))
    connect(cb_puntos,
            SIGNAL(stateChanged(int)),
            GL_widget, //La clase que ejecutará la función cuando se pulse, se indica el objeto
            SLOT(modoPuntos(int)));

    connect(cb_lineas,
            SIGNAL(stateChanged(int)),
            GL_widget,
            SLOT(modoLineas(int)));

    /*
    connect(cb_relleno,
            SIGNAL(stateChanged(int)),
            GL_widget,
            SLOT(modoRelleno(int)));


    connect(cb_ajedrez,
            SIGNAL(stateChanged(int)),
            GL_widget,
            SLOT(modoAjedrez(int)));
    */

    // CONEXION CON LOS DIFERENTES OBJETOS DIBUJABLES
    connect(rb_tetrahedron,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_tetrahedron()));

    connect(rb_cubo,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_cube()));

    connect(rb_cono,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_cone()));

    connect(rb_cilindro,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_cylinder()));

    connect(rb_esfera,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_sphere()));

    connect(rb_ply,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_ply()));

    connect(rb_jerarquico,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_hierarchical()));

    connect(rb_dashboard,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obj_dashboard()));

    // CONEXION CON LOS MOVIMIENTOS DEL OBJETO JERARQUICO

    // GRADO 1
    connect(increase1,
            SIGNAL(released()),
            GL_widget,
            SLOT(First_Increase()));

    connect(decrease1,
            SIGNAL(released()),
            GL_widget,
            SLOT(First_Decrease()));

    connect(increase_r1,
            SIGNAL(released()),
            GL_widget,
            SLOT(First_Rate_Increase()));

    connect(decrease_r1,
            SIGNAL(released()),
            GL_widget,
            SLOT(First_Rate_Decrease()));

    // GRADO 2
    connect(increase2,
            SIGNAL(released()),
            GL_widget,
            SLOT(Second_Increase()));

    connect(decrease2,
            SIGNAL(released()),
            GL_widget,
            SLOT(Second_Decrease()));

    connect(increase_r2,
            SIGNAL(released()),
            GL_widget,
            SLOT(Second_Rate_Increase()));

    connect(decrease_r2,
            SIGNAL(released()),
            GL_widget,
            SLOT(Second_Rate_Decrease()));

    // GRADO 3
    connect(increase3,
            SIGNAL(released()),
            GL_widget,
            SLOT(Third_Increase()));

    connect(decrease3,
            SIGNAL(released()),
            GL_widget,
            SLOT(Third_Decrease()));

    connect(increase_r3,
            SIGNAL(released()),
            GL_widget,
            SLOT(Third_Rate_Increase()));

    connect(decrease_r3,
            SIGNAL(released()),
            GL_widget,
            SLOT(Third_Rate_Decrease()));

    // ANIMACION DIGIDEL
    connect(bt_animacion,
            SIGNAL(released()),
            GL_widget,
            SLOT(AnimarDigidel()));

    // CAMARA
    connect(rb_perspective,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(ChangePerspective()));

    connect(rb_parallel,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(ChangeParallel()));

    // LUCES
    connect(cb_light1,
            SIGNAL(stateChanged(int)),
            GL_widget,
            SLOT(modoLight1(int)));

    connect(cb_light2,
            SIGNAL(stateChanged(int)),
            GL_widget,
            SLOT(modoLight2(int)));

    // RENDER E ILUMINACION
    connect(rb_no_mode,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(no_mode()));

    connect(rb_solid,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(mode_solid()));

    connect(rb_chess,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(mode_chess()));

    connect(rb_flat_shaded_lighting,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(mode_flat_shaded_lighting()));

    connect(rb_gouraud_shaded_lighting,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(mode_gouraud_shaded_lighting()));

    connect(rb_unlit_texture,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(mode_unlit_texture()));

    connect(rb_texture_flat_shaded_lighting,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(mode_texture_flat_shaded_lighting()));

    connect(rb_gouraud_shaded_lighting_texture,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(mode_gouraud_shaded_lighting_texture()));

    // MATERIALES
    connect(rb_obsidian,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(obsidian()));

    connect(rb_turquoise,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(turquoise()));

    connect(rb_redRubber,
            SIGNAL(clicked()),
            GL_widget,
            SLOT(redRubber()));

    connect(bt_material,
            SIGNAL(released()),
            GL_widget,
            SLOT(AlternarMaterial()));

    // ##################################################################################
    // ##################################################################################
    // ACCIONES
    QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
    Exit->setShortcut(tr("Ctrl+Q"));
    Exit->setToolTip(tr("Exit the application"));
    connect(Exit, SIGNAL(triggered()), this, SLOT(close()));
}
