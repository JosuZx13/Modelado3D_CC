/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "object3d.h"
#include "cube.h"

class _dashboard:public _object3D {

public:
  _dashboard(float Size=1.0, unsigned int Divisions1=1);
  void draw_unlit_texture();
  void draw_texture_flat_shaded_lighting();
  void draw_gouraud_shaded_lighting_texture();

protected:
  unsigned int Divisions;
  vector<_vertex2f> Texture_Coordinates;
  _cube board;

};

#endif // DASHBOARD_H
