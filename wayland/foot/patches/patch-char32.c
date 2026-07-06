$NetBSD: patch-char32.c,v 1.2 2026/07/06 18:26:41 bsiegert Exp $

* Add NetBSD support

--- char32.c.orig	2026-05-15 06:26:04.000000000 +0000
+++ char32.c
@@ -34,7 +34,7 @@ _Static_assert(
 #if !defined(__STDC_UTF_32__) || !__STDC_UTF_32__
  #error "char32_t does not use UTF-32"
 #endif
-#if (!defined(__STDC_ISO_10646__) || !__STDC_ISO_10646__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if (!defined(__STDC_ISO_10646__) || !__STDC_ISO_10646__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
  #error "wchar_t does not use UTF-32"
 #endif
 
