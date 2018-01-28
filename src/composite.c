#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <X11/Xlib.h>
#include <X11/extensions/Xcomposite.h>

#include "composite.h"

sphere_composite_t *sphere_composite_init(Display *dpy)
{
  sphere_composite_t *c = malloc(sizeof(sphere_composite_t));
  bool composite_check;

  if(!c)
    return NULL;

  memset(c, 0, sizeof(sphere_composite_t));
  composite_check = XCompositeQueryExtension(
    dpy,
    &c->event_base,
    &c->error_base);

  if(!composite_check)
    return NULL;

  c->version.major = SPHERE_COMP_VERSION_MAJOR;
  c->version.minor = SPHERE_COMP_VERSION_MINOR;
  XCompositeQueryVersion(
    dpy,
    &c->version.major,
    &c->version.minor);

  return c;
}

void sphere_composite_redirect(Display *dpy, int screen_count)
{
  int i;

  for(i = 0; i < screen_count; ++i)
  {
    XCompositeRedirectSubwindows(
      dpy,
      RootWindow(dpy, i),
      CompositeRedirectAutomatic
    );
  }
}
