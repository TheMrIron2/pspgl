#include "pspgl_internal.h"
#include "pspgl_buffers.h"


EGLBoolean eglSwapBuffers (EGLDisplay dpy, EGLSurface draw)
{
	struct pspgl_surface *s = (struct pspgl_surface *) draw;
	struct pspgl_buffer *t;

	t = s->color_front;
	s->color_front = s->color_back;
	s->color_back = t;

	return __pspgl_vidmem_setup_write_and_display_buffer(s);
}

void *eglGetPresentedFrameBufferPSP(EGLSurface draw, EGLint *stride, EGLint *pixelFormat)
{
	struct pspgl_surface *s = (struct pspgl_surface *) draw;

	if (!s || !(s->flags & SURF_DISPLAYED))
		return NULL;

	if (stride)
		*stride = s->pixelperline;
	if (pixelFormat)
		*pixelFormat = s->pixfmt;

	return s->color_front->base;
}
