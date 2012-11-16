$NetBSD: patch-lib_libxview_textsw_txt__18impl.h,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/textsw/txt_18impl.h.orig	2012-11-14 15:33:44.000000000 +0000
+++ lib/libxview/textsw/txt_18impl.h
@@ -24,4 +24,7 @@
 
 #endif /* OW_I18N */
 
+Pkg_private void
+es_file_append_error(char *, CHAR *, Es_status);
+
 #endif /* txt_18impl_h_DEFINED */
