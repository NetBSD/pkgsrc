$NetBSD: patch-src_wmapp.cc,v 1.1 2016/10/01 20:40:06 mrg Exp $

Avoid passing 4-byte aligned data to 8-byte aligned needing functions.

--- src/wmapp.cc.orig	2009-11-08 10:59:46.000000000 -0800
+++ src/wmapp.cc	2016-10-01 13:14:03.000000000 -0700
@@ -219,6 +219,7 @@
 #endif
 
     pid_t pid = getpid();
+    long lpid = (long)pid;
     const char wmname[] = "IceWM "VERSION" ("HOSTOS"/"HOSTCPU")";
 
 #ifdef GNOME1_HINTS
@@ -238,7 +239,7 @@
 
     XChangeProperty(xapp->display(), xid,
                     _XA_NET_WM_PID, XA_CARDINAL, 32,
-                    PropModeReplace, (unsigned char *)&pid, 1);
+                    PropModeReplace, (unsigned char *)&lpid, 1);
 
     XChangeProperty(xapp->display(), xid,
                     _XA_NET_WM_NAME, XA_STRING, 8,
