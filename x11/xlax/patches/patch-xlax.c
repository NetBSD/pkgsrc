$NetBSD: patch-xlax.c,v 1.1 2022/12/06 21:04:14 vins Exp $

* Fix warnings about int signedness mismatch.
* Fix warnings about int to pointer conversion. 
* Use libbsd on Linux to support strlcpy().

--- xlax.c.orig	2008-07-31 20:18:25.000000000 +0000
+++ xlax.c
@@ -30,6 +30,11 @@
  *
  */
 
+#ifdef __linux__
+#include <bsd/string.h>
+#endif
+
+#include "stddef.h"
 #include "xlax.h"
 #include "vroot.h"
 
@@ -50,7 +55,7 @@ XKeyEvent tmpevents[MAXEVENTS];
 int tmpeventindex;
 int tmpwindex;
   
-int 
+uintptr_t 
   WindowIndex;
 
 char *prefix="xlax:";
@@ -70,7 +75,7 @@ XErrorEvent *myerr;
   XGetErrorText(mydisp, myerr->error_code, msg, 80);
   (void) fprintf(stderr, "%s\n", msg);
   if (myerr->error_code == BadWindow) {
-    fprintf(stderr, "Removing window %d\n", myerr->resourceid);
+    fprintf(stderr, "Removing window %lu\n", (unsigned long)myerr->resourceid);
     Remove_Window(myerr->resourceid);
     return 0;
   } else {
@@ -411,8 +416,8 @@ Display *dpy;
 Window top;
 {
   Window *children, dummy;
-  unsigned int nchildren;
-  int i, x;
+  unsigned int i, nchildren;
+  int x;
   Window w=0;
   XClassHint class_hint;
 
@@ -674,7 +679,7 @@ Display *dpy;
 int wi;
 char *str;
 {
-  int i;
+  size_t i;
   long m;
   Window root = RootWindow(dpy,DefaultScreen(dpy));
 
@@ -686,7 +691,7 @@ char *str;
   }
   for (i=0; i<strlen(str)&&i<MAXEVENTS; ++i) {
     /* skip if we don't have a keycode mapping for this character */
-    if (kcmap[str[i]] < 0) {
+    if (kcmap[(unsigned char)str[i]] < 0) {
       fprintf(stderr,"No key mapping for %c!\n", str[i]);
       continue;
     }
@@ -702,8 +707,8 @@ char *str;
     Windows[wi].events[i].x_root=0;
     Windows[wi].events[i].y_root=0;
     Windows[wi].events[i].same_screen=1;
-    Windows[wi].events[i].keycode=kcmap[str[i]];
-    Windows[wi].events[i].state=modmap[str[i]];
+    Windows[wi].events[i].keycode=kcmap[(unsigned char)str[i]];
+    Windows[wi].events[i].state=modmap[(unsigned char)str[i]];
   }
   Windows[wi].eventindex=i;
   cnt = 0;
@@ -746,8 +751,8 @@ Display *disp;
       evt.state=states[m];
       len=XLookupString(&evt, out, 32, NULL, NULL);
       if (len == 1) {
-        kcmap[out[0]] = i;
-        modmap[out[0]] = states[m];
+        kcmap[(unsigned char)out[0]] = i;
+        modmap[(unsigned char)out[0]] = states[m];
       }
     }
   }
@@ -759,7 +764,7 @@ unsigned char c;
 long *m;
 {
   KeySym ks, ksr;
-  KeyCode kc;
+  KeyCode kc = -1;
   XKeyEvent evt;
   long mr, len;
   char str[2], out[32];
@@ -802,11 +807,11 @@ long *m;
       *m = ShiftMask | ControlMask;
       return(kc);
     }
-    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%d,kc=%d\n",c,ks,kc);
+    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%lu,kc=%d\n",c,(unsigned long)ks,kc);
     *m = ControlMask;
     return(0);
   } else if (c>127) {
-    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%d,kc=%d\n",c,ks,kc);
+    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%lu,kc=%d\n",c,(unsigned long)ks,kc);
     *m = 0;
     return(0);
   } else {
@@ -826,7 +831,7 @@ long *m;
       *m = ShiftMask;
       return(kc);
     }
-    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%d,kc=%d\n",c,ks,kc);
+    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%lu,kc=%d\n",c,(unsigned long)ks,kc);
     *m = 0;
     return(0);
   }
@@ -882,7 +887,7 @@ long *m;
       *m = ShiftMask | ControlMask;
       return(kc);
     }
-    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%d,kc=%d\n",c,ks,kc);
+    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%lu,kc=%d\n",c,(unsigned long)ks,kc);
     *m = ControlMask;
     return(0);
   } else {
@@ -902,7 +907,7 @@ long *m;
       *m = ShiftMask;
       return(kc);
     }
-    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%d,kc=%d\n",c,ks,kc);
+    fprintf(stderr, "Didn't resolve keycode! (c=%d, ks=%lu,kc=%d\n",c,(unsigned long)ks,kc);
     *m = 0;
     return(0);
   }
@@ -1040,7 +1045,8 @@ caddr_t  client_data;	/* unused */
 caddr_t  call_data;	/* unused */
 
 {
-  int x, y, n;
+  int x, n;
+  size_t y;
   char *sel;
   XKeyEvent evt;
   long m;
@@ -1052,7 +1058,7 @@ caddr_t  call_data;	/* unused */
     if (Windows[x].active == 1) {
       for (y = 0; y < strlen(sel); y++) {
 	/* skip if we don't have a keycode mapping for this character */
-	if (kcmap[sel[y]] < 0) {
+	if (kcmap[(unsigned char)sel[y]] < 0) {
 	  fprintf(stderr,"No key mapping for %c!\n", sel[y]);
 	  continue;
 	}
@@ -1068,8 +1074,8 @@ caddr_t  call_data;	/* unused */
 	evt.x_root=0;
 	evt.y_root=0;
 	evt.same_screen=1;
-	evt.keycode=kcmap[sel[y]];
-	evt.state=modmap[sel[y]];
+	evt.keycode=kcmap[(unsigned char)sel[y]];
+	evt.state=modmap[(unsigned char)sel[y]];
 
 	XSendEvent(dpy, Windows[x].wind, True, 
 		   KeyPressMask, (XEvent *) &evt);
