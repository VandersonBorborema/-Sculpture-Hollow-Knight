#include <iostream>
#include <cmath>
#include "sculptor.h"
#include "voxel.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    this -> nx = _nx;
    this -> ny = _ny;
    this -> nz = _nz;
    int i, j, k;
    r = g =b = a = 0.5;
    //alocação da matriz 3D
    v =  new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    for(i =1; i<nz; i++){
        v[i] = v[i-1]+ny;
    }
    for(i =1; i<nz*ny; i++){
        v[0][i] = v[0][i-1]+nx;
    }

    //inicializadores
    for(i =0; i<nx; i++){
        for(j =0; j<ny; j++){
            for(k =0; k<nz; k++){
               this -> v[i][j][k].r = this -> r;
               this -> v[i][j][k].g = this -> g;
               this -> v[i][j][k].b = this -> b;
               this -> v[i][j][k].a = this -> a;
               this -> v[i][j][k].show = false;
            }
        }
    }
}
//destrutor da classe
Sculptor::~Sculptor(){
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}
//insere cor aos voxels
void Sculptor::setColor(const float r, const float g, const float b, const float alpha){
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = alpha;
}
//insere voxels
void Sculptor::putVoxel(int x, int y, int z){
    this -> v[x][y][z].r = this -> r;
    this -> v[x][y][z].g = this -> g;
    this -> v[x][y][z].b = this -> b;
    this -> v[x][y][z].a = this -> a;
    this -> v[x][y][z].show = true;
}
//retira voxels
void Sculptor::cutVoxel(int x, int y, int z){
    this -> v[x][y][z].show = false;
}
//insere voxels no formato de um cubo
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0;i<x1;i++){
        for(int j = y0;j<y1;j++){
            for(int k = z0; z0<x1; k++){
                this -> putVoxel(i, j, k);
            }
        }
    }
}
//retira voxels no formato de uma caixa
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0;i<x1;i++){
        for(int j = y0;j<y1;j++){
            for(int k = z0; z0<x1; k++){
                this -> putVoxel(i, j, k);
            }
        }
    }

}
//coloca voxels no formato de uma esfera
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x1 = xcenter+radius;
    int y1 = ycenter+radius;
    int z1 = zcenter+radius;

    for(int i = xcenter;i<x1;i++){
        for(int j = ycenter;j<y1;j++){
            for(int k = zcenter; zcenter<z1; k++){
                if(pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2)<=pow(radius, 2)){
                    this -> putVoxel(i, j, k);
                }
            }
        }
    }
}
//retira voxels no formato de uma esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x1 = xcenter+radius;
    int y1 = ycenter+radius;
    int z1 = zcenter+radius;

    for(int i = xcenter;i<x1;i++){
        for(int j = ycenter;j<y1;j++){
            for(int k = zcenter; zcenter<z1; k++){
                if(pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2)<=pow(radius, 2)){
                    this -> cutVoxel(i, j, k);
                }
            }
        }
    }
}


//coloca voxels em forma de elipse
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x0 = xcenter - rx;
    int x1 = xcenter + rx;
    int y0 = ycenter - ry;
    int y1 = ycenter + ry;
    int z0 = zcenter - rz;
    int z1 = zcenter + rz;

    for(int i = x0;i<x1;i++){
        for(int j = y0;j<y1;j++){
            for(int k = z0; z0<z1; k++){
                if(pow(i - xcenter, 2)/ pow(rx,2) + pow(j - ycenter, 2)/ pow(ry,2) + pow(k - zcenter, 2)/ pow(rz,2)<=1){
                    this -> putVoxel(i, j, k);
                }
            }
        }
    }
}
//Retira voxels em uma elipse
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x0 = xcenter - rx;
    int x1 = xcenter + rx;
    int y0 = ycenter - ry;
    int y1 = ycenter + ry;
    int z0 = zcenter - rz;
    int z1 = zcenter + rz;

    for(int i = x0;i<x1;i++){
        for(int j = y0;j<y1;j++){
            for(int k = z0; z0<z1; k++){
                if(pow(i - xcenter, 2)/ pow(rx,2) + pow(j - ycenter, 2)/ pow(ry,2) + pow(k - zcenter, 2)<1){
                    this -> cutVoxel(i, j, k);
                }
            }
        }
    }
}


