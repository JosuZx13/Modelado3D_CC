HEADERS += \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  dashboard.h \
  digidel_cabeza.h \
  digidel_cola.h \
  digidel_crown.h \
  digidel_pata.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  objhierar.h \
  objply.h \
  objrev.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  dashboard.cc \
  digidel_cabeza.cc \
  digidel_cola.cc \
  digidel_crown.cc \
  digidel_pata.cc \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  objhierar.cc \
  objply.cc \
  objrev.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets

DISTFILES += \
    ply_models/airplane.ply \
    ply_models/ant.ply \
    ply_models/armadillo.ply \
    ply_models/beethoven.ply \
    ply_models/big_dodge.ply \
    ply_models/big_porsche.ply \
    ply_models/bunny.ply \
    ply_models/cow.ply \
    ply_models/footbones.ply \
    ply_models/happy.ply
