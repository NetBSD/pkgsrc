$NetBSD: patch-FDTunnel.cpp,v 1.1 2013/12/10 12:35:41 jperkin Exp $

Need string.h on SunOS.

--- FDTunnel.cpp.orig	2005-08-13 23:47:57.000000000 +0000
+++ FDTunnel.cpp
@@ -34,6 +34,8 @@
 #ifdef __BSD
 	#include "autoconf/select.h"
 	#include <string.h>
+#elif defined(__sun)
+	#include <string.h>
 #else
 	#include <sys/select.h>
 #endif
