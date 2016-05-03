#include "gamewindow.h"

typedef struct {
	GLfloat positionCoordinates[3];
	GLfloat textureCoordinates[2];
} VertexData;

#define SQUARE_SIZE 100.0f

VertexData vertices[] = {
	{{0.0f, 0.0f, 0.0f},               {0.0f, 0.0f}},
	{{SQUARE_SIZE, 0.0f, 0.0f},        {1.0f, 0.0f}},
	{{SQUARE_SIZE, SQUARE_SIZE, 0.0f}, {1.0f, 1.0f}},
	{{0.0f, SQUARE_SIZE, 0.0f},        {0.0f, 1.0f}}
};

void GameWindow::setRunning(bool newRunning)
{
	_running = newRunning;
}

bool GameWindow::getRunning()
{
	return _running;
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

}

void GameWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
	glDrawArrays(GL_QUADS,0,4);

	/* Swap front and back buffers */
	glfwSwapBuffers(_window);
}

void GameWindow::update()
{
}
