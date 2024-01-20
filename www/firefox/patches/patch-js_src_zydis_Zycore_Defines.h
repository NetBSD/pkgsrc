$NetBSD: patch-js_src_zydis_Zycore_Defines.h,v 1.1 2024/01/20 16:41:22 nros Exp $

Make zydis build on more unix platforms,
Fixes debug build on NetBSD.
Debug build brak reported by Nikita Gillman on pkgsrc-users.

Filed upstream:
https://github.com/zyantific/zycore-c/pull/68

--- js/src/zydis/Zycore/Defines.h.orig	2024-01-20 11:40:03.278576923 +0000
+++ js/src/zydis/Zycore/Defines.h
@@ -100,7 +100,7 @@
 #elif defined(sun) || defined(__sun)
 #   define ZYAN_SOLARIS
 #   define ZYAN_POSIX
-#elif defined(__unix)
+#elif defined(__unix) || defined(__unix__)
 #   define ZYAN_UNIX
 #   define ZYAN_POSIX
 #elif defined(__posix)
