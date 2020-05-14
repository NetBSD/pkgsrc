$NetBSD: patch-lib_ts_ink__defs.h,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- lib/ts/ink_defs.h.orig	2020-05-13 23:49:19.084187831 +0000
+++ lib/ts/ink_defs.h
@@ -62,7 +62,7 @@
 #endif
 #endif
 
-#if defined(darwin)
+#if defined(darwin) || defined(__NetBSD__)
 #define RENTRENT_GETHOSTBYNAME
 #define RENTRENT_GETHOSTBYADDR
 #endif
