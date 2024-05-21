#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

void playMp3(){
    system("mpg123 -q ./music.mp3 &");
}

void changeBackgroundColor(int r, int g, int b) {
    glClearColor(0, 255, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void myInit(){
    glClearColor(255, 255, 255, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 700.0, 0.0);
}

void finish(int x, int y){
    if((x > 50 && x < 70) && (y > 20 && y < 50)){
        glClearColor(0, 255, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        cout << "Parabéns, você chegou ao final do labirinto!" << endl;
    }
}


bool isInsideLines(int x, int y) {
    if ((x > 50 && x < 70) && (y > 50 && y < 150)) {
        return true;
    }else if((x > 50 && x < 220) && (y > 120 && y < 150)){
        return true;
    }
    else if ((x > 200 && x < 220) && (y > 85 && y < 150)) {
        return true;
    }else if((x > 200 && x < 250) && (y > 85 && y < 100)){
        return true;
    }
    else if ((x > 230 && x < 250) && (y > 85 && y < 190)) {
        return true;
    }else if((x > 230 && x < 400) && (y > 170 && y < 190)){
        return true;
    }
    else if ((x > 380 && x < 400) && (y > 170 && y < 210)) {
        return true;
    }else if((x > 280 && x < 400) && (y > 200 && y < 210)){
        return true;
    }
    else if ((x > 280 && x < 300) && (y > 210 && y < 260)) {
        return true;
    }else if((x > 70 && x < 300) && (y > 240 && y < 260)){
        return true;
    }
    else if ((x > 70 && x < 100) && (y > 210 && y < 260)) {
        return true;
    }else if((x > 40 && x < 100) && (y > 210 && y < 235)){
        return true;
    }
    else if ((x > 40 && x < 60) && (y > 210 && y < 530)) {
        return true;
    }else if((x > 40 && x < 350) && (y > 500 && y < 530)){
        return true;
    }
    else if ((x > 270 && x < 285) && (y > 510 && y < 530)) {
        return true;
    }else if((x > 285 && x < 320) && (y > 510 && y < 530)){
        return true;
    }
    else if ((x > 320 && x < 350) && (y > 500 && y < 580)) {
        return true;
    }else if((x > 220 && x < 350) && (y > 560 && y < 580)){
        return true;
    }
    else if((x >= 50 && x <= 60) && (y >= 20 && y <= 50)){
        return true;
    }
    else if ((x > 220 && x < 250) && (y > 560 && y < 700))
        return true;
    
    return false;
}


void motion(int x, int y){
    if(!isInsideLines(x, y)){
        glutPassiveMotionFunc(NULL);
        glutWarpPointer(235, 690);
        glutPassiveMotionFunc(motion);
    }
    finish(x, y);

}


void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT); // limpa a janela
    glColor3ub(0, 0, 255); // cor do desenho de chegada (azul)
    glBegin(GL_QUADS);
        glVertex2i(50, 20);
        glVertex2i(60, 20);
        glVertex2i(60, 35);
        glVertex2i(50, 35);
    glEnd();
    glFlush();
    glColor3ub(0, 0, 0); // cor do desenho das paredes (preto)  
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2i(50, 35);
        glVertex2i(50, 150);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
        glVertex2i(60, 35);
        glVertex2i(60, 120);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
        glVertex2i(60, 120);
        glVertex2i(200, 120);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
        glVertex2i(50, 150);
        glVertex2i(220, 150);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
        glVertex2i(220, 100);
        glVertex2i(220, 150);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
        glVertex2i(200, 120);
        glVertex2i(200, 85);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
        glVertex2i(220, 100);
        glVertex2i(230, 100);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
        glVertex2i(250, 85);
        glVertex2i(200, 85);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(250, 85);
        glVertex2i(250, 170);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(230, 100);
        glVertex2i(230, 190);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(230, 190);
        glVertex2i(380, 190);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(250, 170);
        glVertex2i(400, 170);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(400, 170);
        glVertex2i(400, 210);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(380, 190);
        glVertex2i(380, 200);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(380, 200);
        glVertex2i(280, 200);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(400, 210);
        glVertex2i(300, 210);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(300, 210);
        glVertex2i(300, 260);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(280, 200);
        glVertex2i(280, 240);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(300, 260);
        glVertex2i(70, 260);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(280, 240);
        glVertex2i(100, 240);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(100, 240);
        glVertex2i(100, 210);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(70, 260);
        glVertex2i(70, 235);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(100, 210);
        glVertex2i(40, 210);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(70, 235);
        glVertex2i(60, 235);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(40, 210);
        glVertex2i(40, 530);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(60, 235);
        glVertex2i(60, 500);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(60, 500);
        glVertex2i(350, 500);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(40, 530);
        glVertex2i(270, 530);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(270, 530);
        glVertex2i(270, 510);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(270, 510);
        glVertex2i(285, 510);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(285, 510);
        glVertex2i(285, 530);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(285, 530);
        glVertex2i(320, 530);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(350, 500);
        glVertex2i(350, 580);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(320, 530);
        glVertex2i(320, 560);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(350, 580);
        glVertex2i(250, 580);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(320, 560);
        glVertex2i(220, 560);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(220, 560);
        glVertex2i(220, 700);
    glEnd();
    glFlush();
     glBegin(GL_LINES);
        glVertex2i(250, 580);
        glVertex2i(250, 700);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
   glutInit(&argc, argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (500, 700); 
    glutInitWindowPosition (100, 100); 
    glutCreateWindow ("Labirinto"); 
    myInit(); 
    glutDisplayFunc(myDisplay);
    playMp3();
    glutPassiveMotionFunc(motion);
    glutMainLoop(); 

    return 0;
}