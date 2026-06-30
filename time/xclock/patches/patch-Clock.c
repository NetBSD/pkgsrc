$NetBSD: patch-Clock.c,v 1.5 2026/06/30 09:49:22 wiz Exp $

avoid uselocale()
https://gitlab.freedesktop.org/xorg/app/xclock/-/merge_requests/29

--- Clock.c.orig	2026-06-27 20:18:51.000000000 +0000
+++ Clock.c
@@ -608,8 +608,14 @@ XmuCvtStringToXftShape(Display * dpy,
     int points_allocated = 0;
     int count = 0;
 #ifndef NO_I18N
-    locale_t c_loc = newlocale(LC_NUMERIC_MASK, "C", NULL);
-    locale_t old_loc = uselocale(c_loc);
+    char saved_numeric[256] = "";
+    {
+        const char *cur_numeric = setlocale(LC_NUMERIC, NULL);
+        if (cur_numeric != NULL && strlen(cur_numeric) < sizeof(saved_numeric)) {
+            strcpy(saved_numeric, cur_numeric);
+            setlocale(LC_NUMERIC, "C");
+        }
+    }
 #endif
     double t1 = .01, t2 = 0, t3 = 0, t4 = 0, t5 = .01, t6 = 0;
     const char* errmsg = NULL;
@@ -623,8 +629,8 @@ XmuCvtStringToXftShape(Display * dpy,
                 "Number of points must be divisible by three");
             shape.npoints = count;
 #ifndef NO_I18N
-            uselocale(old_loc);
-            freelocale(c_loc);
+            if (saved_numeric[0])
+                setlocale(LC_NUMERIC, saved_numeric);
 #endif
             donestr(XftShape, shape, XtRXftShape);
         }
@@ -709,8 +715,8 @@ XmuCvtStringToXftShape(Display * dpy,
                         msgout, (String *) NULL, (Cardinal *) 0);
         if (shape.points) free(shape.points);
 #ifndef NO_I18N
-        uselocale(old_loc);
-        freelocale(c_loc);
+        if (saved_numeric[0])
+            setlocale(LC_NUMERIC, saved_numeric);
 #endif
         return False;
     }
