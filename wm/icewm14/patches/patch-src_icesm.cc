$NetBSD: patch-src_icesm.cc,v 1.1 2018/11/01 09:25:29 bsiegert Exp $

--- src/icesm.cc.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/icesm.cc
@@ -9,6 +9,8 @@
 #include <wordexp.h>
 #endif
 
+#include <signal.h>
+
 char const *ApplicationName = ICESMEXE;
 
 class SessionManager: public YApplication {
