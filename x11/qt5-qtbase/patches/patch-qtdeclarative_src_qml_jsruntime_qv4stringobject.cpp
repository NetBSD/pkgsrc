$NetBSD: patch-qtdeclarative_src_qml_jsruntime_qv4stringobject.cpp,v 1.1 2014/07/14 16:32:14 jperkin Exp $

SunOS needs alloca.h for alloca()

--- qtdeclarative/src/qml/jsruntime/qv4stringobject.cpp.orig	2014-02-01 20:38:02.000000000 +0000
+++ qtdeclarative/src/qml/jsruntime/qv4stringobject.cpp
@@ -73,6 +73,10 @@
 #  include <windows.h>
 #endif
 
+#ifdef Q_OS_SOLARIS
+#include <alloca.h>
+#endif
+
 using namespace QV4;
 
 DEFINE_MANAGED_VTABLE(StringObject);
