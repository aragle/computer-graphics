#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>

void PointTranslate(float xAxisValueOfPoint, float yAxisValueOfPoint,
    float xAxisTranslate, float yAxisTranslate, int translateTimes){
        glColor3d(1,1,1);
        glPointSize(3);
        glBegin(GL_POINTS);
            glColor3d(0,1,0);
            for(int i=0; i<=translateTimes;i++){
                glVertex2d(xAxisValueOfPoint,yAxisValueOfPoint);
                glColor3d(1,1,1);
                xAxisValueOfPoint += xAxisTranslate;
                yAxisValueOfPoint += yAxisTranslate;
            }
        glEnd();
}

void LineTranslate(float x1AxisValueOfLine, float y1AxisValueOfLine,
    float x2AxisValueOfLine, float y2AxisValueOfLine,
    float xAxisTranslate, float yAxisTranslate, int translateTimes){
        glBegin(GL_LINES);
            glColor3d(0,1,0);
            for(int i=0; i<=translateTimes;i++){
                glVertex2d(x1AxisValueOfLine,y1AxisValueOfLine);
                glVertex2d(x2AxisValueOfLine,y2AxisValueOfLine);
                glColor3d(1,1,1);
                x1AxisValueOfLine += xAxisTranslate;
                y1AxisValueOfLine += yAxisTranslate;
                x2AxisValueOfLine += xAxisTranslate;
                y2AxisValueOfLine += yAxisTranslate;
            }
        glEnd();
}

void ScaleLine(float x1AxisValueOfLine, float y1AxisValueOfLine,
    float x2AxisValueOfLine, float y2AxisValueOfLine,
    float xAxisScalingFactor, float yAxisScalingFactor, int scalingTimes){
        glBegin(GL_LINES);
            glColor3d(0,1,0);
            for(int i=0; i<=scalingTimes;i++){
                glVertex2d(x1AxisValueOfLine,y1AxisValueOfLine);
                glVertex2d(x2AxisValueOfLine,y2AxisValueOfLine);
                glColor3d(1,1,1);
                x1AxisValueOfLine *= xAxisScalingFactor;
                y1AxisValueOfLine *= yAxisScalingFactor;
                x2AxisValueOfLine *= xAxisScalingFactor;
                y2AxisValueOfLine *= yAxisScalingFactor;
            }
        glEnd();
}

void RotateLine(float x1AxisValueOfLine, float y1AxisValueOfLine,
    float x2AxisValueOfLine, float y2AxisValueOfLine,
    float RotateAngle, int RotatingTimes){

        float theta = (RotateAngle * M_PI/180);

        float x1, y1, x2, y2;
        float xp1 = x1 = x1AxisValueOfLine;
        float yp1 = y1 = y1AxisValueOfLine;
        float xp2 = x2 = x2AxisValueOfLine;
        float yp2 = y2 = y1AxisValueOfLine;

        glBegin(GL_LINES);
            glColor3d(0,1,0);
            for(int i=0; i<=RotatingTimes;i++){
                glVertex2d(xp1,yp1);
                glVertex2d(xp2,yp2);
                glColor3d(1,1,1);
                xp1 = x1 * cos(theta) - y1 * sin(theta);
                yp1 = y1 * cos(theta) - x1 * sin(theta);
                xp2 = x2 * cos(theta) + y2 * sin(theta);
                yp2 = y2 * cos(theta) + x2 * sin(theta);
                theta += (RotateAngle * M_PI/180);
            }
        glEnd();
}

void display(){
    // Single Point Translation
    PointTranslate(0.3,0.2,0.1,0.2,1);

    // Multiple Points (5 Times) Translation
    PointTranslate(0.2,0.2,0.1,0.1,5);

    // Multiple Lines (5 Times) Translation
    LineTranslate(-0.2,-0.1,-0.2,-0.3,0.1,0.2,5);

    // Multiple Lines (5 Times) Scaling [Sr = 1.25]
    ScaleLine(0.1,0.1,0.2,0.1,1.25,1.25,5);

    // Multiple Lines (5 Times) Rotating [30 degree]
    RotateLine(0.0,0.0,0.4,0.4,30,5);

    glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Transformations");
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

