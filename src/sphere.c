#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <X11/Xlib.h>

#include "composite.h"
#include "sphere.h"

bool sphere_init(sphere_mgr_t *sphere)
{
  sphere_xorg_t *X = malloc(sizeof(sphere_xorg_t));
  sphere_composite_t *c;

  if(!X)
  {
    fprintf(stderr, "Cannot allocate memory for sphere\n");
    return false;
  }

  X->dpy = XOpenDisplay(NULL);

  if(!X->dpy)
  {
    fprintf(stderr, "cannot open X display session\n");
    return false;
  }

  X->screens.count = ScreenCount(X->dpy);
  fprintf(stdout, "Detected %d screens\n", X->screens.count);

  c = sphere_composite_init(X->dpy);

  if(!c)
  {
    fprintf(stderr, "Xorg Composite Extension is missing\n");
    return false;
  }

  fprintf(stdout, "X composite extension version %d.%d\n",
    c->version.major,
    c->version.minor);

  sphere->X = X;
  sphere->composite = c;

  return true;
}

int main()
{
  sphere_mgr_t sphere;

  memset(&sphere, 0, sizeof(sphere_mgr_t));
  sphere_init(&sphere);

  return 0;
}
