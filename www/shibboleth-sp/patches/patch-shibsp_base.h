$NetBSD: patch-shibsp_base.h,v 1.1 2013/09/20 23:11:01 joerg Exp $

--- shibsp/base.h.orig	2013-09-20 16:02:01.000000000 +0000
+++ shibsp/base.h
@@ -32,6 +32,7 @@
 # define XMLTOOLING_LITE
 # include <xmltooling/base.h>
 #else
+# include <boost/lexical_cast.hpp>
 # include <saml/base.h>
 #endif
 
