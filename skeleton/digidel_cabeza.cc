/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "digidel_cabeza.h"

_digidel_cabeza::_digidel_cabeza() {

    cara = _sphere();
    oreja_izq = _cone();
    oreja_der = _cone();
    oreja_trasera = _cone();

}

void _digidel_cabeza::draw_point(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(-60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.40f);
    glRotatef(92, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_point();
    glPopMatrix();
}

void _digidel_cabeza::draw_line(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(-60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.40f);
    glRotatef(92, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_line();
    glPopMatrix();

}

void _digidel_cabeza::draw_fill(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(300, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.35f);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_fill();
    glPopMatrix();
}

void _digidel_cabeza::draw_chess(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(300, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.35f);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_chess();
    glPopMatrix();
}

// Textura e Iluminacion
void _digidel_cabeza::draw_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(300, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.35f);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_flat_shaded_lighting();
    glPopMatrix();
}
void _digidel_cabeza::draw_gouraud_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(300, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.35f);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_gouraud_shaded_lighting();
    glPopMatrix();
}
void _digidel_cabeza::draw_unlit_texture(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(300, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.35f);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_unlit_texture();
    glPopMatrix();
}
void _digidel_cabeza::draw_texture_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(300, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.35f);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_texture_flat_shaded_lighting();
    glPopMatrix();
}
void _digidel_cabeza::draw_gouraud_shaded_lighting_texture(){

    glMatrixMode(GL_MODELVIEW);
    //Cara
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.6f, 0.6f, 0.6f);
    cara.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Izquierda
    glPushMatrix();
    glTranslatef(-0.4f, 0.2f, 0.0f);
    glRotatef(60, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_izq.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Derecha
    glPushMatrix();
    glTranslatef(0.4f, 0.2f, 0.0f);
    glRotatef(300, 0, 0, 1);
    glScalef(0.3f, 0.4f, 0.3f);
    oreja_der.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Oreja Trasera
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.35f);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2f, 0.4f, 0.2f);
    oreja_trasera.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();
}

