/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "digidel_crown.h"

_digidel_crown::_digidel_crown() {

    cola1 = _cone();
    punta1 = _sphere();
    cola2 = _cone();
    punta2 = _sphere();
    cola3 = _cone();
    punta3 = _sphere();

    // First
    altura = 0.16f;
    speed_altura_first = 0.02f;
    rate_altura = 0.01f;

    // Second
    angulo = 60;
    speed_angulo = 2;
    rate_angulo = 1;
    speed_altura_second = 0.015f;
}

void _digidel_crown::first_cascabeles(bool degree){

    if(degree){
        if(altura < 0.26f){
            altura += speed_altura_first;
        }
    }else{
        if(altura > 0.16f){
            altura -= speed_altura_first;
        }
    }
}

void _digidel_crown::second_corona(bool degree){
    if(degree){
        if(angulo > 50){
            angulo -= speed_angulo;
            if(altura < 0.26f){
                altura += speed_altura_second;
            }
        }

    }else{
        if(angulo < 60){
            angulo += speed_angulo;
            if(altura > 0.16f){
                altura -= speed_altura_second;
            }
        }
    }
}

void _digidel_crown::first_rate(bool rate){

    if(rate){
        if(speed_altura_first < 0.04f){
            speed_altura_first += rate_altura;
        }
    }else{

        if(speed_altura_first > 0.02f){
            speed_altura_first -= rate_altura;
        }
    }
}

void _digidel_crown::second_rate(bool rate){

    if(rate){
        if(speed_angulo < 4){
            speed_angulo += rate_angulo;
            speed_altura_second += rate_altura;
        }
    }else{
        if(speed_angulo > 2){
            speed_angulo -= rate_angulo;
            speed_altura_second -= rate_altura;
        }
    }

}

void _digidel_crown::third_rate(bool rate){
    second_rate(rate);
}


void _digidel_crown::draw_point(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_point();
    glPopMatrix();
}

void _digidel_crown::draw_line(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_line();
    glPopMatrix();


}

void _digidel_crown::draw_fill(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_fill();
    glPopMatrix();
}

void _digidel_crown::draw_chess(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_chess();
    glPopMatrix();
}

// Textura e Iluminacion
void _digidel_crown::draw_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_flat_shaded_lighting();
    glPopMatrix();
}

void _digidel_crown::draw_gouraud_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_gouraud_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_gouraud_shaded_lighting();
    glPopMatrix();
}
void _digidel_crown::draw_unlit_texture(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_unlit_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_unlit_texture();
    glPopMatrix();
}
void _digidel_crown::draw_texture_flat_shaded_lighting(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_texture_flat_shaded_lighting();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_texture_flat_shaded_lighting();
    glPopMatrix();
}
void _digidel_crown::draw_gouraud_shaded_lighting_texture(){

    glMatrixMode(GL_MODELVIEW);
    //Primera Cola
    glPushMatrix();
    glTranslatef(-0.25f, 0.03f, 0.0f);
    glRotatef(angulo, 0, 0, 1);
    glScalef(0.12f, 0.4f, 0.12f);
    cola1.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Primera Punta
    glPushMatrix();
    glTranslatef(-0.45f, altura, 0.0f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta1.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, 0.15f);
    glRotatef(angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola2.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Segunda Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, 0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta2.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Cola
    glPushMatrix();
    glTranslatef(-0.10f, 0.032f, -0.15f);
    glRotatef(-angulo, 1, 0, 0);
    glScalef(0.10f, 0.4f, 0.10f);
    cola3.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    //Tercera Punta
    glPushMatrix();
    glTranslatef(-0.10f, altura, -0.36f);
    glRotatef(0, 0, 0, 0);
    glScalef(0.1f, 0.1f, 0.1f);
    punta3.draw_gouraud_shaded_lighting_texture();
    glPopMatrix();
}
