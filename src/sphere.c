#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <X11/Xlib.h>
#include <X11/extensions/Xcomposite.h>

#define SPHERE_COMP_VERSION_MAJOR 0
#define SPHERE_COMP_VERSION_MINOR 4

typedef struct {
  Display *dpy;
  struct {
    int error_base;
    int event_base;
    struct {
      int major;
      int minor;
    } version;
  } composite;
} sphere_mgr_t;

bool sphere_new_session(sphere_mgr_t *sphere)
{
  bool comp;
  sphere->dpy = XOpenDisplay(NULL);

  if(!sphere->dpy)
  {
    fprintf(stderr, "cannot open X display session\n");
    return false;
  }

  comp = XCompositeQueryExtension(
    sphere->dpy,
    &sphere->composite.event_base,
    &sphere->composite.error_base);

  if(!comp)
  {
    fprintf(stderr, "X composite extension not available\n");
    return false;
  }

  sphere->composite.version.major = SPHERE_COMP_VERSION_MAJOR;
  sphere->composite.version.minor = SPHERE_COMP_VERSION_MINOR;
  XCompositeQueryVersion(
    sphere->dpy,
    &sphere->composite.version.major,
    &sphere->composite.version.minor);

  fprintf(stdout, "X composite extension version %d.%d\n",
    sphere->composite.version.major,
    sphere->composite.version.minor);

  return true;
}

int main()
{
  sphere_mgr_t *sphere = malloc(sizeof(sphere_mgr_t));

  memset(sphere, 0, sizeof(sphere_mgr_t));
  sphere_new_session(sphere);

  return 0;
}
