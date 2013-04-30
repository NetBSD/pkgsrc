$NetBSD: patch-glibmm-utils_log-stream.h,v 1.1 2013/04/30 22:32:43 joerg Exp $

--- glibmm-utils/log-stream.h.orig	2013-04-30 21:39:17.000000000 +0000
+++ glibmm-utils/log-stream.h
@@ -23,7 +23,12 @@
 #define __GLIBMM_UTILS_LOG_STREAM_H__
 
 #include <string>
+
+#ifdef _LIBCPP_VERSION
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 #include <glibmm/ustring.h>
 
 #ifndef GLIBMM_DEFAULT_DOMAIN
@@ -47,7 +52,11 @@ class LogStream
     friend LogStream& flush (LogStream &) ;
     friend LogStream& endl (LogStream &) ;
     struct Priv ;
+#ifdef _LIBCPP_VERSION
+    std::shared_ptr<Priv> m_priv ;
+#else
     std::tr1::shared_ptr<Priv> m_priv ;
+#endif
 
     //forbid copy/assignation
     LogStream (LogStream const&) ;
