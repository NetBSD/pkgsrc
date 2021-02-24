$NetBSD: patch-src_x2goclientconfig.h,v 1.1 2021/02/24 18:39:30 hauke Exp $

We make LDAP an option.

--- src/x2goclientconfig.h.orig	2020-02-13 10:36:07.000000000 +0000
+++ src/x2goclientconfig.h
@@ -25,10 +25,6 @@
 
 //#define LOGFILE QDir::homePath()+"/x2goclient.log"
 
-#if !defined Q_OS_WIN
-#define USELDAP
-#endif
-
 #ifdef Q_OS_WIN
 #undef USELDAP
 #endif
