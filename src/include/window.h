#ifndef SPHERE_WINDOW_H
#define SPHERE_WINDOW_H

#include <X11/Xlib.h>

typedef struct {
  int x;
  int y;
  int w;
  int h;
} sphere_window_t;

sphere_window_t *sphere_window_gather_facts(Display *dpy, Window w);

#endif
