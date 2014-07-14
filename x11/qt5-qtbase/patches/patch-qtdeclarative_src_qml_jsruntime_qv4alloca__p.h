$NetBSD: patch-qtdeclarative_src_qml_jsruntime_qv4alloca__p.h,v 1.2 2014/07/14 16:32:14 jperkin Exp $

* NetBSD has no alloca.h

--- qtdeclarative/src/qml/jsruntime/qv4alloca_p.h.orig	2014-02-01 20:38:02.000000000 +0000
+++ qtdeclarative/src/qml/jsruntime/qv4alloca_p.h
@@ -49,7 +49,7 @@
 #  ifndef __GNUC__
 #    define alloca _alloca
 #  endif
-#else
+#elif defined(Q_OS_LINUX) || defined(Q_OS_SOLARIS)
 #  include <alloca.h>
 #endif
 
