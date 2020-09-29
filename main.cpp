#include <GL/glut.h>

static int Day = 0, Time = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 0.3, 0.3);
    glutWireSphere(0.2, 20, 16);        // 태양
    glPushMatrix();
        glRotatef((GLfloat) Day, 0.0, 1.0, 0.0);
        glTranslatef(0.7, 0.0, 0.0);
        glRotatef((GLfloat) Time, 0.0, 1.0, 0.0);
        glColor3f(0.5, 0.6, 0.7);
        glutWireSphere(0.1, 10, 8);       // 지구
        glPushMatrix();
            glRotatef((GLfloat) Time, 0.0, 1.0, 0.0);
            glTranslatef(0.2, 0.0, 0.0);
            glColor3f(0.9, 0.8, 0.2);
            glutWireSphere(0.04, 10, 8);    // 달
        glPopMatrix( );
    glPopMatrix();
    glutSwapBuffers();
}

void MyKeyboard (unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        Day = (Day + 10) % 360;
        glutPostRedisplay();
        break;
    case 't':
        Time = (Time + 5) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}

/*
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // 회전하고 이동
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);

    glutSolidCube(0.3);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
*/

/*
int MyListID;

void MyCreateList() {
    MyListID = glGenLists(1);
    glNewList(MyListID, GL_COMPILE);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, -0.5, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(-0.5, 0.5, 0.0);
    glEnd( );
    glEndList();
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glCallList(MyListID);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Example Drawing");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc(MyDisplay);
    MyCreateList();
    glutMainLoop();
    return 0;
}
*/

/*
GLfloat MyVertices[8][3] = {
    { -0.25, -0.25, 0.25 },
    { -0.25, 0.25, 0.25 },
    { 0.25, 0.25, 0.25 },
    { 0.25, -0.25, 0.25 },
    { -0.25, -0.25, -0.25 },
    { -0.25, 0.25, -0.25 },
    { 0.25, 0.25, -0.25 },
    { 0.25, -0.25, -0.25 }
};
GLfloat MyColors[8][3] = {
    { 0.2, 0.2, 0.2 },
    { 1.0, 0.0, 0.0 },
    { 1.0, 1.0, 0.0 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    { 1.0, 0.0, 1.0 },
    { 1.0, 1.0, 1.0 },
    { 0.0, 1.0, 1.0 }
};
GLubyte MyVertexList[24] = {
    0, 3, 2, 1,
    2, 3, 7, 6,
    0, 4, 7, 3,
    1, 2, 6, 5,
    4, 5, 6, 7,
    0, 1, 5, 4
};

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(30.0, 1.0, 1.0, 1.0);
    for(GLint i = 0; i < 6; i++)
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4*i]);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
*/

/*
unsigned char PALETTE[16][3] = {
    { 255, 255, 255 },      // WHITE
    {   0, 255, 255 },      // CYAN
    { 255,   0, 255 },      // PURPLE
    {   0,   0, 255 },      // BLUE
    { 192, 192, 192 },      // LIGHT GRAY
    { 128, 128, 128 },      // DARK GRAY
    {   0, 128, 128 },      // DARK TEAL
    { 128,   0, 128 },      // DARK PURPLE
    {   0,   0, 128 },      // DARK BLUE
    { 255, 255,   0 },      // YELLOW
    {   0, 255,   0 },      // GREEN
    { 128, 128,   0 },      // DARK YELLOW
    {   0, 128,   0 },      // DARK GREEN
    { 255,   0,   0 },      // RED
    { 128,   0,   0 },      // DARK RED
    {   0,   0,   0 },      // BLACK
};

GLfloat Delta = 0.0;
GLint   Index = 0;
GLfloat Red = 0.0;
GLfloat Green = 0.0;
GLfloat Blue = 0.0;

void MyDisplay() {
    Red   = PALETTE[Index][0] / 255.0f;
    Green = PALETTE[Index][1] / 255.0f;
    Blue  = PALETTE[Index][2] / 255.0f;

    glColor3f(Red, Green, Blue);
    glBegin(GL_LINES);
        glVertex3f(-1.0 + Delta,  1.0, 0.0);
        glVertex3f( 1.0 - Delta, -1.0, 0.0);
        glVertex3f(-1.0, -1.0 + Delta, 0.0);
        glVertex3f( 1.0,  1.0 - Delta, 0.0);
    glEnd();
    glutSwapBuffers();
}

void MyTimer(int Value) {
    if (Delta < 2.0f)
        Delta = Delta + 0.01;
    else {
        Delta = 0.0;
        if (++Index >= 15) {
            Index = 0;
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, MyTimer, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Timer Animation Sample");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutTimerFunc(10, MyTimer, 1);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
*/

/*
GLfloat Delta = 0.0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.8);
        glVertex3f(-1.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, 0.5, 0.0);
        glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    glutSwapBuffers();
}

void MyTimer(int Value) {
    Delta = Delta + 0.001;
    glutPostRedisplay();
    glutTimerFunc(40, MyTimer, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(40, MyTimer, 1);
    glutMainLoop();
    return 0;
}
*/

/*
GLfloat Delta = 0.0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.8);
        glVertex3f(-1.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, -0.5, 0.0);
        glVertex3f(0.0 + Delta, 0.5, 0.0);
        glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    glutSwapBuffers();
}

void MyIdle() {
    Delta = Delta + 0.001;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc(MyDisplay);
    glutIdleFunc(MyIdle);
    glutMainLoop();
    return 0;
}
*/

/*
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
    glViewport(0, 0, 300, 300);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
        glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0.0);
        glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
        glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
        glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300.0, 0.0);
    glEnd();
    glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
    }
}

void MyMouseMove(GLint X, GLint Y) {
    BottomRightX = X;
    BottomRightY = Y;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    glutMainLoop();
    return 0;
}
*/

// 키보드 콜백
/*
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, -0.5, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed){
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 27:                //'esc' 키의 아스키 코드 값
        exit(0); break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
*/

// 기본 사각형 ortho 이용해서 그리기
/*
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);       //컬러버퍼에 초기화 색을 가함
    glColor3f(0.5, 0.5, 0.5);           //회색
    glBegin(GL_POLYGON);                //사각형
        glVertex3f(-0.5, -0.5, 0.0);    //좌하단 좌표
        glVertex3f(0.5, -0.5, 0.0);     //좌하단 좌표
        glVertex3f(0.5, 0.5, 0.0);      //우상단 좌표
        glVertex3f(-0.5, 0.5, 0.0);     //좌상단 좌표
    glEnd();
    glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) 300;
    GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) 300;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
        -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

int main(int argc, char** argv) {    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Example Drawing");
    glClearColor(1.0, 1.0, 1.0, 1.0);   //초기화 색은 백색
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}
*/