$NetBSD: patch-src_options.h,v 1.1 2023/12/10 11:46:09 wiz Exp $

Improve NetBSD support.

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
