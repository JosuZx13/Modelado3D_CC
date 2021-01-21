/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "objhierar.h"

_objhierar::_objhierar() {

    pata1 = _digidel_pata();
    pata2 = _digidel_pata();
    pata3 = _digidel_pata();
    pata4 = _digidel_pata();

    cuerpo = _sphere();

    cola = _digidel_cola();
    cabeza = _digidel_cabeza();

}

// Se incluiran los métodos para el movimiento antes del dibujo, para comodidad
void _objhierar::first_cascabeles(bool degree){
    cola.first_cascabeles(degree);
}

void _objhierar::second_corona(bool degree){
    cola.second_corona(degree);
}

void _objhierar::third_cola(bool degree){
    cola.third_cola(degree);
}

// Modificaciones en ratio de incremento o decremento de un movimiento
void _objhierar::first_rate(bool rate){
    cola.first_rate(rate);
}

void _objhierar::second_rate(bool rate){
    cola.second_rate(rate);
}

void _objhierar::third_rate(bool rate){
    cola.third_rate(rate);
}

void _objhierar::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_point();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_point();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_point();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_point();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_point();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_point();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_point();
        glPopMatrix();

    glPopMatrix();
}


void _objhierar::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_line();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_line();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_line();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_line();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_line();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_line();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_line();
        glPopMatrix();

    glPopMatrix();
}

void _objhierar::draw_fill(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_fill();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_fill();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_fill();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_fill();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_fill();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_fill();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_fill();
        glPopMatrix();

    glPopMatrix();
}

void _objhierar::draw_chess(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_chess();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_chess();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_chess();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_chess();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_chess();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_chess();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_chess();
        glPopMatrix();

    glPopMatrix();
}

// Textura e Iluminacion
void _objhierar::draw_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_flat_shaded_lighting();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_flat_shaded_lighting();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_flat_shaded_lighting();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_flat_shaded_lighting();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_flat_shaded_lighting();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_flat_shaded_lighting();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_flat_shaded_lighting();
        glPopMatrix();

    glPopMatrix();
}
void _objhierar::draw_gouraud_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_gouraud_shaded_lighting();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_gouraud_shaded_lighting();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_gouraud_shaded_lighting();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_gouraud_shaded_lighting();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_gouraud_shaded_lighting();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_gouraud_shaded_lighting();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_gouraud_shaded_lighting();
        glPopMatrix();

    glPopMatrix();
}
void _objhierar::draw_unlit_texture(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_unlit_texture();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_unlit_texture();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_unlit_texture();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_unlit_texture();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_unlit_texture();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_unlit_texture();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_unlit_texture();
        glPopMatrix();

    glPopMatrix();
}
void _objhierar::draw_texture_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_texture_flat_shaded_lighting();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_texture_flat_shaded_lighting();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_texture_flat_shaded_lighting();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_texture_flat_shaded_lighting();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_texture_flat_shaded_lighting();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_texture_flat_shaded_lighting();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_texture_flat_shaded_lighting();
        glPopMatrix();

    glPopMatrix();
}
void _objhierar::draw_gouraud_shaded_lighting_texture(){

    glMatrixMode(GL_MODELVIEW);

    // DIGIDEL
    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        // CUERPO
        glPushMatrix();
        glTranslatef(0.0f, 0.25f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.85f, 0.80f, 0.78f);
        cuerpo.draw_gouraud_shaded_lighting_texture();
        glPopMatrix();
        //######################################################

        // COLOCACION DE LAS PATAS
        glPushMatrix();

        glTranslatef(0, 0, 0);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // PATA DELANTERA DERECHA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata1.draw_gouraud_shaded_lighting_texture();
            glPopMatrix();

            // PATA DELANTERA IZQUIERDA
            glPushMatrix();
            glTranslatef(0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata2.draw_gouraud_shaded_lighting_texture();
            glPopMatrix();

            // PATA TRASERA DERECHA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, 0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata3.draw_gouraud_shaded_lighting_texture();
            glPopMatrix();

            // PATA TRASERA IZQUIERDA
            glPushMatrix();
            glTranslatef(-0.22f, -0.4f, -0.21f);
            glRotatef(0, 0, 0, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            pata4.draw_gouraud_shaded_lighting_texture();
            glPopMatrix();

        glPopMatrix();

        //######################################################

        // COLA
        glPushMatrix();
        glTranslatef(-0.50f, 0.0f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(1.0f, 1.0f, 1.00f);
        cola.draw_gouraud_shaded_lighting_texture();
        glPopMatrix();

        //######################################################

        // CABEZA
        glPushMatrix();
        glTranslatef(0.3f, 0.75f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.85f, 0.85f, 0.85f);
        cabeza.draw_gouraud_shaded_lighting_texture();
        glPopMatrix();

    glPopMatrix();
}
