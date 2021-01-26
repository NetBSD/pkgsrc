$NetBSD: patch-js_public_ErrorReport.h,v 1.1 2021/01/26 15:02:55 ryoon Exp $

--- js/public/ErrorReport.h.orig	2021-01-14 19:12:25.000000000 +0000
+++ js/public/ErrorReport.h
@@ -20,6 +20,7 @@
 #include "mozilla/Assertions.h"  // MOZ_ASSERT
 
 #include <iterator>  // std::input_iterator_tag, std::iterator
+#include <stdarg.h>  // va_list
 #include <stddef.h>  // size_t
 #include <stdint.h>  // int16_t, uint16_t
 #include <string.h>  // strlen
