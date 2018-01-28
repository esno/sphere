#ifndef SPHERE_H
#define SPHERE_H

#include <stdbool.h>
#include <X11/Xlib.h>

#include "composite.h"

typedef struct {
  Display *dpy;
  struct {
    int count;
  } screens;
} sphere_xorg_t;

typedef struct {
  sphere_xorg_t *X;
  sphere_composite_t *composite;
} sphere_mgr_t;

bool sphere_init(sphere_mgr_t *sphere);

#endif
