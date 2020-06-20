$NetBSD: patch-src_parser-cat.cc,v 1.1 2020/06/20 16:00:07 nia Exp $

Fix NetBSD build.

--- src/parser-cat.cc.orig	2020-05-13 09:51:07.000000000 +0000
+++ src/parser-cat.cc
@@ -706,7 +706,7 @@ private:
 
                 for (auto i = 0; i < repeat; ++i) {
                         if (i > 0 && lseek(fd, 0, SEEK_SET) != 0) {
-                                g_printerr("Failed to seek: %m\n");
+                                g_printerr("Failed to seek: %s\n", strerror(errno));
                                 return false;
                         }
 
@@ -747,7 +747,7 @@ public:
                                 } else {
                                         fd = open(filename, O_RDONLY);
                                         if (fd == -1) {
-                                                g_printerr("Error opening file %s: %m\n", filename);
+                                                g_printerr("Error opening file %s: %s\n", filename, strerror(errno));
                                         }
                                 }
                                 if (fd != -1) {
