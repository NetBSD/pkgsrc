$NetBSD: patch-include_wx_convauto.h,v 1.1 2017/06/14 13:21:52 jperkin Exp $

Avoid conflicting definition of BOM_UTF8 from perl-5.26.

--- include/wx/convauto.h.orig	2011-03-22 12:16:45.000000000 +0000
+++ include/wx/convauto.h
@@ -51,6 +51,7 @@ private:
         BOM_UTF32LE,
         BOM_UTF16BE,
         BOM_UTF16LE,
+#undef BOM_UTF8
         BOM_UTF8
     };
 
