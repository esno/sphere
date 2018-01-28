#include <stdlib.h>
#include <X11/Xlib.h>

#include "window.h"

sphere_window_t *sphere_window_gather_facts(Display *dpy, Window w)
{
  XWindowAttributes attr;
  sphere_window_t *window = malloc(sizeof(sphere_window_t));

  if(!window)
    return NULL;

  XGetWindowAttributes(dpy, w, &attr);
  window->x = attr.x;
  window->y = attr.y;
  window->w = attr.width;
  window->h = attr.height;

  return window;
}
