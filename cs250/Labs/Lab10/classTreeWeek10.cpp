#include <GL/freeglut.h>
#include <cmath>
#include <time.h>


// globals
const int WIDTH = 700;
const int HEIGHT = 700;
const int DEPTH = 4;
const double SPREAD = M_PI/3;
const double REDUCE = 0.50;
const int BRANCHES = 6;

// prototypes
void reshape(int w, int h);
void display();
void line(int x1, int y1, int x2, int y2);
void tree(int x, int y, double angle, double length, int depth);
void circle(int cx, int cy, int r, int num); 


int main(int argc, char **argv) {
	srand(time(NULL));			// seed RNG
	glutInit(&argc, argv);		// init glut
	glutInitWindowSize(WIDTH, HEIGHT); 	// size window
	glutInitWindowPosition(0, 0);		// position window
	glutCreateWindow("test");	// create window
	glutDisplayFunc(display);	// set display function
	glutReshapeFunc(reshape);	// set shape (proj) function
	glutMainLoop();				// begin drawing
	return 0;
}


void reshape(int w, int h) {
	glViewport(0, 0, w, h);       // Establish viewing area to cover entire window
	glMatrixMode(GL_PROJECTION);  // Start modifying the projection matrix
	glLoadIdentity();             // Reset project matrix
	glOrtho(0, w, 0, h, -1, 1);   // Map abstract coords directly to window coords
	//glScalef(1, -1, 1);           // Invert Y axis so increasing Y goes down
	//glTranslatef(0, -h, 0);       // Shift origin up to upper-left corner
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// set color to white (0 to 1 scale)
	glColor3f(0.55,0.27,0.07);		
	
	// draw a line for my trunk
	line(WIDTH/2, 0, WIDTH/2, HEIGHT/3);

	// draw the branches
	tree(WIDTH/2, HEIGHT/3, M_PI/2, HEIGHT/3, DEPTH);
	//circle(100, 100, 50, 100);

	// draw to the screen
	glFlush();				
}



void tree(int x, int y, double angle, double length, int depth) {
	// base case
	if(depth == 0) {
		// draw fruit
		glColor3f(0, 1, 0);
		circle(x, y, 5, 20);
		glColor3f(0.55,0.27,0.07);
		return;
	}
	
	double newAngle = angle - SPREAD/2;
	double newLen = length/2;
	for(int i = 0; i < BRANCHES; i++) {
		glColor3f(0.502, 0.502, 0.000);
		int xNew = x + newLen*cos(newAngle);
		int yNew = y + newLen*sin(newAngle);
		line(x, y, xNew, yNew);
		tree(xNew, yNew, newAngle, length*REDUCE, depth-1);
		newAngle += SPREAD / (BRANCHES-1);
	}
}


void line(int x1, int y1, int x2, int y2) {
	glBegin(GL_LINES);
    	glVertex2i(x1, y1);
    	glVertex2i(x2, y2);
	glEnd();
}


void circle(int cx, int cy, int r, int num) {


glBegin(GL_LINE_LOOP);
    for(int i = 0; i < num; i++)
    {
        float theta = 2*M_PI*i/num;
		//get the current angle

        float x = 6*r * cos(theta);//calculate the x component
        float y = 6*r * sin(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
glEnd();
}
