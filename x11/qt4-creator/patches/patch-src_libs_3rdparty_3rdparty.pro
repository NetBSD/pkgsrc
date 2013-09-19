$NetBSD: patch-src_libs_3rdparty_3rdparty.pro,v 1.1 2013/09/19 10:25:44 joerg Exp $

--- src/libs/3rdparty/3rdparty.pro.orig	2013-09-17 20:10:31.000000000 +0000
+++ src/libs/3rdparty/3rdparty.pro
@@ -1,5 +1,4 @@
 TEMPLATE = subdirs
 CONFIG  += ordered
 
-SUBDIRS += botan \
-           net7ssh
+SUBDIRS += net7ssh
