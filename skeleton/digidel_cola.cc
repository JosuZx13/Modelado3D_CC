/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "digidel_cola.h"

_digidel_cola::_digidel_cola() {

    cuerpo = _cylinder();
    corona = _digidel_crown();

    angulo = 0;
    speed = 2;
    rate_speed = 1; //Sube en una unidad (1) el valor en 5 movimientos
}

void _digidel_cola::first_cascabeles(bool degree){
    corona.first_cascabeles(degree);

}

void _digidel_cola::second_corona(bool degree){
    corona.second_corona(degree);
}

void _digidel_cola::third_cola(bool degree){

    if(degree){
        if(angulo < 10){
            angulo += speed;
            corona.second_corona(degree);
        }
    }else{

        if(angulo > 0){
            angulo -= speed;
            corona.second_corona(degree);
        }
    }
}

void _digidel_cola::first_rate(bool rate){
    corona.first_rate(rate);
}

void _digidel_cola::second_rate(bool rate){
    corona.second_rate(rate);
}

void _digidel_cola::third_rate(bool rate){

    if(rate){
        if(speed < 4){
            speed += rate_speed;
            corona.third_rate(rate);
        }

    }else{
        if(speed > 2){
            speed -= rate_speed;
            corona.third_rate(rate);
        }
    }
}

void _digidel_cola::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_point();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_point();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}

void _digidel_cola::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_line();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_line();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}

void _digidel_cola::draw_fill(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_fill();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_fill();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}

void _digidel_cola::draw_chess(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_chess();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_chess();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();

}

// Textura e Iluminacion
void _digidel_cola::draw_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_flat_shaded_lighting();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_flat_shaded_lighting();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}
void _digidel_cola::draw_gouraud_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_gouraud_shaded_lighting();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_gouraud_shaded_lighting();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}
void _digidel_cola::draw_unlit_texture(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_unlit_texture();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_unlit_texture();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}
void _digidel_cola::draw_texture_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_texture_flat_shaded_lighting();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_texture_flat_shaded_lighting();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}
void _digidel_cola::draw_gouraud_shaded_lighting_texture(){

    glMatrixMode(GL_MODELVIEW);

    // COLA COMPLETA

    glPushMatrix();

    glTranslatef(0, 0, 0);
    glRotatef(angulo, 0, 0, 1);
    glScalef(1.0f, 1.0f, 1.0f);

        // Cuerpo de la Cola
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(-60, 0, 0, 1);
        glScalef(0.15f, 0.4f, 0.15f);
        cuerpo.draw_gouraud_shaded_lighting_texture();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0,0,0);
        glRotatef(-angulo, 1, 0, 0);
        glScalef(1.0f, 1.0f, 1.0f);

            // Corona
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            glRotatef(0, 0, 0, 0);
            glScalef(1.0f, 1.0f, 1.0f);
            corona.draw_gouraud_shaded_lighting_texture();
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}
