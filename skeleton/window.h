/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGuiApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>
#include <QCheckBox>
#include <QLabel>
#include <QTimer>
#include <QComboBox>
#include <QGroupBox>

#include "glwidget.h"

class _gl_widget;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _window : public QMainWindow {
    Q_OBJECT

public:
    _window();

private:
    //Tamaño de la ventana inicial
    const int w_window = 1000;
    const int h_window = 800;

    //Tamaño de la ventana de las opciones
    const int w_opciones = 215;
    const int h_opciones = 800;

    //Pestañas a la derecha
    const char* pest_modo = "Modo";
    const char* pest_objeto = "Objeto";
    const char* pest_textura = "Textura";

    // MODOS disponibles para dibujar la figura
    const char* gbox_modo = "Modo";
    const char* modo_puntos = "Puntos";
    const char* modo_lineas = "Lineas";
    const char* modo_relleno = "Relleno";
    //const char* modo_ajedrez = "Ajedrez";

    // OBJETOS que es posible dibujar
    const char* obj_tetraedro = "TETRAEDRO";
    const char* obj_cubo = "CUBO";
    const char* obj_cono = "CONO";
    const char* obj_cilindro = "CILINDRO";
    const char* obj_esfera = "ESFERA";
    const char* obj_ply = "PLY";
    const char* obj_jerarquico = "JERARQUICO";
    const char* obj_dashboard = "DASHBOARD";

    // GRUPO DEGREE
    const char* gbox_degree1 = "First Degree";
    const char* gbox_degree2 = "Second Degree";
    const char* gbox_degree3 = "Third Degree";

    const char* gbox_rate1 = "First Rate Modification";
    const char* gbox_rate2 = "Second Rate Modification";
    const char* gbox_rate3 = "Third Rate Modification";

    const char* increase_char = "Increase";
    const char* decrease_char = "Decrease";

    // BOTON ANIMACION
    const char* tx_animacion = "Animacion";

    // GRUPO CAMERA
    const char* gbox_camara = "Camara";
    const char* camara_perspective = "Perspective";
    const char* camara_parallel = "Parallel";

    // GRUPO LUCES
    const char* gbox_luz = "Luces";
    const char* first_light = "First Light";
    const char* second_light = "Second Light";

    // MODOS DE RENDER E ILUMINACION que es posible dibujar
    const char* gbox_render = "Render e Iluminacion";
    const char* no_mode = "NO MODE";
    const char* mode_solid = "MODE SOLID";
    const char* mode_chess = "MODE SOLID CHESS";
    const char* mode_flat_shaded_lighting = "MODE FLAT SHADED\nLIGHTING";
    const char* mode_gouraud_shaded_lighting = "MODE GOURAUD\nSHADED LIGHTING";
    const char* mode_unlit_texture = "MODE UNLIT\nTEXTURE";
    const char* mode_texture_flat_shaded_lighting = "MODE_TEXTURE\nFLAT SHADED\nLIGHTING";
    const char* mode_gouraud_shaded_lighting_texture = "MODE GOURAUD\nSHADED LIGHTING\nTEXTURE";

    // MATERIALES ELEGIBLES
    const char* gbox_texturas = "Materiales";
    const char* textura_dia = "Dia";
    const char* textura_estrellas = "Estrellas";
    const char* textura_nubes = " Nubes";

    // MATERIALES ELEGIBLES
    const char* gbox_materiales = "Materiales";
    const char* material_obsidian = "Obsidian";
    const char* material_turquoise = "Turquoise";
    const char* material_redRubber = "Red Rubber";

    // BOTON ANIMACION
    const char* tx_materiales = "Alternar Material";

    _gl_widget *GL_widget;

};

#endif
