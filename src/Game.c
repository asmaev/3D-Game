#ifndef _GAME_C_
#define _GAME_C_

#include "../include/Game.h"

Camera * camera;
float old_t;
Cube* sky ;
Cube* ground;
Car* car1 ;

extern int rows ;
extern int cols ;
extern int** grid;

extern int tileSize;

extern arrayList cubes;
extern arrayList cars;
extern arrayList humans;
extern Aim* endPoint;
extern int GAMESTATE;
extern float deltaTime;

extern int mouseX;
extern int mouseY;


void drawText(int x,int y,const char* text,float r,float g,float b) {
    glColor4f(r,g,b,1);

    y = WINDOW_HEIGHT - y;
    glMatrixMode(GL_PROJECTION);
    GLdouble matrix[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);

    for(int i = 0 ; i < strlen(text);i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
    
}

void initGame(){
    srand(time(NULL));
    //initialiser la camera
    camera = createCamera(0,1,10,8.0f);
    //calcul du tmp delta
    float old_t = glutGet(GLUT_ELAPSED_TIME);

    sky = newCube(newVec3(0,20,0),newVec3(1000,2,1000));
    ground = newCube(newVec3(0,-1,0),newVec3(1000,2,1000));

    createWorld(camera);
}


void playing(){
    glEnable(GL_DEPTH_TEST);
    glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);


    // delta tmps
    int t;
    t = glutGet(GLUT_ELAPSED_TIME);
    deltaTime = (t - old_t) / 1000.0;
    old_t = t;

  
    //maj camera
    Vec3 previousCamPos = camera->eye;
    updateCamera(camera);
    camera->eye.y = 1;


    //vue de la map d'en dessus
    //camera->eye.y = 10;
    // camera->eye.x = -5;

   

    
    // dessin sol et plafond
    glPushMatrix();
    draw1ColorCube(sky,0., 0.75, 1.);
    glPopMatrix();
    glPushMatrix();
    draw1ColorCube(ground,0.25, 0.25, 0.25);
    glPopMatrix();

    glPushMatrix();

    // draw cubes
    glPushMatrix();
    for(int i = 0; i < cubes.size;i++){

        Cube* cube = (Cube*)getItem(&cubes,i);
        //collision du joueur avec un cube 
        if(cubeCollidePlayer(cube,camera->eye.x,camera->eye.z) == 1){ 
            camera->eye = previousCamPos;
        }

        glPushMatrix();
        drawCube(cube);
        glPopMatrix();
    }
    glPopMatrix();

    // dessin et maj de la voiture
    glPushMatrix();
    for(int i = 0; i < cars.size;i++){
        Car* car = (Car*)getItem(&cars,i);
        //gameover si collision avec une voiture
        if(carCollidePlayer(car,camera->eye.x,camera->eye.z) == 1){ 
            GAMESTATE = GAME_OVER;
        }
            
        updateCar(car);
        glPushMatrix();
        drawCar(car);
        glPopMatrix();
    }
    glPopMatrix();

    // dessin et maj de l'humain
    glPushMatrix();
    for(int i = 0; i < humans.size;i++){
        Human* human = (Human*)getItem(&humans,i);
        //gameover si collision avec un humain
        if(humanCollidePlayer(human,camera->eye.x,camera->eye.z) == 1){ 
            GAMESTATE = GAME_OVER;
        }
         
        updateHuman(human);
        glPushMatrix();
        drawHuman(human);
        glPopMatrix();
    }
    glPopMatrix();


    // si collision avec le tore
    if(aimCollidePlayer(endPoint,camera->eye.x,camera->eye.z) == 1){
        GAMESTATE = YOU_WIN;
    }
    drawAim(endPoint);
    glPopMatrix();


    // si collision d'un humain avec une voiture 
    for(int i = 0 ; i < cars.size;i++){
        for(int j = 0 ; j < humans.size;j++){
            Car* car = (Car*)getItem(&cars,i);
            Human* human = (Human*)getItem(&humans,j);

            float d = 0;
            if(car->dir == -1){
                d = distance(human->pos.x,human->pos.z, car->pos.x,car->pos.z );
            }
            else{
                d = distance(human->pos.x,human->pos.z, -car->pos.x,car->pos.z );
            }
            if(d < 1.0f ){
                deleteItem(&humans,j);
            }
        }  
    }

    char humanStr[100];
    sprintf(humanStr, "Humans: %d", humans.size);
    drawText(40,50,humanStr,0.0f,0.0f,0.0f);

    char carStr[100];
    sprintf(carStr, "Cars: %d", cars.size);
    drawText(40,100,carStr,0.0f,0.0f,0.0f);


}


void menu(){
    drawText(340,200,"Find the torus!",1.0f,1.0f,0.2f);
    drawText(270,300,"Press 'Space' to start the game!",1.0f,1.0f,0.2f);
    drawText(240,400,"Hold 'Left Mouse' to control camera",1.0f,1.0f,1.0f);
}
void gameOver(){
    drawText(340,250,"Game Over!",1.0f,0.2f,0.2f);
    drawText(270,350,"Press 'Space' to play again!",1.0f,1.0f,0.2f);
}
void youWin(){
    drawText(340,250,"You Win!",0.0f,0.2f,0.9f);
    drawText(270,350,"Press 'Space' to play again!",1.0f,1.0f,0.2f);
}


void updateGame(){
    switch (GAMESTATE){
    case PLAYING:
        playing();
        break;
    case MAIN_MENU:
        menu();
        break;
    case GAME_OVER:
        gameOver();
        break;
    case YOU_WIN:
        youWin();
        break;
    }
}


void onKeyDown(unsigned char key, int x, int y){
    switch (GAMESTATE){
    case PLAYING:
        cameraKeyDown(camera,key);
        break;
    default:
        if(key == ' '){
            GAMESTATE = PLAYING;
            initGame();
        }
        break;
    }
    
}
void onKeyUp(unsigned char key, int x, int y){
    switch (GAMESTATE){
    case PLAYING:
        cameraKeyUp(camera,key);
        break;
    
    }
}

void mouseMove(int x, int y){
    mouseX = x;
    mouseY = y;
}


void mouseClick(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        camera->keys[4] = 1;
        camera->mouseX = x;
        camera->mouseY = y;
        mouseX = WINDOW_WIDTH/2;
        mouseY = WINDOW_HEIGHT/2;  
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        camera->keys[4] = 0;
    }
}

#endif

