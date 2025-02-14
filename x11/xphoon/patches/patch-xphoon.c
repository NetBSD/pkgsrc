$NetBSD: patch-xphoon.c,v 1.2 2025/02/14 07:00:15 vins Exp $

* Add Xrandr support.
* Silence warnings about missing preprocessor defined macros.
* Do not require a tty when forking to background.

--- xphoon.c.orig	2014-08-04 21:57:59.000000000 +0000
+++ xphoon.c
@@ -23,15 +23,19 @@
 ** SUCH DAMAGE.
 */
 
+#include "stddef.h"
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
 #include <math.h>
+#include <errno.h>
 #include <sys/ioctl.h>
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/Xatom.h>
+#include <X11/extensions/Xrandr.h>
 #include "vroot.h"
 #include "astro.h"
 #include "date_parse.h"
@@ -190,13 +194,20 @@ usage:
 	(void) fflush( stdout );
 
 	/* Go stealth (ditch our controlling tty). */
+#ifdef TIOCNOTTY
 	tty = open( "/dev/tty", 0 );
 	if ( tty < 0 )
 	    {
-	    (void) fprintf( stderr, "%s: ", argv0 );
-	    perror( "/dev/tty open" );
-	    exit( 1 );
-	    }
+	    if ( errno != ENXIO )
+		{
+		(void) fprintf( stderr, "%s: ", argv0 );
+		perror( "/dev/tty open" );
+		exit( 1 );
+		}
+	}
+#else
+	setsid();
+#endif
 	else
 	    {
 	    if ( ioctl( tty, TIOCNOTTY, 0 ) < 0 )
@@ -236,6 +247,10 @@ usage:
 
 /* xinit - initialize X stuff */
 
+struct crtcinfo {
+    int x, y, w, h;
+    };
+
 static Display* display;
 static int screen;
 static Window root;
@@ -244,11 +259,14 @@ static GC onegc;
 static GC zerogc;
 static GC copygc;
 static GC clipgc;
+static int hasrandr, ncrtc;
+struct crtcinfo *crtcs;
 
 static void
 xinit( char* display_name )
     {
     Pixmap temp_pixmap;
+    int i, j;
 
     display = XOpenDisplay( display_name );
     if ( display == (Display*) 0 )
@@ -260,8 +278,23 @@ xinit( char* display_name )
 	}
     screen = DefaultScreen( display );
     root = DefaultRootWindow( display );
-    root_w = DisplayWidth( display, screen );
-    root_h = DisplayHeight( display, screen );
+    hasrandr = XRRQueryExtension( display, &i, &j );
+    if ( ! hasrandr )
+	{
+	root_w = DisplayWidth( display, screen );
+	root_h = DisplayHeight( display, screen );
+	ncrtc = 1;
+	crtcs = malloc( sizeof( struct crtcinfo ) );
+	if ( crtcs == NULL )
+	    {
+	    (void) fprintf( stderr, "%s: couldn't allocate crtc", argv0 );
+	    exit( 1 );
+	    }
+	crtcs[0].x = 0;
+	crtcs[0].y = 0;
+	crtcs[0].w = root_w;
+	crtcs[0].h = root_h;
+	}
     temp_pixmap = XCreatePixmap( display, root, 1, 1, 1 );
     onegc = XCreateGC( display, temp_pixmap, 0, (XGCValues*) 0 );
     XSetForeground( display, onegc, 1L );
@@ -278,6 +311,52 @@ xinit( char* display_name )
     XSetBackground( display, clipgc, WhitePixel( display, screen ) );
     }
 
+static void
+xrrinit( void )
+    {
+    XRRScreenResources *sr;
+    XRRCrtcInfo *ci;
+    int i;
+
+    if ( ! hasrandr )
+	return;
+    root_w = DisplayWidth( display, screen );
+    root_h = DisplayHeight( display, screen );
+    sr = XRRGetScreenResources( display, root );
+    ncrtc = sr->ncrtc;
+    crtcs = malloc( sizeof( struct crtcinfo ) * ncrtc );
+    if ( crtcs == NULL )
+	{
+	(void) fprintf( stderr, "%s: couldn't allocate crtc", argv0 );
+	exit( 1 );
+	}
+    memset( crtcs, 0, sizeof( struct crtcinfo ) * ncrtc);
+    for ( i = 0; i < ncrtc; i++ )
+	{
+	ci = XRRGetCrtcInfo( display, sr, sr->crtcs[i] );
+	if ( ci == NULL )
+	    continue;
+	if ( ci->noutput != 0 )
+	    {
+	    crtcs[i].x = ci->x;
+	    crtcs[i].y = ci->y;
+	    crtcs[i].w = ci->width;
+	    crtcs[i].h = ci->height;
+	    }
+	XRRFreeCrtcInfo( ci );
+	}
+    XRRFreeScreenResources( sr );
+    }
+
+static void
+xrrcleanup( void )
+    {
+    if ( ! hasrandr )
+	return;
+    free( crtcs );
+    crtcs = NULL;
+    }
+
 
 /* make_star_tiles - make random star tiles */
 
@@ -518,6 +597,8 @@ set_root( int bits_w, int bits_h, unsign
 	display, mask_bitmap, onegc, cx - r + 2, cy - r + 2,
 	r * 2 - 3, r * 2 - 3, 0, 360 * 64 );
 
+    xrrinit();
+
     /* Make the root pixmap. */
     root_pixmap = XCreatePixmap(
 	display, root, root_w, root_h, DefaultDepth( display, screen ) );
@@ -545,13 +626,20 @@ set_root( int bits_w, int bits_h, unsign
 	}
 
     /* Put the moon into the stars. */
-    x = ( root_w - bits_w ) / 2;
-    y = ( root_h - bits_h ) / 2;
-    XSetClipMask( display, clipgc, mask_bitmap );
-    XSetClipOrigin( display, clipgc, x, y );
-    XCopyPlane(
-	display, moon_bitmap, root_pixmap, clipgc, 0, 0, bits_w, bits_h, x, y,
-	1 );
+    for ( i = 0; i < ncrtc; i++ )
+	{
+	if ( crtcs[i].w == 0 )
+	    continue;
+	x = crtcs[i].x + ( ( crtcs[i].w - bits_w ) / 2 );
+	y = crtcs[i].y + ( ( crtcs[i].h - bits_h ) / 2 );
+	XSetClipMask( display, clipgc, mask_bitmap );
+	XSetClipOrigin( display, clipgc, x, y );
+	XCopyPlane(
+	    display, moon_bitmap, root_pixmap, clipgc, 0, 0, bits_w, bits_h,
+	    x, y, 1 );
+	}
+
+    xrrcleanup();
 
     /* And set the root. */
     XSetWindowBackgroundPixmap( display, root, root_pixmap );
@@ -585,6 +673,8 @@ cleanup( void )
     if ( star_tiles_made )
 	for ( i = 0; i < NUM_TILES; ++i )
 	    XFreePixmap( display, star_tile[i] );
+    if ( ! hasrandr )
+	free( crtcs );
     XFreeGC( display, onegc );
     XFreeGC( display, zerogc );
     XFreeGC( display, copygc );
