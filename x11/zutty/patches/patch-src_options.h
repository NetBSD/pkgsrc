$NetBSD: patch-src_options.h,v 1.2 2023/12/10 11:50:43 wiz Exp $

Improve NetBSD support.
https://github.com/tomscii/zutty/pull/132

--- src/options.h.orig	2023-12-10 11:42:36.219352467 +0000
+++ src/options.h
@@ -39,6 +39,8 @@ namespace zutty
 
 #if defined(FREEBSD)
    static constexpr const char* fontpath = "/usr/local/share/fonts";
+#elif defined(NETBSD)
+   static constexpr const char* fontpath = "/usr/X11R7/lib/X11/fonts";
 #elif defined(OPENBSD)
    static constexpr const char* fontpath = "/usr/X11R6/lib/X11/fonts";
 #else
