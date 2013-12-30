$NetBSD: patch-qtbase_src_corelib_io_qfileselector.cpp,v 1.2 2013/12/30 11:49:48 jperkin Exp $

* NetBSD and SunOS need sys/utsname.h for uname(3)

--- qtbase/src/corelib/io/qfileselector.cpp.orig	2013-11-27 01:01:16.000000000 +0000
+++ qtbase/src/corelib/io/qfileselector.cpp
@@ -51,6 +51,10 @@
 #include <QtCore/QLocale>
 #include <QtCore/QDebug>
 
+#if defined(Q_OS_NETBSD) || defined(Q_OS_SOLARIS)
+#include <sys/utsname.h>
+#endif
+
 QT_BEGIN_NAMESPACE
 
 //Environment variable to allow tooling full control of file selectors
