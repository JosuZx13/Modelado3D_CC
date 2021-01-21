/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "dashboard.h"

_dashboard::_dashboard(float Size,unsigned int Divisions1) {// rows x cols board; nxn board;
    unsigned int rows=sqrt(Divisions1), cols=rows, triangles=0, k=0;
    float row, tex_size=1.0, tex_row;

    Vertices.resize(4*Divisions1);
    Triangles.resize(2*Divisions1);
    Texture_Coordinates.resize(4*Divisions1);

    for(unsigned int i=0; i < rows; i++)
    {
        row = Size/2-i*Size/cols;
        tex_row = tex_size-i*tex_size/cols;
        for(unsigned int j=0; j < cols; j++)
        {
            Texture_Coordinates[k] = _vertex2f(j*tex_size/cols,tex_row);
            Vertices[k]=_vertex3f(j*Size/cols - Size/2, row,0.0);

            Texture_Coordinates[k+1] = _vertex2f(Texture_Coordinates[k].x + tex_size/cols,tex_row);
            Vertices[k+1]=_vertex3f(Vertices[k].x + Size/cols, Vertices[k].y, 0.0);

            Texture_Coordinates[k+2] = _vertex2f(Texture_Coordinates[k+1].x,tex_row - tex_size/cols);
            Vertices[k+2]=_vertex3f(Vertices[k+1].x, Vertices[k].y - Size/cols, 0.0);

            Texture_Coordinates[k+3] = _vertex2f(Texture_Coordinates[k].x, Texture_Coordinates[k+2].y);
            Vertices[k+3]=_vertex3f(Vertices[k].x, Vertices[k+2].y, 0.0);


            Triangles[triangles] = _vertex3ui(k,k+3,k+2);
            Triangles[triangles+1] = _vertex3ui(k,k+2,k+1);
            k+=4;
            triangles += 2;
        }
    }

}

void _dashboard::draw_unlit_texture() {
    glEnable(GL_TEXTURE_2D);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        glTexCoord2f(Texture_Coordinates[Triangles[i]._0].x, Texture_Coordinates[Triangles[i]._0].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2f(Texture_Coordinates[Triangles[i]._1].x, Texture_Coordinates[Triangles[i]._1].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2f(Texture_Coordinates[Triangles[i]._2].x, Texture_Coordinates[Triangles[i]._2].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void _dashboard::draw_texture_flat_shaded_lighting(){
    glEnable(GL_TEXTURE_2D);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        glTexCoord2f(Texture_Coordinates[Triangles[i]._0].x, Texture_Coordinates[Triangles[i]._0].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2f(Texture_Coordinates[Triangles[i]._1].x, Texture_Coordinates[Triangles[i]._1].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2f(Texture_Coordinates[Triangles[i]._2].x, Texture_Coordinates[Triangles[i]._2].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void _dashboard::draw_gouraud_shaded_lighting_texture(){
    glEnable(GL_TEXTURE_2D);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        glTexCoord2f(Texture_Coordinates[Triangles[i]._0].x, Texture_Coordinates[Triangles[i]._0].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2f(Texture_Coordinates[Triangles[i]._1].x, Texture_Coordinates[Triangles[i]._1].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2f(Texture_Coordinates[Triangles[i]._2].x, Texture_Coordinates[Triangles[i]._2].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
