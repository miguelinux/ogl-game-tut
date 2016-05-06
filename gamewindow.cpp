#include "gamewindow.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include <stb_image.h>


typedef struct {
	GLfloat positionCoordinates[3];
	GLfloat textureCoordinates[2];
} VertexData;

#define SQUARE_SIZE 100.0f

VertexData vertices[] = {
	{{0.0f, 0.0f, 0.0f},               {0.0f, 1.0f}},
	{{SQUARE_SIZE, 0.0f, 0.0f},        {1.0f, 1.0f}},
	{{SQUARE_SIZE, SQUARE_SIZE, 0.0f}, {1.0f, 0.0f}},
	{{0.0f, SQUARE_SIZE, 0.0f},        {0.0f, 0.0f}}
};

void GameWindow::setRunning(bool newRunning)
{
	_running = newRunning;
}

bool GameWindow::getRunning()
{
	return _running;
}

GLuint GameWindow::loadAndBufferImage(const char *filename)
{
	int width, height, bpp /* 8-bit component per pixel */;
        unsigned char *data = NULL;
	GLuint textureBufferID;

	data = stbi_load(filename, &width, &height, &bpp, 0);

	if (data == NULL)
		return 0;

	glGenTextures(1, &textureBufferID);
	glBindTexture(GL_TEXTURE_2D, textureBufferID);

	/* glTexImage2D - specify a two-dimensional texture image
         * void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format,
         *               GLenum type, const GLvoid * data);
	 */
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);

	stbi_image_free(data);

	return textureBufferID;
}

GameWindow::GameWindow(bool running, GLFWwindow* window): _running(running),
	_vertexBufferID(0)
{
	_window = window;
	/* glClearColor - specify clear values for the color buffers
	   void glClearColor(GLfloat red, GLfloat green, GLfloat blue,
			     GLfloat alpha); */
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	/* This function retrieves the size, in pixels, of the framebuffer of
	 * the specified window. */
	glfwGetFramebufferSize(window, &_width, &_height);
	glViewport(0, 0, _width, _height);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* void glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
			GLdouble top, GLdouble nearVal, GLdouble farVal); */
	glOrtho(0.0, _width, 0.0, _height, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	glGenBuffers(1, &_vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
	/* creates and initializes a buffer object's data store */
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid *) offsetof(VertexData,positionCoordinates));

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, sizeof(VertexData), (GLvoid *) offsetof(VertexData, textureCoordinates));

	_textureBufferID = loadAndBufferImage("nave.png");
}

void GameWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_QUADS,0,4);

	/* Swap front and back buffers */
	glfwSwapBuffers(_window);
}

void GameWindow::update()
{
}
