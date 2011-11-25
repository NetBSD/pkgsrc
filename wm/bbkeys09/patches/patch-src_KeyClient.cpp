$NetBSD: patch-src_KeyClient.cpp,v 1.1 2011/11/25 22:21:28 joerg Exp $

--- src/KeyClient.cpp.orig	2011-11-25 17:00:02.000000000 +0000
+++ src/KeyClient.cpp
@@ -46,6 +46,7 @@ extern "C" {
 
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <strings.h>
 
 }
 
