#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLfloat house[3][9]={{250.0,250.0,300.0,350.0,350.0,275.0,275.0,325.0,325.0},
					 {250.0,400.0,450.0,400.0,250.0,250.0,325.0,325.0,250.0},
					 {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0}, {0}, {0}};
GLfloat h=250.0; // Pivot point 
GLfloat k=250.0;
GLfloat theta,rad;
void multiply()
{        // Rotation MATRIX and Object Matrix => Resultant Transformed House
	int i,j,l;
	for(i=0;i<3;i++)
		for(j=0;j<9;j++)
		{
			result[i][j]=0;
			for(l=0;l<3;l++)
				result[i][j]=result[i][j]+(rot_mat[i][l]*house[l][j]);
		}
}
void rotate()
{
	GLfloat m,n;   // Build the rotation matrix
	m=-h*(cos(theta)-1)+k*(sin(theta));
	n=-k*(cos(theta)-1)-h*(sin(theta));
	rot_mat[0][0]=cos(theta);
	rot_mat[0][1]=-sin(theta);
	rot_mat[0][2]=m;
	rot_mat[1][0]=sin(theta);
	rot_mat[1][1]=cos(theta);
	rot_mat[1][2]=n;
	rot_mat[2][0]=0;
	rot_mat[2][1]=0;
	rot_mat[2][2]=1;
	//multiply the two matrices: Rotation Matrix * Objet Matrix(house)
	multiply();
}
void drawhouse(GLfloat houses[3][9])
{
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	  glVertex2f(houses[0][0],houses[1][0]);
	  glVertex2f(houses[0][1],houses[1][1]);
	  glVertex2f(houses[0][3],houses[1][3]);
	  glVertex2f(houses[0][4],houses[1][4]);
         glEnd();
	glColor3f(1.0,0.0,0.5);
	glBegin(GL_POLYGON);
	 glColor3f(1.0,0.0,0.5);
	 glVertex2f(houses[0][5],houses[1][5]);
 	 glVertex2f(houses[0][6],houses[1][6]);
 	 glVertex2f(houses[0][7],houses[1][7]);
 	 glVertex2f(houses[0][8],houses[1][8]);
	glEnd();
	glColor3f(0.20, 0.50, 01.0);
	glBegin(GL_TRIANGLES);
  	 glColor3f(0.20, 0.50, 01.0);
  	 glVertex2f(houses[0][1],houses[1][1]);
  	 glVertex2f(houses[0][2],houses[1][2]);
  	 glVertex2f(houses[0][3],houses[1][3]);
  	glEnd();
}
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);	
	theta=rad;
	drawhouse(house);
	rotate();
	drawhouse(result);
	glFlush();
}

int main(int argc, char* argv[])
{
	
	printf("Enter the rotation angle\n");
	scanf("%f", &theta);
        rad=theta*(3.14/180);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("house rotation");
	glutDisplayFunc(display);
	glClearColor(1.0,1.0,1.0,1.0);
	gluOrtho2D(0,499,0,499);
	glutMainLoop();
        return 1;
}

