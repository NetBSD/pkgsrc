$NetBSD: patch-lib-Util.hh,v 1.1 2011/09/24 13:01:29 joerg Exp $

--- lib/Util.hh.orig	2011-09-22 13:58:57.000000000 +0000
+++ lib/Util.hh
@@ -94,7 +94,7 @@ namespace bt {
 
   std::string tolower(const std::string &string);
 
-#ifdef _XUTIL_H_
+#if defined(_XUTIL_H_) || defined(_X11_XUTIL_H_)
   std::string textPropertyToString(::Display *display,
                                    ::XTextProperty& text_prop);
 #endif
