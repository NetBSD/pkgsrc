$NetBSD: patch-src_mouse.c,v 1.3 2018/05/12 12:16:00 ryoon Exp $

From: https://cgit.freedesktop.org/xorg/driver/xf86-input-mouse/commit/?id=3c8f243b750a92d5837a449d344ff884dbd02b57
Adapt to removal of xf86GetOS

--- src/mouse.c.orig	2016-09-06 03:53:31.000000000 +0000
+++ src/mouse.c
@@ -794,7 +794,6 @@ InitProtocols(void)
 {
     int classes;
     int i;
-    const char *osname = NULL;
 
     if (osInfo)
         return TRUE;
@@ -821,11 +820,11 @@ InitProtocols(void)
                 mouseProtocols[i].id = PROT_UNSUP;
 
     /* NetBSD uses PROT_BM for "PS/2". */
-    xf86GetOS(&osname, NULL, NULL, NULL);
-    if (osname && xf86NameCmp(osname, "netbsd") == 0)
-        for (i = 0; mouseProtocols[i].name; i++)
-            if (mouseProtocols[i].id == PROT_PS2)
-                mouseProtocols[i].id = PROT_BM;
+#if defined(__NetBSD__)
+    for (i = 0; mouseProtocols[i].name; i++)
+        if (mouseProtocols[i].id == PROT_PS2)
+            mouseProtocols[i].id = PROT_BM;
+#endif
 
     return TRUE;
 }
