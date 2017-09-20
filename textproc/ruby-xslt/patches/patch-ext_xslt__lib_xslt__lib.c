$NetBSD: patch-ext_xslt__lib_xslt__lib.c,v 1.1 2017/09/20 15:43:44 taca Exp $

* libxslt 1.1.30 removed norm:localTime extension function.

--- ext/xslt_lib/xslt_lib.c.orig	2017-09-20 15:19:45.000000000 +0000
+++ ext/xslt_lib/xslt_lib.c
@@ -561,7 +561,6 @@ void Init_xslt_lib( void ) {
   rb_define_const( cXSLT, "DEFAULT_VERSION",      rb_str_new2(XSLT_DEFAULT_VERSION) );
   rb_define_const( cXSLT, "DEFAULT_URL",          rb_str_new2(XSLT_DEFAULT_URL) );
   rb_define_const( cXSLT, "NAMESPACE_LIBXSLT",    rb_str_new2((char *)XSLT_LIBXSLT_NAMESPACE) );
-  rb_define_const( cXSLT, "NAMESPACE_NORM_SAXON", rb_str_new2((char *)XSLT_NORM_SAXON_NAMESPACE) );
   rb_define_const( cXSLT, "NAMESPACE_SAXON",      rb_str_new2((char *)XSLT_SAXON_NAMESPACE) );
   rb_define_const( cXSLT, "NAMESPACE_XT",         rb_str_new2((char *)XSLT_XT_NAMESPACE) );
   rb_define_const( cXSLT, "NAMESPACE_XALAN",      rb_str_new2((char *)XSLT_XALAN_NAMESPACE) );
