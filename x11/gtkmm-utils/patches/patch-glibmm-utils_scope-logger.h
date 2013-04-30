$NetBSD: patch-glibmm-utils_scope-logger.h,v 1.1 2013/04/30 22:32:43 joerg Exp $

--- glibmm-utils/scope-logger.h.orig	2013-04-30 21:39:57.000000000 +0000
+++ glibmm-utils/scope-logger.h
@@ -22,7 +22,13 @@
 #ifndef __GLIBMM_UTILS_SCOPE_LOGGER_H__
 #define __GLIBMM_UTILS_SCOPE_LOGGER_H__
 
+#include <ciso646>
+
+#ifdef _LIBCPP_VERSION
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 #include "log-stream-utils.h"
 
 namespace Glib {
@@ -33,7 +39,11 @@ class ScopeLogger
 {
     friend struct ScopeLoggerPriv ;
 
+#ifdef _LIBCPP_VERSION
+    std::shared_ptr<ScopeLoggerPriv> m_priv ;
+#else
     std::tr1::shared_ptr<ScopeLoggerPriv> m_priv ;
+#endif
     //forbid copy/assignation
     ScopeLogger (ScopeLogger const &) ;
     ScopeLogger& operator= (ScopeLogger const &) ;
