$NetBSD: patch-libs_ksysguard_processcore_processes__netbsd__p.cpp,v 1.2 2017/06/25 19:58:04 youri Exp $

--- libs/ksysguard/processcore/processes_netbsd_p.cpp.orig	2015-08-12 07:03:15.000000000 +0000
+++ libs/ksysguard/processcore/processes_netbsd_p.cpp
@@ -29,7 +29,7 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
+#include <sys/resource.h>
 #include <sys/stat.h>
 #include <signal.h>
 #include <unistd.h>
