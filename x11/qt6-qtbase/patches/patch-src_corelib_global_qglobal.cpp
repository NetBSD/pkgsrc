$NetBSD: patch-src_corelib_global_qglobal.cpp,v 1.1 2022/11/24 11:11:38 nros Exp $

* set the right product type and product version for Net and OpenBSD

--- src/corelib/global/qglobal.cpp.orig	2021-03-05 22:37:13.455522697 +0000
+++ src/corelib/global/qglobal.cpp
@@ -2607,7 +2607,9 @@ QString QSysInfo::productType()
     return QStringLiteral("macos");
 #elif defined(Q_OS_DARWIN)
     return QStringLiteral("darwin");
-
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+    return kernelType();
+    
 #elif defined(USE_ETC_OS_RELEASE) // Q_OS_UNIX
     QUnixOSVersion unixOsVersion;
     findUnixOsVersion(unixOsVersion);
@@ -2668,6 +2670,8 @@ QString QSysInfo::productVersion()
     }
     // fall through
 
+#elif defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+    return kernelVersion();
 #elif defined(USE_ETC_OS_RELEASE) // Q_OS_UNIX
     QUnixOSVersion unixOsVersion;
     findUnixOsVersion(unixOsVersion);
