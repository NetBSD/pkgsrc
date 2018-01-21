$NetBSD: patch-src_qml_jsruntime_qv4alloca__p.h,v 1.1 2018/01/21 21:39:41 markd Exp $

Make sure we pick up gcc's builtin alloca on NetBSD

--- src/qml/jsruntime/qv4alloca_p.h.orig	2017-11-30 15:10:22.000000000 +0000
+++ src/qml/jsruntime/qv4alloca_p.h
@@ -78,9 +78,13 @@
 #define Q_ALLOCA_DECLARE(type, name) \
     type *name = 0
 
+#if defined(__GNUC__)
+#define Q_ALLOCA_ASSIGN(type, name, size) \
+    name = static_cast<type*>(__builtin_alloca(size))
+#else
 #define Q_ALLOCA_ASSIGN(type, name, size) \
     name = static_cast<type*>(alloca(size))
-
+#endif
 #else
 QT_BEGIN_NAMESPACE
 class Qt_AllocaWrapper
