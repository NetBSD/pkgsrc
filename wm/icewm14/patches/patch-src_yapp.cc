$NetBSD: patch-src_yapp.cc,v 1.1 2018/11/01 09:25:29 bsiegert Exp $

--- src/yapp.cc.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/yapp.cc
@@ -20,6 +20,8 @@
 #include <sys/signalfd.h>
 #endif
 
+#include <signal.h>
+
 // FIXME: get rid of this global
 extern char const *ApplicationName;
 char const *&YApplication::Name = ApplicationName;
