$NetBSD: patch-qtbase_src_corelib_arch_sparc_arch.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Fix for SPARC64

--- qtbase/src/corelib/arch/sparc/arch.pri.orig	2013-11-27 01:01:15.000000000 +0000
+++ qtbase/src/corelib/arch/sparc/arch.pri
@@ -1,7 +1,7 @@
 #
 # SPARC architecture
 #
-*-64* {
+sEqual(QT_HOST_BITSIZE, 64) | *-64* {
     SOURCES += $$PWD/qatomic64.s
 }
 else {
