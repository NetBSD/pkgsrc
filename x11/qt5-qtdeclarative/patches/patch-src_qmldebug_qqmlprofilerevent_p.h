$NetBSD: patch-src_qmldebug_qqmlprofilerevent_p.h,v 1.1 2021/07/09 22:52:54 markd Exp $

Add missing limits include to fix build with GCC 11
Change-Id: I97606ea493e723006759608b7d4c4f00632f340c
Reviewed-by: ￼Albert Astals Cid <albert.astals.cid@kdab.com>
(cherry picked from commit 367293b1)

--- src/qmldebug/qqmlprofilerevent_p.h.orig	2020-10-27 08:02:12.000000000 +0000
+++ src/qmldebug/qqmlprofilerevent_p.h
@@ -48,6 +48,7 @@
 #include <QtCore/qmetatype.h>
 
 #include <initializer_list>
+#include <limits>
 #include <type_traits>
 
 //
