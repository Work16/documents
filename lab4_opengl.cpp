// lab4_opengl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h> 
#include <glaux.h>
#include<iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


int LoadGLTextures();
int LoadGLTexture(GLuint texture, char *Filename);

struct game_object {
	float x;
	float y;
	float size;
};

float EGIK_SIZE = 0.1;
float APPLE_SIZE = 0.05;
int APPLE_COUNT = 10;

GLuint	egic_texture = 0;
GLuint	apple_texture = 0;	


game_object* egik;
std::vector<game_object*> apples;

float getRandAppleXY() {
 return (100 - APPLE_SIZE*100 - rand() % 200) / 100;
}

void initGameObjects() {
	egik = new game_object;
	egik->x = 0;
	egik->y = 0;
	egik->size = EGIK_SIZE;

	srand(time(NULL));

	for (int i = 0; i < APPLE_COUNT; i++)
	{
		game_object* apple = new game_object;
		apple->x = getRandAppleXY();
		apple->y = getRandAppleXY();
		apple->size = APPLE_SIZE;
		apples.push_back(apple);
	}
}
/*void PrintStroka(float X, float Y, char* str)
{
	//устанавливаем позицию в то место где будем выводить текст 

	glRasterPos2f(X, Y);
	
	//читаем строку текста пока она не закончиться 
	while (*str)
	{
		//вызываем функцию рисования символа 
		glutBitmapCharacter
			(
				GLUT_BITMAP_TIMES_ROMAN_10, //шрифт и размер 10 
				*str //текущий символ для вывода на экран 
			);
		//выбираем следующий символ 
		str++;
	}
}*/
void checkEatApple()
{
	for (int i = 0; i < apples.size(); i++)
	{
		game_object* apple = apples.at(i);

		if (apple->x + apple->size <= egik->x + egik->size &&
			apple->x - apple->size >= egik->x - egik->size &&
			apple->y + apple->size <= egik->y + egik->size &&
			apple->y - apple->size >= egik->y - egik->size)
		{
			apples.erase(apples.begin() + i);
			std::cout << "\a";
		//	if (apples.empty())
//				PrintStroka(0, 0, "You Win!");
			//return;
		}
	}
}

void drawEgik()
{


	glBindTexture(GL_TEXTURE_2D, egic_texture);


	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	//glColor3f(1.0f, 0.0f, 1.0f); // Red

	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(egik->x - egik->size, egik->y - egik->size);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(egik->x + egik->size, egik->y - egik->size);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(egik->x + egik->size, egik->y + egik->size);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(egik->x - egik->size, egik->y + egik->size);


	glEnd();
}

void drawApple()
{
	glBindTexture(GL_TEXTURE_2D, apple_texture);

	glBegin(GL_QUADS);              
	for (int i = 0; i < apples.size(); i++)
	{
		game_object* apple = apples.at(i);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(apple->x - apple->size, apple->y - apple->size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(apple->x + apple->size, apple->y - apple->size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(apple->x + apple->size, apple->y + apple->size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(apple->x - apple->size, apple->y + apple->size);
	}
	glEnd();
}

void display() {

	if (egic_texture == 0) {
		LoadGLTextures();
	}

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);

	drawApple();
	drawEgik();


	glFlush(); 
}


void specialKeys(int key, int x, int y) {
	switch (key) {

	case GLUT_KEY_LEFT:
	{
		egik->x -= egik->size;
		if (egik->x < -1.0)
			egik->x = -1.0;
		break;
	};
	case GLUT_KEY_UP:
			{
				egik->y += egik->size;
				if (egik->y > 1.0)
					egik->y = 1.0;
				break;
	};
	case GLUT_KEY_RIGHT:
	{
		egik->x += egik->size;
		if (egik->x > 1.0)
			egik->x = 1.0;
		break;
	};
	case GLUT_KEY_DOWN:
	{
		egik->y -= egik->size;
		if (egik->y <- 1.0)
			egik->y = -1.0;
		break;
	}

	}

	checkEatApple();

	glutPostRedisplay();
}


int main(int argc, char** argv) {

	initGameObjects();
	

	glutInit(&argc, argv); 

	glutInitWindowSize(800, 800);   
	glutInitWindowPosition(20, 0); 
	glutCreateWindow("Laba OpenGL"); 
	glutDisplayFunc(display); 
	glutSpecialFunc(specialKeys);
	glutMainLoop();         
	return 0;
}

AUX_RGBImageRec *LoadBMP(char *Filename)				// Loads A Bitmap Image
{
	FILE *File = NULL;									// File Handle

	if (!Filename)										// Make Sure A Filename Was Given
	{
		return NULL;									// If Not Return NULL
	}

	File = fopen(Filename, "r");							// Check To See If The File Exists

	if (File)											// Does The File Exist?
	{
		fclose(File);									// Close The Handle
		return auxDIBImageLoad(Filename);				// Load The Bitmap And Return A Pointer
	}

	return NULL;										// If Load Failed Return NULL
}

int LoadGLTextures()
{
	int Status = FALSE;
	glGenTextures(1, &egic_texture);
	Status = LoadGLTexture(egic_texture, "../Data/egik.bmp");
	if (!Status)
		return Status;
	glGenTextures(1, &apple_texture);
	Status = LoadGLTexture(apple_texture, "../Data/apple.bmp");

	return Status;
}

int LoadGLTexture(GLuint texture, char *Filename)									// Load Bitmaps And Convert To Textures
{
	int Status = FALSE;									// Status Indicator

	AUX_RGBImageRec *TextureImage[1];					// Create Storage Space For The Texture

	memset(TextureImage, 0, sizeof(void *) * 1);           	// Set The Pointer To NULL

															// Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
	if (TextureImage[0] = LoadBMP(Filename))
	{
		Status = TRUE;									// Set The Status To TRUE

		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	if (TextureImage[0])									// If Texture Exists
	{
		if (TextureImage[0]->data)							// If Texture Image Exists
		{
			free(TextureImage[0]->data);					// Free The Texture Image Memory
		}

		free(TextureImage[0]);								// Free The Image Structure
	}

	return Status;										// Return The Status
}
