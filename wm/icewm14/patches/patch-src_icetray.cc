$NetBSD: patch-src_icetray.cc,v 1.1 2018/11/01 09:25:29 bsiegert Exp $

--- src/icetray.cc.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/icetray.cc
@@ -10,6 +10,8 @@
 #include "yprefs.h"
 #include "yconfig.h"
 
+#include <signal.h>
+
 char const *ApplicationName = "icewmtray";
 
 #ifdef CONFIG_TASKBAR
