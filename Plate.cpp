/******************************************
 *
 * Official Name:  Geri Madanguit
 *
 * Nickname:  Geri
 *
 * E-mail:  gemadang@syr.edu
 *
 * Assignment:  Assignment 2
 *
 * Environment/Compiler:  XCODE
 *
 * Date:  February 22, 2017
 *
 *******************************************/

#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;

// Globals.
static int id1, id2; // Window identifiers.
static GLsizei width, height; // OpenGL window size.
static int rangle = 0;
static int small, big = 0;
static int reg = 1;

static int plate_center = 100;
static int radiusPlate = 50;

static int breakfast = 1;
static int lunch = 0;
static int dinner = 0;

static int letsEat = 0;
    //0, when on 'home page' of choosing plates. 1, when the user is at breakfast, lunch, or dinner
static int home = 1;
    //1, when click 'go back' button and at home. 0, when user is at breakfast, lunch, or dinner

//FILIPINO FIRST
static int changePlate = 0;
//main course
static int tocino = 0;
static int spam = 0;
static int milkfish = 0;
//included sides
static int rice = 1;
static int egg1 = 1;
static int egg2 = 1;
//optional side
static int teapot = 1;

//JAPAN JOY
//main course
static int spicy_ramen = 0; //spicy with corn
static int orig_ramen = 0; //with boiled agg and swirlies
//included sides
static int soy_sauce = 1;
static int wasabi = 1;
static int ginger = 1;
//optional sides
static int shrimp_tempura_roll = 0;
static int tuna_roll = 0;

static unsigned int noodles; // List index.


//gradient colors
static float gradient_soySauce[5][3] =
{
    {0.0,0.0,0.0},
    {.13,.13, .19},
    {0.36,0.22,0.0},
    {0.38,0.29,0.17},
    {0.0,0.0,0.0}
};
static float gradient_wasabi[5][3] =
{
    {0.67,0.76, 0.34},
    {0.85,0.80,0.2},
    {0.89,0.57,0.58},
    {0.55,0.84,0.86},
    {0.0,1.0,0.0}
};
static float gradient_ginger[3][3] =
{
    {.78,.32, .27},
    {0.99,0.50,0.26},
    {0.98,0.81,0.68}
};
static float gradient_ramen_red[4][3] =
{
    {0.87,0.39,0.18},
    {0.98,0.63,0.55},
    {0.94,0.71,0.50},
    {0.98,0.63,0.55}
};
static float gradient_ramen_yellow[3][3] =
{
    {0.96,0.82,0.47},
    {0.89,0.84,0.53},
    {0.93,0.89,0.72}
};

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string){
    char *c;
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}
// Routine to draw a stroke character string.
void writeStrokeString(void *font, char *string){
    char *c;
    for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
    
}

void drawChoosePlate(){
    
    //background is white
    glClearColor(1.0, 1.0, 1.0, 0.0);
    int i; float angle;
    
    
    //lets eat!
    glColor3f(0.5, 0.2, 0.8);
    glBegin(GL_POLYGON);
    for(i = 0; i < 6; ++i)
    {
        angle = 2 * PI * i / 6;
        glVertex2f(25 + cos(angle) * 13.5, 13 + sin(angle) * 8.5);
    }
    glEnd();
    
    
    //radio triangles
    
    //outline for Breakfast
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 3; ++i)
    {
        angle = 2 * PI * i / 3;
        glVertex2f(5 + cos(angle) * 3.0, 70 + sin(angle) * 3.0);
    }
    glEnd();
   
    //filler for Breakfast
    if(breakfast){
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        for(i = 0; i < 3; ++i)
        {
            angle = 2 * PI * i / 3;
            glVertex2f(5 + cos(angle) * 2.0, 70 + sin(angle) * 2.0);
        }
        glEnd();
    }
    
    //outline for Lunch
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 3; ++i)
    {
        angle = 2 * PI * i / 3;
        glVertex2f(5 + cos(angle) * 3.0, 50 + sin(angle) * 3.0);
    }
    glEnd();
    
    //filler for Lunch
    if(lunch){
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        for(i = 0; i < 3; ++i)
        {
            angle = 2 * PI * i / 3;
            glVertex2f(5 + cos(angle) * 2.0, 50 + sin(angle) * 2.0);
        }
        glEnd();
    }
    
    //outline for Dinner
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 3; ++i)
    {
        angle = 2 * PI * i / 3;
        glVertex2f(5 + cos(angle) * 3.0, 30 + sin(angle) * 3.0);
    }
    glEnd();
    
    //filler for Dinner
    if(dinner){
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        for(i = 0; i < 3; ++i)
        {
            angle = 2 * PI * i / 3;
            glVertex2f(5 + cos(angle) * 2.0, 30 + sin(angle) * 2.0);
        }
        glEnd();
    }
    
    glPushMatrix();
    glTranslatef(7.8, 90.0, 0.0);
    glScalef(0.025, 0.035, 0.035);
    writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Asian Cuisine");
    glPopMatrix();

    glRasterPos3f(10.0, 68.5, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Have an early Breakfast at Filipino First");
    
    glRasterPos3f(10.0, 48.5, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Enjoy some Lunch at Japan Joy");
    
    glRasterPos3f(10.0, 29.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Surprise Dinner");
    
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(17.5, 11.0, 0.0);
    glScalef(0.015, 0.025, 0.025);
    writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Let's Eat");
    glPopMatrix();

}

void drawRice(){
    int i, j;
    
    float R = 35.0; // Radius of hemisphere.
    int p = 51; // Number of longitudinal slices.
    int q = 38; // Number of latitudinal slices.
    float Xangle = 90.0;
    
    float cx = 0.0;
    float cy = 0.0;
    float cz = 0.0;
    
    glRotatef(Xangle, 1.0, 0.0, 0.0);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(0.79, 0.49, 0.38);
    
    // Array of latitudinal triangle strips, each parallel to the equator, stacked one
    // above the other from the equator to the north pole.
    for(j = 0; j < q; j++)
    {
        // One latitudinal triangle strip.
        glBegin(GL_TRIANGLE_STRIP);
        for(i = 0; i <= p; i++)
        {
            if (j <= (q/2)){
                glColor3f(0.95, 0.9, 0.84); // color
                glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ) +cx,
                           R * sin( (float)(j+1)/q * PI/2.0 ) +cy+10,
                           R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI )+ cz );
                glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ) +cx,
                           R * sin( (float)j/q * PI/2.0 ) + cy+10,
                           R * cos( (float)j/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI )+ cz );
            }
            else{
                glColor3f(0.98, 0.97, 0.95); //color
                //glColor3f(0.79, 0.49, 0.38);
                glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ) +cx,
                           R * sin( (float)(j+1)/q * PI/2.0 ) +cy+10,
                           R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI )+ cz );
                glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ) +cx,
                           R * sin( (float)j/q * PI/2.0 ) + cy+10,
                           R * cos( (float)j/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI )+ cz );
            }
        }
        glEnd();
    }
    
}
void drawEgg1(){
    float angle;
    int i;
    float eggx = 150;
    float eggy = 90;
    
    float orientx = 8;
    float orienty = 3;
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(eggx + cos(angle) * 23.0, eggy + sin(angle) * 23.0);
    }
    glEnd();
    
    
    glColor3f(1.0, 0.8, 0);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(eggx + orientx + cos(angle) * 10.0, eggy + orienty + sin(angle) * 10.0);
    }
    glEnd();
}
void drawEgg2(){
    float angle;
    int i;
    
    float eggx = 135;
    float eggy = 58;
    
    float orientx = 3;
    float orienty = 8;
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(eggx + cos(angle) * 23.0, eggy + sin(angle) * 23.0);
    }
    glEnd();
    
    
    glColor3f(1.0, 0.8, 0);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(eggx + orientx + cos(angle) * 10.0, eggy + orienty + sin(angle) * 10.0);
    }
    glEnd();}

void drawX(){
    
    glLineWidth(3.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(26.0,77.3, -4.0);
    glVertex3f(28.0,75.3, -4.0);
    
    glVertex3f(28.0,75.3, -4.0);
    glVertex3f(30.0,83.3, -4.0);
    glEnd();
    glLineWidth(1.0);
}

void drawMenu_B(){
    
    int i; float angle;

    //background is red
    glClearColor(.83, 0.09, 0.03, 0.0);
    
    //white triangle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(i = 0; i < 3; ++i)
    {
        angle = 2 * PI * i / 3;
        glVertex2f(5 + cos(angle) * 50.0, 50 + sin(angle) * 50.0);
    }
    glEnd();
    
    //put blue bottom part
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, -5.0);
    glVertex3f(50.0, 0.0, -5.0);
    glVertex3f(50.0, 50.0, -5.0);
    glVertex3f(0.0, 20.0, -5.0);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(7.8, 90.0, 0.0);
        glScalef(0.025, 0.035, 0.035);
        writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Filipino First");
    glPopMatrix();
    
    glRasterPos3f(11.0, 85.0, 0.0);
    writeBitmapString(GLUT_BITMAP_9_BY_15, "comes with a cup of rice, and 2 eggs");
    
    
    //rice
    glPushMatrix();
    glTranslatef(28.5, 78.0, -5.0);
    glScalef(0.1, 0.1, 0.1);
        drawRice();
    glPopMatrix();
    
    //egg1
    glPushMatrix();
    glTranslatef(23.8, 70.0, 0.0);
    glScalef(0.1, 0.1, 0.1);
        drawEgg1();
    glPopMatrix();
    
    //egg2
    glPushMatrix();
    glTranslatef(25.0, 63.0, 0.0);
    glScalef(0.1, 0.1, 0.1);
        drawEgg2();
    glPopMatrix();
    
    
    if(rice){
    glPushMatrix();
        drawX();
    glPopMatrix();
    }
    if (egg1){
        glPushMatrix();
        glTranslatef(10, 1, 0);
            drawX();
        glPopMatrix();
    }
    if (egg2){
        glPushMatrix();
        glTranslatef(10, -8, 0);
        drawX();
        glPopMatrix();
    }
    
    //SUN radio buttons
    
    //SPAM OUTLINE
    glColor3f(0.04, 0.18, 0.55);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 14 * PI * i / 30;
        glVertex2f(8 + cos(3*angle) * 3.8, 65 + sin(3*angle) * 3.8);
    }
    glEnd();
    
    //SPAM FILL
    if(spam){
        glColor3f(1.0, 0.97, 0.29);
        glBegin(GL_POLYGON);
        for(i = 0; i < 30; ++i)
        {
            angle = 14 * PI * i / 30;
            glVertex2f(8 + cos(3*angle) * 4, 65 + sin(3*angle) * 4);
        }
        glEnd();
    }
    
    //MILKFISH OUTLINE
    glColor3f(0.04, 0.18, 0.55);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 14 * PI * i / 30;
        glVertex2f(25 + cos(3*angle) * 3.8, 50 + sin(3*angle) * 3.8);
    }
    glEnd();
    
    //MILKFISH FILL
    if(milkfish){
        glColor3f(1.0, 0.97, 0.29);
        glBegin(GL_POLYGON);
        for(i = 0; i < 30; ++i)
        {
            angle = 14 * PI * i / 30;
            glVertex2f(25 + cos(3*angle) * 4, 50 + sin(3*angle) * 4);
        }
        glEnd();
    }
    
    //TOCINO OUTLINE
    glColor3f(0.04, 0.18, 0.55);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 14 * PI * i / 30;
        glVertex2f(8 + cos(3*angle) * 3.8, 35 + sin(3*angle) * 3.8);
    }
    glEnd();
    
    //TOCINO FILL
    if(tocino){
        glColor3f(1.0, 0.97, 0.29);
        glBegin(GL_POLYGON);
        for(i = 0; i < 30; ++i)
        {
            angle = 14 * PI * i / 30;
            glVertex2f(8 + cos(3*angle) * 4, 35 + sin(3*angle) * 4);
        }
        glEnd();
    }
    
    
    glColor3f(0.04, 0.18, 0.55);
    
    glRasterPos3f(12.0, 65.5, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Spam");
    
    glRasterPos3f(30.0, 48.5, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Milkfish");
    
    glRasterPos3f(12.0, 35.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Tocino");
    
    //lets eat!
    glColor3f(1.0, 0.97, 0.29);
    glBegin(GL_POLYGON);
    for(i = 0; i < 6; ++i)
    {
        angle = 2 * PI * i / 6;
        glVertex2f(25 + cos(angle) * 13.5, 13 + sin(angle) * 8.5);
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(15.5, 11.0, 0.0);
    glScalef(0.025, 0.035, 0.035);
    writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Go Back");
    glPopMatrix();

}
void drawMenu_L(){
    int i; float angle;
    
    //background is white
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    //red circle
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(25 + cos(angle) * 13.0, 50 + sin(angle) * 20.0);
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(7.8, 90.0, 0.0);
    glScalef(0.025, 0.035, 0.035);
    writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Japan Joy");
    glPopMatrix();
    
    glRasterPos3f(11.0, 85.0, 0.0);
    writeBitmapString(GLUT_BITMAP_9_BY_15, "comes with soy sauce, ginger, and wasabi");
    
    //CHOOSE RAMEN SQUARE CHECKS
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 3; ++i){
        glVertex3f(10.0, 10.0, 0.0);
        glVertex3f(15.0, 10.0, 0.0);
        glVertex3f(15.0, 15.0, 0.0);
        glVertex3f(10.0, 15.0, 0.0);
    }
    glEnd();
    
    glPopMatrix();
    //--------------------------
    glPushMatrix();
    glTranslatef(18, 0, 0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 3; ++i){
        glVertex3f(10.0, 10.0, 0.0);
        glVertex3f(15.0, 10.0, 0.0);
        glVertex3f(15.0, 15.0, 0.0);
        glVertex3f(10.0, 15.0, 0.0);
    }
    glEnd();
    glPopMatrix();
    //--------------------------
    glPushMatrix();
    glTranslatef(2, -65, 0);
    
    glPushMatrix();
    glTranslatef(-23, 0, 0);
    if (spicy_ramen)
        drawX();
    glPopMatrix();
    
    if (orig_ramen)
        drawX();
    glPopMatrix();
    //--------------------------
    
    //INCLUDED SIDES, RADIO BUTTONS
    glColor3f(0.0, 0.0, 0.0);
    //SOY SAUCE
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {

        angle = 2 * PI * i / 30;
        glVertex2f(23 + cos(angle) * 2.0, 80 + sin(angle) * 2.0);
    }
    glEnd();
    //fill soysauce
    if(soy_sauce){
        glBegin(GL_POLYGON);
        for(i = 0; i < 30; ++i)
        {
            glColor3fv(gradient_soySauce [i%3]);
            angle = 2 * PI * i / 30;
            glVertex2f(23 + cos(angle) * 1.5, 80 + sin(angle) * 1.5);
        }
        glEnd();
    }
    
    //GINGER
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(30 + cos(angle) * 2.0, 80 + sin(angle) * 2.0);
    }
    glEnd();
    //filler ginger
    if(ginger){
        glColor3fv(gradient_ginger [i%2]);
        glBegin(GL_POLYGON);
        for(i = 0; i < 30; ++i)
        {
            angle = 2 * PI * i / 30;
            glVertex2f(30 + cos(angle) * 1.5, 80 + sin(angle) * 1.5);
        }
        glEnd();
    }
    
    //WASABI
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(38 + cos(angle) * 2.0, 80 + sin(angle) * 2.0);
    }
    glEnd();
    //filler wasabi
    if(wasabi){
        glColor3fv(gradient_wasabi[i%3]);
        glBegin(GL_POLYGON);
        for(i = 0; i < 30; ++i)
        {
            angle = 2 * PI * i / 30;
            glVertex2f(38 + cos(angle) * 1.5, 80 + sin(angle) * 1.5);
        }
        glEnd();
    }
    
    //GO BACK IN THE MIDDLE RED DOT
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(15.5, 50.0, 0.0);
    glScalef(0.025, 0.035, 0.035);
    writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Go Back");
    glPopMatrix();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(12.0, 10.5, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Spicy Ramen");
    
    glRasterPos3f(35.0, 10.5, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Original Ramen");
}
void drawMenu_D(){
    int i; float angle;
    
    //background is white
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    //star radio buttons
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 6; ++i)
    {
        angle = 4.8 * PI * i / 6;
        glVertex2f(10 + cos(angle) * 8.0, 30 + sin(angle) * 8.0);
    }
    glEnd();
    
    //filler for Dinner
    if(1){
        glColor3f(1.0, 0.97, 0.29);
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 6; ++i)
        {
            angle = 4.8 * PI * i / 6;
            glVertex2f(10 + cos(angle) * 8.0, 30 + sin(angle) * 8.0);
        }
        glEnd();
    }
    
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(7.8, 90.0, 0.0);
    glScalef(0.025, 0.035, 0.035);
    writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Indian Interest");
    glPopMatrix();
    
    glRasterPos3f(11.0, 85.0, 0.0);
    writeBitmapString(GLUT_BITMAP_9_BY_15, "comes with rice and naan");

}

void drawMenu(){
    if (breakfast){
        drawMenu_B();
    }
    if (lunch){
        glPushMatrix();
        //glTranslatef(0, 0, -5.0);
        
            drawMenu_L();
        glPopMatrix();
    }
    if  (dinner){
        home = 1;
        letsEat = 0;
        drawChoosePlate();
    }
}
// Drawing routine for first window.
void drawScene1(void)
{
    // Choose window.
    glutSetWindow(id1);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    //glLoadIdentity();
    
    if(!letsEat){
        drawChoosePlate();
    }
    else {
        drawMenu();
    }
    
    /*
     glRasterPos3f(20.0, 90.0, 0.0);
     writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Welcome to the Asian Cuisine");
    
    glRasterPos3f(10.0, 87.0, 0.0);
    writeBitmapString(GLUT_BITMAP_8_BY_13, "We have a selection of food");
    
    glRasterPos3f(10.0, 85.0, 0.0);
    writeBitmapString(GLUT_BITMAP_9_BY_15, "from Breakfast...");
    
    glRasterPos3f(10.0, 80.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "To Lunch...");
    
    glRasterPos3f(10.0, 70.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "To Dinner...");
    
    glRasterPos3f(10.0, 60.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Tocino");
    
    glRasterPos3f(10.0, 55.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Spam");
    
    glRasterPos3f(10.0, 45.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_10, "Milkfish");
    
    glPushMatrix();
    glTranslatef(10.0, 10.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glScalef(0.025, 0.025, 0.025);
    writeStrokeString(GLUT_STROKE_ROMAN, "to the left...");
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(40.0, 40.0, 0.0);
    glRotatef(-30.0, 0.0, 0.0, 1.0);
    glScalef(0.025, 0.025, 0.025);
    writeStrokeString(GLUT_STROKE_MONO_ROMAN, "take it back now ya'll");
    glPopMatrix();
     */
    
    /*glTranslatef(0.0, 0.0, -15.0);
    
    glScalef(1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glutWireTeapot(3.0);*/
    
    glFlush();
}

// Additional drawing components for second window.
void drawPlate_B(){

    float angle;
    int i;
    
    glColor3f(0.16, 0.2, 0.36);
    
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 85.0, plate_center + sin(angle) * 85.0);
    }
    glEnd();
    
    glColor3f(0.95, 0.65, 0.07);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 8 * PI * i / 30;
        glVertex2f(plate_center + cos(0.5*angle) * 80, plate_center + sin(0.5*angle) * 80);
    }
    glEnd();
    
    glColor3f(0.94, 0.33, 0.31);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 14 * PI * i / 30;
        glVertex2f(plate_center + cos(3*angle) * 74.38, plate_center + sin(3*angle) * 74.38);
    }
    glEnd();
    
    glColor3f(.98, 0.47, 0.13);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 64.0, plate_center + sin(angle) * 64.0);
    }
    glEnd();
    
    glColor3f(0.94, 0.81, 0.63);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 53.0, plate_center + sin(angle) * 53.0);
    }
    glEnd();
    
}
void drawBowl(){
    /*
    glPushMatrix();
    glTranslatef(75, 60, -70.0);
    drawRice();
    glPopMatrix();
    */
    float angle;
    int i, j;

    glColor3f(0.24, 0.21, 0.13);
    
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(plate_center - 33 + cos(angle) * 65.0, plate_center - 30 + sin(angle) * 65.0);
    }
    glEnd();
    /*
     glPushMatrix();
     float R = 52.0; // Radius of hemisphere.
     int p = 51; // Number of longitudinal slices.
     int q = 38; // Number of latitudinal slices.
     float Xangle = 90.0 +180;
     
     float cx = 0.0;
     float cy = 0.0;
     float cz = 0.0;
     
     glRotatef(Xangle, 1.0, 0.0, 0.0);
     
     glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
     // Array of latitudinal triangle strips, each parallel to the equator, stacked one
     // above the other from the equator to the north pole.
     for(j = 0; j < q; j++)
     {
     // One latitudinal triangle strip.
     glBegin(GL_TRIANGLE_STRIP);
     for(i = 0; i <= p; i++)
     {
     glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ) +cx,
     R * sin( (float)(j+1)/q * PI/2.0 ) +cy+10,
     R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI )+ cz );
     glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ) +cx,
     R * sin( (float)j/q * PI/2.0 ) + cy+10,
     R * cos( (float)j/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI )+ cz );
     }
     glEnd();
     }
     glPopMatrix();
     */

}
void drawSushiPlate(){
    glColor3f(.83, 0.09, 0.03);
    
    glBegin(GL_POLYGON);
        glVertex3f(120.0, 20.0, 0.0);
        glVertex3f(180.0, 20.0, 0.0);
        glVertex3f(180.0, 180.0, 0.0);
        glVertex3f(120.0, 180.0, 0.0);
    glEnd();
    
    glColor3f(0.13, 0.13, 0.19);
    glBegin(GL_POLYGON);
        glVertex3f(130.0, 30.0, 0.0);
        glVertex3f(170.0, 30.0, 0.0);
        glVertex3f(170.0, 170.0, 0.0);
        glVertex3f(130.0, 170.0, 0.0);
    glEnd();
}
void drawExtraPlate(){
    glColor3f(.69, 0.66, 0.56);
   
    glBegin(GL_POLYGON);
        glVertex3f(11.0, 130.0, 0.0);
        glVertex3f(111.0, 130.0, 0.0);
        glVertex3f(111.0, 180.0, 0.0);
        glVertex3f(11.0, 180.0, 0.0);
    glEnd();

}
void drawPlate_L(){

    drawBowl();
    
    glPushMatrix();
        glTranslatef(0.0,10.0,0.0);

        glPushMatrix();
            glTranslatef(13.0,0.0,0.0);
            //LONG RECTANGLE PLATE
            drawSushiPlate();
        glPopMatrix();
    
        //SOYSAUCE RECTANGLE
        drawExtraPlate();
    
    glPopMatrix();
}
void drawPlate_D(){
    
    float angle;
    int i;
    
    glColor3f(0.52, 0.05, 0.25);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 85.0, plate_center + sin(angle) * 85.0);
    }
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 14 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 75.0, plate_center + sin(angle) * 75.0);
    }
    glEnd();
    
    glColor3f(0.87, 0.84, 0.84);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 65.0, plate_center + sin(angle) * 65.0);
    }
    glEnd();
    
    
    glColor3f(.49, 0.57, 0.54);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
        angle = 8 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 60.0, plate_center + sin(angle) * 60.0);
    }
    glEnd();
    
    glColor3f(0.98, 0.91, 0.91);
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(plate_center + cos(angle) * 50.0, plate_center + sin(angle) * 50.0);
    }
    glEnd();
}

//  BREAKFAST
void drawEggs(){
    float eggx = 150;
    float eggy = 90;
    
    float orientx = 8;
    float orienty = 3;
    
    if (egg1){
    //EGG1
    drawEgg1();
    }
    
    if (egg2){
    //EGG2
    drawEgg2();
    }
}
void drawSpam(){
    glColor3f(0.94, 0.71, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(11.0, 130.0, 0.0);
    glVertex3f(111.0, 130.0, 0.0);
    glVertex3f(111.0, 180.0, 0.0);
    glVertex3f(11.0, 180.0, 0.0);
    glEnd();
    
    glPushMatrix();
    glTranslatef(-10.0, -10, 3);
    glBegin(GL_POLYGON);
    glVertex3f(11.0, 130.0, 0.0);
    glVertex3f(111.0, 130.0, 0.0);
    glVertex3f(111.0, 180.0, 0.0);
    glVertex3f(11.0, 180.0, 0.0);
    glEnd();
    glPopMatrix();
}
void drawTocino(){
    /*
     int i,j;
    int v,h = 10;
    float R = 10;
    float cx = 0;
    float cy = 0;
    float cz = 0;
    
    
    glColor3f(1.0, 0.0, 0.0);
    for (j=0; j<h; j++){
        glBegin(GL_POLYGON);
        for(i = 0; i <= v; i++){
            glVertex3f(R*(j+1)/3.0-16+cx,
                       R*cos(2.0 * (float)i/v * PI)+cy,
                       R*sin(2.0 * (float)i/v * PI)+cz);
            glVertex3f(R*j/3.0-16+cx,
                       R*cos(2.0 * (float)i/v * PI)+cy,
                       R*sin(2.0 * (float)i/v * PI)+cz);
        }
        glEnd();
    }
    
    glBegin(GL_POLYGON);
    glVertex3f(11.0, 130.0, 0.0);
    glVertex3f(111.0, 130.0, 0.0);
    glVertex3f(111.0, 180.0, 0.0);
    glVertex3f(11.0, 180.0, 0.0);
    glEnd();
     */
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(10.0, 60.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Sorry ran out of Tocino!");
    
}
void drawMilkfish(){
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(10.0, 60.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Sorry ran out of Milkfish!");
}

//LUNCH
void drawsoySauce(){

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    int i;
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        //glColor3f(1.0, 1.0, 0.80);
        glColor3fv(gradient_soySauce [i % 4]);
        glVertex3f(20.0, 20.0, 0.0);
        glColor3fv(gradient_soySauce [i % 2]);
        glVertex3f(68.0, 20.0, 0.0);
        glColor3fv(gradient_soySauce [i % 3]);
        glVertex3f(68.0, 68.0, 0.0);
        glColor3fv(gradient_soySauce [i % 5]);
        glVertex3f(20.0, 68.0, 0.0);
    
    }
    glEnd();
}
void drawWasabi(){
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    float angle; int i;
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        glColor3fv(gradient_wasabi [i%5]);
        angle = 2 * PI * i / 30;
        glVertex2f(65.0 + cos(angle) * 11.0, 108.0 + sin(angle) * 11.0);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        glColor3fv(gradient_wasabi [i%5]);
        angle = 2 * PI * i / 30;
        glVertex2f(75.0 + cos(angle) * 11.0, 103.0 + sin(angle) * 11.0);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        glColor3fv(gradient_wasabi [i%5]);
        angle = 2 * PI * i / 30;
        glVertex2f(85.0 + cos(angle) * 11.0, 108.0 + sin(angle) * 11.0);
    }
    glEnd();
}
void drawGinger(){
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    int i;
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        glColor3fv(gradient_ginger [i % 4]);
        glVertex3f(50.0, 120.0, 0.0);
        glColor3fv(gradient_ginger [i % 2]);
        glVertex3f(50.0, 150.0, 0.0);
        glColor3fv(gradient_ginger [i % 3]);
        glVertex3f(80.0, 120.0, 0.0);
        //glColor3fv(gradient_ginger [i % 5]);
        glVertex3f(80.0, 150.0, 0.0);
    }
    glEnd();
}
void drawSpicy(){
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    float angle; int i;
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        if (i<15)
            glColor3fv(gradient_ramen_red [i%2]);
        else
            glColor3fv(gradient_ramen_red [i%3]);
        angle = 2 * PI * i / 30;
        glVertex2f(75.0 + cos(angle) * 60.0, 80.0 + sin(angle) * 60.0);
    }
    glEnd();
}
void drawOrig(){
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    float angle; int i;
    glBegin(GL_POLYGON);
    for(i = 0; i < 30; ++i)
    {
        if (i<15)
            glColor3fv(gradient_ramen_yellow [i%2]);
        else
            glColor3fv(gradient_ramen_yellow [i%3]);
        angle = 2 * PI * i / 30;
        glVertex2f(75.0 + cos(angle) * 60.0, 80.0 + sin(angle) * 60.0);
    }
    glEnd();
}
void drawNoodle(){
    float t; // Angle parameter
    glLineWidth(3.0);
    
    if(spicy_ramen)
        glColor3f(0.96, 0.96, 0.96);
    else
        glColor3f(0.26, 0.13, 0.25);
    // Draw a helix.
    glBegin(GL_LINE_STRIP);
    for(t = -10 * PI; t <= 10 * PI; t += PI/20.0)
        glVertex3f(20 * cos(t), 20 * sin(t), t);
    glEnd();
    
    glLineWidth(1.0);
}
void drawNoodles(){
    glPushMatrix();
        glTranslatef(100, 86.5, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        drawNoodle();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(73, 80, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        drawNoodle();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(47,73.5, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        drawNoodle();
    glPopMatrix();
}


void drawBreakfast(){
    if (rice){
        glPushMatrix();
        glTranslatef(75, 60, -70.0);
        drawRice();
        glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(0, 0, -70.0);
    drawEggs();
    glPopMatrix();
    if(spam){
        glPushMatrix();
        glTranslatef(50, -10, -60.0);
        drawSpam();
        glPopMatrix();
    }
    if (tocino){
        glPushMatrix();
        glTranslatef(50, -10, -60.0);
            drawTocino();
        glPopMatrix();
    }
    if(milkfish){
        glPushMatrix();
        glTranslatef(50, 50, -70.0);
            drawMilkfish();
        glPopMatrix();
    }
    if(teapot){
        glColor3f(0.0, 0.0, 0.0);
        glPushMatrix();
        glTranslatef(100, 100, 0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glTranslatef(-100, -100, 0);
        
        glTranslatef(45, 10, -70);
        glutWireTeapot(38.0);
        glPopMatrix();
    }
}
void drawLunch(){
    if (soy_sauce){
        glPushMatrix();
        //glScalef(1.0, 1.0, 0);
        glTranslatef(42, 121, -70.0);
        drawsoySauce();
        glPopMatrix();
    }
    if(wasabi){
        glPushMatrix();
        glTranslatef(-36.8, 48, -70.0);
        drawWasabi();
        glPopMatrix();
    }
    if(ginger){
        glPushMatrix();
        glTranslatef(-35, 48, -70.0);
        drawGinger();
        glPopMatrix();
    }
    if(spicy_ramen){
        glPushMatrix();
        glTranslatef(-8, -9, -70.0);
        drawSpicy();
        drawNoodles();
        glPopMatrix();
    }
    if(orig_ramen){
        glPushMatrix();
        glTranslatef(-8, -9, -70.0);
        drawOrig();
        drawNoodles();
        glPopMatrix();
    }
}
void drawPlate(){
    
    if(breakfast) {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glPushMatrix();
            glTranslatef(0.0, 0.0, -85.0);
            if (changePlate)
                drawPlate_D();
            else
                drawPlate_B();
        glPopMatrix();
    }
    if(lunch){
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glPushMatrix();
            glTranslatef(0.0, 0.0, -85.0);
            drawPlate_L();
        glPopMatrix();
    }
    if (dinner){
        glClearColor(0.0, 1.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glPushMatrix();
        glTranslatef(50.0, 50.0, -85.0);
        glRotatef(45.0, 0.0, 0.0, 1.0);
        glScalef(0.05, 0.05, 0.05);
        writeStrokeString(GLUT_STROKE_ROMAN, "JUST KIDDING! NO ONE LIKES SURPRISE DINNERS.");
        glPopMatrix();
        if(letsEat){
        glClearColor(0.0, 1.0, 0.0, 0.0);
        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glTranslatef(50.0, 190.0, -85.0);
        glRotatef(-45.0, 0.0, 0.0, 1.0);
        glScalef(0.08, 0.08, 0.08);
        writeStrokeString(GLUT_STROKE_ROMAN, "SERIOUSLY THERE IS NO DINNER.");
        glPopMatrix();
        }
    }
}
void drawFood(){
    if (breakfast)
        drawBreakfast();
    if (lunch){
        drawLunch();
        /*
        //shrimp tempura tail?
        glBegin(GL_POLYGON);
        glVertex3f(20.0, 40.0, 0.0);
        glVertex3f(20.0, 80.0, 0.0);
        glVertex3f(40.0, 40.0, 0.0);
        glVertex3f(40.0, 80.0, 0.0);
        glEnd();
         
         or
         
         glBegin(GL_POLYGON);
         glVertex3f(50.0, 120.0, 0.0);
         glVertex3f(50.0, 150.0, 0.0);
         glVertex3f(80.0, 120.0, 0.0);
         glVertex3f(80.0, 150.0, 0.0);
         glEnd();
        */
    }
    if (dinner){
    }
}
// Drawing routine for second window.
void drawScene2(void)
{
    // Choose window.
    glutSetWindow(id2);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
        glTranslatef(100,100,0);
        glRotatef(rangle, 0, 0, 1);
        glTranslatef(-100,-100,0);
        drawPlate();
        if(letsEat){
            glPushMatrix();
                if(big)
                    glScalef(1.0, 0.0, 0);
                if(small)
                    glScalef(0.99, 0.99, 0);
                drawFood();
            glPopMatrix();
        }
    glPopMatrix();
    
    glFlush();
}

//ID==1 mouse countrol
void mouseControl(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        y = height - y; // Correct from mouse to OpenGL co-ordinates.
        cout << x << "----after---"<<y <<endl;

        if(!letsEat){
            rangle = 0;
            // Click Breakfast Radio Triangle
            if ( x < 98 && x > 40 && y < 645 && y > 610 ) {
                breakfast = 1;
                lunch = 0;
                dinner = 0;
                letsEat = 0;
            }
        
            // Click Lunch Radio Triangle
            if ( x < 98 && x > 40 && y < 530 && y > 490 ) {
                breakfast = 0;
                lunch = 1;
                dinner = 0;
                letsEat = 0;
            }
        
            // Click Dinner Radio Triangle
            if ( x < 98 && x > 40 && y < 420 && y > 360 ) {
                breakfast = 0;
                lunch = 0;
                dinner = 1;
                letsEat = 0;
            }
        
            // Click Lets Eat Radio Button
            if ( x < 450 && x > 130 && y < 350 && y > 280 ) {
                letsEat = 1;
                home = 0;
            }
        }
        else{
            if (breakfast) {
                // Click Spam Radio Sun
                if ( x < 140 && x > 45 && y < 630 && y > 560 ) {
                    tocino = 0;
                    spam = !spam;
                    milkfish = 0;
                }
                
                // Click Milkfish Radio Sun
                if ( x < 340 && x > 140 && y < 540 && y > 480 ) {
                    tocino = 0;
                    spam = 0;
                    milkfish = !milkfish;
                }
                
                // Click Tocino Radio Sun
                if ( x < 140 && x > 50 && y < 450 && y > 390 ) {
                    tocino = !tocino;
                    spam = 0;
                    milkfish = 0;
                }
                
                //Click Rice Check
                if ( x < 360 && x > 280 && y < 720 && y > 645 ) {
                    rice = !rice;
                }
                //Click Egg1 Check
                if ( x < 500 && x > 400 && y < 710 && y > 650 ) {
                    egg1 = !egg1;
                }
                //Click Egg2 Check
                if ( x < 470 && x > 400 && y < 650 && y > 600 ) {
                    egg2 = !egg2;
                }
                //mango
                    //mango = !mango;
                //Click Go Back
                if ( x < 430 && x > 130 && y < 350 && y > 230 ) {
                    letsEat = 0;
                    home = 1;
                }
            }
            if (lunch){
                // Click Soysauce Radio Button
                if ( x < 300 && x > 230 && y < 710 && y > 650 ) {
                    soy_sauce = !soy_sauce;
                }
                //Click Ginger Radio Button
                if ( x < 400 && x > 320 && y < 710 && y > 650 ) {
                    ginger = !ginger;
                }
                //Click Wasabi Button
                if ( x < 480 && x > 400 && y < 710 && y > 650 ) {
                    wasabi = !wasabi;
                }
                
                //Click Spicy Check
                if ( x < 140 && x > 50 && y < 330 && y > 270 ) {
                    spicy_ramen = 1;
                    orig_ramen = 0;
                }
                //Click Original Check
                if ( x < 400  && x > 300 && y < 330 && y > 250 ) {
                    orig_ramen = 1;
                    spicy_ramen = 0;
                }
                
                //Go back Button
                if ( x < 450  && x > 130 && y < 650 && y > 390 ) {
                    letsEat = 0;
                    home = 1;
                }
            }
        }
    }
    
    glutSetWindow(id1);
    glutPostRedisplay();
    
    glutSetWindow(id2);
    glutPostRedisplay();
    
}

// Initialization routine for first window.
void setup1(void)
{
    // Black background.
    glClearColor(1.0, 1.0, 1.0, 0.0);
}
// Initialization routine for second window.
void setup2(void)
{
    // Green background.
    glClearColor(1.0, 1.0, 1.0, 0.0);
}
// Reshape routine for first window.
void resize1(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Non-square aspect ratio squashes the square.
    glOrtho(0.0, 50.0, 0.0, 100.0, -1.0, 10.0);
    //glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
// Reshape routine for second window.
void resize2(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(0.0, 200.0, 0.0, 200.0, 5, 100.0);
    //glFrustum(-1.0, 8.0, -1.0, 8.0, 3, 100.0);
    //glFrustum(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    
    // Pass the size of the OpenGL window to globals.
    width = w;
    height = h;
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard input processing routine shared by both windows.
void keyInput(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

// The top menu callback function.
void top_menu(int id)
{
    if (id==1)
        exit(0);
    if (id==2){
        rangle= rangle + 90;
    }
    glutSetWindow(2);
    glutPostRedisplay();
}
// The sub-menu callback function(s)
void size_menu(int id){
    if (id==3){
        small = 1;
        big = 0;
        reg = 0;
        //make main course smaller
    }
    if (id==4){
        //make main course larger
        small = 0;
        big = 1;
        reg = 0;
    }
    if (id==5){
        //make main course original size
        small = 0;
        big = 0;
        reg = 1;
    }
    glutSetWindow(2);
    glutPostRedisplay();
}
void color_menu(int id){
    if (id==6)
    {
        changePlate = 1;
    }
    if (id==7)
    {
        changePlate = 0;
    }
    glutSetWindow(2);
    glutPostRedisplay();
}
// Routine to make the menu.
void makeMenu(void)
{
    // The sub-menu is created first (because it should be visible when the top
    // menu is created): its callback function is registered and menu entries added.
    int sub_menuC;
    sub_menuC = glutCreateMenu(color_menu);
    glutAddMenuEntry("Second Color Scheme", 6);
    glutAddMenuEntry("Original Color Scheme",7);
    
    int sub_menuS;
    sub_menuS = glutCreateMenu(size_menu);
    glutAddMenuEntry("Small Main Course", 3);
    glutAddMenuEntry("Big Main Course",4);
    glutAddMenuEntry("Original Size Main Course",5);
    
    // The top menu is created: its callback function is registered and menu entries,
    // including a submenu, added.
    
        glutCreateMenu(top_menu);
        glutAddSubMenu("Color", sub_menuC);
        glutAddSubMenu("Size", sub_menuS);
        glutAddMenuEntry("Rotate", 2);
        glutAddMenuEntry("Quit",1);
    
    
    // The menu is attached to a mouse button.
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Main routine.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    
    // First top-level window definition.
    glutInitWindowSize(580, 580);
    glutInitWindowPosition(38, 100);
    
    // Create the first window and return id.
    id1 = glutCreateWindow("Menu");
    
    // Initialization, display, and other routines of the first window.
    setup1();
    glutDisplayFunc(drawScene1);
    glutReshapeFunc(resize1);
    glutKeyboardFunc(keyInput); // Routine is shared by both windows.
    
    glutMouseFunc(mouseControl);
    
    // Second top-level window definition.
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(623, 3000);
    
    // Create the second window and return id.
    id2 = glutCreateWindow("Plate");
    
    // Initialization, display, and other routines of the second window.
    setup2();
    glutDisplayFunc(drawScene2);
    glutReshapeFunc(resize2);
    glutKeyboardFunc(keyInput); // Routine is shared by both windows.
    
    // Make menu.
    makeMenu();
    
    glutMainLoop();
    
    return 0;   
}
