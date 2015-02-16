$NetBSD: patch-js_src_shell_jsoptparse.cpp,v 1.1 2015/02/16 16:16:17 bad Exp $

--- js/src/shell/jsoptparse.cpp.orig	2015-01-23 06:00:02.000000000 +0000
+++ js/src/shell/jsoptparse.cpp	2015-02-05 13:10:47.000000000 +0000
@@ -94,7 +94,7 @@
 
         /* Delimit the current token. */
         const char *limit = it;
-        while (!isspace(*limit) && *limit != '\0')
+        while (!isspace(((unsigned char)*limit)) && *limit != '\0')
             ++limit;
 
         /*
