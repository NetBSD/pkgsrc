$NetBSD: patch-glibmm-utils_ustring.h,v 1.1 2012/11/16 00:27:20 joerg Exp $

--- glibmm-utils/ustring.h.orig	2012-11-15 13:48:06.000000000 +0000
+++ glibmm-utils/ustring.h
@@ -107,7 +107,7 @@ inline T convert_to(const Glib::ustring&
 }
 
 /// \brief a printf() that returns a Glib::ustring
-Glib::ustring uprintf(const Glib::ustring& format, ...);
+Glib::ustring uprintf(const char *format, ...);
 
 } // namespace Util
 
