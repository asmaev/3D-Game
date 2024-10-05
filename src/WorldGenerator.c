#ifndef _WORLDGENERATOR_C_
#define _WORLDGENERATOR_C_


#include "../include/WorldGenerator.h"

int rows = HEIGHT;
int cols = WIDTH;
int** grid;

int tileSize;

arrayList cubes;
arrayList cars;
arrayList humans;
Aim* endPoint;


void generateWorld(){

    // 8: start
    // 9: end
    // 7: car 
    // 1: cube
    // 6: human
    // 2: cube scale++
    // 6: human

    tileSize = 2;

  
   int tmpGrid[HEIGHT][WIDTH] = {
     { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
     { 1,9,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1 }, 
     { 1,1,1,1,1,1,0,0,0,0,0,1,0,0,2,0,0,0,0,1 }, 
     { 1,0,0,1,0,0,0,6,1,1,0,0,0,0,1,0,0,2,0,1 }, 
     { 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1 }, 
     { 1,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,1,0,2,2,0,0,0,0,0,0,0,0,1 }, 
     { 1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1 }, 
     { 1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,6,0,0,1 }, 
     { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }, 
     { 1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,8,1 }, 
     { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } 
    };


    grid = (int**)malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = (int*)malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = tmpGrid[i][j];
        }
    }
}


void createWorld(Camera* camera){
    generateWorld();
    newArrayList(&cubes);
    newArrayList(&cars);
    newArrayList(&humans);


    //ajout des elements de l'environnement en fct de ce qu'il y a dans la matrice 
    for(int row = 0; row < HEIGHT; row++){
        for(int col = 0; col < WIDTH; col++){
            switch (grid[row][col])
            {
            case 1:
            {
                Cube* cube = newCube(newVec3(col * tileSize,1,row * tileSize),newVec3(1,2,1));
                addItem(&cubes,cube);
                break;
            }
            case 2:
            {
                Cube* cube = newCube(newVec3(col * tileSize,9,row * tileSize),newVec3(1,10,1));
                addItem(&cubes,cube);
                break;
            }
            case 6:
            {
                Human* human = newHuman(newVec3(col * tileSize,0.6f,row * tileSize),grid,rows,cols);
                addItem(&humans,human);
                break;
            }
            case 7:
            {
                Car* car = newCar(newVec3(col * tileSize,0.5f,row * tileSize),newVec3((col - 19) *  tileSize,1,row * tileSize));
                addItem(&cars,car);
                break;
            }
            case 8:
            {
                camera->eye.x = col * tileSize;
                camera->eye.z = row * tileSize;
                break;
            }
            case 9:
            {
                endPoint = newAim(newVec3(col * tileSize,1,row * tileSize));
                break;
            }
                   
            }
        }
    }
    

}



#endif
