$NetBSD: patch-libs_safemalloc.h,v 1.1 2020/09/29 12:22:35 nia Exp $

Missing headers for size_t and va_list.

--- libs/safemalloc.h.orig	2020-08-16 22:59:05.000000000 +0000
+++ libs/safemalloc.h
@@ -1,3 +1,6 @@
+#include <stdarg.h>
+#include <stddef.h>
+
 #ifndef _SAFEMALLOC_H
 #define _SAFEMALLOC_H
 void	*fxmalloc(size_t);
