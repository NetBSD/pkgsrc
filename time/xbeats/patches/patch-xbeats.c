$NetBSD: patch-xbeats.c,v 1.1 2023/07/07 08:25:37 nia Exp $

Make it not immediately trigger the stack protector and segfault.

--- xbeats.c.orig	1999-01-25 16:13:27.000000000 +0000
+++ xbeats.c
@@ -54,6 +54,7 @@ struct timezone *tz;
 #define MW_EVENTS	(ExposureMask | ButtonPressMask | StructureNotifyMask)
 
 int main(int argc, char *argv[]);
+void parser(int, char **);
 void GetXPM(void);
 int flush_expose(Window w);
 void RedrawWindow(XpmIcon *v);
@@ -208,8 +209,8 @@ void GetXPM(void)
 {
 	XColor col;
 	XWindowAttributes attributes;
-	char led1[22];
-	char led2[22];
+	char led1[23];
+	char led2[23];
 	int ret;
 	XGetWindowAttributes(dpy,Root,&attributes);
 	if(!XParseColor(dpy,attributes.colormap,LedColor,&col)) 
