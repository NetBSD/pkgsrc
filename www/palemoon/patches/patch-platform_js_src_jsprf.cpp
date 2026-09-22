$NetBSD: patch-platform_js_src_jsprf.cpp,v 1.1 2026/09/22 14:38:43 nia Exp $

Revert commit 4c346cc711118689b9b6d05495c2fbcf495e5ab0 to work around
bug in NetBSD/amd64 libc.

https://repo.palemoon.org/MoonchildProductions/UXP/issues/3188
https://gnats.netbsd.org/60744

--- platform/js/src/jsprf.cpp.orig	2026-09-12 13:38:01.000000000 +0000
+++ platform/js/src/jsprf.cpp
@@ -312,13 +312,17 @@ cvt_s(SprintfState* ss, const char* s, int width, int 
         s = generic_null_str(s);
 
     // Limit string length by precision value
+#ifndef __NetBSD__
     // We'd want to use strnlen() here, but it is not supported by all targets
     // (Most notably old OS X), so use memchr instead.
     // Replace with `size_t slen = strnlen(s, size_t(prec));` once we no longer
     // need to cater to this.
     const char* sptr = (const char*)memchr(s, 0, size_t(prec));
     size_t slen = sptr ? sptr - s : size_t(prec);
-    
+#else
+    size_t slen = strnlen(s, size_t(prec));
+#endif
+
     if (slen > INT_MAX) {
         return false;
     }
