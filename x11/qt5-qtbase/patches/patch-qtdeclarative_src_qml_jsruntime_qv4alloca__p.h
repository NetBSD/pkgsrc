$NetBSD: patch-qtdeclarative_src_qml_jsruntime_qv4alloca__p.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* NetBSD has no alloca.h

--- qtdeclarative/src/qml/jsruntime/qv4alloca_p.h.orig	2013-11-27 01:02:16.000000000 +0000
+++ qtdeclarative/src/qml/jsruntime/qv4alloca_p.h
@@ -49,7 +49,7 @@
 #  ifndef __GNUC__
 #    define alloca _alloca
 #  endif
-#else
+#elif defined(Q_OS_LINUX)
 #  include <alloca.h>
 #endif
 
