#ifndef MYGLFW3_H
#define MYGLFW3_H

/* Copied from GLFW/glfw3.h */
/* If we are on Windows, we want a single define for it.
 */
#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__))
 #define _WIN32
#endif /* _WIN32 */

#ifdef _WIN32
  #define GLEW_STATIC
  #include <GL/glew.h>
#else
  /* To use glGenBuffers and othres */
  #define GL_GLEXT_PROTOTYPES
  #define GLFW_INCLUDE_GLEXT
#endif
#include <GLFW/glfw3.h>

#endif
