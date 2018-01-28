#ifndef SPHERE_COMPOSITE_H
#define SPHERE_COMPOSITE_H

#include <X11/Xlib.h>

#define SPHERE_COMP_VERSION_MAJOR 0
#define SPHERE_COMP_VERSION_MINOR 4

typedef struct {
  int error_base;
  int event_base;
  struct {
    int major;
    int minor;
  } version;
} sphere_composite_t;

sphere_composite_t *sphere_composite_init(Display *dpy);

#endif
