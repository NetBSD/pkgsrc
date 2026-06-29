$NetBSD: patch-Clock.c,v 1.4 2026/06/29 07:27:32 wiz Exp $

https://gitlab.freedesktop.org/xorg/app/xclock/-/merge_requests/27

--- Clock.c.orig	2026-06-27 20:18:51.000000000 +0000
+++ Clock.c
@@ -607,7 +607,7 @@ XmuCvtStringToXftShape(Display * dpy,
     XftShape shape;
     int points_allocated = 0;
     int count = 0;
-#ifndef NO_I18N
+#if !defined(NO_I18N) && defined(HAVE_USELOCALE)
     locale_t c_loc = newlocale(LC_NUMERIC_MASK, "C", NULL);
     locale_t old_loc = uselocale(c_loc);
 #endif
@@ -622,7 +622,7 @@ XmuCvtStringToXftShape(Display * dpy,
             XmuCvtStringToXftShape_Assert(count % 3 == 0,
                 "Number of points must be divisible by three");
             shape.npoints = count;
-#ifndef NO_I18N
+#if !defined(NO_I18N) && defined(HAVE_USELOCALE)
             uselocale(old_loc);
             freelocale(c_loc);
 #endif
@@ -708,7 +708,7 @@ XmuCvtStringToXftShape(Display * dpy,
                         "cvtStringToXftShape", "wrongParameters", "XtToolkitError",
                         msgout, (String *) NULL, (Cardinal *) 0);
         if (shape.points) free(shape.points);
-#ifndef NO_I18N
+#if !defined(NO_I18N) && defined(HAVE_USELOCALE)
         uselocale(old_loc);
         freelocale(c_loc);
 #endif
