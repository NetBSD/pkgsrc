$NetBSD: patch-src_corelib_global_qsysinfo.cpp,v 1.1 2023/04/07 18:28:05 nros Exp $

* set the right product type and product version for Unix-like os (NetBSD, OpenBSd etc)

--- src/corelib/global/qsysinfo.cpp.orig	2023-03-14 08:29:43.000000000 +0000
+++ src/corelib/global/qsysinfo.cpp
@@ -794,6 +794,9 @@ QString QSysInfo::productType()
     findUnixOsVersion(unixOsVersion);
     if (!unixOsVersion.productType.isEmpty())
         return unixOsVersion.productType;
+
+#else // Q_OS_UNIX
+    return kernelType();
 #endif
     return unknownText();
 }
@@ -850,6 +853,9 @@ QString QSysInfo::productVersion()
     findUnixOsVersion(unixOsVersion);
     if (!unixOsVersion.productVersion.isEmpty())
         return unixOsVersion.productVersion;
+
+#else // Q_OS_UNIX
+    return kernelVersion();
 #endif
 
     // fallback
