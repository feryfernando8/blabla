#include <GL/glut.h>
#define RATIO 1.300
#define WW 100
#define WH (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .001

int WindowWidth;

int WindowHeight;


void InitGL();
void Tween();
void Reshape(int,int);

main(int argc, char **argv)
{

 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);


 WindowWidth = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.4);
 WindowHeight = (int)(WindowWidth/RATIO);

 glutInitWindowSize(WindowWidth,WindowHeight);
 glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.3),(glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2)-(WindowHeight/2));

 glutCreateWindow("Fery Fernando - 672018116");

 glutDisplayFunc(Tween);

 glutReshapeFunc(Reshape);

 InitGL();

 glutMainLoop();
}

void Tween()
{

 glLineWidth(1.0);

float StartShape[12][2]={{0,0},{5,0},{5,-3},{1,-3},{1,-6},{5,-6},
                        {5,-9},{1,-9},{1,-15},{0,-15},{0,-15},{0,-15}};

float EndShape[12][2]={{0,0},{5,0},{5,-3},{2,-3},{2,-6},{5,-6},
                    {5,-15},{0,-15},{0,-12},{3,-12},{3,-9},{0,-9}};


float IntermediateShape[12][2];

float VertexColors[12][3]={{1,1,1},{1,1,0},{1,0,0},{1,1,1},{1,1,0},{1,0,0},{1,1,1},{1,1,0},{1,0,0},{1,1,1},{1,1,0},{1,0,0}};

 static float Tween=0.0-deltat;

 if(Tween<1)
 {
 Tween+= deltat;
 }

 for (int Vtx=0;Vtx<12;Vtx++)
 {
 IntermediateShape[Vtx][0]=(1.0-Tween)*StartShape[Vtx][0]+Tween*EndShape[Vtx][0];
 IntermediateShape[Vtx][1]=(1.0-Tween)*StartShape[Vtx][1]+Tween*EndShape[Vtx][1];
 }

 glVertexPointer(2,GL_FLOAT,0,IntermediateShape);
 glColorPointer(3,GL_FLOAT,0,VertexColors);

for (int i = 0; i < 2000000; i++);
 glClear(GL_COLOR_BUFFER_BIT);
 glDrawArrays(GL_LINE_LOOP,0,12);
 glutSwapBuffers();
 glutPostRedisplay();
}

void Reshape(int w,int h)
{
 glutReshapeWindow(w,(int)(w/RATIO));
 WindowWidth=w;
 WindowHeight=(int)(w/RATIO);
 InitGL();
}

void InitGL()
{

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-HALFX,HALFX,-HALFY,HALFY);
 glMatrixMode(GL_MODELVIEW);
 glClearColor(0, 0, 0, 0);
 glEnableClientState (GL_VERTEX_ARRAY);
 glEnableClientState (GL_COLOR_ARRAY);
 glShadeModel(GL_SMOOTH);
 glViewport(0,0,WindowWidth,WindowHeight);
}
