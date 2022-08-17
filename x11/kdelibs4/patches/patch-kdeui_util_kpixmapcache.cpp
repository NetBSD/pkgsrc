$NetBSD: patch-kdeui_util_kpixmapcache.cpp,v 1.1 2022/08/17 18:51:09 tnn Exp $

Remove unused legacy madvise(2) prototype.
The code already uses posix_madvise(2) unconditionally.

--- kdeui/util/kpixmapcache.cpp.orig	2017-11-05 01:51:22.000000000 +0000
+++ kdeui/util/kpixmapcache.cpp
@@ -58,12 +58,6 @@
 
 //#define DISABLE_PIXMAPCACHE
 
-#ifdef Q_OS_SOLARIS
-#ifndef _XPG_4_2
-extern "C" int madvise(caddr_t addr, size_t len, int advice);
-#endif
-#endif
-
 #define KPIXMAPCACHE_VERSION 0x000208
 
 namespace {
