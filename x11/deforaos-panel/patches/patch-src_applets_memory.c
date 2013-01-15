$NetBSD: patch-src_applets_memory.c,v 1.1 2013/01/15 15:34:12 joerg Exp $

--- src/applets/memory.c.orig	2013-01-15 13:21:08.000000000 +0000
+++ src/applets/memory.c
@@ -21,12 +21,13 @@
 #include <errno.h>
 #if defined(__linux__)
 # include <sys/sysinfo.h>
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__NetBSD__)
+# include <sys/sysctl.h>
+# include <sys/vmmeter.h>
+#elif defined(__FreeBSD__)
 # include <sys/sysctl.h>
-# if defined(__FreeBSD__)
-#  include <sys/vmmeter.h>
-#  include <vm/vm_param.h>
-# endif
+# include <sys/vmmeter.h>
+# include <vm/vm_param.h>
 #endif
 #include <libintl.h>
 #include "Panel.h"
