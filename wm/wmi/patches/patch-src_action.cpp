$NetBSD: patch-src_action.cpp,v 1.1 2011/12/05 22:56:58 joerg Exp $

--- src/action.cpp.orig	2011-12-05 20:32:53.000000000 +0000
+++ src/action.cpp
@@ -5,2 +5,4 @@
 
+#include <cstdlib>
+#include <cstring>
 #include <string>
