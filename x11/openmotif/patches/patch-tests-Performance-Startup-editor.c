$NetBSD: patch-tests-Performance-Startup-editor.c,v 1.1.1.1 2000/10/29 16:17:13 mjl Exp $

--- tests/Performance/Startup/editor.c.orig	Wed May  3 05:12:48 2000
+++ tests/Performance/Startup/editor.c	Wed Aug  9 19:29:43 2000
@@ -238,7 +238,7 @@
 
     strcpy(tempname, "/tmp/xmeditXXXXXX");
     
-    if ((tfp = fopen(mktemp(tempname), "w")) == NULL) {
+    if ((tfp = mkstemp(tempname)) == NULL) {
        fprintf(stderr, "Warning: unable to open temp file, text not saved.\n");
        return(False);;
     }
