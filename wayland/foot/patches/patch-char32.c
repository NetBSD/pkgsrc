$NetBSD: patch-char32.c,v 1.1 2026/04/14 12:11:48 kikadf Exp $

* Add NetBSD support

--- char32.c.orig	2026-02-05 16:00:31.082232514 +0000
+++ char32.c
@@ -34,7 +34,8 @@ _Static_assert(
 #if !defined(__STDC_UTF_32__) || !__STDC_UTF_32__
  #error "char32_t does not use UTF-32"
 #endif
-#if (!defined(__STDC_ISO_10646__) || !__STDC_ISO_10646__) && !defined(__FreeBSD__)
+#if (!defined(__STDC_ISO_10646__) || !__STDC_ISO_10646__) && !defined(__FreeBSD__) && \
+    !defined(__NetBSD__)
  #error "wchar_t does not use UTF-32"
 #endif
 
