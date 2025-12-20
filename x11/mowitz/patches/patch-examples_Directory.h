$NetBSD: patch-examples_Directory.h,v 1.1 2025/12/20 16:16:55 nia Exp $

Need higher _POSIX_C_SOURCE for lstat(2).

--- examples/Directory.h.orig	2025-12-20 16:08:10.641535927 +0000
+++ examples/Directory.h
@@ -26,8 +26,8 @@
 #ifndef _FWF_DIRECTORY_H_
 #define _FWF_DIRECTORY_H_
 
-#ifndef _POSIX_SOURCE
-#define _POSIX_SOURCE	1
+#ifndef _POSIX_C_SOURCE
+#define _POSIX_C_SOURCE	200112L
 #endif
 
 #include <stdio.h>
