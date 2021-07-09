$NetBSD: patch-src_corelib_text_qbytearraymatcher.h,v 1.1 2021/07/09 22:48:47 markd Exp $

Build fixes for GCC 11

Task-number: QTBUG-89977
Change-Id: Ic1b7ddbffb8a0a00f8c621d09a868f1d94a52c21
Reviewed-by: ￼Lars Knoll <lars.knoll@qt.io>
Reviewed-by: ￼Thiago Macieira <thiago.macieira@intel.com>
(cherry picked from commit 813a928c)

--- src/corelib/text/qbytearraymatcher.h.orig	2020-10-27 08:02:11.000000000 +0000
+++ src/corelib/text/qbytearraymatcher.h
@@ -42,6 +42,8 @@
 
 #include <QtCore/qbytearray.h>
 
+#include <limits>
+
 QT_BEGIN_NAMESPACE
 
 
