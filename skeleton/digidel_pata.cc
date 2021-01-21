/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "digidel_pata.h"

_digidel_pata::_digidel_pata() {

    pata = _cylinder();
    rodilla = _sphere();
    garra = _cone();
}

void _digidel_pata::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_point();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_point();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_point();
    glPopMatrix();
}

void _digidel_pata::draw_line(){

    glMatrixMode(GL_MODELVIEW); //Para que se vea
    /*
        Estructura del objeto jerarquico
        Para cada parte del cuerpo:
            glPushMatrix();
                Movimientos de posición
                Objeto.draw_X()
            glPopMatrix();

        Los movimientos de posición son (MUY IMPORTANTE EL ORDEN):
            glTranslatef(X, Y, Z) --> Se suma a todas las coordenadas
                Transladar un objeto de la coordenada inicial sumando el valor indicado a esta coordenada
            glRotatef(ANGULO, X, Y, Z) --> Se rota al eje deseado el ángulo indicado
                Si se pone glRotate(90, 1, 0, 0) --> Se rota 90º el eje X
            glScalef(X, Y, Z) --> Agrandar o hacer pequeño el objeto (Más pequeño el valor, más pequeño el objeto)
                NUNCA PONER 0.0 O DE LO CONTRARIO EL OBJETO DESAPARECE
    */
    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_line();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_line();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_line();
    glPopMatrix();

}

void _digidel_pata::draw_fill(){

    glMatrixMode(GL_MODELVIEW);

    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_fill();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_fill();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_fill();
    glPopMatrix();
}

void _digidel_pata::draw_chess(){

    glMatrixMode(GL_MODELVIEW);

    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_chess();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_chess();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_chess();
    glPopMatrix();
}

// Textura e Iluminacion
void _digidel_pata::draw_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glScalef(1.0f, 1.0f, 1.0f);

        //Pata
        glPushMatrix();
        glTranslatef(0.0f, 0.4f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.15f, 0.4f, 0.15f);
        pata.draw_flat_shaded_lighting();
        glPopMatrix();

        //Rodilla
        glPushMatrix();
        glTranslatef(0.0f, 0.2f, 0.0f);
        glRotatef(0, 0, 0, 0);
        glScalef(0.2f, 0.2f, 0.2f);
        rodilla.draw_flat_shaded_lighting();
        glPopMatrix();

        //Garra
        glPushMatrix();
        glTranslatef(0.0f, -0.05f, 0.0f);
        glRotatef(180, 1, 0, 0);
        glScalef(0.15f, 0.4f, 0.15f);
        garra.draw_flat_shaded_lighting();
        glPopMatrix();

    glPopMatrix();
}

void _digidel_pata::draw_gouraud_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_gouraud_shaded_lighting();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_gouraud_shaded_lighting();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_gouraud_shaded_lighting();
    glPopMatrix();
}
void _digidel_pata::draw_unlit_texture(){

    glMatrixMode(GL_MODELVIEW);

    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_unlit_texture();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_unlit_texture();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_unlit_texture();
    glPopMatrix();
}
void _digidel_pata::draw_texture_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_texture_flat_shaded_lighting();
    glPopMatrix();
}
void _digidel_pata::draw_gouraud_shaded_lighting_texture(){

    glMatrixMode(GL_MODELVIEW);

    //Pata
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    pata.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    //Rodilla
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    rodilla.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    //Garra
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    glRotatef(180, 1, 0, 0);
    glScalef(0.15f, 0.4f, 0.15f);
    garra.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();
}
