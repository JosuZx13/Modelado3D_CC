/*! \file
 * Copyright Jose Manuel Osuna Luque
 * 2020
 */

#include "objrev.h"

//El perfil se va a rotar sobre el Eje Y (Coordenada Y no cambia)
_vertex3f _objrev::rotarY(_vertex3f v, double alpha){
    // x' = x * cos(alpha) + z * sin(alpha)
    // y' = y // Porque es sobre el Eje Y
    // z' = -x * sin(alpha) + z*cos(alpha)

    float x_prima = v.x * cos(alpha) + v.z * sin(alpha);
    float y_prima = v.y;
    float z_prima = ((-1)*v.x) * sin(alpha) + v.z*cos(alpha);

    return _vertex3f(x_prima, y_prima, z_prima);

}

//Metodo para revolucionar el objeto
// El número de cortes lo denota n, en otras palabras, es el número de rotaciones
void _objrev::revolucion(unsigned int n){

    double alphaOrigen = (2*M_PI)/n; //Esto irá cambiando el ángulo en la circunferencia del Eje respecto al punto
    unsigned int posV = 0;
    // Hay que recordar que se debe añadir un perfil fantasma de los primeros puntos al final por eso +Perfil.size()
    // Si hace 10 rotaciones, tendrá el Perfil, más las 10 rotaciones (11 columnas) + el Perfil fantasma
    Vertices.resize((Perfil.size()*(n))+Perfil.size());
    // Primero se añade el Perfil principal a los vertices
    for(unsigned int p=0; p<Perfil.size(); p++, posV++){
        Vertices[posV] = Perfil[p];
    }

    // Ahora se realiza la rotacion n veces

    unsigned int rotacion = 1; // Controla que ya se han rotado todos los puntos en ese angulo
    unsigned int ciclo = 0;
    double alpha = alphaOrigen;
    // Se multiplica por Perfil.size() porque son el número de puntos que hay que rotar (n-1 porque el primer perfil ya se tiene)
    for(unsigned int r=0; r<(n-1)*Perfil.size(); r++, posV++, ciclo++){
        if(ciclo == Perfil.size()){ //Indica un ciclo, hay que cambiar el angulo
            alpha = alphaOrigen*rotacion;
            rotacion++;
            ciclo = 0; //Coge los puntos del perfil unicamente
        }
        // Ese %Perfil.size() se hace para coger siempre los primeros perfiles, cuando vaya por el vertice 3 ([2]) cogerá de nuevo el Perfil[0]
        Vertices[posV] = rotarY(Perfil[ciclo], alpha);    //En la vuelta r=0, en el Vertice[2] se guarda el Vertice[0] rotado en alpha
        //Vertices.push_back(rotarY(Perfil[ciclo], alpha));                                                //En la vuelta r=2, en el vertice[4] se guarda el vertice[2] rotado en alpha
    }

    // Hay que añadir un perfil falso de los primeros puntos
    // Se reusa la variable posV que se ha quedado en Vertice[5] siendo el ultimo punto guardado, faltaría [6] y [7]
    for(unsigned int f=0; f<Perfil.size(); f++, posV++){
        Vertices[posV] = Perfil[f];

    }

}

void _objrev::creacionCuerpo(unsigned int n){
    // La creación de las caras se tiene que hacer de forma automática
    // Se construye un bucle anidado y se recorren los vértices en forma de matriz

    /*
    Hay que tener en cuenta que hay dos tipos de Triangulos, los que conforman
    caras IMPARES y las PARES
    */

    /*
        TRIANGULOS PARES
            a = col * Perfil.size() + fil
            b = a + Perfil.size()
            c = a + 1

        TRIANGULOS IMPARES
            v = v-1 + Perfil.size()
            t = v + 1
            s = c

            Donde v-1 es el anterior v calculado (es decir, a), es decir, b
            y c es el vertice c en los triángulos par, o sea

    */

    Triangles.resize(0); //Se resetean a 0

    unsigned int a, b, c, v, t, s = 0;

    for(unsigned int fil=0; fil<Perfil.size()-1; fil++){ //Le puse +1 porque de lo contrario se quedaba un perfil sin dibujar

        // Hay tantas columnas como el número de cortes
        for(unsigned int col=0; col<n; col++){

            // Formulacion para los triangulos pares
            a = col * Perfil.size() + fil;
            b = a + Perfil.size();
            c = (a + 1);

            Triangles.push_back(_vertex3ui(a, b, c)); // PARES

            // Formulacion para los triangulos impares
            v = b; //a + Perfil.size()
            t = (v + 1);
            s = c;

            Triangles.push_back(_vertex3ui(v, t, s)); // IMPARES

        }

    }

}

void _objrev::creacionBases(unsigned int n, bool inferior, bool superior){

    unsigned int posBase;
    unsigned int pInicial; // Punto por el que empieza el bucle de los Triangulos
    unsigned int pIntermedio;

    // Se hace un vector auxiliar para las bases. Explicación de esto
    /*
    Puede ser que el objeto tenga solo base superior o solo inferior, sin embargo si en el IF
    se controla de forma que si tiene inferior se coge el primer elemento de Bases, y para superior
    el segundo, ¿qué ocurriría si solo tuviese una Base Superior, Bases[1] no existiría y daría error

    Para controlar eso, se añade un vector auxiliar que guarda las bases y cuando se coja un elemento, se elimina
    De esta forma al llegar a superior, se coge igualmente el primero.

    Si ha entrado en el IF-INFERIOR se ha eliminado el primero
    y cogería Bases[0] que en realidad es el segundo vertice

    Si NO ha entrado en el IF-SUPERIOR, igualmente coge el Bases[0] y sería correcto

    */
    vector<_vertex3f> aux_Bases = Bases;

    //Se construyen las tapas desde abajo hacia arriba
    if(inferior){

        // Lo primero es añadir la Base al vector de vertices
        Vertices.push_back(aux_Bases[0]); // Se añade al final de la lista de vertices
        // Se elimina del auxiliar Bases
        aux_Bases.erase(aux_Bases.begin());
        // La posicion en el vector de dicho punto añadido es Vertices.size()-1
        // Pues si el vector tiene 30 elementos, van del 0 al 29
        posBase = Vertices.size()-1;
        // Las Base inferior se quiere añadir a los vértices inferiores
        // Si se tienen los vertices como en una matriz, eso son el 0, 0+Perfil.size() y así hasta el numero de cortes
        pInicial = 0;
        for(unsigned int c=0; c<n+1; c++){
            pIntermedio = pInicial+Perfil.size();
            Triangles.push_back(_vertex3ui(pInicial, pIntermedio, posBase));
            pInicial = pIntermedio;
        }
    }



    //Se construyen las tapas desde abajo hacia arriba
    if(superior){

        // Lo primero es añadir la Base al vector de vertices
        Vertices.push_back(aux_Bases[0]); // Se añade al final de la lista de vertices

        // La posicion en el vector de dicho punto añadido es Vertices.size()-1
        // Pues si el vector tiene 30 elementos, van del 0 al 29
        posBase = Vertices.size()-1;

        // Las Base superior se quiere añadir a los vértices superiores
        // Si se tienen los vertices como en una matriz, eso son el Perfil.size(), Perfil.size()+Perfil.size() y así hasta el numero de cortes
        pInicial = Perfil.size()-1; // Este es el último vertice del perfil (Si tiene 4, pues va de 0 a 3)
        for(unsigned int c=0; c<n; c++){
            pIntermedio = pInicial+Perfil.size();
            Triangles.push_back(_vertex3ui(pInicial, pIntermedio, posBase));
            pInicial = pIntermedio;
        }
    }

}
