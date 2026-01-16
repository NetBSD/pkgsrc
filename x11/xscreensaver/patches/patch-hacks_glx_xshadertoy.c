$NetBSD: patch-hacks_glx_xshadertoy.c,v 1.1 2026/01/16 14:53:05 hauke Exp $

Do not mess with <stdio.h>'s 'stdin'.

--- hacks/glx/xshadertoy.c.orig	2026-01-16 13:53:15.457872933 +0000
+++ hacks/glx/xshadertoy.c
@@ -732,7 +732,7 @@ init_xshadertoy (ModeInfo *mi)
 # ifndef HAVE_ANDROID /* X11, Cocoa and iOS read files with fopen. */
   {
     int j;
-    FILE *in = 0, *stdin = 0;
+    FILE *in = 0, *the_stdin = 0;
     Bool nl_p = True;
     int order[] = { 5, 0, 1, 2, 3, 4 };    /* Read "common" first on stdin */
 
@@ -757,8 +757,8 @@ init_xshadertoy (ModeInfo *mi)
           in = fopen (fn, "r");
         else
           {
-            in = (stdin ? stdin : fdopen (STDIN_FILENO, "r"));
-            stdin = in;
+            in = (the_stdin ? the_stdin : fdopen (STDIN_FILENO, "r"));
+            the_stdin = in;
           }
 
         if (!in)
@@ -773,7 +773,7 @@ init_xshadertoy (ModeInfo *mi)
         while (fgets (buf, sizeof(buf)-1, in))
           {
             res = strlen (buf);
-            if (nl_p && stdin &&
+            if (nl_p && the_stdin &&
                 !strcmp (buf, ".\n"))	/* "." alone on a line is EOF */
               break;
             nl_p = (res > 0 && buf[res-1] == '\n');
@@ -791,7 +791,7 @@ init_xshadertoy (ModeInfo *mi)
             bp->shader_program[i][len] = 0;
           }
 
-        if (!stdin)
+        if (!the_stdin)
           {
             fclose (in);
             in = 0;
