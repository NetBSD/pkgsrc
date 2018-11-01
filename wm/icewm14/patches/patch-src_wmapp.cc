$NetBSD: patch-src_wmapp.cc,v 1.1 2018/11/01 09:25:29 bsiegert Exp $

--- src/wmapp.cc.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/wmapp.cc
@@ -43,6 +43,8 @@
 #include "ypointer.h"
 #include "intl.h"
 
+#include <signal.h>
+
 char const *ApplicationName("IceWM");
 int rebootOrShutdown = 0;
 static bool initializing(true);
