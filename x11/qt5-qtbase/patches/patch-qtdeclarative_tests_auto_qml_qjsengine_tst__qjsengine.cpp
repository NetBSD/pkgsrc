$NetBSD: patch-qtdeclarative_tests_auto_qml_qjsengine_tst__qjsengine.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* NetBSD has no alloca.h

--- qtdeclarative/tests/auto/qml/qjsengine/tst_qjsengine.cpp.orig	2013-11-27 01:01:54.000000000 +0000
+++ qtdeclarative/tests/auto/qml/qjsengine/tst_qjsengine.cpp
@@ -57,7 +57,7 @@
 
 #if defined(Q_OS_WIN)
 #include <malloc.h>
-#else
+#elif defined(Q_OS_LINUX)
 #include <alloca.h>
 #endif
 
