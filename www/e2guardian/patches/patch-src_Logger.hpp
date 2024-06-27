$NetBSD: patch-src_Logger.hpp,v 1.1 2024/06/27 15:26:23 sborrill Exp $

Don't clash with definitions in stdio.h

--- src/Logger.hpp.orig	2024-03-28 12:10:30.960888443 +0000
+++ src/Logger.hpp	2024-03-28 12:11:02.392972161 +0000
@@ -15,6 +15,12 @@
 #include <fstream>
 #include <sstream>
 #include <cstdio>
+#ifdef stdout
+#undef stdout
+#endif
+#ifdef stderr
+#undef stderr
+#endif
 #include <atomic>
 #include <syslog.h>
 #include <unistd.h>
