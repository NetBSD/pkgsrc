$NetBSD: patch-src_concurrent_qtconcurrentiteratekernel.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

--- src/concurrent/qtconcurrentiteratekernel.cpp.orig	2013-11-27 01:01:16.000000000 +0000
+++ src/concurrent/qtconcurrentiteratekernel.cpp
@@ -41,7 +41,7 @@
 
 #include "qtconcurrentiteratekernel.h"
 
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(__APPLE__)
 #include <mach/mach.h>
 #include <mach/mach_time.h>
 #include <unistd.h>
@@ -67,7 +67,7 @@ enum {
     MedianSize = 7
 };
 
-#if defined(Q_OS_MAC)
+#if defined(Q_OS_MAC) || defined(__APPLE__)
 
 static qint64 getticks()
 {
